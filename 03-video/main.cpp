#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
    Vertex(int y, int x) : m_y(y), m_x(x) {}
    const bool operator == ( const Vertex & a) {return a.m_x == m_x && a.m_y == m_y;}
    const bool operator != ( const Vertex & a) {return a.m_x != m_x || a.m_y != m_y;}
    int m_y, m_x;
};

bool isConcaveShape(Vertex &a, Vertex &b, Vertex &c, Vertex &d)
{
    if(a.m_y < b.m_y && b.m_x > c.m_x && c.m_y > d.m_y) /// -||-
        return true;
    if(a.m_y > b.m_y && b.m_x < c.m_x && c.m_y < d.m_y) /// -||-
        return true;
    if(a.m_x < b.m_x && b.m_y < c.m_y && c.m_x > d.m_x) /// =
        return true;
    if(a.m_x > b.m_x && b.m_y > c.m_y && c.m_x < d.m_x) /// =
        return true;

    return false;
}

bool containsConcaveShape(vector<Vertex> &inOrder)  /// for every four vertex try to find concave shape
{
    inOrder.push_back(inOrder[0]);
    inOrder.push_back(inOrder[1]);
    inOrder.push_back(inOrder[2]);

    for (int j = 0; j < inOrder.size() - 3; ++j)
        if (isConcaveShape(inOrder[j], inOrder[j + 1], inOrder[j + 2], inOrder[j+3]))
            return true;

    inOrder.pop_back();
    inOrder.pop_back();
    inOrder.pop_back();

    return false;
}



void swapElem(int & a, int &b) { int tmp = a; a = b; b=tmp; }
int giveNext(int curr , vector<Vertex> & inOrder) { return curr == inOrder.size() - 1 ? 0 : curr  +1; }

int givePrev(int curr , vector<Vertex> & inOrder) { return curr == 0 ? (int)inOrder.size()-1 : curr -1; }

bool swipeLeftToRight(vector<Vertex> & inOrder)
{
    /// najdi dva nejlevejsi a dva nejpravejsi body
    int maxLeftA = 0, maxLeftB = 0;
    int maxRightA = 0, maxRightB = 0;
    for(int i = 0 ; i < inOrder.size() ; ++i)
    {
        if( inOrder[i].m_x <  inOrder[maxLeftA].m_x )
            maxLeftA = maxLeftB = i;
        if ( inOrder[i].m_x ==  inOrder[maxLeftA].m_x && i != maxLeftA)
            maxLeftB = i;
        if(inOrder[i].m_x >  inOrder[maxRightA].m_x)
            maxRightA = maxRightB = i;
        if ( inOrder[i].m_x ==  inOrder[maxRightA].m_x && i != maxRightA)
            maxRightB = i;
    }

    ///srovnej tak aby A cka byly nad Bckama...
    if(inOrder[maxLeftA].m_y < inOrder[maxLeftB].m_y)
        swapElem(maxLeftA, maxLeftB);
    if(inOrder[maxRightA].m_y < inOrder[maxRightB].m_y)
        swapElem(maxRightA, maxRightB);

    ///zadej pocatecni interval
    int to = inOrder[maxLeftA].m_y;
    int from = inOrder[maxLeftB].m_y;

    while(true)
    {
        /// udelej prunik intervalu s novymi body todo... tady mozna boda kvuli bote niz
        to = inOrder[maxLeftA].m_y < to ? inOrder[maxLeftA].m_y : to;
        from = inOrder[maxLeftB].m_y > from ? inOrder[maxLeftB].m_y : from;

        if(from > to)
            return false;

        /// dosli jsme na konec a ok...
        if(maxLeftA == maxRightA && maxLeftB == maxRightB)
            return true;

        /// vyber jaky prvek posunes todo tady mozna bota ...


        // todo pozor nesmi hodit jinej nez posledni ! mam to zle
        int nextLeftA = maxLeftA == maxRightA ? maxLeftA :  giveNext(maxLeftA, inOrder);
        int nextLeftB = maxLeftB == maxRightB ? maxLeftB : givePrev(maxLeftB, inOrder);

        /// pokud je jeden mensi jak druhy vyuber ten
        if(inOrder[maxLeftA].m_x > inOrder[maxLeftB].m_x)
        {
            maxLeftB = nextLeftB;
        }
        else if(inOrder[maxLeftA].m_x < inOrder[maxLeftB].m_x)
        {
            maxLeftA = nextLeftA;
        }
        /// pokud jsou na stejne urovni, vyber ten ktery ma dalsi na stejne urovni; todo mam ( pokud oba - vol A ) vadi ? mam pocit ze ne. protoze pak budu zas vilit B a opacne
        else
        {
            if(inOrder[nextLeftA].m_x == inOrder[maxLeftA].m_x)
                maxLeftA = nextLeftA;

            else if(inOrder[nextLeftB].m_x == inOrder[maxLeftB].m_x)
                maxLeftB = nextLeftB;
            else
                maxLeftA = nextLeftA;
        }

    }
}

int main() {

    int floorCnt = 0;
    while (true)
    {
        floorCnt++; int vCnt; scanf("%d", &vCnt); if (vCnt == 0) break;
        printf("Floor #%d\n", floorCnt);
        vector<Vertex> inOrder;

        /// scan
        for (int i = 0; i < vCnt; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            inOrder.emplace_back(Vertex(y, x));
        }

        if (containsConcaveShape(inOrder)) { printf("Surveillance is impossible.\n\n"); continue; }

        vector<Vertex> inOrderRotated;
        for(auto & elem : inOrder)
            inOrderRotated.emplace_back(Vertex(elem.m_x, elem.m_y * -1));

        if(swipeLeftToRight(inOrder) && swipeLeftToRight(inOrderRotated))
            printf("Surveillance is possible.\n\n");
        else
            printf("Surveillance is impossible.\n\n");
    }
    return 0;
}

/**
 // possible
8
0 0
0 2
1 2
1 6
3 6
3 3
4 3
4 0


12
-1 -4
-3 -4
-3 -3
-1 -3
-1 -2
1 -2
1 -4
2 -4
2 -5
1 -5
1 -6
-1 -6

 ///impossible
10
0 11
1 11
1 10
10 10
10 6
2 6
2 8
-1 8
-1 10
0 10


 */
