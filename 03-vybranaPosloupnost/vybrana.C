#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/// nejlepsi delky 1 2 3 4 5 ... 100 000
    /// a na jake pozici
    // dve koncici sestkou

/// 2 6 12 5 9 4 5 10 7 1 14 8

/// 1 2  3  4 5 6 7 8 9 delka posloupnosti
//  2 6 12
//    5
//      9
//    4
//      5
//         10

/// prepisu vetsi
// kdyz neni dam na nove misto
//

int main()
{
    int testsCnt;
    scanf("%d", &testsCnt);

    for (int i = 0; i < testsCnt; ++i)
    {
        vector<int> maxDelka;

        while(true)
        {
            int num; scanf("%d", &num);
            // vloz cislo na posledni pozici ktera neni vetsi nez toto cislo
            // lower bound - prvni prvek roven nebo vetsi
            // upper bound - prvni vetsi
            // vezmu upper bound a tam vlozim to cislo
            vector<int>::iterator it =  upper_bound(maxDelka.begin(), maxDelka.end() , num);
            if(it == maxDelka.end())
                maxDelka.push_back(num);
            else
                *it = num;

            if(num==0)break;
        }

        printf("%d\n", (int)maxDelka.size() );
    }
    return 0;
}