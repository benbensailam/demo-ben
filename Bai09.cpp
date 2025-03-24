#include <bits/stdc++.h>
using namespace std;

struct POINT{
    double x, y;
};

struct CIRCLE{
    POINT o;
    double r;
};

void inp(POINT &);
void out(POINT &);
void inp(CIRCLE &);
void out(CIRCLE &);
double perimeter(const CIRCLE &);
double area(const CIRCLE &);

int main(){
    CIRCLE c;
    inp(c);
    out(c);
    double p = perimeter(c);
    double a = area(c);
    cout << "Chu vi = " << p << "\n";
    cout << "Dien tich = " << a << "\n";
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

void inp(CIRCLE &c){
    cout << "Nhap tam O: \n";
    inp(c.o);
    cout << "Nhap ban kinh R: \n";
    cin >> c.r;
}

void out(CIRCLE &c){
    cout << "Tam O: ";
    out(c.o);
    cout << "Ban kinh R: " << c.r << "\n";
}

double perimeter(const CIRCLE &c){
    return 2 * 3.14 * c.r;
}

double area(const CIRCLE &c){
    return 3.14 * c.r * c.r;
}
