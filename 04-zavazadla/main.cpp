#include <iostream>
#include <vector>

using namespace std;



// ze ja to predelam tak ze budu mit tri hromadky a budu na ne doopravdy davat

int countRecursively(vector<int> & containers, int position)
{
    if(containers.empty())
        return 0;

    int firstOne = containers[0];

    if(position == firstOne)
    {
        int curr = containers[0];
        while(! containers.empty())
            if(containers[0] == curr)
                containers.erase(containers.begin());
            else
                break;

        if(containers.empty())
            return 0;
    }


    //2

    //0 0 - false
    //1 1 - false

    //0 1 -true
    //0 2 - false
    //1 0 -true
    //1 2 - false

    // stejna stejna - false
    // a , b && b != te co tu byla - true
    //
    // jeste musim podchytnout kdyz davam poprve na nakou hromadku
    // tam pak bude true i kdyby nekdy vlastne bylo false

    if(containers.size() == 1)
        return 1;

    int lower = containers[0];
    containers.erase(containers.begin());


    int newCoumn;

    if(containers[0] == lower)
    {
        if(position == 0 && lower == 1) newCoumn = 2;
        if(position == 0 && lower == 2) newCoumn = 1;
        if(position == 1 && lower == 0) newCoumn = 2;
        if(position == 1 && lower == 2) newCoumn = 0;
        if(position == 2 && lower == 0) newCoumn = 1;
        if(position == 2 && lower == 1) newCoumn = 0;
    }
    else
    {
        if(containers[0] == position)
        {
            if(position == 0 && lower == 1) newCoumn = 2;
            if(position == 0 && lower == 2) newCoumn = 1;
            if(position == 1 && lower == 0) newCoumn = 2;
            if(position == 1 && lower == 2) newCoumn = 0;
            if(position == 2 && lower == 0) newCoumn = 1;
            if(position == 2 && lower == 1) newCoumn = 0;
        }
        else
        {
             newCoumn = containers[0];
        }
    }

    int soFar = 1 + (1 << containers.size()) - 1;

    return  soFar +  countRecursively(containers, newCoumn);

}
int main() {

    int cntTests;
    scanf("%d", &cntTests);

    for (int i = 0; i < cntTests; ++i)
    {
        int containersCnt;
        scanf("%d", &containersCnt);

        vector<int> containers;
        for (int j = 0; j < containersCnt; ++j)
        {
            int containerNum;
            scanf("%d", &containerNum);
            containers.emplace_back(containerNum);
        }

        if(containers.empty())
            containers.push_back(0);

        int cntMoves = countRecursively(containers, containers[0]);

        printf("Je treba %d presunu.\n", cntMoves);
    }
    return 0;
}