#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e5 + 7;
int n, a[N];

void quickSort(int a[], int l, int r){
    if(l >= r) return;
    int pivot = a[l + (r - l) / 2];
    int i = l, j = r;
    while(i < j){
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    quickSort(a, l, j);
    quickSort(a, i, r);
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    quickSort(a, 1, n);
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    if(fopen("ben.inp", "r")){
        freopen("ben.inp", "r", stdin);
        freopen("ben.out", "w", stdout);
    }
    solve();
}
