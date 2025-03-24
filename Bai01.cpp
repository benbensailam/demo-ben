#include <bits/stdc++.h>
using namespace std;

struct FRACTION{
    int numerator, denominator;
};

void inp(FRACTION &);
void out(FRACTION &);
int check(const FRACTION &);

int main(){
    FRACTION x;
    inp(x);
    out(x);
    int res = check(x);
    switch(res){
        case 1:
            cout << "Phan so > 0";
            break;
        case -1:
            cout << "Phan so < 0";
            break;
        case 0:
            cout << "Phan so = 0";
            break;
    }
}

void inp(FRACTION &x){
    cout << "Nhap tu so: ";
    cin >> x.numerator;
    cout << "Nhap mau so: ";
    cin >> x.denominator;
}

void out(FRACTION &x){
    cout << "Tu so = " << x.numerator << "\n";
    cout << "Mau so = " << x.denominator << "\n";
}

int check(const FRACTION &x){
    if(x.numerator * x.denominator > 0) return 1;
    else if(x.numerator * x.denominator < 0) return -1;
    else return 0;
}


