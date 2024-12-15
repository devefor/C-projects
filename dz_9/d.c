#include <math.h>
#include <stdio.h>

const double eps = 0.0001;

double gradient_x(double x, double y);
double gradient_y(double x, double y);
double gradient_normalize(double x, double y);
void gradient_descent(double* x, double* y);

int main(void)
{
    double x = 0.0;
    double y = 0.0;

    if (scanf("%lf %lf", &x, &y) != 2)
        return -1;

    gradient_descent(&x, &y);

    if (x < 0 && x > -eps)
        x = 0;
    if (y < 0 && y > -eps)
        y = 0;

    x = round(x * 1000) / 1000;
    y = round(y * 1000) / 1000;

    printf("%.3f %.3f\n", x, y);

    return 0;
}

double gradient_x(double x, double y)
{
    return 6 * x + y - 1;
}

double gradient_y(double x, double y)
{
    return x + 4 * y - 4;
}

double gradient_normalize(double x, double y)
{
    return sqrt((6 * x + y - 1) * (6 * x + y - 1) + (x + 4 * y - 4) * (x + 4 * y - 4));
}

void gradient_descent(double* x, double* y)
{
    double alpha = 0.01;

    while (gradient_normalize(*x, *y) >= eps) {
        double grad_x = gradient_x(*x, *y);
        double grad_y = gradient_y(*x, *y);

        *x -= alpha * grad_x;
        *y -= alpha * grad_y;
    }
}