#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    // go through all test cases
    for (int i = 0; i < t; ++i)
    {
        int f, e, n;
        scanf("%d %d %d", &e, &f, &n);

        int coinWeight = f - e;
        vector<int> values;
        vector<int> weights;

        // scan all coint types
        for (int j = 0; j < n; ++j)
        {
            int val, weight;
            scanf("%d %d", &val, &weight);
            values.emplace_back(val);
            weights.emplace_back(weight);
        }

        vector<int> allValues(coinWeight+1, 0);


        for (int j = 0; j < values.size(); ++j)
        {
            // out of bound
            if(weights[j] >= allValues.size())
                continue;
            if(allValues[weights[j]] == 0 || allValues[weights[j]] > values[j])
                allValues[weights[j]] = values[j];
        }


        for(int k = 0; k < allValues.size(); k++)
        {
            // go through all coin weights
            for (int j = 0; j < values.size(); ++j)
            {
                // out of bound
                if(k+weights[j] >= allValues.size())
                    continue;

                //nahrad nizzsi hodnotou
                if((allValues[k] != 0) && (allValues[weights[j]+k] > values[j]+allValues[k] || allValues[weights[j]+k] == 0))
                    allValues[weights[j]+k] = values[j]+allValues[k];
            }
        }

        if(allValues[allValues.size()-1] == 0)
            printf("This is impossible.\n");
        else
                printf("The minimum amount of money in the piggy-bank is %d.\n", allValues[allValues.size()-1]);


    }

    return 0;
}
