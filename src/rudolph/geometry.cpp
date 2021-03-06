#include "geometry.h"

#include <cmath>

using rudolph::geometry::Point2D;

namespace rudolph {

void Point2D::translate(int dx, int dy) {
    Matrix<int> t(3, 3);
    t(0, 0) = 1;
    t(1, 1) = 1;
    t(2, 0) = dx;
    t(2, 1) = dy;
    t(2, 2) = 1;

    data = data * t;
}

void Point2D::scale(int sx, int sy) {
    Matrix<int> t(3, 3);
    t(0, 0) = sx;
    t(1, 1) = sy;
    t(2, 2) = 1;

    data = data * t;
}

void Point2D::rotate(double angle) {
    const double pi = std::acos(-1);

    Matrix<int> t(3, 3);
    t(0, 0) = std::cos(angle*pi/180);
    t(0, 1) = -std::sin(angle*pi/180);
    t(1, 0) = std::sin(angle*pi/180);
    t(1, 1) = std::cos(angle*pi/180);
    t(2, 2) = 1;

    data = data * t;
}

Point2D& Point2D::operator+=(const Point2D& p) {
    x() += p.x();
    y() += p.y();
    return *this;
}

Point2D& Point2D::operator-=(const Point2D& p) {
    return *this += -p;
}

Point2D geometry::operator-(const Point2D& p) {
    return Point2D{-p.x(), -p.y()};
}

Point2D geometry::operator+(const Point2D& lhs, const Point2D& rhs) {
    return Point2D{rhs.x() + lhs.x(), rhs.y() + lhs.y()};
}

Point2D geometry::operator-(const Point2D& lhs, const Point2D& rhs) {
    return lhs + (-rhs);
}

Point2D geometry::operator*(const Point2D& p, int value) {
    return Point2D{p.x() * value, p.y() * value};
}

Point2D geometry::operator*(const Point2D& p, double value) {
    return Point2D{int(p.x() * value), int(p.y() * value)};
}

Point2D geometry::operator*(int value, const Point2D& p) {
    return Point2D{p.x() * value, p.y() * value};
}

Point2D geometry::operator*(double value, const Point2D& p) {
    return Point2D{int(p.x() * value), int(p.y() * value)};
}

}
