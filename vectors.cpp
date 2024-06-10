#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define ldcout cout << fixed << setprecision(12)
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

    // scolar product
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

template<typename T>
bool second_in_first(Point<T> const& one, Point<T> const& two) {
    return (two * (two - one) <= 1e-9);
}

Point<ll> main_line = {1, 1};


bool compare_by_main_line (const Point<ll> a, const Point<ll> b) {
    return (b - a) * main_line > 0;
}

bool compare_by_cords (const Point<ll> a, const Point<ll> b) {
    return pair(a.x, a.y) < pair(b.x, b.y);
}

Point<ld> find_intersection(ld a, ld b, ld c, ld a2, ld b2, ld c2) {
    ld y = (a * c2 - a2 * c) / (a2 * b - a * b2);
    ld x = (b * c2 - c * b2) / (a * b2 - b * a2);
    return {x, y};
}

Point<ld> find_intersection(tuple<ld, ld, ld> f, tuple<ld, ld, ld> s) {
    ld a, b, c, a2, b2, c2;
    tie(a, b, c) = f;
    tie(a2, b2, c2) = s;
    return find_intersection(a, b, c, a2, b2, c2);
}

template<typename T>
tuple <ld, ld, ld> line_from_points(Point<T> a1, Point<T> a2) {
    return tuple(a1.y - a2.y, a2.x - a1.x, -(a2.x - a1.x) * a1.y - (a1.y - a2.y) * a1.x);
}

bool everything_online(vector<Point<ll>> &arr) {
    if (arr.size() <= 1) return true;
    Point<ll> line(arr[1] - arr[0]);
    for (int i = 2; i < arr.size(); i++) {
        if (line % (arr[i] - arr[0]) != 0) return false;
    }
    return true;
}
