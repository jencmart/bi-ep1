#include <iostream>
#include <vector>

using namespace std;

struct Triangle {
    Triangle() : m_L(0), m_R(0), m_T(0), m_B(0), m_hole(true) {}

    int m_L;
    int m_R;
    int m_T;
    int m_B;
    bool m_hole;

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

        /// select biggest triangle
        for (int i = 1; i < dim; ++i) {
            for (int j = i; j < (dim - 1) * 2 - i + 1; ++j) {
                if (!TMatrix[i][j].m_hole) // only valid places
                {
                    int minBottom = TMatrix[i][j].minBottom(); // trojuhelnik spicka dole
                    int minTop = TMatrix[i][j].minTop();       // trojuhelnik spicka nahore

                    if (i % 2 == j % 2) // trojuhelnicky pozice 'V'
                    {
                        if (minBottom % 2 == 0)
                            area = (minBottom+1)*(minBottom+1) > area ? (minBottom+1)*(minBottom+1) : area;
                        else
                            area = (minBottom)*(minBottom) > area ? (minBottom)*(minBottom) : area;
                        if (minTop % 2 == 1)
                            area = (minTop+1)*(minTop+1) > area ? (minTop+1)*(minTop+1) : area;
                        else
                            area = (minTop)*(minTop) > area ? (minTop)*(minTop) : area;
                    }
                    else // trojuhelnicky tvaru '^'
                    {
                        if (minBottom % 2 == 1)
                            area = (minBottom+1)*(minBottom+1) > area ? (minBottom+1)*(minBottom+1) : area;
                        else
                            area = (minBottom)*(minBottom) > area ? (minBottom)*(minBottom) : area;
                        if (minTop % 2 == 0)
                            area = (minTop+1)*(minTop+1) > area ? (minTop+1)*(minTop+1) : area;
                        else
                            area = (minTop)*(minTop) > area ? (minTop)*(minTop) : area;
                    }
                }
            }
        }
        printf("Triangle #%d\nThe largest triangle area is %d.\n\n", trianNum, area);
    }
    return 0;
}

