#include <bits/stdc++.h>
using namespace std;

struct Date {
    int ngay, thang, nam;
};

struct SoTietKiem {
    string maso, loaitietkiem, hoten;
    long long cmnd;
    Date ngaymoso;
    double sotien;
};

// kiem tra ma soso
bool kiemtramaso(const string& a) {
    if (a.size() > 5 || a.empty()) return false;
    for (char c : a) {
        if (!isalnum(c)) return false;
    }
    return true;
}

// kiem tra ho tenten
bool kiemtrahoten(const string& hoten) {
    if (hoten.size() > 30 || hoten.empty()) return false;
    for (char c : hoten) {
        if (!isalpha(c) || c != ' ') return false;
    }
    return true;
}

// kiểm tra CMND 
bool kiemtraCMND(long long cmnd) {
    int count = 0;
    long long temp = cmnd;

    while (temp > 0) {
        temp /= 10;
        count++;
    }

    return (count == 9 || count == 12);
}

// kiểm tra ngày hợp lệ
bool kiemtradate(int d, int m, int y) {
    if (m < 1 || m > 12 || y < 1900) return false;
    int ngaytrongthang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)) ngaytrongthang[1] = 29;
    return (d >= 1 && d <= ngaytrongthang[m - 1]);
}

// nhập thông tin sổ tiết kiệm
void nhapSoTietKiem(SoTietKiem &stk) {
    do {
        cout << "Nhap ma so tiet kiem (toi da 5 ky tu): ";
        cin >> stk.maso;
    } while (!kiemtramaso(stk.maso));

    do {
        cout << "Nhap loai tiet kiem (ngan han, dai han, khong ky han): ";
        cin >> stk.loaitietkiem;
    } while (stk.loaitietkiem.size() > 10 || stk.loaitietkiem.empty());

    cin.ignore();
    do {
        cout << "Nhap ho ten khach hang: ";
        getline(cin, stk.hoten);
    } while (!kiemtrahoten(stk.hoten));

    do {
        cout << "Nhap CMND (9 hoac 12 so): ";
        cin >> stk.cmnd;
    } while (!kiemtraCMND(stk.cmnd));

    do {
        cout << "Nhap ngay mo so (dd mm yyyy): ";
        cin >> stk.ngaymoso.ngay >> stk.ngaymoso.thang >> stk.ngaymoso.nam;
    } while (!kiemtradate(stk.ngaymoso.ngay, stk.ngaymoso.thang, stk.ngaymoso.nam));

    do {
        cout << "Nhap so tien gui: ";
        cin >> stk.sotien;
    } while (stk.sotien <= 0);
}

// xuất thông tin sổ tiết kiệm
void xuatSoTietKiem(const SoTietKiem &stk) {
    cout << stk.maso << " | " << stk.loaitietkiem << " | " << stk.hoten 
         << " | " << stk.cmnd << " | " << stk.ngaymoso.ngay << "/" << stk.ngaymoso.thang << "/" << stk.ngaymoso.nam 
         << " | " << fixed << setprecision(2) << stk.sotien << " VND" << endl;
}

// tính lãi suất
double tinhLaiSuat(const SoTietKiem &stk, double laiSuat, int soThang) {
    if (stk.loaitietkiem == "nganhan" && soThang <= 6)
        return stk.sotien * laiSuat * soThang / 12;
    if (stk.loaitietkiem == "daihan" && soThang > 6)
        return stk.sotien * (laiSuat + 0.02) * soThang / 12;
    return stk.sotien * 0.005 * soThang / 12;  // Lãi suất 0.5%/năm nếu rút trước hạn
}

// Chức năng rút tiền
void rutTien(SoTietKiem &stk) {
    double soTienRut;
    cout << "Nhap so tien muon rut: ";
    cin >> soTienRut;

    if (soTienRut > stk.sotien) {
        cout << "Khong du so du!\n";
        return;
    }

    stk.sotien -= soTienRut;
    cout << "Rut thanh cong! So du con lai: " << stk.sotien << " VND\n";
}

// tìm kiếm theo mã sổ hoặc CMND
void timKiem(const vector<SoTietKiem>& ds, const string &tukhoa) {
    for (const auto &stk : ds) {
        if (stk.maso == tukhoa || to_string(stk.cmnd) == tukhoa) {
            xuatSoTietKiem(stk);
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

// Liệt kê sổ tiết kiệm mở trong khoảng thời gian
void lietKeTheoThoiGian(const vector<SoTietKiem>& ds, const Date &bd, const Date &kt) {
    for (const auto &stk : ds) {
        if ((stk.ngaymoso.nam > bd.nam || (stk.ngaymoso.nam == bd.nam && stk.ngaymoso.thang > bd.thang) || 
             (stk.ngaymoso.nam == bd.nam && stk.ngaymoso.thang == bd.thang && stk.ngaymoso.ngay >= bd.ngay)) &&
            (stk.ngaymoso.nam < kt.nam || (stk.ngaymoso.nam == kt.nam && stk.ngaymoso.thang < kt.thang) ||
             (stk.ngaymoso.nam == kt.nam && stk.ngaymoso.thang == kt.thang && stk.ngaymoso.ngay <= kt.ngay))) {
            xuatSoTietKiem(stk);
        }
    }
}

// Sắp xếp giảm dần
bool compareTien(const SoTietKiem &a, const SoTietKiem &b) {
    return a.sotien > b.sotien;
}

// Sắp xếp  tăng dần
bool compareNgay(const SoTietKiem &a, const SoTietKiem &b) {
    return tie(a.ngaymoso.nam, a.ngaymoso.thang, a.ngaymoso.ngay) < tie(b.ngaymoso.nam, b.ngaymoso.thang, b.ngaymoso.ngay);
}

int main() {
    vector<SoTietKiem> ds;
    int n;
    cout << "Nhap so luong so tiet kiem: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        SoTietKiem stk;
        nhapSoTietKiem(stk);
        ds.push_back(stk);
    }

    sort(ds.begin(), ds.end(), compareTien);
    cout << "\nDanh sach sau khi sap xep theo so tien:\n";
    for (const auto &stk : ds) xuatSoTietKiem(stk);

    return 0;
}
