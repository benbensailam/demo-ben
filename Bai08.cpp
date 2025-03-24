#include <bits/stdc++.h>
using namespace std;

struct POINT{
    double x, y;
};

struct TRIANGLE{
    POINT a, b, c;
};

void inp(POINT &);
void inp(TRIANGLE &);
void out(POINT &);
void out(TRIANGLE &);
double dist(const POINT &, const POINT &);
double perimeter(const TRIANGLE &);
double area(const TRIANGLE &);
POINT centroid(const TRIANGLE &);

int main(){
    TRIANGLE t;
    POINT c;
    cout << "Nhap tam giac: \n";
    inp(t);
    out(t);
    cout << "Chu vi = " << perimeter(t) << "\n";
    cout << "Dien tich = " << area(t) << "\n";
    cout << "Toa do trong tam tam giac la: ";
    out(c = centroid(t));
}

void inp(POINT &p){
    cout << "Nhap x: ";
    cin >> p.x;
    cout << "Nhap y: ";
    cin >> p.y;
}

void out(POINT &p){
    cout << "(" << p.x << ", " << p.y << ")\n";
}

void inp(TRIANGLE &t){
    cout << "Nhap diem A: \n";
    inp(t.a);
    cout << "Nhap diem B: \n";
    inp(t.b);
    cout << "Nhap diem C: \n";
    inp(t.c);
}

void out(TRIANGLE &t){
    cout << "Diem A: ";
    out(t.a);
    cout << "Diem B: ";
    out(t.b);
    cout << "Diem C: ";
    out(t.c);
}

double dist(const POINT &p, const POINT &q){
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

double perimeter(const TRIANGLE &t){
    return dist(t.a, t.b) + dist(t.b, t.c) + dist(t.c, t.a);
}

double area(const TRIANGLE &t){
    double halfP = perimeter(t) / double(2);
    return sqrt(halfP * (halfP - dist(t.a, t.b)) * (halfP - dist(t.b, t.c)) * (halfP - dist(t.c, t.a)));
}

POINT centroid(const TRIANGLE &t){
    POINT res;
    res.x = (t.a.x + t.b.x + t.c.x) / double(3);
    res.y = (t.a.y + t.b.y + t.c.y) / double(3);
    return res;
}
