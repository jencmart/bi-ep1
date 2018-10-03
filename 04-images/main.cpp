#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;
string binToHex(string & str)
{
    if      (str == "0000") return "0";
    else if (str == "0001") return "1";
    else if (str == "0010") return "2";
    else if (str == "0011") return "3";
    else if (str == "0100") return "4";
    else if (str == "0101") return "5";
    else if (str == "0110") return "6";
    else if (str == "0111") return "7";
    else if (str == "1000") return "8";
    else if (str == "1001") return "9";
    else if (str == "1010") return "A";
    else if (str == "1011") return "B";
    else if (str == "1100") return "C";
    else if (str == "1101") return "D";
    else if (str == "1110") return "E";
    else                    return "F";
}

string HexToBin(char str)
{
    if      (str == '0') return "0000";
    else if (str == '1') return "0001";
    else if (str == '2') return "0010";
    else if (str == '3') return "0011";
    else if (str == '4') return "0100";
    else if (str == '5') return "0101";
    else if (str == '6') return "0110";
    else if (str == '7') return "0111";
    else if (str == '8') return "1000";
    else if (str == '9') return "1001";
    else if (str == 'A') return "1010";
    else if (str == 'B') return "1011";
    else if (str == 'C') return "1100";
    else if (str == 'D') return "1101";
    else if (str == 'E') return "1110";
    else                 return "1111";
}

char hexa [16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
string decodeIntersectEncode(string & a, string & b)
{
    if(a[0] == '1' && b[0] == '1' ) // jednobarevny qad
    {
        a.erase(0,1); b.erase(0,1); // nasleduji pouze barvy
        string ret;
        ret.push_back('1');
        char c = a[0] == '1' && b[0] == '1' ? '1' : '0';
        ret.push_back(c);
        a.erase(0,1); b.erase(0,1); // odstran barvy
        return ret;
    }

    string p1,p2,p3,p4;

    if(a[0] == '0' && b[0] == '0') {
        a.erase(0,1); // nasleduji 4 quad stromy
        b.erase(0,1); // nasleduji 4 quad stromy
    }
    else if(a[0] == '1' && b[0] == '0') {
        b.erase(0,1); // nasleduji 4 quad stromy...

        string x; x += a[0];x += a[1];
        a.insert(0, x);
        a.insert(0, x);
        a.insert(0, x);
    }
    else if(a[0] == '0' && b[0] == '1') {
        a.erase(0,1); // nasleduji 4 quad stromy...

        string x; x += b[0];x += b[1];
        b.insert(0, x);
        b.insert(0, x);
        b.insert(0, x);
    }

    p1 = decodeIntersectEncode(a,b);
    p2 = decodeIntersectEncode(a,b);
    p3 = decodeIntersectEncode(a,b);
    p4 = decodeIntersectEncode(a,b);

    string ret;
    if(p1 == p2 && p2 == p3 && p3 == p4)
    {
        ret.push_back('1');
        ret +=p1;
    }

    else
    {
        ret.push_back('0');
        ret +=p1;
        ret +=p2;
        ret +=p3;
        ret +=p4;
    }

    return ret;
}

int main()
{
    int cnt = 1;
    while(true)
    {
        string a, b;getline(cin, a);getline(cin, b);
        if(a.size() == 1 && b.size() == 1 && a[0] == '0' && b[0] == '0')
            break;

        string aa,bb;

        for(auto & c : a)
            aa += HexToBin(c);
        for(auto & c : b)
            bb += HexToBin(c);

        //odmaz prebytecne nuly na zacatku
        while(aa[0] == '0')
            aa.erase(0,1);
        while(bb[0] == '0')
            bb.erase(0,1);

        // odmaz navesti
        aa.erase(0,1);
        bb.erase(0,1);


        string result = decodeIntersectEncode(aa,bb);
        result.insert(0, "1");

        while(result.size() % 4 != 0)
            result.insert(0, "0");

        string resultHexa;

        for(int i = 0 ; i <= result.size()-4 ; i+=4)
        {
            string tmp = result.substr (i,4);

            resultHexa += binToHex(tmp);
        }

        cout << "Image " << cnt++ << ':' << endl;
        cout << resultHexa << endl << endl;
    }
    return 0;
}
