#include <math.h>
#include <stdio.h>

const double eps = 0.00001;

double f(double x);
double f_derivative(double x, double step);
double newton(double start, double end);

int main(void)
{
    double start_segment = 0.0;
    double end_segment = 0.0;

    if (scanf("%lf %lf", &start_segment, &end_segment) != 2)
        return -1;

    if (start_segment == 0 || end_segment == 0 || start_segment >= end_segment) {
        printf("no root\n");
        return 0;
    }

    double res = newton(start_segment, end_segment);
    printf("%.4f\n", round(res * 10000) / 10000);

    return 0;
}

double f(double x)
{
    return sin(x) - 1.0 / x;
}

// Численный метод вычисления производной
double f_derivative(double x, double step)
{
    return (f(x + step) - f(x - step)) / (2 * step);
}

double newton(double start, double end)
{
    double x0 = (start + end) / 2;
    double step = 1e-6;

    double x1 = x0 - f(x0) / f_derivative(x0, step);

    while (fabs(x1 - x0) >= eps) {
        x0 = x1;
        x1 = x0 - f(x0) / f_derivative(x0, step);
    }

    return x1;
}