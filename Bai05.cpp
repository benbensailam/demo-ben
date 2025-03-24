#include <bits/stdc++.h>
using namespace std;

struct COMPLEX{
    double real, imaginary;
};

void inp(COMPLEX &);
void out(COMPLEX &);
COMPLEX addition(const COMPLEX &, const COMPLEX &);
COMPLEX subtraction(const COMPLEX &, const COMPLEX &);
COMPLEX multiplication(const COMPLEX &, const COMPLEX &);
COMPLEX division(const COMPLEX &, const COMPLEX &);

int main(){
    COMPLEX x, y, res;
    cout << "Nhap so phuc thu nhat: \n";
    inp(x);
    cout << "Nhap so phuc thu hai: \n";
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

void inp(COMPLEX &x){
    cout << "Nhap phan thuc: ";
    cin >> x.real;
    cout << "Nhap phan ao: ";
    cin >> x.imaginary;
}

void out(COMPLEX &x){
    cout << x.real << " + " << x.imaginary << "i\n";
}

COMPLEX addition(const COMPLEX &x, const COMPLEX &y){
    COMPLEX res;
    res.real = x.real + y.real;
    res.imaginary = x.imaginary + y.imaginary;
    return res;
}

COMPLEX subtraction(const COMPLEX &x, const COMPLEX &y){
    COMPLEX res;
    res.real = x.real - y.real;
    res.imaginary = x.imaginary - y.imaginary;
    return res;
}

COMPLEX multiplication(const COMPLEX &x, const COMPLEX &y){
    COMPLEX res;
    res.real = x.real * y.real - x.imaginary * y.imaginary;
    res.imaginary = x.real * y.imaginary + x.imaginary * y.real;
    return res;
}

COMPLEX division(const COMPLEX &x, const COMPLEX &y){
    COMPLEX res;
    res.real = (x.real * y.real + x.imaginary * y.imaginary) / (y.real * y.real + y.imaginary * y.imaginary);
    res.imaginary = (x.imaginary * y.real - x.real * y.imaginary) / (y.real * y.real + y.imaginary * y.imaginary);
    return res;
}

