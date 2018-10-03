#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    unsigned testCases;
    scanf("%u ", &testCases);

    for(int i = 0 ; i < testCases ; ++i)
    {
        string str;
        getline(cin, str);
        std::reverse(str.begin(), str.end());
        cout << str << endl;
    }
    return 0;
}