#include <iostream>
#include <vector>

enum content {EMPTY, WHITE, BLACK};

struct ChessPosition
{
    ChessPosition() : m_contains(EMPTY), m_c('0') {};
    content m_contains;
    char m_c;
};

void scanIt(std::vector<ChessPosition> &);
void printIt(std::vector<ChessPosition> &);

int main()
{
    std::vector<ChessPosition> chessBoard(64);
    scanIt(chessBoard);
    printIt(chessBoard);
    return 0;
}

void scanIt(std::vector<ChessPosition> &chessBoard)
{
    char type, charPos, intPos;
    /// SCAN WHITES
    scanf("White:%c", &type);
    for(;;)
    {
        scanf("%c", &type );

        if(type == '\n')
            break;

        if(type > 'Z') //scan pawns..
        {
            scanf("%c", &intPos );
            charPos = type;
            type = 'P';
        }
        else
            scanf("%c%c", &charPos, &intPos );

        int intCharPos = charPos - 'a';
        int intIntPos = intPos - '1';
        chessBoard[(7-intIntPos)*8 + intCharPos ].m_contains = WHITE;
        chessBoard[(7-intIntPos)*8 + intCharPos ].m_c = type;

        scanf("%c", &type);
        if(  type != ',' )
            break;
    }

    /// SCAN BLACKS
    scanf("Black:%c", &type);
    for(;;)
    {
        scanf("%c", &type );

        if(type == '\n')
            break;

        if(type > 'Z') //scna pawns..
        {
            scanf("%c", &intPos );
            charPos = type;
            type = 'P';
        }
        else
            scanf("%c%c", &charPos, &intPos );

        int intCharPos = charPos - 'a';
        int intIntPos = intPos - '1';
        chessBoard[(7-intIntPos)*8 + intCharPos ].m_contains = BLACK;
        chessBoard[(7-intIntPos)*8 + intCharPos ].m_c = (char)tolower(type);

        scanf("%c", &type);
        if(  type != ',' )
            break;
    }
}

void printIt(std::vector<ChessPosition> &chessBoard)
{
    bool sud = false;
    for(int i = 0; i < chessBoard.size() ; ++i)
    {
        if(  i%8 == 0)
        {
            if(i == 0)
                printf("+---+---+---+---+---+---+---+---+\n|");
            else
                printf("\n+---+---+---+---+---+---+---+---+\n|");
            sud = !sud;
        }

        if(chessBoard[i].m_contains != EMPTY)
        {
            if( (i%2 == 0 && sud ) || (! sud && i%2 != 0) )
            {
                printf(".%c.|", chessBoard[i].m_c);
            }
            else
            {
                printf(":%c:|", chessBoard[i].m_c);
            }
        }
        else
        {
            if( (i%2 == 0 && sud ) || (! sud && i%2 != 0) )
                printf("...|");
            else
                printf(":::|");
        }
    }

    printf("\n+---+---+---+---+---+---+---+---+\n");
}
