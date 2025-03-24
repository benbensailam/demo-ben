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
};

void solve(){
    FRACTION fraction, res;
    cin >> fraction.numerator >> fraction.denominator;
    res = fraction.simplify();
    cout << res.numerator << " " << res.denominator;
}

int main(){
    solve();
}
