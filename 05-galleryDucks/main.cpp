#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int duckCnt;
    while(scanf("%d", &duckCnt) == 1)
    {
        vector<int> duckArray;
        for (int j = 0; j < duckCnt ; ++j)
        {
            int duckType;
            scanf("%d", &duckType);
            duckArray.emplace_back(duckType);
        }

        vector< vector<int>> duckingMatrix(duckCnt, vector<int>(duckCnt, 0));
        for(int len=1; len < duckingMatrix.size() ; ++len)
        {
            for(int i = 0; i+len < duckingMatrix.size() ; ++i)
            {
                int j = i + len;
                if(duckArray[i] == duckArray[j])
                    duckingMatrix[i][j] = 1 + duckingMatrix[i+1][j-1];
                else
                    duckingMatrix[i][j] =  duckingMatrix[i][j-1] > duckingMatrix[i+1][j] ? duckingMatrix[i][j-1] : duckingMatrix[i+1][j]   ;
            }
        }

        printf("%d\n", duckingMatrix[0][duckCnt-1]);
    }
    return 0;
}