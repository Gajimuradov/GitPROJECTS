#!/bin/bash

# Т.к. утилита cat ведет себя в разных ОС по разному, и в макОс не поддерживает GNU флаги
# В тестах для GNU блока в оригинальной утилите ключи заменяются согласно заданию
# T -> t
# E -> e
# number-nonblank -> b
# number -> n
# squeeze-blank -> s

# программа эмулирует поведение cat на MacOS Big Sur 
# Darwin tammiravs-iMac.local 20.1.0 Darwin Kernel Version 20.1.0: Sat Oct 31 00:07:11 PDT 2020; root:xnu-7195.50.7~2/RELEASE_X86_64 x86_64

SUCCESS=0
FAIL=0
COUNTER=0
DIFF=""

s21_command=(
    "./s21_cat"
    )
sys_command=(
    "cat"
    )

tests=(
"FLAGS test_files/test_case_cat.txt"
"FLAGS test_files/test_case_cat.txt test_files/test_1_cat.txt"
)
flags=(
    "b"
    "e"
    "n"
    "s"
    "t"
    "v"
)
manual=(
"-s test_files/test_1_cat.txt"
"-b -e -n -s -t -v test_files/test_1_cat.txt"
"-b test_files/test_1_cat.txt nofile.txt"
"-t test_files/test_3_cat.txt"
"-n test_files/test_2_cat.txt"
"no_file.txt"
"-n -b test_files/test_1_cat.txt"
"-s -n -e test_files/test_4_cat.txt"
"-n test_files/test_1_cat.txt"
"-n test_files/test_1_cat.txt test_files/test_2_cat.txt"
"-v test_files/test_5_cat.txt"
)

gnu=(
"-T test_files/test_1_cat.txt"
"-E test_files/test_1_cat.txt"
"-vT test_files/test_3_cat.txt"
"--number test_files/test_2_cat.txt"
"--squeeze-blank test_files/test_1_cat.txt"
"--number-nonblank test_files/test_4_cat.txt"
"--number --number test_files/test_1_cat.txt"
"-bnvste test_files/test_6_cat.txt"
"-TE test_files/test_1_cat.txt"
"--number --squeeze-blank test_files/test_2_cat.txt"
)
run_test() {
    param=$(echo "$@" | sed "s/FLAGS/$var/")
    "${s21_command[@]}" $param > "${s21_command[@]}".log
    "${sys_command[@]}" $param > "${sys_command[@]}".log
    DIFF="$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
    let "COUNTER++"
    if [ "$DIFF" == "Files "${s21_command[@]}".log and "${sys_command[@]}".log are identical" ]
    then
        let "SUCCESS++"
        echo "$COUNTER - Success $param"
    else
        let "FAIL++"
        echo "$COUNTER - Fail $param"
    fi
    rm -f "${s21_command[@]}".log "${sys_command[@]}".log
}
run_gnu_test() {
    param=$(echo "$@" | sed "s/FLAGS/$var/")
	param_cat=$(echo "$param" | sed "s/T/t/g")
	param_cat=$(echo "$param_cat" | sed "s/E/e/g")
	param_cat=$(echo "$param_cat" | sed "s/-number-nonblank/b/g")
	param_cat=$(echo "$param_cat" | sed "s/-number/n/g")
	param_cat=$(echo "$param_cat" | sed "s/-squeeze-blank/s/g")
	${s21_command[@]} $param > "${s21_command[@]}".log
    ${sys_command[@]} $param_cat > "${sys_command[@]}".log

    DIFF="$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
    let "COUNTER++"
    if [ "$DIFF" == "Files "${s21_command[@]}".log and "${sys_command[@]}".log are identical" ]
    then
        let "SUCCESS++"
        echo "$COUNTER - Success $param"
    else
        let "FAIL++"
        echo "$COUNTER - Fail $param"
    fi
    rm -f "${s21_command[@]}".log "${sys_command[@]}".log
}

echo "^^^^^^^^^^^^^^^^^^^^^^^"
echo "TESTS WITH NORMAL FLAGS"
echo "^^^^^^^^^^^^^^^^^^^^^^^"
printf "\n"
echo "#######################"
echo "MANUAL TESTS"
echo "#######################"
printf "\n"
for i in "${manual[@]}"
do
    var="-"
    run_test "$i"
done
printf "\n"
echo "#######################"
echo "AUTOTESTS"
echo "#######################"
printf "\n"
echo "======================="
echo "1 PARAMETER"
echo "======================="
printf "\n"

for var1 in "${flags[@]}"
do
    for i in "${tests[@]}"
    do
        var="-$var1"
        run_test "$i"
    done
done
printf "\n"
echo "======================="
echo "2 PARAMETERS"
echo "======================="
printf "\n"

for var1 in "${flags[@]}"
do
    for var2 in "${flags[@]}"
    do
        if [ $var1 != $var2 ]
        then
            for i in "${tests[@]}"
            do
                var="-$var1 -$var2"
                run_test "$i"
            done
        fi
    done
done
printf "\n"
echo "======================="
echo "3 PARAMETERS"
echo "======================="
printf "\n"
for var1 in "${flags[@]}"
do
    for var2 in "${flags[@]}"
    do
        for var3 in "${flags[@]}"
        do
            if [ $var1 != $var2 ] && [ $var2 != $var3 ] && [ $var1 != $var3 ]
            then
                for i in "${tests[@]}"
                do
                    var="-$var1 -$var2 -$var3"
                    run_test "$i"
                done
            fi
        done
    done
done
printf "\n"
echo "======================="
echo "4 PARAMETERS"
echo "======================="
printf "\n"
for var1 in "${flags[@]}"
do
    for var2 in "${flags[@]}"
    do
        for var3 in "${flags[@]}"
        do
            for var4 in "${flags[@]}"
            do
                if [ $var1 != $var2 ] && [ $var2 != $var3 ] \
                && [ $var1 != $var3 ] && [ $var1 != $var4 ] \
                && [ $var2 != $var4 ] && [ $var3 != $var4 ]
                then
                    for i in "${tests[@]}"
                    do
                        var="-$var1 -$var2 -$var3 -$var4"
                        run_test "$i"
                    done
                fi
            done
        done
    done
done
# 2 склеенных параметра
printf "\n"
echo "======================="
echo "2 GLUED PARAMETERS"
echo "======================="
printf "\n"
for var1 in "${flags[@]}"
do
    for var2 in "${flags[@]}"
    do
        if [ $var1 != $var2 ]
        then
            for i in "${tests[@]}"
            do
                var="-$var1$var2"
                run_test "$i"
            done
        fi
    done
done

# 3 склеенных параметра
printf "\n"
echo "======================="
echo "3 GLUED PARAMETERS"
echo "======================="
printf "\n"
for var1 in "${flags[@]}"
do
    for var2 in "${flags[@]}"
    do
        for var3 in "${flags[@]}"
        do
            if [ $var1 != $var2 ] && [ $var2 != $var3 ] && [ $var1 != $var3 ]
            then
                for i in "${tests[@]}"
                do
                    var="-$var1$var2$var3"
                    run_test "$i"
                done
            fi
        done
    done
done

# 4 склеенных параметра
printf "\n"
echo "======================="
echo "4 GLUED PARAMETERS"
echo "======================="
printf "\n"
for var1 in "${flags[@]}"
do
    for var2 in "${flags[@]}"
    do
        for var3 in "${flags[@]}"
        do
            for var4 in "${flags[@]}"
            do
                if [ $var1 != $var2 ] && [ $var2 != $var3 ] \
                && [ $var1 != $var3 ] && [ $var1 != $var4 ] \
                && [ $var2 != $var4 ] && [ $var3 != $var4 ]
                then
                    for i in "${tests[@]}"
                    do
                        var="-$var1$var2$var3$var4"
                        run_test "$i"
                    done
                fi
            done
        done
    done
done
printf "\n"
echo "FAILED: $FAIL"
echo "SUCCESSFUL: $SUCCESS"
echo "ALL: $COUNTER"
printf "\n"
##############################
