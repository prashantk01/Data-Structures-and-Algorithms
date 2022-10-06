#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    cout << "welcome to matrix multiplication page: ";
    int m,n,a,b;
    cout << "enter matrix 1 size (m x n): " << endl;
    cin >> m;
    cin >> n;
    cout << "enter matrix 2 size (a x b): " << endl;
    cin >> a;
    cin >> b;
    int m1[m][n];
    int m2[a][b];

    if(n!=a){
        cout << "matrix m1 and m2 are not compatible for multiplication" << endl;
        return 0;
    }

    cout << "enter matrix m1 elements: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n;j++){
            cin >> m1[i][j];
        }
    }

    cout << "enter matrix m2 elements: ";
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b;j++){
            cin >> m2[i][j];
        }
    }


    int ans[m][b]; // ANS MATRIX WILL BE ROWm1*COLm2

    // matrix multiplication equation is: cij=ai1b1j+ai2b2j+⋯+ainbnj
    // cij=∑k(1ton)a(ik)b(kj)
    for (int i = 0; i < m; i++)  
    {
        for (int j = 0; j < b; j++)
        {
            int tmp = 0;
            for (int k = 0; k < a;k++){
                tmp += m1[i][k] * m2[k][j];
            }
            ans[i][j] = tmp;
        }
    }

    cout << "matrix multiplication is:   "<<endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < b; j++){
            cout << ans[i][j]<<"            ";
        }
        cout << endl;
    }
}