#include <bits/stdc++.h>
using namespace std;

struct POINT{
    double x, y;
};

void inp(POINT &);
void out(POINT &);
double dist(const POINT &, const POINT &);

int main(){
    POINT p, q;
    cout << "Nhap diem thu nhat: \n";
    inp(p);
    cout << "Nhap diem thu hai: \n";
    inp(q);
    double res = dist(p, q);
    out(p);
    out(q);
    cout << "Khoang cach giua hai diem = " << res;
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

double dist(const POINT &p, const POINT &q){
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

