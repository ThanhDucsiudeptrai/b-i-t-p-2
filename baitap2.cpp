#include <iostream>
using namespace std;

struct phanso{
    int ts;
    int ms;
};
// hàm nhập phân số
void nhap(phanso &a){
    cin>>a.ts;
    do {
         cin>>a.ms;
        }
    while (a.ms==0);
}
// hàm tìm ước chung lớn nhấtt
int ucln(int a, int b){
    
    while (b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
// hàm rút gọn phân số 
void rutgon(phanso &a){
    int x=ucln(a.ts,a.ms);
    a.ts/=x;
    a.ms/=x;
    if (a.ms<0){
        a.ts=-a.ts;
        a.ms=-a.ms;
    }
}
// hàm tìm phân số lớn hơnhơn
phanso phansomax(phanso a,phanso b){
    if (a.ts*b.ms>a.ms*b.ts) return a;
    else return b;
}
// hàm xuất phân số
void xuat(phanso a){
    if (a.ts==0) cout << "0";
    else if (a.ms==1) cout << a.ts;
    else  cout << a.ts << " / " << a.ms;
}

int main(){
    phanso a;
    phanso b;
    nhap(a);
    nhap(b);
    rutgon(a);
    rutgon(b);
    xuat(phansomax(a,b));
    return 0;
}