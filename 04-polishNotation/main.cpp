#include <iostream>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;

struct Node {
    Node(char v) : m_v(v), m_l(nullptr), m_r(nullptr){}
    char m_v;
    Node * m_l, * m_r;
    void print()
    {
        if(m_l) m_l->print();
        if(m_r) m_r->print();
        cout << m_v << ' ';
    }
};

Node * fillTree(list<char> & tokens)
{
    char c = tokens.front();
    tokens.pop_front();

    auto * curr = new Node(c);

    if( c < '0' || c > '9' ) {
        curr->m_l = fillTree(tokens);
        curr->m_r = fillTree(tokens);
    }

    return curr;
}
int main() {
    while (true)
    {
        string s; getline(cin, s);
        if(s.size() == 1 & s[0] == '0') break;

        list<char> tokens;

        for(auto c : s)
            if(c != ' ')
                tokens.push_back(c);

        fillTree(tokens)->print();
        printf("\n");
    }
}