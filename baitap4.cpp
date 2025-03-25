#include <iostream>
#include <cmath>
using namespace std;

long gt(int n){
    if(n==0||n==1) return 1;
    else return n*gt(n-1);
}

double mu(double x, int n){
    double result=1;
    for(int i=0; i<n;i++){
        result*=x;
    }
    return result;
}

double sinTaylor(double x) {
    int n = 1;                
    double sum = x;           
    double result;

    do {
        result = (mu(-1, n) * mu(x, 2 * n + 1)) / gt(2 * n + 1); 
        sum += result;                                         
        n++;
    } while (fabs(result) > 0.00001); // Kiểm tra giá trị tuyệt đối
    return sum;
}



int main(){
    double x;
    cin>>x;
    double y=sin(x);
    cout << y;
    return 0;

}