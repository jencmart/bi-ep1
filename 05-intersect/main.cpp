#include <iostream>
#include <cfloat>
#include <math.h>
struct Paralell
{

};
struct Coords {
    Coords(int xx, int yy) : x(xx), y(yy), xdbl(xx), ydbl(yy) {}
    int x, y;
    double xdbl, ydbl;
};

struct DblCoords
{
    DblCoords(double xx, double yy) : x(xx), y(yy) {}
    double x,y;
};

bool inside(Coords &p1, Coords &r1, Coords &r2, Coords &r3, Coords &r4) {
    return p1.x >= r1.x && p1.x <= r2.x && p1.y >= r1.y && p1.y <= r4.y;
}

bool nearEqv(double a, double b) { return (fabs(a - b) < 0.001); }

bool nearlyEqual(DblCoords a, Coords b) { return (nearEqv(a.x, b.xdbl) && nearEqv(a.y, b.ydbl) ); }

DblCoords intersection(Coords A, Coords B, Coords C, Coords D)
{
    double a1 = B.y - A.y;
    double b1 = A.x - B.x;
    double c1 = a1*(A.x) + b1*(A.y);

    double a2 = D.y - C.y;
    double b2 = C.x - D.x;
    double c2 = a2*(C.x)+ b2*(C.y);

    double det = a1*b2 - a2*b1;

    if (nearEqv(det, 0))
      throw Paralell();

    else
    {
        double x = (b2*c1 - b1*c2)/det;
        double y = (a1*c2 - a2*c1)/det;
        return DblCoords(x, y);
    }
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

        try {
            DblCoords a = intersection(p1,p2,r1,r2);

            if( nearlyEqual(a,r1) || nearlyEqual(a,r2) || (r1.x < a.x && r2.x > a.x )  )
            {
                printf("T\n");
                continue;
            }
        } catch( Paralell x) {}


        try {
            DblCoords a = intersection(p1,p2,r2,r3);
            if( nearlyEqual(a,r2) || nearlyEqual(a,r3) || (r3.y > a.y && r2.y < a.y )  )
            {
                printf("T\n");
                continue;
            }
        } catch( Paralell x) {}

        try {
            DblCoords a = intersection(p1,p2,r3,r4);
            if( nearlyEqual(a,r3) || nearlyEqual(a,r4) || (r4.x < a.x && r3.x > a.x )  )
            {
                printf("T\n");
                continue;
            }

        } catch( Paralell x) {}

        try {
            DblCoords a = intersection(p1,p2,r4,r1);
            if( nearlyEqual(a,r4) || nearlyEqual(a,r1) || (r4.y > a.y && r1.y < a.y )  )
            {
                printf("T\n");
                continue;
            }
        } catch( Paralell x) {}

        printf("F\n");
    }
    return 0;
}