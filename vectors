#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld PI = acos(-1.0);


template<typename T>
struct Point {
    T x, y;
    Point() : x(0), y(0) {}
    Point(T _x, T _y) : x(_x), y(_y) {}

    Point operator+(Point const& other) const {
        return {x + other.x, y + other.y};
    }

    Point operator-(Point const& other) const {
        return {x - other.x, y - other.y};
    }

    // scalar product
    T operator*(Point const& other) const{
        return x * other.x + y * other.y;
    }
    
    // vector product
    T operator%(Point const& other) const{
        return x * other.y - y * other.x;
    }

    bool operator==(Point const& other) const{
        return x == other.x && y == other.y;
    }

    bool operator!=(Point const& other) const{
        return !(*this == other);
    }

    T lenSqr() const {
        return x * x + y * y;
    }

    ld len() const {
        return sqrt(lenSqr());
    }

    Point ort() const {
        return {-y, x};
    }

};

template<typename T>
istream& operator>>(istream& in, Point<T>  & x) {
    in >> x.x >> x.y;
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, Point<T> const& x) {
    out << x.x << ' ' << x.y;
    return out;
}

template<typename T>
ld angle(Point<T> const& one, Point<T> const& two) {
    return atan2(one % two, one * two);
}
