#include<iostream>
#include<cmath>
#include "Point.h"
    Point::Point() {
        //std::cout<<"Create"<<std::endl;
        m_x = 0;
        m_y = 0;
    }
    Point::Point(int x, int y) {
        m_x = x;
        m_y = y;
    }
    void Point::SetX(int x) {
        m_x = x;
    }
    int Point::GetX() {
        return m_x;
    }
    void Point::SetY(int y) {
        m_y = y;
    }
    int Point::GetY() {
        return m_y;
    }
    void Point::Set(int x, int y) {
        m_x = x;
        m_y = y;
    }
    void Point::Print() {
        std::cout<<"( "<<m_x<<", "<<m_y<<" )"<<std::endl;
    }
    double Point::GetDistanceTo(Point B) {
        return std::sqrt((m_x - B.m_x) * (m_x - B.m_x) + (m_y - B.m_y) * (m_y - B.m_y));
    }
    /*Point& Point::operator= (const Point &A) {
        std::cout<<"Assign"<<std::endl;
        this->m_x = A.m_x;
        this->m_y = A.m_y;
        return *this;
    }*/
