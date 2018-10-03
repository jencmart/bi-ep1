#include <iostream>
#include <cfloat>
#include <math.h>
struct Paralell
{

};
struct Coords {
    Coords(long long xx, long long yy) : x(xx), y(yy), xdbl(xx), ydbl(yy) {}
    long long x, y;
    double xdbl, ydbl;
};

struct TwoCoords
{
    long long aX, aY, bX, bY;
    TwoCoords(long long axx,long long ayy, long long bxx,long long byy) : aX(axx), aY(ayy), bX(bxx), bY(byy) {}
};



TwoCoords getBoundingBox(Coords a, Coords b)
{
    if(a.x > b.x)
    {
        Coords tmp = b;
        b.x = a.x;
        b.y = a.y;
        a.x = tmp.x;
        a.y = tmp.y;
    }

    if(a.y > b.y)
        return TwoCoords(a.x, a.y, b.x, b.y);
    else
        return TwoCoords(a.x, b.y, b.x, a.y);
}


bool boundingBoxesIntersect(TwoCoords a, TwoCoords b)
{
    return b.aY >= a.bY &&
           a.aY >= b.bY &&
           a.aX >= b.bX &&
           b.aX >= a.bX;
}

long long crossProduct(Coords a, Coords b) { return a.x * b.y - b.x * a.y; }
bool onLine(Coords p1, Coords p2, Coords b) { return 0 == crossProduct(Coords(p2.x - p1.x, p2.y - p1.y), Coords(b.x - p1.x, b.y - p1.y)); }
bool rightSide(Coords p1, Coords p2, Coords b) { return 0 > crossProduct(Coords(p2.x - p1.x, p2.y - p1.y), Coords(b.x - p1.x, b.y - p1.y)); }
bool inside(Coords p1, Coords r1, Coords r2, Coords r3, Coords r4) {
    return p1.x >= r1.x && p1.x <= r2.x && p1.y >= r1.y && p1.y <= r4.y;
}


//p segmet, r line
bool lineIntersects(Coords p1, Coords p2, Coords r1, Coords r2)
{
    return onLine(p1, p2, r1)
           || onLine(p1, p2, r2)
           || (rightSide(p1, p2, r1) &&  !rightSide(p1, p2, r2)
           || (!rightSide(p1, p2, r1) && rightSide(p1, p2, r2)));
}

bool intersect(Coords p1, Coords p2, Coords r1, Coords r2) {
    TwoCoords bound1 = getBoundingBox(p1,p2);
    TwoCoords bound2 = getBoundingBox(r1,r2);

    return boundingBoxesIntersect(bound1, bound2) && lineIntersects(p1, p2, r1, r2) &&
            lineIntersects(r1, r2, p1, p2);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2, xx4, yy4, xx2, yy2;
        scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &xx4, &yy4, &xx2, &yy2);
        Coords p1(x1, y1), p2(x2, y2);
        Coords r1(xx4, yy2), r2(xx2, yy2), r3(xx2, yy4), r4(xx4, yy4);

        if (inside(p1, r1, r2, r3, r4) || inside(p2, r1, r2, r3, r4))
        {
            printf("T\n");
            continue;
        }

        if (intersect(p1,p2, r1,r2) ||
            intersect(p1,p2, r2,r3) ||
            intersect(p1,p2, r3,r4) ||
            intersect(p1,p2, r4,r1))
            printf("T\n");
        else
            printf("F\n");
    }
    return 0;
}