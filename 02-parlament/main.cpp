#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int testCases;
    scanf("%d", &testCases);
    for (int i = 0; i < testCases; ++i)
    {
        unsigned rows, cols;
        scanf("%d%d", &rows, &cols);
        vector<vector<int>> parliament(rows,vector<int>(cols));

        /// scan da shit & sum da shit
        for (int j = 0; j < rows; ++j)
        {
            for (int k = 0; k < cols; ++k) {
                int comfort; scanf("%d", &comfort);
                parliament[j][k] = comfort;
                if(k)
                {
                    if(j)
                        parliament[j][k] += parliament[j][k-1] - parliament[j-1][k-1] ;
                    else
                        parliament[j][k] += parliament[j][k-1];

                }
                if(j)
                    parliament[j][k] += parliament[j-1][k];
            }
        }

        ///scan some test questions & print answer
        int questions;
        scanf("%d", &questions);
        for (int l = 0; l < questions; ++l)
        {
            int R1,S1,R2,S2;
            scanf("%d%d%d%d", &R1,&S1,&R2,&S2);
            R1--; S1--; R2--; S2--;

            int result = parliament[R2][S2];

            if(S1)
                result -= parliament[R2][S1-1];

            if(R1)
            {
                if(S1)
                    result = result - parliament[R1-1][S2] + parliament[R1-1][S1-1];
                else
                    result -= parliament[R1-1][S2];
            }

            printf("Absolutni hodnota pohodlnosti je %d bodu.\n", result);
        }

        /// odsadit rade
        printf("\n");
    }
    return 0;
}