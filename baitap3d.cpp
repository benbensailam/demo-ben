#include <bits/stdc++.h>
using namespace std;

struct DATE{
    int day, month, year;
    
    bool leapYear() const{
        if((year % 4 == 0) && (year % 100 != 0)) return true;
        else return false;
    }
    
    bool _31Days() const{
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return true;
    }
    
    DATE nextDay() const{
        DATE res;
        if(month == 2){
            if(leapYear()){
                if(day == 29) return res = {01, month + 1, year};
                else return res = {day + 1, month, year};
            }
            else{
                if(day == 28) return res = {01, month + 1, year};
                else return res = {day + 1, month, year};
            }
        }
        else if(month == 12){
            if(day == 31) return res = {01, 01, year + 1};
            else return res = {day + 1, month, year};
        }
        else if(_31Days()){
            if(day == 31) return res = {01, month + 1, year};
            else return res = {day + 1, month, year};
        }
        else{
            if(day == 30) return res = {01, month + 1, year};
            else return res = {day + 1, month, year};
        }
    }
};

void solve(){
    DATE date, res;
    cin >> date.day >> date.month >> date.year;
    res = date.nextDay();
    cout << res.day << " " << res.month << " " << res.year;
}

int main(){
    solve();
}
