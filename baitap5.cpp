#include <iostream>
using namespace std;

struct datetime{
    int ngay;
    int thang;
    int nam;
};

void nhap(datetime &date){
    cin>> date.nam;
    do cin>>date.thang;
    while (date.thang>12||date.thang<1);
    switch(date.thang){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    {
        do cin>>date.ngay;
        while (date.ngay>31||date.ngay<1);
        break;
    }
    case 4: case 6: case 9: case 11:
    {
        do cin>> date.ngay;
        while(date.ngay>30||date.ngay<1);
        break;
    }
    case 2:
    {
        if (date.nam%4==0){
            do cin>>date.ngay;
            while (date.ngay>29||date.ngay<1);
        }
        else do cin >> date.ngay;
        while (date.ngay>28||date.ngay<1);
    }
    }
}

datetime tomorrow(datetime date) {
    switch (date.thang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            if (date.ngay != 31) {
                date.ngay++;
            } else {
                date.ngay = 1;
                if (date.thang != 12) {
                    date.thang++;
                } else {
                    date.thang = 1;
                    date.nam++;
                }
            }
            break;

        case 4: case 6: case 9: case 11: 
            if (date.ngay != 30) {
                date.ngay++;
            } else {
                date.ngay = 1;
                date.thang++;
            }
            break;

        case 2: 
            if ((date.nam % 4 == 0 && date.nam % 100 != 0) || (date.nam % 400 == 0)) {
                if (date.ngay != 29) {
                    date.ngay++;
                } else {
                    date.ngay = 1;
                    date.thang++;
                }
            } else {
                if (date.ngay != 28) {
                    date.ngay++;
                } else {
                    date.ngay = 1;
                    date.thang++;
                }
            }
            break;
    }
    return date;
}

datetime yesterday(datetime date) {
    switch (date.thang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            if (date.ngay != 1) {
                date.ngay--;
            } else {
                date.ngay = 31;
                if (date.thang != 1) {
                    date.thang--;
                } else {
                    date.thang = 12;
                    date.nam--;
                }
            }
            break;

        case 4: case 6: case 9: case 11: 
            if (date.ngay != 1) {
                date.ngay--;
            } else {
                date.ngay = 30;
                date.thang--;
            }
            break;

        case 2: 
            if ((date.nam % 4 == 0 && date.nam % 100 != 0) || (date.nam % 400 == 0)) {
                if (date.ngay != 1) {
                    date.ngay--;
                } else {
                    date.ngay = 29;
                    date.thang--;
                }
            } else {
                if (date.ngay != 1) {
                    date.ngay--;
                } else {
                    date.ngay = 28;
                    date.thang--;
                }
            }
            break;
    }
    return date;
}

int count(datetime date){
    int dem=date.ngay;
    for (int i=1; i<date.thang; i++){
    switch (i){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
        dem+= 31;
        break;
        case 4: case 6: case 9: case 11: 
        dem+=30;
        break;
        case 2: 
        if ((date.nam % 4 == 0 && date.nam % 100 != 0) || (date.nam % 400 == 0)) {
            dem+=29;
        } else {
            dem+=28;
        }
        break;
    }
    }
    return dem;
}

int main(){
    datetime date;
    nhap(date);
    datetime Y=yesterday(date);
    cout<<Y.ngay<<" / "<<Y.thang<<" / "<<Y.nam<<endl;
    datetime T=tomorrow(date);
    cout<<T.ngay<<" / "<<T.thang<<" / "<<T.nam<<endl;
    int dem=count(date);
    cout << "ngay thu "<<dem<<" trong nam";
    return 0;

}