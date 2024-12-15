#include <math.h>
#include <stdio.h>

double fi(double x, double y);
double euler(double start, double end, double y0);

int main(void)
{
    double start_segment = 0.0;
    double end_segment = 0.0;
    double initial_condition = 0.0;

    if (scanf("%lf %lf %lf", &start_segment, &end_segment, &initial_condition) != 3)
        return -1;

    if (start_segment <= 0 || end_segment <= 0 || start_segment >= end_segment) {
        printf("no root\n");
        return 0;
    }

    double res = euler(start_segment, end_segment, initial_condition);
    printf("%.4f\n", round(res * 10000) / 10000);

    return 0;
}

double fi(double x, double y)
{
    return y / x - log(x) / x;
}

double euler(double start, double end, double y0)
{
    double step = 0.000001;

    for (double i = start; i < end; i += step) {
        double y1 = y0 + step * fi(i, y0);
        y0 = y1;
    }

    return y0;
}