#include<iostream>
#include<cmath>

#define PI 3.14159265359

using namespace std;

class Point {
private:
    int m_x, m_y;
public:
    Point() {
        m_x = 0;
        m_y = 0;
    }
    Point(int x, int y) {
        m_x = x;
        m_y = y;
    }
    void SetX(int x) {
        m_x = x;
    }
    int GetX() {
        return m_x;
    }
    void SetY(int y) {
        m_y = y;
    }
    int GetY() {
        return m_y;
    }
    void Set(int x, int y) {
        m_x = x;
        m_y = y;
    }
    void Print() {
        cout<<"( "<<m_x<<", "<<m_y<<" )"<<endl;
    }
    double GetDistanceTo(Point B) {
        return sqrt((m_x - B.m_x) * (m_x - B.m_x) + (m_y - B.m_y) * (m_y - B.m_y));
    }
};

class Circle {
private:
    Point m_O;
    int m_r;
public:
    Circle() {
        m_r = 0;
    }
    Circle(Point A) {
        //m_O = A; this is allowed
        int x = A.GetX(), y = A.GetY();
        m_O.Set(x,y);
        m_r = 0;
    }
    Circle(int x, int y) {
        m_O.Set(x,y);
        m_r = 0;
    }
    Circle(Point A, int r) {
        //m_O = A; is allowed too
        int x = A.GetX(), y = A.GetY();
        m_O.Set(x,y);
        m_r = r;
    }
    Circle(int x, int y, int r) {
        m_O.Set(x,y);
        m_r = r;
    }
    void SetO(Point A) {
        //m_O = A; is allowed too
        int x = A.GetX(), y = A.GetY();
        m_O.Set(x,y);
    }
    Point GetO() {
        return m_O;
    }
    void SetR(int r) {
        m_r = r;
    }
    int GetR() {
        return m_r;
    }
    double Area() {
        return PI * m_r * m_r;
    }
    double Perimeter() {
        return 2 * PI * m_r;
    }
};

class Triangle {
private:
    Point m_A, m_B, m_C;
public:
    Triangle() {}
    Triangle(Point A, Point B, Point C) {
        m_A = A;
        m_B = B;
        m_C = C;
    }
    double Perimeter() {
        return m_A.GetDistanceTo(m_B) + m_A.GetDistanceTo(m_C) + m_B.GetDistanceTo(m_C);
    }
    double Area() {
        double p = this->Perimeter();
        int a = m_A.GetDistanceTo(m_B), b = m_A.GetDistanceTo(m_C), c = m_B.GetDistanceTo(m_C);
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

int main() {
    return 0;
}
