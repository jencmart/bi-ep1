#include <iostream>
#include <vector>

using namespace std;

struct Triangle {
    Triangle() : m_L(0), m_R(0), m_T(0), m_B(0), m_hole(true), m_pos('.') {}

    int m_L;
    int m_R;
    int m_T;
    int m_B;
    bool m_hole;
    char m_pos;

    const int minTop() { return std::min(m_T, std::min(m_L, m_R)); }

    const int minBottom() { return std::min(m_B, std::min(m_L, m_R)); }
};

int main() {
    int trianNum=0;
    while (++trianNum) {
        unsigned dim;
        scanf("%u\n", &dim);
        if (++dim == 1) break;
        vector<vector<Triangle>> TMatrix(dim + 1, vector<Triangle>((dim - 1) * 2 + 1)); // zarazka ze vsech 4 stran...

        ///scan data & count left, right and top direction
        for (int i = 1; i < dim; ++i) {
            for (int j = 1; j < (dim - 1) * 2 - i + 1; ++j) {
                char c; scanf("%c", &c);
                if (c == '-') {
                    TMatrix[i][j].m_hole = false;
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

            char c; scanf("%c", &c); // \n
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
        printf("\n");
        /// select biggest triangle
        for (int i = 1; i < dim; ++i) {
            for (int j = i; j < (dim - 1) * 2 - i + 1; ++j) {
                if (!TMatrix[i][j].m_hole) // only valid places
                {
                    int tmpArea = 0;
                    if(i % 2 == j % 2)
                        TMatrix[i][j].m_pos = 'V';
                    else
                        TMatrix[i][j].m_pos = '^';

                    int minBottom = TMatrix[i][j].minBottom(); // trojuhelnik spicka dole
                    int minTop = TMatrix[i][j].minTop();       // trojuhelnik spicka nahore

                    int Bstd = (minBottom+1)*(minBottom+1);
                    int Tstd = (minTop+1)*(minTop+1);
                    int Bsmaller = minBottom*minBottom;
                    int Tsmaller = minTop*minTop;

                    if( (TMatrix[i][j].m_pos == 'V') == (minTop%2 == 0) ) /// trojuhelnik spickou nahoru
                        tmpArea = Tsmaller > tmpArea ? Tsmaller : tmpArea;
                    else
                        tmpArea = Tstd > tmpArea ? Tstd : tmpArea;

                    if ( (TMatrix[i][j].m_pos == 'V') ==  (minBottom%2 == 0) ) /// trojuhlenik spickou dolu
                        tmpArea =  Bstd > tmpArea ? Bstd : tmpArea;
                    else
                        tmpArea = Bsmaller > tmpArea ? Bsmaller : tmpArea;


                    printf("%c(%d)-L%d,R%d,T%d,B%d ; ", TMatrix[i][j].m_pos, tmpArea, TMatrix[i][j].m_L, TMatrix[i][j].m_R, TMatrix[i][j].m_T, TMatrix[i][j].m_B );

                    area = tmpArea > area ? tmpArea : area;
                }
                else
                {
                    printf("# ; ");
                }
            }
            printf("\n");
        }
        printf("Triangle #%d\nThe largest triangle area is %d.\n\n", trianNum, area);
    }
    return 0;
}




/***
         if (TMatrix[i][j].m_pos == 'V') // trojuhelnicky pozice 'V'
        {
            if (minBottom % 2 == 0)
                area =  Bstd > area ? Bstd : area;
            else
                area = Bsmaller > area ? Bsmaller : area;

            if (minTop % 2 == 1)
                area = Tstd > area ? Tstd : area;       // position == 'V' && minTop%2 != 0
            else
                area = Tsmaller > area ? Tsmaller : area; // position == 'V' && minTop%2 == 0
        }
        else // trojuhelnicky tvaru '^'
        {
            if (minBottom % 2 == 1)
                area = Bstd > area ? Bstd : area;
            else
                area = Bsmaller > area ? Bsmaller : area;

            if (minTop % 2 == 0)
                area = Tstd > area ? Tstd : area;  // position != 'V' &&minTop%2 == 0
            else
                area = Tsmaller > area ? Tsmaller : area; // positon != 'V' && minTop%2 != 0
        }
 */
