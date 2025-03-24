#include <bits/stdc++.h>
using namespace std;

struct COMPANY{
    string ID, name, department;
    int basicSalary, bonus, basicSalaryAndBonus;
    
    operator < (const COMPANY &other) const{
        if(department == other.department) return ID > other.ID;
        else return department < other.department;
    }
};

vector<COMPANY> member;

void solve(){
    int numnerOfMembers;
    cin >> numnerOfMembers;
    while(numnerOfMembers--){
        COMPANY temp;
        cin >> temp.ID >> temp.name >> temp.department >> temp.basicSalary >> temp.bonus;
        temp.basicSalaryAndBonus = temp.basicSalary + temp.bonus;
        member.push_back(temp);
    }
    
    // Bài tập 4a
    long long sum = 0;
    for(vector<COMPANY>::iterator it = member.begin(); it != member.end(); it++){
        sum += it->basicSalaryAndBonus;
    }
    cout << sum << "\n";
    
    // Bài tập 4b
    int minBasicSalary = INT_MAX;
    for(vector<COMPANY>::iterator it = member.begin(); it != member.end(); it++){
        minBasicSalary = min(minBasicSalary, it->basicSalary);
    }
    for(vector<COMPANY>::iterator it = member.begin(); it != member.end(); it++){
        if(it->basicSalary == minBasicSalary){
            cout << it->ID << " " << it->name << " " << it->department << "\n";
        }
    }
    
    // Bài tập 4c
    int cnt = 0;
    for(vector<COMPANY>::iterator it = member.begin(); it != member.end(); it++){
        if(it->bonus >= 1200000) cnt++;
    }
    cout << cnt << "\n";
    
    // Bài tập 4d
    sort(member.begin(), member.end());
    for(vector<COMPANY>::iterator it = member.begin(); it != member.end(); it++){
        cout << it->ID << " " << it->name << " " << it->department << "\n";
    }
}

int main(){
    solve();
}
