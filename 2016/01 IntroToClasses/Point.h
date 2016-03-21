#ifndef POINT
#define POINT

class Point {
private:
    int m_x, m_y;
public:
    Point();
    Point(int x, int y);
    void SetX(int x);
    int GetX();
    void SetY(int y);
    int GetY();
    void Set(int x, int y);
    void Print();
    double GetDistanceTo(Point B);
    //Point& operator= (const Point &A);
};

#endif // POINT
