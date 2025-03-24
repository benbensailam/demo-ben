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
    
    FRACTION comparing(const FRACTION &other) const{
        double resA = (double) numerator / denominator;
        double resB = (double) other.numerator / other.denominator;
        if(resA >= resB) return *this;
        else return other;
    }
};

void solve(){
    FRACTION fractionA, fractionB, res;
    cin >> fractionA.numerator >> fractionA.denominator >> fractionB.numerator >> fractionB.denominator;
    res = fractionA.comparing(fractionB);
    cout << res.numerator << " " << res.denominator;
}

int main(){
    solve();
}

