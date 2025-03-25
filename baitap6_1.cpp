#include <iostream>
#include <vector>
using namespace std;

vector<int> count(vector<int> A, vector<int> B, int n, int m){
    vector<int> C;
    for (int i=0; i<m-n; i++){
        bool value=true;
        for (int j=0; j<n; j++){
            if (A[j]!=B[i+j]){
                value=false;
                break;
            }
        }
        if (value) C.push_back(i);
    }
    return C;
}

int main (){
    int n,m;
    cin >>n>>m;
    vector<int> A(n);
    vector<int> B(m);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    for(int i=0; i<m; i++){
        cin >> B[i];
    }
    vector<int> C=count(A,B,n,m);
    cout << C.size()<<endl;
    for(int x:C){
        cout << x<<" ";
    }
    
    return 0;

}