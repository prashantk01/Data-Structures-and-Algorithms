#include<bits/stdc++.h>
using namespace std;

int main(){
    int r;
    cout << "enter size of sqaure matrix: ";
    cin >> r;
    // cout << " enter num of col: ";
    // cin >> c;

    vector<vector<int>> matrix(r,vector<int> (r)); 
    cout << "enter matrix values: ";
    for (int i = 0; i < r;i++){
        for (int j = 0; j < r;j++){
            cin >> matrix[i][j];
        }
    }
    // in place transpose of matrix:
    for (int i = 0; i < r;i++){
        for (int j = 0; j < i;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    cout << "matrix transpose is:   "<<endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < r; j++){
            cout << matrix[i][j]<<"            ";
        }
        cout << endl;
    }
    return 0;
}