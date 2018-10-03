#include <iostream>
#include <list>

unsigned reverse(unsigned x);
using namespace std;
int main() {
    unsigned testCases;
    scanf("%u", &testCases);

    for(int i = 0 ; i < testCases; ++i)
    {
        unsigned x, y;
        scanf("%u%u", &x, &y);

        unsigned res = reverse(x) + reverse(y);


        cout <<  reverse(res) << endl;
    }
    return 0;
}

unsigned reverse(unsigned x)
{
    if(x/10 == 0)
        return x;

    list<unsigned> values;

    while(x)
    {
        values.push_back(x%10);
        x /= 10;
    }

    unsigned exp = 10;
    for(int i = 1 ; i < (values.size() - 1); ++i)
        exp *= 10;



    unsigned  finalNumber = 0;
    for( auto val : values )
    {
        if(!exp)
            finalNumber += val;
        else
            finalNumber += exp*val;
        exp/=10;
    }

    return finalNumber;
}