#include<iostream>
#include <string> 
#include <vector>
#include <algorithm>
using namespace std;

struct Ngay{
    int ngay;
    int thang;
    int nam;
};

struct Gio{
    int phut;
    int gio;
};

struct quanlibay{
    string flightnumber;
    Ngay date;
    Gio time;
    string Departure , Arrival ;
};

//kiem tra ngay hop le 
bool kiemtradate(int d, int m, int y) {
    if (m < 1 || m > 12 || y < 2025) return false;
    int ngaytrongthang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && (y%4==0&&y%100!=0||y%400==0)) ngaytrongthang[1] = 29;
    return d >= 1 && d <= ngaytrongthang[m - 1];
}

//kiem tra gio hop le
bool kiemtratime(int h, int m) {
    return (h >= 0 && h < 24) && (m >= 0 && m < 60);
}

//kiem tra ma chuyen bay
bool kiemtraflightnumber(const string& flightNumber) {
    if (flightNumber.length() > 5 || flightNumber.empty()) return false;
    for (char c : flightNumber) {
        if (!isalnum(c)) return false;
    }
    return true;
}

//kiem tra dia chi hop le
bool kiemtradiachi(const string& flightNumber) {
    if (flightNumber.length() > 20|| flightNumber.empty()) return false;
    for (char c : flightNumber) {
        if (!isalpha(c)&&c!=' ') return false;
    }
    return true;
}

//nhap thong tin 
void nhapChuyenBay(quanlibay &cb) {
    do {
        cout << "Nhap ma chuyen bay (toi da 5 ky tu, khong chua ky tu dac biet) : ";
        cin >> cb.flightnumber;
    } while (!kiemtraflightnumber(cb.flightnumber));

    do {
        cout << "Nhap ngay bay (dd mm yyyy): ";
        cin >> cb.date.ngay >> cb.date.thang >> cb.date.nam;
    } while (!kiemtradate(cb.date.ngay, cb.date.thang, cb.date.nam));

    do {
        cout << "Nhap gio bay: ";
        cin >> cb.time.gio >> cb.time.phut;
    } while (!kiemtratime(cb.time.gio, cb.time.phut));

    cin.ignore();
    do {
        cout << "Nhap noi di: ";
        getline(cin, cb.Departure);
    } while (!kiemtradiachi(cb.Departure));

    do {
        cout << "Nhap noi den: ";
        getline(cin, cb.Arrival);
    } while (!kiemtradiachi(cb.Arrival));
}

//xuat chuyen bay
void xuatchuyenbay(quanlibay x){
    cout<< x.flightnumber<<" | "
    << x.date.ngay<<"/"<<x.date.thang<<"/"<<x.date.nam<<" | "
    << x.time.gio<<":"<<x.time.phut<<" | "
    << x.Departure<<" -> "<<x.Arrival<<endl;
}

//tim kiem chuyen bay
void timchuyenbay(vector<quanlibay> x){
    string tukhoa;
    getline(cin,tukhoa);
    for(quanlibay a:x){
        if(a.flightnumber==tukhoa||a.Departure==tukhoa||a.Arrival==tukhoa){
             cout<<"thong tin chuyen bay: "<<endl;
             xuatchuyenbay(a);
             break;
        }   
    }
    cout<<"khong tim thay chuyen bay tren"<<endl;
}

//sap xep danh sach chuyen bay
bool compare(quanlibay &x, quanlibay &y){
    if (x.date.nam!=y.date.nam) return x.date.nam<y.date.nam;
    else if(x.date.thang!=y.date.thang) return x.date.thang<y.date.thang;
    else if(x.date.ngay!=y.date.ngay) return x.date.ngay<y.date.ngay;
    else if (x.time.gio!=y.time.gio) return x.time.gio<y.time.gio;
    else return x.time.phut<y.time.phut ;
}

//hien thi tat ca chuyen bay cu the khoi hanh tu va vao ngay cu the
void bangchuyenbay(vector<quanlibay> a, string noidi, Ngay x){
    for(quanlibay c:a){
        if(noidi==c.Departure&&x.ngay==c.date.ngay&&x.thang==c.date.thang&&x.nam==c.date.nam) xuatchuyenbay(c);
    }
}

// Hàm đếm số lượng chuyến bay giữa hai địa điểm
int demchuyenbay(const vector<quanlibay>& ds, const string& noiDi, const string& noiDen) {
    int count = 0;
    for (const auto& cb : ds) {
        if (cb.Departure == noiDi && cb.Arrival == noiDen) count++;
    }
    return count;
}

int main(){
    vector<quanlibay> danhsach;
    int n;
    cout << "Nhap so luong chuyen bay: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin chuyen bay thu " << i + 1 << ":\n";
        quanlibay cb;
        nhapChuyenBay(cb);
        danhsach.push_back(cb);
    }

    sort(danhsach.begin(), danhsach.end(), compare);
    
    cout << "\nDanh sach chuyen bay sau khi sap xep:\n";
    for (const auto& cb : danhsach) {
        xuatchuyenbay(cb);
    }
    timchuyenbay(danhsach);

    string noiDi, noiDen;
    Ngay datetime;
    cout << "\nNhap noi di can liet ke: ";
    cin >> noiDi;
    cout << "Nhap ngay (dd mm yyyy): ";
    cin >> datetime.ngay >> datetime.thang >> datetime.nam;
    bangchuyenbay(danhsach, noiDi,datetime );

    cout << "\nNhap noi di va noi den can dem: ";
    cin >> noiDi >> noiDen;
    cout << "So chuyen bay tu " << noiDi << " den " << noiDen << ": " << demchuyenbay(danhsach, noiDi, noiDen) << endl;

    return 0;
}