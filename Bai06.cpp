#include <bits/stdc++.h>
using namespace std;

struct DATE{
    int day, month, year;
};

void inp(DATE &);
void out(DATE &);
bool isLeapYear(const DATE &);
long long ordinal(const DATE &);
int ordinalInYear(const DATE &);
DATE findDate(long long);
DATE findDate(int, int);
DATE tomorrow(const DATE &);

int main(){
    DATE x, res;
    cout << "Nhap ngay hien tai: \n";
    inp(x);
    out(x);
    cout << "Ngay ke tiep: ";
    out(res = tomorrow(x));
}

void inp(DATE &x){
    cout << "Nhap ngay: ";
    cin >> x.day;
    cout << "Nhap thang: ";
    cin >> x.month;
    cout << "Nhap nam: ";
    cin >> x.year;
}

void out(DATE &x){
    cout << x.day << "/" << x.month << "/" << x.year << "\n";
}

bool isLeapYear(const DATE &x){
    if((x.year % 4 == 0) && (x.year % 100 != 0)) return true;
    else if(x.year % 400 == 0) return true;
    else return false;
}

long long ordinal(const DATE &x){
    long long ord = 0;
    for(int i = 1; i < x.year; i++){
        ord += 365;
        DATE temp = {1, 1, i};
        if(isLeapYear(temp)) ord++;
    }
    return ord + ordinalInYear(x);
}

int ordinalInYear(const DATE &x){
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(isLeapYear(x)) month[1] = 29;
    int ord = 0;
    for(int i = 1; i < x.month; i++){
        ord += month[i - 1];
    }
    return ord + x.day;
}

DATE findDate(long long ord){
    int year = 1;
    int days = 365;
    while(ord - days > 0){
        ord -= days;
        year++;
        DATE x = {1, 1, year};
        if(isLeapYear(x)) days = 366;
        else days = 365;
    }
    return findDate(year, ord);
}

DATE findDate(int year, int ord){
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    DATE x = {1, 1, year};
    if(isLeapYear(x)) month[1] = 29;
    x.month = 1;
    while(ord - month[x.month - 1] > 0){
        ord -= month[x.month - 1];
        x.month++;
    }
    x.day = ord;
    return x;
}

DATE tomorrow(const DATE &x){
    long long ord = ordinal(x);
    ord++;
    return findDate(ord);
}

