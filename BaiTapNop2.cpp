#include <bits/stdc++.h>
using namespace std;

class FRACTION{
    int numerator, denominator;
    public:
        FRACTION(){
            numerator = 0;
            denominator = 1;
        }

        FRACTION(int x, int y){
            numerator = x;
            denominator = y;
        }

        FRACTION simplify(){
            int GCD = __gcd(numerator, denominator);
            numerator /= GCD;
            denominator /= GCD;
            if(denominator < 0){
                numerator = -numerator;
                denominator = -denominator;
            }
            return *this;
        }

        FRACTION add(const FRACTION &other) const{
            FRACTION res;
            res.numerator = numerator * other.denominator + other.numerator * denominator;
            res.denominator = denominator * other.denominator;
            return res.simplify();
        }

        FRACTION subtract(const FRACTION &other) const{
            FRACTION res;
            res.numerator = numerator * other.denominator - other.numerator * denominator;
            res.denominator = denominator * other.denominator;
            return res.simplify();
        }

        int check(){
            if(numerator * denominator < 0) return -1;
            else return 1;
        }

        FRACTION greaterFunction(const FRACTION &other) const{
            FRACTION res = subtract(other);
            if(res.check() == 1) return *this;
            else return other;
        }

        void print(){
            cout << numerator << "/" << denominator << "\n";
        }
};

int numerator, denominator;

void inp(){
    cout << "Nhap tu so: ";
    cin >> numerator;
    cout << "Nhap mau so: ";
    cin >> denominator;
}

void solve(){
    cout << "Nhap so luong phan so: ";
    int n; cin >> n;
    FRACTION sum, greatestFraction;

    inp();
    sum = FRACTION(numerator, denominator);
    greatestFraction = sum;

    for(int i = 1; i < n; i++){
        inp();
        sum = sum.add(FRACTION(numerator, denominator));
        greatestFraction = greatestFraction.greaterFunction(FRACTION(numerator, denominator));
    }

    cout << "Tong cac phan so: ";
    sum.print();
    cout << "Phan so lon nhat: ";
    greatestFraction.print();
}

int main(){
    solve();
}
