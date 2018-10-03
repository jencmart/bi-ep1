#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

void permutate(list<char> & x, string & printStr)
{
    if(x.empty()) { cout << printStr << endl; return; }

    for(auto it = x.begin() ; it != x.end() ; ++it)
    {
        printStr.push_back(*it);

        /// lvl. retarded
        list<char> newList; for (auto a =  x.begin() ; a != x.end() ; ++a)  { if (a != it) newList.push_back(*a);}
        permutate(newList, printStr);

        printStr.pop_back();

        /// skip repeating chars
        auto it2 = it; for( ; *it == *it2 && it2 != x.end(); it2++) ; it = --it2;
    }
}

int main()
{
    string str;
    while(getline(cin, str))
    {
        sort(str.begin(), str.end());
        list<char> lst;

        for(char a : str)
            lst.push_back(a);

        string printStr;
        permutate(lst, printStr);
        printf("\n");
    }

    return 0;
}