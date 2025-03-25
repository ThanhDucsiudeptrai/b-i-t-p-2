#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct hocsinh{
    string hoten,xeploai;
    float diemtoan,diemvan,diemngoaingu,dtb;
};

bool kiemtrahoten(string B){
    if(B.empty()||B.length()>27)
    return false;
    for(char c:B){
        if(isdigit(c)) return false;
        if(!(isalpha(c)||c==' ')) return false;
    }
    return true;
}

bool kiemtradiem(float diem){
    return diem>=0&&diem<=10;
}

float dtb(float toan, float van, float ngoaingu){
    return (toan*2+van+ngoaingu)/4;
}

string phanloaihs(float diemtrungbinh){
    if (diemtrungbinh>=9) return "xuat sat";
    else if (diemtrungbinh>=8) return "gioi";
    else if (diemtrungbinh>=6.5) return "kha ";
    else if (diemtrungbinh>=5) return "trung binh";
    return "yeu";
}

void nhapthongtinhs(hocsinh &A){
    do{
    cout << "Nhap ho va ten hoc sinh: ";
    getline(cin,A.hoten);
    if (!kiemtrahoten(A.hoten)) 
    cout <<"Ten khong hop le! Vui long nhap lai.\n";
    }while (!kiemtrahoten(A.hoten));

    do{
        cout<<" nhap diem mon toan:";
        cin>>A.diemtoan;
        if(!kiemtradiem(A.diemtoan)) 
        cout <<"Diem khong hop le! Vui long nhap lai.\n";
    } while (!kiemtradiem(A.diemtoan));

    do{
        cout<<" nhap diem mon van:";
        cin>>A.diemvan;
        if(!kiemtradiem(A.diemvan)) 
        cout <<"Diem khong hop le! Vui long nhap lai.\n";
    } while (!kiemtradiem(A.diemvan));
    
    do{
        cout<<" nhap diem mon ngoai ngu:";
        cin>>A.diemngoaingu;
        if(!kiemtradiem(A.diemngoaingu)) 
        cout <<"Diem khong hop le! Vui long nhap lai.\n";
    } while (!kiemtradiem(A.diemngoaingu));
    cin.ignore();

    A.dtb=dtb(A.diemtoan,A.diemvan,A.diemngoaingu);
    A.xeploai=phanloaihs(A.dtb);
}

hocsinh dtbmax(vector<hocsinh> a, int n){
    float dtbmax=0;
    int result=0;
    for(int i=0; i<n; i++){
        if (a[i].dtb>dtbmax){
            dtbmax=a[i].dtb;
            result=i;
        }
    }
    return a[result];
}

// Chuyển họ tên thành chữ thường
void transfer_lower(string &hoten){
    for (int i = 0; i < hoten.length(); i++) {
        if (hoten[i] >= 'A' && hoten[i] <= 'Z') {
            hoten[i] = hoten[i] + 32;
        }
    }
}

void xuat(hocsinh hs){
    cout << "Ho ten hoc sinh: "<<hs.hoten<<endl<<" Diem toan: "<<hs.diemtoan<<endl<<"diem van: "<< hs.diemvan<<endl<<"diem ngoai ngu: "<< hs.diemngoaingu<<endl <<"diem trung binh: "<< hs.dtb<<endl<< "xep loai: "<<hs.xeploai<<endl;
}

void timkiemhoten(vector<hocsinh> a){
    for(auto hs:a){
        string hotenhocsinh=hs.hoten;
        transfer_lower(hotenhocsinh);
        string tukhoa;
        do {
            cout << "Nhap tu khoa: ";
            getline(cin, tukhoa);
            if (!tukhoa.empty() && tukhoa.length() <= 27) break; // Kiểm tra đơn giản hơn
            cout << "Tu khoa khong hop le! Vui long nhap lai!\n";
        } while (true);
        transfer_lower(tukhoa);
        if (hotenhocsinh.find(tukhoa)!=string::npos) 
        xuat(hs);

    }
}

hocsinh diemtoanmin(vector<hocsinh> a,int n){
    float diemtoanmin=a[0].diemtoan;
    int result=0;
    for(int i=1; i<n; i++){
        if (a[i].diemtoan<diemtoanmin){
            diemtoanmin=a[i].diemtoan;
            result=i;
        }
    }
    return a[result];
}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<hocsinh> danhsach(n);
    for (int i=0; i<n; i++){
        cout << "Nhap thong tin hoc sinh thu "<<i+1<<endl;
        nhapthongtinhs(danhsach[i]);
    }

    for(auto hs:danhsach){
        hs.dtb=dtb(hs.diemtoan,hs.diemvan,hs.diemngoaingu);
        hs.xeploai=phanloaihs(hs.dtb);
        xuat(hs);
    }
    
    cout << "hoc sinh co diem trung binh cao nhat la: ";
    xuat(dtbmax(danhsach,n));
    timkiemhoten(danhsach);
    cout<<"danh sach hoc sinh co diem toan thap nhaty la: ";
    xuat(diemtoanmin(danhsach,n));
    return 0;
}