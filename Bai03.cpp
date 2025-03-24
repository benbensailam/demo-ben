#include <bits/stdc++.h>
using namespace std;

struct FRACTION{
    int numerator, denominator;
};

void inp(FRACTION &);
void out(FRACTION &);
int check(const FRACTION &);
FRACTION greatestFraction(const FRACTION &, const FRACTION &);

int main(){
    FRACTION x, y;
    cout << "Nhap phan so thu nhat: \n";
    inp(x);
    cout << "Nhap phan so thu hai: \n";
    inp(y);
    out(x);
    out(y);
    FRACTION res = greatestFraction(x, y);
    cout << "Phan so lon nhat la: ";
    out(res);
}

void inp(FRACTION &x){
    cout << "Nhap tu so: ";
    cin >> x.numerator;
    cout << "Nhap mau so: ";
    cin >> x.denominator;
}

void out(FRACTION &x){
    cout << x.numerator << " " << x.denominator << "\n";
}

int check(const FRACTION &x){
    if(x.numerator * x.denominator > 0) return 1;
    else if(x.numerator * x.denominator < 0) return -1;
    else return 0;
}

FRACTION subtraction(const FRACTION &x, const FRACTION &y){
    FRACTION res;
    res.numerator = x.numerator * y.denominator - y.numerator * x.denominator;
    res.denominator = x.denominator * y.denominator;
    return res;
}

FRACTION greatestFraction(const FRACTION &x, const FRACTION &y){
    FRACTION res = subtraction(x, y);
    if(check(res) == 1) return x;
    else return y;
}

