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
    return atan2l(one % two, one * two);
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

bool compare_by_angle (const Point<ll> a, const Point<ll> b) {
    if (a % b < 0) return true;
    if (a % b > 0) return false;
    return a.len() < b.len();
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

template<typename T>
ld point_line(Point<T> a, Point<T> b, Point<T> c) {
    return abs(((a - b) % (c - b)) / (c - b).len());
}

ld point_ray(Point<ll> a, Point<ll> b, Point<ll> c) {
    if ((c - b) * (a - b) >= 0)
        return point_line(a, b, c);
    else
        return (a - b).len();
}

ld point_segment(Point<ll> a, Point<ll> b, Point<ll> c) {
    if ((c - b) * (a - b) >= 0 && (b - c) * (a - c) >= 0)
        return point_line(a, b, c);
    else
        return min((a - b).len(), (a - c).len());
}

bool point_in_segment(Point<ll> a, Point<ll> b, Point<ll> c) {
    if ((c - b) % (a - b) == 0 && (a - b) * (a - c) <= 0)
        return true;
    return false;
}

bool segment_intersection(Point<ll> a1, Point<ll> a2, Point<ll> b1, Point<ll> b2) {
    Point<ll> a(a2 - a1), b(b2 - b1);
    if (a % b == 0) {
        if (a % (b1 - a1) != 0 || b % (a1 - b1) != 0)
            return false;
        if (second_in_first(a, (b1 - a1)) || second_in_first(a, (b2 - a1)) ||
            second_in_first(b, (a1 - b1)) || second_in_first(b, (a2 - b1)))
            return true;
        return false;
    }
    Point<ll> c(b1 - a1), d(b2 - a1);
    if ((a % c) * (a % d) > 0)
        return false;
    c = a1 - b1;
    d = a2 - b1;
    if ((b % c) * (b % d) > 0)
        return false;
    return true;
}

 
bool point_in_angle(Point <ll> a, Point<ll> o, Point<ll> b, Point <ll> p) {
    a = a - o;
    b = b - o;
    p = p - o;
    o = {0, 0};
    ll x, y;
    x = a % p;
    y = b % p;
    if (x == 0 && (p * (p - a) <= 0 || a * (a - p) <= 0)) return true;
    else if (y == 0 && (p * (p - b) <= 0 || b * (b - p) <= 0)) return true;
    else if (x * (a % b) > 0 && y * (b % a) > 0) return true;
    else return false;
}
