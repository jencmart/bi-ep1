#include <iostream>
#include <vector>
#include <math.h>

void countPonorks(int stepLen, std::vector<double> & parts);
int main() {
    int cntTests;
    scanf("%d", &cntTests);

    for (int i = 0; i < cntTests; ++i)
    {
        int stepLength, cntParts;
        scanf("%d%d", &stepLength, &cntParts);
        std::vector<double> parts;

        for (int j = 0; j < cntParts; ++j)
        {
            int part;
            scanf("%d", &part);
            parts.emplace_back(part);
        }

        countPonorks(stepLength,parts);
    }
    return 0;
}



bool nearlyEqual(double a, double b)
{
    return ( fabs(a - b) < .001);
}


void countPonorks(int stepLen, std::vector<double> & parts)
{
    int ponorksCnt = 0;

    for (int i = 0; i < parts.size(); ++i)
    {
        while( nearlyEqual(parts[i], (double)stepLen) || parts[i] > stepLen )
        {
            ponorksCnt++;
            parts[i] -= stepLen;
        }

        if(parts[i] > 0)
        {
            if(i+1 == parts.size()) // last step
            {
                double halfOfStep = ((double)stepLen) / 2;

                if( nearlyEqual(parts[i], halfOfStep) || parts[i] > halfOfStep)
                    ponorksCnt++;
            }

            else                    // more steps to go
            {
                parts[i+1] -= sqrt(  stepLen*stepLen - parts[i] * parts[i] );
                ponorksCnt++;
            }

        }
    }

    printf("Strazny ujde %d ponorku.\n", ponorksCnt);
}