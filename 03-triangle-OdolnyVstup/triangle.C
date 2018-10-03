#include <iostream>
#include <vector>

using namespace std;


int mensi(int a, int b) {
    return a < b ? a : b;
}

int vetsi(int a, int b) {
    return a > b ? a : b;
}

enum typ {
    upstrait, downstrait
};
struct Triangle {
    Triangle() : m_L(0), m_R(0), m_T(0), m_B(0), m_hole(true), m_typ(upstrait), m_row(0), m_col(0) {}

    int m_L;
    int m_R;
    int m_T;
    int m_B;
    bool m_hole;
    typ m_typ;

    int m_row;
    int m_col;

    const int minTop() {
        int minT = mensi(m_T, mensi(m_L, m_R));
        if ((m_typ == downstrait && minT % 2 == 0) || (m_typ == upstrait && minT % 2 == 1))
            minT = 0 > minT - 1 ? 0 : minT - 1;
        return minT;
    }

    const int minBottom() {
        int minB = mensi(m_B, mensi(m_L, m_R));
        if ((m_typ == upstrait && minB % 2 == 0) || (m_typ == downstrait && minB % 2 == 1))
            minB = 0 > minB - 1 ? 0 : minB - 1;
        return minB;
    }


    ///******************************* SPICKA SMEREM NAHORU *********************
    const int maxFacingUp(vector<vector<Triangle>> & matice) // triangle facing up
    {
        int minT = minTop();

        for (int i = minT; i > 0  ; --i)
        {
            int closerProblem = mensi(matice[m_row - i][m_col].m_L, matice[m_row - i][m_col].m_R);

            if(closerProblem < minT - i)
                if( (m_row - i) % 2 != (m_col + closerProblem)%2) // na ^ ok na V posun
                    minT = i + closerProblem;
                else
                    minT = i + closerProblem  -1;
        }

        return (minT +1 ) * ( minT + 1 );
    }

    ///************************** SPICKA SMEREM DOLU*********************
    const int maxFacingDown(vector<vector<Triangle>> & matice) // triangle facing down
    {
        int minB = minBottom();

        for (int i = minB; i > 0  ; --i)
        {
            int closerProblem = mensi( matice[m_row + i][m_col].m_L , matice[m_row + i][m_col].m_R); //ok

            if(closerProblem < minB - i)  // ok
                if( (m_row + i) % 2 != (m_col + closerProblem)%2) // na V ok na ^ posun
                    minB = i + closerProblem - 1  ;
                else
                    minB = i + closerProblem ;
        }

        return (minB +1 ) * ( minB + 1 );
    }

    const int giveMax(vector<vector<Triangle>> & matice ) { return vetsi( maxFacingUp(matice), maxFacingDown(matice)); }
};

int main() {
    int trianNum = 0;
    while (++trianNum) {
        unsigned dim;
        scanf("%u\n", &dim);
        if (++dim == 1) break;
        vector<vector<Triangle>> TMatrix(dim + 1, vector<Triangle>((dim - 1) * 2 + 1)); // zarazka ze vsech 4 stran...

        ///scan data & count left, right and top direction
        for (int i = 1; i < dim; ++i) {

            char c;
            while (true) // preskoc jakekoli smeti na radce ale v pripade ze narazis na znak, urzd ho a nezahod
            {
                scanf("%c", &c);
                if (c == '#' || c == '-') break;
            }

            for (int j = i; j < (dim - 1) * 2 - i + 1; ++j) {
                if (j != i)
                    scanf("%c", &c);

                if (c != '#' && c != '-') break;

                if (c == '-') {
                    TMatrix[i][j].m_hole = false;
                    TMatrix[i][j].m_typ = (i % 2 == j % 2) ? downstrait : upstrait;
                    TMatrix[i][j].m_row = i;
                    TMatrix[i][j].m_col = j;
                    if (!TMatrix[i][j - 1].m_hole)
                        TMatrix[i][j].m_L = TMatrix[i][j - 1].m_L + 1;
                    if (!TMatrix[i - 1][j].m_hole)
                        TMatrix[i][j].m_T = TMatrix[i - 1][j].m_T + 1;
                }
            }

            ///traverse line left (count right direction)
            for (int k = (dim - 1) * 2 - i + 1 - 1; k > i - 1; --k) {
                if (!TMatrix[i][k].m_hole && !TMatrix[i][k + 1].m_hole)
                    TMatrix[i][k].m_R = TMatrix[i][k + 1].m_R + 1;
            }
        }

        /// traverse bottom-top, left-right and count the remaining (down) direction
        for (int j = 1; j < (dim - 1) * 2; ++j) {
            int i = j;
            if (j > dim - 1) i = 2 * dim - 2 - j;
            for (; i > 0; --i)
                if (!TMatrix[i][j].m_hole && !TMatrix[i + 1][j].m_hole)
                    TMatrix[i][j].m_B = TMatrix[i + 1][j].m_B + 1;
        }

        int area = 0;

        for(auto & row : TMatrix)
            for(auto & elem : row)
                if(!elem.m_hole)
                {
                    if((elem.minBottom()+1)*(elem.minBottom()+1) > area || (elem.minTop()+1)*(elem.minTop()+1)) // small optimalization
                    {
                        int newMax = elem.giveMax(TMatrix);
                        area = area > newMax ? area : newMax;
                    }
                }

        printf("Triangle #%d\nThe largest triangle area is %d.\n\n", trianNum, area);
    }
    return 0;
}


/***
4
#--##--
 ---##
  ##-
   -
5
#-------#
 -------
  ##-##
   #-#
    -
8
---------------
 #####--------
  -----------
   ---------
    ---#---
     --#--
      -#-
       #


   ***/
