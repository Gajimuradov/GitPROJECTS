#include "s21_math.h"

int s21_abs(int x) { return (x < 0 && x > INT_MIN) ? -x : x; }

long double s21_ceil(double x) {
  if (x == S21_INF) {
    x = S21_INF;
  } else if (x != x) {
    x = S21_NAN;
  } else if (x == -S21_INF) {
    x = -S21_INF;
  } else {
    int minx = x;
    double sravnenie = x - minx;
    if (sravnenie > 0.0) minx += 1;
    x = minx;
  }
  return x;
}

// Возвращает значение е, возведённое в заданную степень
long double s21_exp(double x) {
  int racional = 0;
  long double res = 1.0;
  long double temp = 1.0;
  long double counter = 1.0;
  if (x < 0) {
    x *= -1;
    racional = 1;
  }
  while (s21_fabs(res) > S21_EXP) {
    res *= x / counter;
    counter += 1;
    temp += res;
    if (temp > S21_MAX_LONG_DOUBLE) {
      temp = S21_INF;
      break;
    }
  }
  if (racional == 1) {
    if (temp > S21_MAX_LONG_DOUBLE) {
      temp = 0;
    } else {
      temp = 1. / temp;
    }
  }
  if (temp > S21_MAX_LONG_DOUBLE) {
    temp = S21_INF;
  }
  return temp;
}

long double s21_fabs(double x) {
  if (x < 0) x = -x;
  return (long double)x;
}

long double s21_floor(double x) {
  if (x == S21_INF) {
    x = S21_INF;
  } else if (x == -S21_INF) {
    x = -S21_INF;
  } else if (x < 0) {
    x = (int)x - 1.0;
  } else {
    int minx = x;
    double sravnenie = x - minx;
    if (sravnenie > 0.0) {
      x = minx;
    }
  }
  return x;
}

long double s21_fmod(double x, double y) {
  long double ost = 0.0;
  long double fx = s21_fabs(x);
  if ((y == 0) || (x == S21_INF && y == S21_INF) ||
      (x == -S21_INF && y == -S21_INF) || (x == -S21_INF && y == S21_INF)) {
    ost = S21_NAN;
  } else if (fx == y) {
    ost = -0;
  } else if ((fx < y) || (x < 0 && y == -S21_INF)) {
    ost = x;
  } else {
    long long int mod = x / y;
    ost = (long double)x - mod * (long double)y;
  }
  return ost;
}

long double s21_log(double x) {
  long double log = 0.0;
  int count = 0;
  double res = 0.0;
  double comparison = 0.0;
  if (x == 0) {
    log = -S21_INF;
  } else if (x < 0) {
    log = S21_NAN;
  } else if (x == S21_INF) {
    log = S21_INF;
  } else {
    while (x >= S21_M_E) {
      x /= S21_M_E;
      count++;
    }
    for (int i = 0; i < 100; i++) {
      comparison = res;
      res = comparison +
            2 * (x - s21_exp(comparison)) / (x + s21_exp(comparison));
    }
    log = res + count;
  }
  return log;
}

long double s21_pow(double base, double exp) {
  long double res = (base < 0 && exp != (long long int)exp) ? S21_NAN : 0;
  if (res == 0) {
    int sign = base < 0 ? -1 : 1;
    res = s21_exp(exp * s21_log(base * sign));
    if (s21_fmod(exp, 2)) res *= sign;
  }
  return res;
}

long double s21_sqrt(double x) {
  double res = x < 0 ? S21_NAN : s21_pow(x, 0.5);
  return res;
}

long double s21_cos(double x) {
  double r, s, numerator, denominator = 1, ratio = 1;
  int n = 1;
  r = s21_fmod(x, 2 * S21_PI);
  s = 1;
  numerator = 1;
  do {
    numerator *= (-1) * r * r;
    denominator *= (2 * n - 1) * 2 * n;
    ratio = numerator / denominator;
    s += ratio;
    n++;
  } while (s21_fabs(ratio) > S21_EPS10);
  return s;
}

long double s21_sin(double x) {
  double r, s, numerator, denominator = 1, ratio = 1;
  int n = 1;

  r = s21_fmod(x, 2 * S21_PI);
  s = r;
  numerator = r;
  do {
    numerator *= (-1) * r * r;
    denominator *= 2 * n * (2 * n + 1);
    ratio = numerator / denominator;
    s += ratio;
    n++;
  } while (s21_fabs(ratio) > S21_EPS10);

  return (s);
}

long double s21_tan(double x) {
  double result = s21_sin(x) / s21_cos(x);
  return result;
}

/////////////////////////////////////////////////////////////////
long double s21_asin(double x) {
  double asin = x;
  if ((x >= (-S21_PI / 2)) && (x <= (S21_PI / 2))) {
    double d = x;
    int n = 1;
    if (x > 1 || x < -1) {
      asin = S21_NAN;
    } else if (x == 1) {
      asin = (S21_PI / 2);
    } else if (x == -1) {
      asin = (-S21_PI / 2);
    } else {
      while (!(d >= -S21_EPS10 && d <= S21_EPS10)) {
        d = ((d) * (x * x) * (2 * n - 1) * (2 * n - 1)) /
            ((2 * n + 1) * (2 * n));
        asin = asin + d;
        n++;
      }
    }
  } else {
    asin = S21_NAN;
  }
  return asin;
}

long double s21_acos(double x) {
  double resultc;
  if (x < -1.0 || x > 1.0) {
    resultc = S21_NAN;
  } else {
    resultc = (S21_PI / 2) - s21_asin(x);
  }
  return resultc;
}

long double s21_atan(double x) {
  double res = 0;
  double y = x;
  if (x != x) {
    res = x;
  } else if (x == 1 || x == -1) {
    res = x * 0.785398163;
  } else if (x == 0) {
    res = x;
  } else {
    if (x > 1 || x < -1) {
      x = 1 / x;
    }
    for (int i = 1; i < 100; i += 2) {
      res += s21_pow(-1, (i - 1) / 2) * s21_pow(x, i) /
             i;  // заработает когда подключат к общей библиотеке
    }
  }
  if (y > 1) {
    res = (S21_PI / 2) - res;
  }
  if (y < -1) {
    res = (-S21_PI / 2) - res;
  }
  return res;
}