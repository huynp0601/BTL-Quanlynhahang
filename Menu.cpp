#include <iostream>
#include <string>
using namespace std;

struct Menu {
    string ten;   
    double gia;   
};

class ThucDon {
private:
    Menu* thucDon;
    int soLuong;      
    int tongMon;      
    
public:
    ThucDon() {
        tongMon = 10; 
        thucDon = new Menu[tongMon];
        soLuong = 0;
        cout << "Nha hang hom nay co the lam " << tongMon <<" mon an:"<< endl;
    }

    ~ThucDon() {
        delete[] thucDon;
    }

    void themMonAn() {
        cin.ignore();
        cout << "Nhap ten mon an: ";
        getline(cin, thucDon[soLuong].ten);
        cout << "Nhap gia mon an: ";
        cin >> thucDon[soLuong].gia;
        cout << "Da them mon: " << thucDon[soLuong].ten << " voi gia: " << thucDon[soLuong].gia << " VND" << endl;
        soLuong++;
        /*if (soLuong >= tongMon) {
            cout << "So luong mon an da dat toi da. Ban khong the them mon nua." << endl;
            return;
        }*/
    }

    void xoaMonAn(int chiSo) {
        if (chiSo >= 0 && chiSo < soLuong) {
            cout << "Da xoa mon an: " << thucDon[chiSo].ten << endl;
            for (int i = chiSo; i < soLuong - 1; i++) {
                thucDon[i] = thucDon[i + 1];
            }
            soLuong--;
        } else {
            cout << "Chi so mon khong hop le" << endl;
        }
    }

    void xemThucDon() {
        cout << "\nCac mon trong thuc don:" << endl;
        for (int i = 0; i < soLuong; i++) {
            cout << i + 1 << ". " << thucDon[i].ten << " - " << thucDon[i].gia << " VND" << endl;
        }
        if (soLuong == 0) {
            cout << "Thuc don hien tai dang trong." << endl;
        }
    }
};

int main() {
    ThucDon thucDon1;
    int luaChon, chiSo;
    while (true) {
        cout << "\nTuy chon:\n";
        cout << "1. Them mon an\n";
        cout << "2. Xoa mon an theo thu tu(chi so):\n";
        cout << "3. Xem menu:\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                thucDon1.themMonAn();
                break;
            case 2:
                cout << "Nhap mon an muon xoa: ";
                cin >> chiSo;
                thucDon1.xoaMonAn(chiSo - 1); 
                break;
            case 3:
                thucDon1.xemThucDon();
                break;
            case 4:
                cout << "Thoat" << endl;
                return 0;
            default:
                cout << "Lua chon khong hop le. Chon lai:" << endl;
        }
    }
}

