#include <iostream>
#include <vector>

using namespace std;

void insertDigit(int , char , vector<vector<char>>  &);

int main() {

    char dig1, dig2, col, dig3, dig4;
    while(scanf("%c%c%c%c%c", &dig1, &dig2, &col, &dig3, &dig4) == 5)
    {
        if(dig1 == 'e')
            break;
        vector<vector<char>> digits(7,vector<char>(29,' '));
        digits[2][14] = 'o';
        digits[4][14] = 'o';

        insertDigit(0, dig1, digits);
        insertDigit(7, dig2, digits);
        insertDigit(17, dig3, digits);
        insertDigit(24, dig4, digits);

        for (auto & row : digits)
        {
            for(auto & column : row)
            {
                printf("%c", column);
            }
            printf("\n");
        }

        printf("\n");
        printf("\n");

        char dummy;
        scanf("%c", &dummy);
    }


    printf("end\n");
    return 0;
}


void insertSegment(int pos,int segment, vector<vector<char>>& digits)
{
    if(segment == 1)
    {
        digits[0][pos] = '+';
        digits[0][pos+1] = '-';
        digits[0][pos+2] = '-';
        digits[0][pos+3] = '-';
        digits[0][pos+4] = '+';

    }
    else if(segment == 2)
    {
        digits[0][pos+4] = '+';
        digits[1][pos+4] = '|';
        digits[2][pos+4] = '|';
        digits[3][pos+4] = '+';

    }
    else if(segment == 3)
    {
        digits[3][pos+4] = '+';
        digits[4][pos+4] = '|';
        digits[5][pos+4] = '|';
        digits[6][pos+4] = '+';
    }

    else if(segment == 4)
    {
        digits[6][pos] = '+';
        digits[6][pos+1] = '-';
        digits[6][pos+2] = '-';
        digits[6][pos+3] = '-';
        digits[6][pos+4] = '+';
    }
    else if(segment == 5)
    {
        digits[3][pos] = '+';
        digits[4][pos] = '|';
        digits[5][pos] = '|';
        digits[6][pos] = '+';
    }
    else if(segment == 6)
    {
        digits[0][pos] = '+';
        digits[1][pos] = '|';
        digits[2][pos] = '|';
        digits[3][pos] = '+';
    }
    else
    {
        digits[3][pos] = '+';
        digits[3][pos+1] = '-';
        digits[3][pos+2] = '-';
        digits[3][pos+3] = '-';
        digits[3][pos+4] = '+';
    }

}

void insertDigit(int pos, char dig, vector<vector<char>>  &digits)
{
    if(dig == '0')
    {
        insertSegment(pos, 1, digits);
        insertSegment(pos, 2, digits);
        insertSegment(pos, 3, digits);
        insertSegment(pos, 4, digits);
        insertSegment(pos, 5, digits);
        insertSegment(pos, 6, digits);
    }
    else if(dig == '1')
    {
        insertSegment(pos, 2, digits);
        insertSegment(pos, 3, digits);

    }
    else if(dig == '2')
    {
        insertSegment(pos, 1, digits);
        insertSegment(pos, 2, digits);
        insertSegment(pos, 7, digits);
        insertSegment(pos, 5, digits);
        insertSegment(pos, 4, digits);

    }
    else if(dig == '3')
    {
        insertSegment(pos, 1, digits);
        insertSegment(pos, 2, digits);
        insertSegment(pos, 7, digits);
        insertSegment(pos, 3, digits);
        insertSegment(pos, 4, digits);

    }
    else if(dig == '4')
    {
        insertSegment(pos, 6, digits);
        insertSegment(pos, 2, digits);
        insertSegment(pos, 7, digits);
        insertSegment(pos, 3, digits);
    }
    else if(dig == '5')
    {
        insertSegment(pos, 1, digits);
        insertSegment(pos, 6, digits);
        insertSegment(pos, 7, digits);
        insertSegment(pos, 3, digits);
        insertSegment(pos, 4, digits);

    }
    else if(dig == '6')
    {
        insertSegment(pos, 1, digits);
        insertSegment(pos, 6, digits);
        insertSegment(pos, 7, digits);
        insertSegment(pos, 5, digits);
        insertSegment(pos, 3, digits);
        insertSegment(pos, 4, digits);

    }
    else if(dig == '7')
    {
        insertSegment(pos, 1, digits);
        insertSegment(pos, 2, digits);
        insertSegment(pos, 3, digits);

    }
    else if(dig == '8')
    {
        insertSegment(pos, 1, digits);
        insertSegment(pos, 2, digits);
        insertSegment(pos, 3, digits);
        insertSegment(pos, 4, digits);
        insertSegment(pos, 5, digits);
        insertSegment(pos, 6, digits);
        insertSegment(pos, 7, digits);
    }
    else
    {
        insertSegment(pos, 1, digits);
        insertSegment(pos, 6, digits);
        insertSegment(pos, 2, digits);
        insertSegment(pos, 7, digits);
        insertSegment(pos, 3, digits);
        insertSegment(pos, 4, digits);
    }
}