#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;
vector<string> toSort;

void permutate(list<char> & x, string & printStr)
{
    if(x.empty()) //{ cout << printStr << "\n"; return; }
    {
        toSort.push_back(printStr);
    }
    for(auto it = x.begin() ; it != x.end() ; ++it)
    {
        printStr.push_back(*it);

        /// lvl. retard
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
        if(str == "x")
            break;

        sort(str.begin(), str.end());
        list<char> lst;

        for(char a : str)
            lst.push_back(a);

        string printStr;
        permutate(lst, printStr);
      //  printf("\n");
    }

    sort(toSort.begin(), toSort.end());
    for(auto str : toSort)
    {
        for(auto c : str)
        {
            cout << 1 << " "<< c << endl;
        }
        cout  << "4\n\n" ;
    }
    return 0;
}