#include <iostream>
#include <vector>

using namespace std;
struct Point
{
    int m_x, m_y;
    bool m_left;
    bool m_right;
    Point(int x, int y) : m_x(x), m_y(y), m_left(false), m_right(false) {};
};


void computeArea(int startPointPos, vector<Point> & points)
{
    int areaSpace = 0 ;

    for(int i = startPointPos+1 ; i <  points.size() ; ++i)
    {
        if(points[i].m_x == points[i-1].m_x)
            continue;
        else if(points[i].m_x > points[i-1].m_x)
            areaSpace += points[i].m_y;
        else
            areaSpace -= points[i].m_y;
    }

    for(int i = 1 ; i <=  startPointPos ; ++i)
    {
        if(points[i].m_x == points[i-1].m_x)
            continue;
        else if(points[i].m_x > points[i-1].m_x)
            areaSpace += points[i].m_y;
        else
            areaSpace -= points[i].m_y;
    }


    if(areaSpace < 0)
        areaSpace += -2*areaSpace;
    printf("The area is %d squares.\n", areaSpace);
}

int main() {
    unsigned testCases; scanf("%u", &testCases);
    for (int i = 0; i < testCases; ++i)
    {
        int x, y; scanf("%d%d\n", &x, &y);
        std::vector<Point> points;
        points.emplace_back(Point(x,y));
        char  c;
        int startPointPos=0;
        int lastPoint=0;
        while(true)
        {
            scanf("%c", &c);
            if(c =='E')
                points.emplace_back(Point(points[lastPoint].m_x+1, points[lastPoint].m_y));
            else if(c =='W')
                points.emplace_back(Point(points[lastPoint].m_x-1, points[lastPoint].m_y));
            else if(c =='N')
                points.emplace_back(Point(points[lastPoint].m_x, points[lastPoint].m_y+1));
            else if(c =='S')
                points.emplace_back(Point(points[lastPoint].m_x, points[lastPoint].m_y-1));
            else // dot ...
                break;

            lastPoint++;
            if(points[lastPoint].m_x < points[startPointPos].m_x ||
                    (points[lastPoint].m_x == points[startPointPos].m_x &&
                     points[lastPoint].m_y > points[startPointPos].m_y
                    )
               )
                startPointPos = lastPoint;
        }
        computeArea(startPointPos, points);
        ///scan newline char...
        scanf("%c", &c);
    }
    return 0;
}