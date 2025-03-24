#include <bits/stdc++.h>
using namespace std;

struct STUDENT{
    string ID, name;
    double maths, literature, physics, chemistry;
    
    double GPA(){
        return (maths + literature + physics + chemistry) / double(4);
    }
};

vector<STUDENT> student;

void solve(){
    int numberOfStudents;
    cin >> numberOfStudents;
    while(numberOfStudents--){
        STUDENT temp;
        cin >> temp.ID >> temp.name >> temp.maths >> temp.literature >> temp.physics >> temp.chemistry;
        student.push_back(temp);
    }
    
    for(vector<STUDENT>::iterator it = student.begin(); it != student.end(); it++){
        cout << it->ID << " " << it->name << " " << it->GPA() << "\n";
    }
}

int main(){
    solve();
}

