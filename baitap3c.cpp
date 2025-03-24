#include <bits/stdc++.h>
using namespace std;

struct FRACTION{
    int numerator, denominator;
    
    FRACTION simplify(){
        int GCD = __gcd(numerator, denominator);
        numerator /= GCD;
        denominator /= GCD;
        if(denominator < 0){
            numerator = - numerator;
            denominator = - denominator;
        }
        return FRACTION{numerator, denominator};
    }
    
    int commonDenominator(const FRACTION &other) const{
        int GCD = __gcd(denominator, other.denominator);
        return denominator * other.denominator / GCD;
    }
    
    FRACTION addition(const FRACTION &other) const{
        int cD = commonDenominator(other);
        FRACTION res = {numerator * (cD / denominator) + other.numerator * (cD / other.denominator), cD};
        return res.simplify();
    }
    
    FRACTION subtraction(const FRACTION &other) const{
        int cD = commonDenominator(other);
        FRACTION res = {numerator * (cD / denominator) - other.numerator * (cD / other.denominator), cD};
        return res.simplify();
    }
    
    FRACTION multiplication(const FRACTION &other) const{ 
        FRACTION res = {numerator * other.numerator, denominator * other.denominator};
        return res.simplify();
    }
    
    FRACTION division(const FRACTION &other) const{
        FRACTION res = {numerator * other.denominator, denominator * other.numerator};
        return res.simplify();
    }
};

void solve(){
    FRACTION fractionA, fractionB, res;
    cin >> fractionA.numerator >> fractionA.denominator >> fractionB.numerator >> fractionB.denominator;
    
    res = fractionA.addition(fractionB);
    cout << res.numerator << " " << res.denominator << "\n";
    
    res = fractionA.subtraction(fractionB);
    cout << res.numerator << " " << res.denominator << "\n";
    
    res = fractionA.multiplication(fractionB);
    cout << res.numerator << " " << res.denominator << "\n";
    
    res = fractionA.division(fractionB);
    cout << res.numerator << " " << res.denominator << "\n";
}

int main(){
    solve();
}

