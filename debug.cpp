#include <bits/stdc++.h>
using namespace std;

int rnd32(int l, int r){
    return l + rand() % (r - l + 1);
}

long long rnd64(long long l, long long r){
    return l + rand() * 1LL * rand() % (r - l + 1);
}

void gen(){
    ofstream inp("ben.inp");
    int n = rnd32(1, 1000);
    inp << n << "\n";
    for(int i = 1; i <= n; i++){
        inp << rnd32(1, 1000) << "\n";
    }
    inp.close();
}

int main(){
    srand(time(0));
    for(int test = 1; test <= 100; test++){
        gen();
        system("ben.exe");
        system("sailam.exe");
        if(system("fc ben.out ben.ans")){
            cout << "Test " << test << ": " << "WRONG!\n";
            return 0;
        }
        cout << "Test " << test << ": " << "CORRECT!\n";
    }
}
