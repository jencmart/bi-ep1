#include <iostream>
#include <vector>

#include <stdlib.h>
#include <bitset>

using namespace std;


char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void commitRecursiveFill(vector<vector<bool>> &picture, string &s, int posX, int posY, int size) {
    if (s[0] == 'Q') {
        s.erase(0, 1);
        commitRecursiveFill(picture, s, posX, posY, size >>= 1);
        commitRecursiveFill(picture, s, posX + size, posY, size);
        commitRecursiveFill(picture, s, posX, posY + size, size);
        commitRecursiveFill(picture, s, posX + size, posY + size, size);
    } else {
        char c = s[0];
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                picture[posY + i][posX + j] = s[0] == 'B';
            }
        }

        s.erase(0, 1);
    }

}

int main() {
    int n;
    scanf("%d\n", &n);

    vector<vector<bool>> picture(n, vector<bool>(n, false));
    string s;
    getline(cin, s);
    commitRecursiveFill(picture, s, 0, 0, n);
    cout << "#define quadtree_width " << n << endl << "#define quadtree_height " << n << endl << "static char quadtree_bits() = {\n";
    for (int i = 0; i < n; i++) // radky
    {
        for (int j = 0; j <= n - 8; j += 8) //sloupecky po osmi
        {
            int val = 0;
            for (int k = 0; k < 8; ++k) {
                val = picture[i][j + k] ? val + (1 << k) : val;
            }
            int hi = val >> 4; // ok
            int lo = val & 15; // ok
            cout << "0x" << hexa[hi] << hexa[lo] << ',';
        }
        cout << endl;
    }
    cout << "};\n";
    return 0;
}