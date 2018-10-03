#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

using  namespace std;

int main() {
    int testCases;scanf("%d\n", &testCases);

    for (int i = 0; i < testCases; ++i)
    {
        char c;
        bool mistake = false;
        string line;
        getline(std::cin, line);
        vector<char> myStack(0);
        vector<char> pseudoLine;
        for(char ch : line)
            pseudoLine.push_back(ch);

        for( int j = 0 ; j < pseudoLine.size() ; ++j)
        {

            c = pseudoLine[j];

            if( c == '[' || c == '{' || c == '<')
                myStack.push_back(c);

            else if( c == '(')
            {
                if(j+1 < pseudoLine.size() && pseudoLine[j+1] == '*')
                {
                    j++;
                    myStack.push_back('&');
                }
                else
                    myStack.push_back('(');

            }

            else if( c == '*') {
                if(j+1 < pseudoLine.size() && pseudoLine[j+1] == ')' )
                {
                    if(myStack.empty() || myStack.back() != '&') { mistake = true; break; }
                    j++;
                    myStack.pop_back();
                }
            }
            else if( c == ')' || c == ']' || c == '}' || c == '>') {
                if(myStack.empty()    ||
                   (c == ')' && myStack.back() != '(') ||
                   (c == ']' && myStack.back() != '[') ||
                   (c == '}' && myStack.back() != '{') ||
                   (c == '>' && myStack.back() != '<') )
                {
                    mistake = true; break;
                }
                else
                    myStack.pop_back();
            }
        }

        if(mistake || !myStack.empty())
            printf("V planu je chyba.\n");
        else
            printf("Plan je v poradku.\n");
    }

    return 0;
}
