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

        FRACTION multiply(const FRACTION &other) const{
            FRACTION res;
            res.numerator = numerator * other.numerator;
            res.denominator = denominator * other.denominator;
            return res.simplify();
        }
        
        FRACTION divide(const FRACTION &other) const{
            FRACTION res;
            res.numerator = numerator * other.denominator;
            res.denominator = denominator * other.numerator;
            return res.simplify();
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
    FRACTION fraction1, fraction2;
    cout << "Nhap phan so thu nhat: \n";
    inp();
    fraction1 = FRACTION(numerator, denominator);
    cout << "Nhap phan so thu hai: \n";
    inp();
    fraction2 = FRACTION(numerator, denominator);

    FRACTION sum = fraction1.add(fraction2);
    cout << "Tong hai phan so: ";
    sum.print();
    FRACTION difference = fraction1.subtract(fraction2);
    cout << "Hieu hai phan so: ";
    difference.print();
    FRACTION product = fraction1.multiply(fraction2);
    cout << "Tich hai phan so: ";
    product.print();
    FRACTION quotient = fraction1.divide(fraction2);
    cout << "Thuong hai phan so: ";
    quotient.print();
}

int main(){
    solve();
}
