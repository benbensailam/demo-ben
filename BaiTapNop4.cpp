#include <bits/stdc++.h>
using namespace std;

class STUDENT{
    string ID, name, sex;
    float maths, physics, chemistry;

    public:
        STUDENT(){
            ID = "";
            name = "";
            sex = "";
            maths = physics = chemistry = 0;
        }

        STUDENT(string _ID, string _name, string _sex, float _maths, float _physics, float _chemistry){
            ID = _ID;
            name = _name;
            sex = _sex;
            maths = _maths;
            physics = _physics;
            chemistry = _chemistry;
        }

        float average(){
            return (maths + physics + chemistry) / float(3);
        }
        
        void print(){
            cout << "Thong tin chi tiet cua hoc sinh: \n";
            cout << "Ma hoc sinh: " << ID << "\n";
            cout << "Ho ten: " << name << "\n";
            cout << "Gioi tinh: " << sex << "\n";
            cout << "Diem toan: " << maths << "\n";
            cout << "Diem ly: " << physics << "\n";
            cout << "Diem hoa: " << chemistry << "\n";
            cout << "Diem trung binh: " << average() << "\n";
        }
        
};

void solve(){
    string ID, name, sex;
    float maths, physics, chemistry;

    cout << "Nhap thong tin hoc sinh: \n";
    cout << "Nhap ma hoc sinh: ";
    getline(cin, ID);
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap gioi tinh: ";
    cin >> sex;
    cout << "Nhap diem toan: ";
    cin >> maths;
    cout << "Nhap diem ly: ";
    cin >> physics;
    cout << "Nhap diem hoa: ";
    cin >> chemistry;

    STUDENT student(ID, name, sex, maths, physics, chemistry);
    student.print();
}

int main(){
    solve();
}
