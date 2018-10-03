#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define DBL_EPSILON 2.2204460492503131e-16

bool almostEqual(double a, double b)
{
    double diff = fabs(a - b);

    if (a == b)
        return true;

    if (a == 0 || b == 0 )
        return diff < DBL_EPSILON;

    return (diff / fabs(a) + fabs(b)) < DBL_EPSILON;
}

int main()
{

    for (;;)
    {
        unsigned testCases; scanf("%u", &testCases); if (testCases == 0) break;

        double maxLength = 0;
        unsigned usCnt = 0;

        for (unsigned i = 0; i < testCases; ++i)
        {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

            double result = (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);

            if (almostEqual(result, maxLength))
                usCnt++;

            else if (result > maxLength) {
                maxLength = result;
                usCnt = 1;
            }
        }
        printf("%u usecek ma delku %.2f.\n", usCnt, sqrt(maxLength));
    }
    return 0;
}