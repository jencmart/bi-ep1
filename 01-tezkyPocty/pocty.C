#include <iostream>

using namespace std;

void count(int a, char c, int b);

int main() {
    unsigned testCases;
    scanf("%u", &testCases);

    for (int i = 0; i < testCases; ++i) {
        int a, b;
        char c;
        scanf("%d%c%d", &a, &c, &b);
        count(a, c, b);

    }
    return 0;
}

void count(int a, char c, int b)
{
    if (c == '+')
        cout << "Vysledek je " << a+b;
     else if (c == '-')
        cout << "Vysledek je " << a-b;
     else if (c == '*')
        cout << "Vysledek je " << a*b;
     else
    {
        if( a%b == 0)
            cout << "Vysledek je " << a/b;
        else
            cout << "Vysledek je " << a/b <<", zbytek " << a%b;
    }
    cout << '.' << endl;
}