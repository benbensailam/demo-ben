#include <bits/stdc++.h>
using namespace std;

int n, m;

class MATRIX{
    vector<vector<int>> matrix;

    public:
        MATRIX(){
            matrix.resize(2, vector<int>(2, 0));
        }

        MATRIX(int n, int m){
            matrix.resize(n, vector<int>(m, 0));
        }

        MATRIX(int n, int m, const vector<vector<int>> &other){
            matrix.resize(n, vector<int>(m, 0));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    matrix[i][j] = other[i][j];
                }
            }
            
        }

        int getRows(){
            return matrix.size();
        }

        int getCols(){
            return matrix[0].size();
        }

        MATRIX add(const MATRIX &other) const{
            MATRIX res(matrix.size(), matrix[0].size());
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[0].size(); j++){
                    res.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
                }
            }
            return res;
        }

        MATRIX subtract(const MATRIX &other) const{
            MATRIX res(matrix.size(), matrix[0].size());
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[0].size(); j++){
                    res.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
                }
            }
            return res;
        }

        MATRIX multiply(const MATRIX &other) const{
            MATRIX res(matrix.size(), other.matrix[0].size());
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < other.matrix[0].size(); j++){
                    for(int k = 0; k < matrix[0].size(); k++){
                        res.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                    }
                }
            }
            return res;
        }

        void print(){
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[0].size(); j++){
                    cout << matrix[i][j] << " ";
                }
                cout << "\n";
            }
        }
};

void inp(string name, int &n, int &m, MATRIX &matrix){
    cout << "Nhap so hang cua ma tran " << name << ": ";
    cin >> n;
    cout << "Nhap so cot cua ma tran " << name << ": ";
    cin >> m;
    cout << "Nhap ma tran " << name << ": \n";
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    matrix = MATRIX(n, m, arr);
}

void solve(){
    MATRIX A, B;
    inp("A", n, m, A);
    inp("B", n, m, B);

    if(A.getRows() != B.getRows() || A.getCols() != B.getCols()){
        cout << "Khong the cong hoac tru hai ma tran A va B voi nhau\n";
    }
    else{
        cout << "Ma tran A + B: \n";
        MATRIX sum = A.add(B);
        sum.print();
    
        cout << "Ma tran A - B: \n";
        MATRIX difference = A.subtract(B);
        difference.print();
    }

    if(A.getCols() != B.getRows()){
        cout << "Khong the nhan hai ma tran A va B voi nhau\n";
    }
    else{
        cout << "Ma tran A * B: \n";
        MATRIX product = A.multiply(B);
        product.print();
    }
}

int main(){
    solve();
}
