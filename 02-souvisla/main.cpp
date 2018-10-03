#include <iostream>

int main() {

    unsigned testCases; scanf("%u", &testCases);

    for (int i = 0; i < testCases; ++i)
    {
        unsigned maxLength = 0;
        unsigned lastNum = 0;
        unsigned tmpMaxLength = 1;
        while(true)
        {
            unsigned num; scanf("%u", &num); if(num == 0) break;
            if(!lastNum) { lastNum = num; continue;}

            if(num >= lastNum)
                tmpMaxLength++;
            else
            {
                maxLength = maxLength > tmpMaxLength ? maxLength : tmpMaxLength;
                tmpMaxLength = 1;
            }

            lastNum = num;
        }

        maxLength = maxLength > tmpMaxLength ? maxLength : tmpMaxLength;
        if(maxLength == 1)
            maxLength = 1;
        printf("%u\n", maxLength);
    }
    return 0;
}