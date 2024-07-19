#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
using namespace std;
//Khai bao cac hang so
const int MAX_MONAN = 100;
const int MAXX=1e9+7;
class Menu { //Dinh nghia lop menu
private:
    struct MonAn { //Thong tin mon an
        string ten;
        long long gia;
    };
    MonAn danhSachMonAn[MAX_MONAN];
    int soLuongMonAn;

public:
     Menu() : soLuongMonAn(0) {} //Ham tao menu

    void themMon() { // Ham them mon an vao menu(Ham set)
        if (soLuongMonAn < MAX_MONAN) {
            MonAn mon;
            cout << "Nhap ten mon an: ";
            cin.ignore();
            getline(cin, mon.ten);
            cout << "Nhap gia tien: ";
            cin >> mon.gia;
            danhSachMonAn[soLuongMonAn++] = mon;
            cout << "Mon an da duoc them thanh cong!\n";
        } else {
            cout << "Menu da day, khong the them mon an moi!\n";
        }
    }
	void displayMenu() const { //Ham hien thi menu
        cout << "+----------------------------+------------+\n";
        cout << "| Ten mon an                 | Gia tien   |\n";
        cout << "+----------------------------+------------+\n";
        for (int i = 0; i < soLuongMonAn; ++i) {
            cout << "| " << setw(27) << left << danhSachMonAn[i].ten << "| " << setw(10) << right << danhSachMonAn[i].gia << " |\n";
        	cout << "+----------------------------+------------+\n";	
		}
        
    }

    void xoaMon() { //Ham xoa mon khoi menu
        cout << "                  MENU                     \n";
        displayMenu();
        string ten;
        bool timThay = false;

        cout << "Nhap ten mon an can xoa: ";
        cin.ignore();
        getline(cin, ten);

        for (int i = 0; i < soLuongMonAn; ++i) {
            if (danhSachMonAn[i].ten == ten) {
                for (int j = i; j < soLuongMonAn - 1; ++j) {
                    danhSachMonAn[j] = danhSachMonAn[j + 1];
                }
                --soLuongMonAn;
                cout << "Mon an da duoc xoa thanh cong!\n";
                timThay = true;
                break;
            }
        }

        if (!timThay) {
            cout << "Khong tim thay mon an trong menu! Vui long thu lai.\n";
        }
    }
	
	string laygiamon(const string &a) const { //Ham lay gia mon an tu ten mon(ham get)
        for (int i = 0; i < soLuongMonAn; ++i) {
            if (danhSachMonAn[i].ten == a) {
                return to_string(danhSachMonAn[i].gia);
            }
        }
        return "0";
    }

};
class HoaDon { //Lop quan li hoa don
private:
    vector<vector<pair<string, long long>>> hoadon; // Vector chua cac hoa don, moi hoa don la mot cap: ten mon, gia
    Menu& me;
public:
    HoaDon(Menu &menu) : me(menu) {} // ke thua, da hinh

    void ordermon() {
        vector<pair<string, long long>> donHang; // Vector chua cac don hang, moi don hang la mot cap: ten mon, gia
        cout << "Hoa don so " << hoadon.size() + 1 << ":\n";
        me.displayMenu();
        cout << "So luong mon an ban muon order: ";
        long long somonan;
        cin >> somonan;
        cin.ignore();

        long long tongGiaTri = 0;
        for (long long i = 0; i < somonan; i++) {
            cout << "Mon an thu " << i + 1 << ": ";
            string a;
            getline(cin, a);
            long long gia = stoll(me.laygiamon(a));
            if (gia > 0) {
                donHang.push_back({a, gia});
                tongGiaTri += gia;
            } else {
                cout << "Mon an khong ton tai. Vui long thu lai.\n";
                i--; // Nhap lai mon an
            }
        }

        hoadon.push_back(donHang);
        cout << "Tong gia tri hoa don: " << tongGiaTri << endl;
        cout << "Hoa don so " << hoadon.size() << " da order thanh cong!!!\n";
    }

    void orderthem(long long u) { // Ham dat them mon vao hoa don da co
        if (u < 1 || u > hoadon.size()) {
            cout << "Hoa don khong ton tai. Vui long thu lai.\n";
            return;
        }

        cout << "Hoa don so " << u << ":\n";
        me.displayMenu();
        cout << "So luong mon an ban muon order them: ";
        long long somonanthem;
        cin >> somonanthem;
        cin.ignore();

        long long tongGiaTri = 0;
        for (long long i = 0; i < somonanthem; i++) {
            cout << "Mon an thu " << i + 1 << ": ";
            string a;
            getline(cin, a);
            long long gia = stoll(me.laygiamon(a));
            if (gia > 0) {
                hoadon[u - 1].push_back({a, gia});
                tongGiaTri += gia;
            } else {
                cout << "Mon an khong ton tai. Vui long thu lai.\n";
                i--; // nhap lai mon an
            }
        }

        cout << "Hoa don so " << u << " da order them thanh cong!!!\n";
    }

    void xemhoadon() { // Ham hien thi hoa don
        cout << "Ma hoa don lon nhat hien tai la: " << hoadon.size() << endl;
        cout << "Nhap ma hoa don ban muon xem: ";
        long long n;
        cin >> n;
        if (n < 1 || n > hoadon.size()) {
            cout << "Ma hoa don khong hop le! Vui long thu lai!!!\n";
            return;
        }

        cout << "Hoa don so " << n << ":\n";
        long long tongGiaTri = 0;
        for (const auto& item : hoadon[n - 1]) {
            cout << item.first << "    " << item.second << endl;
            tongGiaTri += item.second;
        }
        cout << "----------------------\n";
        cout << "TONG HOA DON SO " << n << ": " << tongGiaTri << endl;
    }

    double tinhTongDoanhThu() const {
        double tongThu = 0;
        for (const auto& donHang : hoadon) {
            for (const auto& item : donHang) {
                tongThu += item.second;
            }
        }
        return tongThu;
    }
};

class danhgia { //Lop de danh gia chat luong mon an
private:
    string ten;
    string SDT;
    double diem;
    int dem ;
    int sonhanxet ;
    double tong ;
    string nhanxet[100];
    string sdt[100];
    string kh[100];

public:
	danhgia() : dem(0), sonhanxet(0), tong(0) {} //Ham tao
    void nhap() { //Ham de khach hang nhap thong tin
        cout << "Nhap thong tin quy khach: " << endl;
        cout << "Ten: ";
        cin.ignore(); 
        getline(cin, ten);
        cout << "SDT: ";
        getline(cin, SDT);
        cout << "Quy khach cham diem ve chat luong mon an: ";
        cin >> diem;
        cin.ignore(); 
        dem++;
        tong += diem;
        if (diem <= 5) {
            cout << "Quy khach co the nhan xet de nha hang co the khac phuc: ";
            getline(cin, nhanxet[sonhanxet]);
            sdt[sonhanxet] = SDT;
            kh[sonhanxet]=ten;
            sonhanxet++;
            cout << "Cam on quy khach da danh thoi gian de danh gia!!!" << endl;
        } else {
            cout << "Cam on quy khach da danh thoi gian de danh gia!!!" << endl;
        }
    }

    void hienthi() { //Ham hien thi danh gia cua khach
		for (int i = 0; i < sonhanxet; i++) {
            cout << "+---------------------------------------------+" << endl;
            cout << "| Ten khach hang: " << setw(28) << left << kh[i] << "|" << endl;
			cout << "| SDT: " << setw(39) << left << sdt[i] << "|" << endl;
            cout << "| Nhan xet: " << setw(34) << left << nhanxet[i] << "|" << endl;
        }
        cout << "+---------------------------------------------+" << endl;
        
    }
    void diemTB(){ //Ham tinh diem trung binh
    	double a=(tong/dem);
    	cout<< "Diem trung binh hien tai cua cua hang: "<<fixed<< setprecision(2)<<a<< endl;
    	
	}
};
class admin { //Lop de admin quan li
private:
	string const username = "1"; //Ten dang nhap mac dinh
	string const password = "1"; //Mat khau mac dinh
public:
	admin(){
	}
	string getUsername() const { //Ham lay ten dang nhap (Ham get)
		return username;
	}
	string getPassword() const	{ //Ham lay mat khau (Ham get)
		return password;
	}
};
class Ban { //Lop de tao ban
private:
    int maBan;
    bool trangThai;

public:
    Ban() { //Ham tao ban (Ham tao mac dinh)
        maBan = 0;
        trangThai = true;
    }

    Ban(int maBan) { //Ham tao ban(Ham tao dung tham so)
        this->maBan = maBan;
        this->trangThai = true;
    }

    int getMaBan() const { //Ham get ma ban
        return maBan;
    }

    void setTrangThai(bool trangThai) { //Ham set trang thai ban
        this->trangThai = trangThai;
    }

    bool getTrangThai() const { //Ham get trang thai ban
        return trangThai;
    }
};

class QuanLyBan { //Lop quan ly ban
private:
    Ban danhSachBan[10]; 
    int soLuongBan = 10; 

public:
    QuanLyBan() { 
        for (int i = 0; i < soLuongBan; ++i) {
            danhSachBan[i] = Ban(i + 1); 
        }
    }

    void hienThiDanhSachBan() { //Ham hien thi danh sach ban
        cout << "Danh sach ban:" << endl;
        for (int i = 0; i < soLuongBan; i++) {
            cout << " - Ban " << danhSachBan[i].getMaBan() << ": " 
                 << (danhSachBan[i].getTrangThai() ? "Trong" : "Co nguoi") << endl;
        }
    }


	void datBan() { //Ham dat ban (Ham set)
            int soLuongDat;
            cout << "Nhap so luong ban muon dat: ";
            cin >> soLuongDat;

            if (soLuongDat < 1 || soLuongDat > soLuongBan) {
                cout << "So luong ban khong hop le. Vui long thu lai!" << endl;
                return;
            }

            for (int i = 0; i < soLuongDat; ++i) {
                int maBan;
                cout << "Nhap ma ban thu " << (i + 1) << " muon dat: ";
                cin >> maBan;

                if (maBan < 1 || maBan > soLuongBan) {
                    cout << "Ma ban khong hop le. Vui long thu lai!" << endl;
                    --i;
                    continue;
                }

                if (danhSachBan[maBan - 1].getTrangThai()) {
                    danhSachBan[maBan - 1].setTrangThai(false);
                    cout << "Dat ban " << maBan << " thanh cong!" << endl;
                } else {
                    cout << "Ban " << maBan << " dang co nguoi. Vui long chon ban khac!" << endl;
                    --i;
                }
            }
        }

    void huyDatBan() { //Ham huy dat ban
        cout << "Danh sach ban dang su dung:" << endl;
        for (int i = 0; i < soLuongBan; i++) {
			if (!danhSachBan[i].getTrangThai()) {
                cout << " - Ban " << danhSachBan[i].getMaBan() << endl;
            }
        }
		int maBanHuy; 
        
        cout << "Nhap ban muon huy: ";
        cin >> maBanHuy;

        if (maBanHuy < 1 || maBanHuy > soLuongBan) {
            cout << "Ma ban khong hop le!" << endl;
            return;
        }

        if (!danhSachBan[maBanHuy - 1].getTrangThai()) {
            danhSachBan[maBanHuy - 1].setTrangThai(true);
            cout << "Xoa ban " << maBanHuy << " thanh cong!" << endl;
        } 
		else {
            cout << "Ban " << maBanHuy << " dang trong!" << endl;
        }
    }
    void trangThaiBan() { //Ham hien thi trang thai ban
        cout << "Danh sach ban trong:" << endl;
        for (int i = 0; i < soLuongBan; i++) {
            if (danhSachBan[i].getTrangThai()) {
                cout << " - Ban " << danhSachBan[i].getMaBan() << endl;
            }
        }

        cout << "Danh sach ban dang su dung:" << endl;
        for (int i = 0; i < soLuongBan; i++) {
            if (!danhSachBan[i].getTrangThai()) {
                cout << " - Ban " << danhSachBan[i].getMaBan() << endl;
            }
        }
    }
    void bandangdung(){ //Ham hien thi ban dang dung
    	cout << "Danh sach ban dang su dung:" << endl;
        for (int i = 0; i < soLuongBan; i++) {
            if (!danhSachBan[i].getTrangThai()) {
                cout << " - Ban " << danhSachBan[i].getMaBan() << endl;
            }
        }
        
	}
	 bool checktrangthaiban(int n) { //Ham kiem tra trang thai ban
        return (n >= 1 && n <= soLuongBan && !danhSachBan[n - 1].getTrangThai());
    }
	int laysoluongban(){ //Ham lay so luong ban
		return soLuongBan;
	}
};
class date{ //Lop ngay
private:
	int day,month,year;
public:
	date(int d = 0, int m = 0, int y = 0) { //Ham tao co tham so
		day = d;
		month = m;
		year = y;
	}
	void setDay(int d) { //Ham set ngay
		day = d;
	}
	void setMonth(int m) { //Ham set thang
		month = m;
	}
	void setYear(int y) { //Ham set nam
		year = y;
	}
	int getDay() const { //Ham get ngay
		return day;
	}
	int getMonth() const { //Ham get thang
		return month;
	}
	int getYear() const { //Ham get nam
		return year;
	}
};

class nhahang { //Lop nha hang
private:
	admin chu;
	date ngay;
	danhgia dg;
	Menu &me; //Tham chieu den Menu de thao tac voi menu mon an
	HoaDon &hd;
public:
	nhahang(Menu &menu, HoaDon &hoaDon) : me(menu), hd(hoaDon) {}// Ham khoi tao, ke thua, da hinh
	string getAdminUsername() const {
	return chu.getUsername();
	}
	string getAdminPassword() const {
	return chu.getPassword();
	}
	void setDate() { //Ham set ngay
		int day, month, year;
		cout << " \nNhap ngay: ";
		cin >> day;
		ngay.setDay(day);
		cout << " \nNhap thang: ";
		cin >> month;
		ngay.setMonth(month);
		cout << " \nNhap nam: ";
		cin >> year;
		ngay.setYear(year);
	}
	void nhapDanhGia() { //Ham nhap danh gia
        dg.nhap();
    }

    void hienThiDanhGia() { //Ham hien thi danh gia
        dg.hienthi();
    }

    void hienThiDiemTB() { //Ham hien thi diem TB
        dg.diemTB();
    }
    void themmonan(){ //Ham them mon an
    	me.themMon();
	}
	void xoamonan(){ //Ham xoa mon an
		me.xoaMon();
	}
	void hienthimenu(){ //Ham hien thi menu
		me.displayMenu();
	}
	void tinhTongDoanhThu() const {
        cout << "Tong Doanh Thu: " << hd.tinhTongDoanhThu() << " VND" << endl;
    }
};
//Khai bao cac ham, mo ta cac ham o phia duoi
void adminMenu(nhahang &phu, QuanLyBan &khach, int tt, HoaDon& hd);
void adminLogin(nhahang &phu2, QuanLyBan &khach, int tt2, HoaDon& hd);
void mainMenu(nhahang &phu, QuanLyBan& phu2, int tt, HoaDon &hd);
void userMenu(nhahang &nhom8, QuanLyBan &phu2, int tt, HoaDon &hd);
void orderMenu(nhahang &phu, QuanLyBan &phu2, int tt, HoaDon &hd);

////Ham quan li chuc nang cua admin
void adminMenu(nhahang &phu, QuanLyBan &khach, int tt,HoaDon &hd) {
	int adminOption = 0;

	cout << " ===============================" << endl;
	cout << " |                             |" << endl;
    cout << " |  Lua chon muc muon truy cap |\n";
    cout << " |      1) Xem danh gia        |\n";
    cout << " |      2) Xem doanh thu       |\n";
    cout << " |      3) Them mon vao Menu   |\n";
    cout << " |      4) Xoa mon khoi Menu   |\n";
	cout << " |      5) Thoat               |\n";
	cout << " |                             |" << endl;
	cout << " ===============================" << endl;
	cin >> adminOption;
	system("cls");
	switch (adminOption)
	{
	case 1:
		phu.hienThiDiemTB();
        phu.hienThiDanhGia();
        _getch();
		adminMenu(phu, khach, tt, hd);
		break;
	case 2:
		phu.tinhTongDoanhThu();
		_getch();
		adminMenu(phu, khach, tt, hd);
		break;
	case 3:
		phu.themmonan();
		_getch();
		system("cls");
		adminMenu(phu,khach, tt, hd);
		break;
	case 4:
		phu.xoamonan();
		_getch();
		system("cls");
		adminMenu(phu,khach,tt, hd);
		break;
	case 5:
		mainMenu(phu, khach, tt, hd);
		break;
	
	default:
		cout << " Vui long chon lai!!" << endl;
		adminMenu(phu, khach, tt, hd);
		break;
	};
}
////Ham kiem tra admin dang nhap
void adminLogin(nhahang &phu2, QuanLyBan& khach, int tt2,HoaDon &hd) {
    string username, password;
    cout << " ===============================\n";
    cout << "                              \n";
    cout << "         - Dang nhap -        \n";
    cout << "        Ten dang nhap: "; cin >> username;
    cout << "        Mat khau: "; cin >> password;
    cout << "                              \n";
    cout << "                              \n";
    cout << " ===============================\n";
    if ((phu2.getAdminPassword() == password) && (phu2.getAdminUsername() == username))
	{
		system("cls");
		int adminOption = 0;
		cout << " ===============================" << endl;
		cout << " |                             |" << endl;
        cout << " |  Lua chon muc muon truy cap |\n";
        cout << " |      1) Xem danh gia        |\n";
        cout << " |      2) Xem doanh thu       |\n";
        cout << " |      3) Them mon vao Menu   |\n";
        cout << " |      4) Xoa mon khoi Menu   |\n";
		cout << " |      5) Thoat               |\n";
		cout << " |                             |" << endl;
		cout << " ===============================" << endl;
		cin >> adminOption;
		system("cls");
		switch (adminOption)
			{
			case 1:
				phu2.hienThiDiemTB();
				phu2.hienThiDanhGia();
				_getch();
				system("cls");
				adminMenu(phu2,khach, tt2, hd);
				break;
				
			case 2:				
				phu2.tinhTongDoanhThu();
				_getch();
				system("cls");
				adminMenu(phu2, khach,tt2, hd);
				break;
			case 3:
				phu2.themmonan();
				_getch();
				system("cls");
				adminMenu(phu2,khach, tt2, hd);
				break;
			case 4:
				phu2.xoamonan();
				_getch();
				system("cls");
				adminMenu(phu2,khach, tt2, hd);
				break;
			case 5:				
				mainMenu(phu2, khach, tt2, hd);
				break;
			
			default:
				cout << " Vui long chon lai!" << endl;
				adminMenu(phu2, khach, tt2, hd);
				break;
			}
		}
		else {
			cout << " Thong tin dang nhap khong hop le, an phim bat ky de thu lai!" << endl;
			_getch();
			system("cls");
			adminLogin(phu2, khach, tt2, hd);
		}    
}
//Ham hien thi va quan li menu chinh
void mainMenu(nhahang &phu, QuanLyBan &phu2, int tt,HoaDon &hd) {
	
	int loginOption = 0;
	int userOption = 0;
	int orderSlot = tt;

	cout << " ===============================" << endl;
	cout << " |                             |" << endl;
	cout << " |   Truy cap voi tu cach:     |\n";
    cout << " |         1) Chu nha hang     |\n";
    cout << " |         2) Khach            |\n";
    cout << " |         3) Thoat ra         |\n";
	cout << " |                             |" << endl;
	cout << " ===============================" << endl;
	cin >> loginOption;
	system("cls");

	string username, password;

	switch (loginOption) {
	case 1:
		cout << " ===============================" << endl;
		cout << "                              " << endl;
	  	cout << "         - Dang nhap -        \n";
    	cout << "        Ten dang nhap: "; cin >> username;
    	cout << "        Mat khau: "; cin >> password;
		cout << "                              " << endl;
		cout << "                              " << endl;
		cout << " ===============================" << endl;
		if ((phu.getAdminPassword() == password) && (phu.getAdminUsername() == username))
		{
			system("cls");
            adminMenu(phu, phu2, tt, hd);
		}
		else
		{
			cout << " Thong tin dang nhap khong hop le, an phim bat ky de thu lai thu lai!!" << endl;
			_getch();
			system("cls");
			adminLogin(phu,phu2, orderSlot, hd);
		}
	case 2:
		userMenu(phu,phu2,tt, hd);
		break;
		
	case 3:
		cout << " ===============================" << endl;
		cout << " |                             |" << endl;
		cout << " |                             |" << endl;
		cout << " |          Cam on  !!!        |" << endl;
		cout << " |                             |" << endl;
		cout << " |                             |" << endl;
		cout << " ===============================" << endl;
		break;
	default:
		cout << "Lua chon khong hop le! Vui long chon lai\n";
		_getch();
		mainMenu(phu, phu2, tt , hd);
		break;
	};
}
//Ham de nguoi dung quan li menu
void userMenu(nhahang &nhom8,QuanLyBan &phu, int tt,HoaDon& hd){
	cout<<	" ===============================" << endl;
	cout<<	" |                             |" << endl;
	cout<<	" | Lua chon thao tac ban muon: |" << endl;
	cout<<	" | 1) Dat ban                  |" << endl;
	cout<<	" | 2) Menu                     |" << endl;
	cout<<	" | 3) Order                    |" << endl;
	cout<<	" | 4) Xem hoa don              |" << endl;
	cout<<	" | 5) Xoa ban                  |" << endl;
	cout<<	" | 6) Danh gia chat luong      |" << endl;
	cout<<	" | 7) Quay lai                 |" << endl;
	cout<<	" | 8) Trang thai ban an        |" << endl;
	cout<<	" |                             |" << endl;
	cout<<	" ===============================" << endl;
	int userOption=0;
	cin >> userOption;
	system("cls");
	switch(userOption){
	case 1:
		phu.hienThiDanhSachBan();
		phu.datBan();
		_getch();
		system("cls");
		userMenu(nhom8,phu,tt,hd);
		break;
	case 2:	
		nhom8.hienthimenu();
		_getch();
		system("cls");
		userMenu(nhom8,phu,tt,hd);
		break;
	case 3:
		orderMenu(nhom8,phu,tt,hd);
		_getch();
		system("cls");
		userMenu(nhom8, phu,tt,hd);
		break;
	case 4:
		hd.xemhoadon();
		_getch();
		system("cls");
		userMenu(nhom8,phu, tt, hd);
		break;
	case 5:
		phu.huyDatBan();
		_getch();
		system("cls");
		userMenu(nhom8,phu,tt,hd);				
		break;
	case 6:
		nhom8.nhapDanhGia();
		_getch();
		system("cls");
		userMenu(nhom8,phu,tt,hd);
		break;
	case 7:
		mainMenu(nhom8,phu,tt, hd);
		break;
	case 8:
		phu.trangThaiBan();
		_getch();
		system("cls");
		userMenu(nhom8,phu,tt,hd);
		break;
	 default:
        cout << "Lua chon khong hop le! Vui long chon lai\n";
        _getch();
        userMenu(nhom8, phu, tt, hd);
        break;
    }
	
}
//Ham de quan li chuc nang order cua nguoi dung
void orderMenu(nhahang &phu, QuanLyBan &khach, int tt, HoaDon &hd){
	cout << " ===============================" << endl;
	cout << " |                             |" << endl;
	cout << " | 1) Order mon an             |" << endl;
	cout << " | 2) Order them               |" << endl;
	cout << " | 3) Hien thi hoa don         |" << endl;
	cout << " | 4) Thoat                    |" << endl;
	cout << " |                             |" << endl;
	cout << " ===============================" << endl;
	int optionorder;
	cin>> optionorder;
	system("cls");
	switch(optionorder){
		case 1:
			khach.bandangdung();
			cout<<"Nhap ma ban ban muon ngoi:  ";
			int n;
			cin>> n;
			if(n<1||n>khach.laysoluongban()){
				cout<<"Ma ban khong hop le! Vui long thu lai"<< endl;
				return;
			}
			if(!khach.checktrangthaiban(n)){
				cout<<"Ban nay dang trong! Xin quy khach vui long quay lai dat ban truoc!!!";
				userMenu(phu,khach,tt,hd);
			}
			else{
				hd.ordermon();
			}
           
			_getch();
			system("cls");
			orderMenu(phu,khach,tt,hd);
			break;
		case 2:			
			cout<<"Nhap ma hoa don ban muon order them: ";
			int z;
			cin>>z;
			hd.orderthem(z);
			_getch();
			system("cls");
			orderMenu(phu,khach,tt,hd);
			break;
		case 3:			
			hd.xemhoadon();
			_getch();
			system("cls");
			orderMenu(phu,khach,tt,hd);
			break;
		case 4:
			userMenu(phu,khach,tt, hd);
			break;
		default:
          	cout << "Lua chon khong hop le! Vui long chon lai\n";
			orderMenu(phu,khach,tt,hd);
          	break;
	}
	
}
	
int main() {
	Menu menu;
	QuanLyBan khach;	
    HoaDon hd(menu);
    nhahang nhom8(menu,hd);
    int dangnhap, tt = 0;
    cout << "Nhap ngay hom nay\n";
    nhom8.setDate();
    system("cls");
    cout << " ===============================\n";
    cout << " |                             |\n";
    cout << " |                             |\n";
    cout << " |          He thong           |\n";
    cout << " |      Quan ly nha hang       |\n";
    cout << " |                             |\n";
    cout << " |                             |\n";
    cout << " ===============================\n";
    cout << "An phim bat ky de tiep tuc...\n";
    _getch();
    system("cls");
    cout << " ===============================\n";
    cout << " |                             |\n";
    cout << " |   Truy cap voi tu cach:     |\n";
    cout << " |         1) Chu nha hang     |\n";
    cout << " |         2) Khach            |\n";
    cout << " |         3) Thoat ra         |\n";
    cout << " |                             |\n";
    cout << " ===============================\n";
    cin >> dangnhap;
    system("cls");
	string username, password;
    switch (dangnhap) {
        case 1:
	        adminLogin(nhom8,khach,tt,hd);
	        break;    
        case 2:
	        userMenu(nhom8,khach,tt,hd);
	        break;
	    case 3:
	    	return 0;
					    
	};
	return 0;
}
