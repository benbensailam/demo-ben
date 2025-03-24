#include <bits/stdc++.h>
using namespace std;

struct FRACTION{
    int numerator, denominator;
};

void inp(FRACTION &);
void out(FRACTION &);
void simplify(FRACTION &);
FRACTION addition(const FRACTION &, const FRACTION &);
FRACTION subtraction(const FRACTION &, const FRACTION &);
FRACTION multiplication(const FRACTION &, const FRACTION &);
FRACTION division(const FRACTION &, const FRACTION &);

int main(){
    FRACTION x, y, res;
    cout << "Nhap phan so thu nhat: \n";
    inp(x);
    cout << "Nhap phan so thu hai: \n";
    inp(y);
    out(x);
    out(y);
    cout << "Tong = ";
    out(res = addition(x, y));
    cout << "Hieu = ";
    out(res = subtraction(x, y));
    cout << "Tich = ";
    out(res = multiplication(x, y));
    cout << "Thuong = ";
    out(res = division(x, y));
}

void inp(FRACTION &x){
    cout << "Nhap tu so: ";
    cin >> x.numerator;
    cout << "Nhap mau so: ";
    cin >> x.denominator;
}

void out(FRACTION &x){
    cout << x.numerator << " " << x.denominator <<  "\n";
}

int gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a % b);
}

void simplify(FRACTION &x){
    int GCD = gcd(x.numerator, x.denominator);
    x.numerator /= GCD;
    x.denominator /= GCD;
    if(x.denominator < 0){
        x.numerator = - x.numerator;
        x.denominator = - x.denominator;
    }
}

FRACTION addition(const FRACTION &x, const FRACTION &y){
    FRACTION res;
    res.numerator = x.numerator * y.denominator + y.numerator * x.denominator;
    res.denominator = x.denominator * y.denominator;
    simplify(res);
    return res;
}

FRACTION subtraction(const FRACTION &x, const FRACTION &y){
    FRACTION res;
    res.numerator = x.numerator * y.denominator - y.numerator * x.denominator;
    res.denominator = x.denominator * y.denominator;
    simplify(res);
    return res;
}

FRACTION multiplication(const FRACTION &x, const FRACTION &y){
    FRACTION res;
    res.numerator = x.numerator * y.numerator;
    res.denominator = x.denominator * y.denominator;
    simplify(res);
    return res;
}

FRACTION division(const FRACTION &x, const FRACTION &y){
    FRACTION res;
    res.numerator = x.numerator * y.denominator;
    res.denominator = x.denominator * y.numerator;
    simplify(res);
    return res;
}


