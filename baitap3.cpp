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
// tổng giữa 2 phân số a và b
phanso tong(phanso a, phanso b){
    phanso c;
    c.ts=a.ts*b.ms+a.ms*b.ts;
    c.ms=a.ms*b.ms;
    return c;
}
// hiệu giữa 2 phân số a và b
phanso hieu(phanso a, phanso b){
    phanso c;
    c.ts=a.ts*b.ms-a.ms*b.ts;
    c.ms=a.ms*b.ms;
    return c;
}
// tích giữa 2 phân số a và b
phanso tich(phanso a, phanso b){
    phanso c;
    c.ts=a.ts*b.ts;
    c.ms=a.ms*b.ms;
    return c;
}
// thương giữa 2 phân số a và b
phanso thuong(phanso a, phanso b){
    phanso c;
    if (b.ts==0){
        cout<<"khong xac dinh";
    }
    else
    c.ts=a.ts*b.ms;
    c.ms=a.ms*b.ts;
    return c;
}
// hàm xuất phân số
void xuat(phanso a){
    if (a.ts==0) cout << "0";
    else if (a.ms==1) cout << a.ts;
    else  cout << a.ts << " / " << a.ms;
    cout << endl;
}

int main(){
    phanso a;
    phanso b;
    nhap(a);
    nhap(b);
    rutgon(a);
    rutgon(b);
    phanso T=tong(a,b);
    rutgon(T);
    phanso H=hieu(a,b);
    rutgon(H);
    phanso Ti=tich(a,b);
    rutgon(Ti);
    phanso Th=thuong(a,b);
    rutgon(Th);
    xuat(T);
    xuat(H);
    xuat(Ti);
    xuat(Th);
    return 0;
}