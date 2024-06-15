#include<bits/stdc++.h >
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
using namespace std;
const int MAX_MONAN = 100;
const int MAXX=1e9+7;
class Menu {
private:
    struct MonAn {
        string ten;
        long long gia;
    };
    MonAn danhSachMonAn[MAX_MONAN];
    int soLuongMonAn;

public:
     Menu() : soLuongMonAn(0) {}

    void themMon() {
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
	void displayMenu() const {
        cout << "+----------------------------+------------+\n";
        cout << "| Ten mon an                 | Gia tien   |\n";
        cout << "+----------------------------+------------+\n";
        for (int i = 0; i < soLuongMonAn; ++i) {
            cout << "| " << setw(27) << left << danhSachMonAn[i].ten << "| " << setw(10) << right << danhSachMonAn[i].gia << " |\n";
        	cout << "+----------------------------+------------+\n";	
		}
        
    }

    void xoaMon() {
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
	
	string laygiamon(const string &a) const {
        for (int i = 0; i < soLuongMonAn; ++i) {
            if (danhSachMonAn[i].ten == a) {
                return to_string(danhSachMonAn[i].gia);
            }
        }
        return "0";
    }

};
class HoaDon{
	private:
		
		vector<vector<pair<string, long long>>> hoadon;
    	Menu& me;
	public:
		HoaDon(Menu &menu) : me(menu) {}
		
		void odermon() {
        	vector<pair<string, long long>> donHang;
        	cout << "Hoa don so " << hoadon.size() + 1 << ":\n";
        	me.displayMenu();
        	cout << "So luong mon an ban muon oder: ";
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
                	i--; 
            	}
        	}

        	hoadon.push_back(donHang);
        	cout << "Tong gia tri hoa don: " << tongGiaTri << endl;
        	cout << "Hoa don so " << hoadon.size() << " da oder thanh cong!!!\n";
    	}

    	void oderthem(long long u) {
       		if (u < 1 || u > hoadon.size()) {
            	cout << "Hoa don khong ton tai. Vui long thu lai.\n";
            	return;
        	}

        	cout << "Hoa don so " << u << ":\n";
        	me.displayMenu();
        	cout << "So luong mon an ban muon oder them: ";
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
                	i--; // nhập lại món ăn
            	}
        	}

        	cout << "Hoa don so " << u << " da oder them thanh cong!!!\n";
    }

    	void xemhoadon() {
    		cout<<"Ma hoa don lon nhat hien tai la: "<< hoadon.size()<< endl;
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
};
class danhgia {
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
	danhgia() : dem(0), sonhanxet(0), tong(0) {}
    void nhap() {
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

    void hienthi() {
		for (int i = 0; i < sonhanxet; i++) {
            cout << "+---------------------------------------------+" << endl;
            cout << "| Ten khach hang: " << setw(28) << left << kh[i] << "|" << endl;
			cout << "| SDT: " << setw(39) << left << sdt[i] << "|" << endl;
            cout << "| Nhan xet: " << setw(34) << left << nhanxet[i] << "|" << endl;
        }
        cout << "+---------------------------------------------+" << endl;
        
    }
    void diemTB(){
    	double a=(tong/dem);
    	cout<< "Diem trung binh hien tai cua cua hang: "<<fixed<< setprecision(2)<<a<< endl;
    	
	}
};
class admin {
private:
	string const username = "1";
	string const password = "1";
public:
	admin(){
	}
	string getUsername() const {
		return username;
	}
	string getPassword() const	{
		return password;
	}
};
class Ban {
private:
    int maBan;
    bool trangThai;

public:
    Ban() {
        maBan = 0;
        trangThai = true;
    }

    Ban(int maBan) {
        this->maBan = maBan;
        this->trangThai = true;
    }

    int getMaBan() const {
        return maBan;
    }

    void setTrangThai(bool trangThai) {
        this->trangThai = trangThai;
    }

    bool getTrangThai() const {
        return trangThai;
    }
};

class QuanLyBan {
private:
    Ban danhSachBan[10]; 
    int soLuongBan = 10; 

public:
    QuanLyBan() {
        for (int i = 0; i < soLuongBan; ++i) {
            danhSachBan[i] = Ban(i + 1); 
        }
    }

    void hienThiDanhSachBan() {
        cout << "Danh sach ban:" << endl;
        for (int i = 0; i < soLuongBan; i++) {
            cout << " - Ban " << danhSachBan[i].getMaBan() << ": " 
                 << (danhSachBan[i].getTrangThai() ? "Trong" : "Co nguoi") << endl;
        }
    }


	void datBan() {
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

    void huyDatBan() {
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
    void trangThaiBan() {
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
    void bandangdung(){
    	cout << "Danh sach ban dang su dung:" << endl;
        for (int i = 0; i < soLuongBan; i++) {
            if (!danhSachBan[i].getTrangThai()) {
                cout << " - Ban " << danhSachBan[i].getMaBan() << endl;
            }
        }
        
	}
	 bool checktrangthaiban(int n) {
        return (n >= 1 && n <= soLuongBan && !danhSachBan[n - 1].getTrangThai());
    }
	int laysoluongban(){
		return soLuongBan;
	}
};
class date{
private:
	int day,month,year;
public:
	date(int d = 0, int m = 0, int y = 0) {
		day = d;
		month = m;
		year = y;
	}
	void setDay(int d) {
		day = d;
	}
	void setMonth(int m) {
		month = m;
	}
	void setYear(int y) {
		year = y;
	}
	int getDay() const {
		return day;
	}
	int getMonth() const {
		return month;
	}
	int getYear() const {
		return year;
	}
};

class nhahang {
private:
	admin chu;
	date ngay;
	danhgia dg;
	Menu &me;
	
public:
	nhahang(Menu &menu) : me(menu) {}
	string getAdminUsername() const {
	return chu.getUsername();
	}
	string getAdminPassword() const {
	return chu.getPassword();
	}
	void setDate() {
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
	void nhapDanhGia() {
        dg.nhap();
    }

    void hienThiDanhGia() {
        dg.hienthi();
    }

    void hienThiDiemTB() {
        dg.diemTB();
    }
    void themmonan(){
    	me.themMon();
	}
	void xoamonan(){
		me.xoaMon();
	}
	void hienthimenu(){
		me.displayMenu();
	}
	
};

void adminMenu(nhahang &phu, QuanLyBan &khach, int tt, HoaDon& hd);
void adminLogin(nhahang &phu2, QuanLyBan &khach, int tt2, HoaDon& hd);
void mainMenu(nhahang &phu, QuanLyBan& phu2, int tt, HoaDon &hd);
void userMenu(nhahang &nhom8, QuanLyBan &phu2, int tt, HoaDon &hd);
void oderMenu(nhahang &phu, QuanLyBan &phu2, int tt, HoaDon &hd);

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
//void userMenu(nhahang nhom8, QuanLyBan phu2, int tt2,HoaDon hd);
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
void userMenu(nhahang &nhom8,QuanLyBan &phu, int tt,HoaDon& hd){
	cout<<	" ===============================" << endl;
	cout<<	" |                             |" << endl;
	cout<<	" | Lua chon thao tac ban muon: |" << endl;
	cout<<	" | 1) Dat ban                  |" << endl;
	cout<<	" | 2) Menu                     |" << endl;
	cout<<	" | 3) Oder them                |" << endl;
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
		oderMenu(nhom8,phu,tt,hd);
		_getch();
		system("cls");
		userMenu(nhom8, phu,tt,hd);
		break;
	case 4:
		nhom8.xoamonan();
		_getch();
		system("cls");
		adminMenu(nhom8,phu, tt, hd);
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
void oderMenu(nhahang &phu, QuanLyBan &phu2, int tt, HoaDon &hd){
	cout << " ===============================" << endl;
	cout << " |                             |" << endl;
	cout << " | 1) Oder mon an              |" << endl;
	cout << " | 2) Oder them                |" << endl;
	cout << " | 3) Hien thi hoa don         |" << endl;
	cout << " | 4) Thoat                    |" << endl;
	cout << " |                             |" << endl;
	cout << " ===============================" << endl;
	int optionoder;
	cin>> optionoder;
	system("cls");
	switch(optionoder){
		case 1:
			phu2.bandangdung();
			cout<<"Nhap ma ban ban muon ngoi:  ";
			int n;
			cin>> n;
			if(n<1||n>phu2.laysoluongban()){
				cout<<"Ma ban khong hop le! Vui long thu lai"<< endl;
				return;
			}
			if(!phu2.checktrangthaiban(n)){
				cout<<"Ban nay dang trong! Xin quy khach vui long quay lai dat ban truoc!!!";
				userMenu(phu,phu2,tt,hd);
			}
			else{
				hd.odermon();
			}
           
			_getch();
			system("cls");
			oderMenu(phu,phu2,tt,hd);
			break;
		case 2:
			cout<<"Nhap ma hoa don ban muon oder them: ";
			int z;
			cin>>z;
			hd.oderthem(z);
			_getch();
			system("cls");
			oderMenu(phu,phu2,tt,hd);
			break;
		case 3:
			
			hd.xemhoadon();
			_getch();
			system("cls");
			oderMenu(phu,phu2,tt,hd);
			break;
		case 4:
			userMenu(phu,phu2,tt, hd);
			break;
		default:
          	cout << "Lua chon khong hop le! Vui long chon lai\n";
			oderMenu(phu,phu2,tt,hd);
          	break;
	}
	
}
	
int main() {
	Menu menu;
	nhahang nhom8(menu);
	QuanLyBan khach;
	
    HoaDon hd(menu);
    int dangnhap = 0, tt = 0;
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
        cout << " ===============================\n";
        cout << "                              \n";
        cout << "         - Dang nhap -        \n";
        cout << "        Ten dang nhap: "; cin >> username;
        cout << "        Mat khau: "; cin >> password;
        cout << "                              \n";
        cout << "                              \n";
        cout << " ===============================\n";
        if ((nhom8.getAdminPassword() == password) && (nhom8.getAdminUsername() == username))
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
			switch (adminOption) {
			case 1:
				nhom8.hienThiDiemTB();
				nhom8.hienThiDanhGia();
				_getch();
				system("cls");
				adminMenu(nhom8,khach, tt, hd);
				break;
			case 2:
				adminMenu(nhom8,khach, tt, hd);
				break;
			case 3:
				nhom8.themmonan();
				_getch();
				system("cls");
				adminMenu(nhom8,khach, tt, hd);
				break;
			case 4:
				nhom8.xoamonan();
				_getch();
				system("cls");
				adminMenu(nhom8,khach, tt, hd);
				break;
			case 5:
				mainMenu(nhom8,khach,tt, hd);
				break;
			
			default:
				cout << " Vui long chon lai!" << endl;
				adminMenu(nhom8,khach, tt, hd);
				break;
			}
		}
		else {
			cout << " Thong tin dang nhap khong hop le, an phim bat ky de thu lai!" << endl;
			_getch();
			system("cls");
			adminLogin(nhom8,khach, tt, hd);
		}    
        	break;    
        case 2:
        cout<<	" ===============================" << endl;
		cout<<	" |                             |" << endl;
		cout<<	" | Lua chon thao tac ban muon: |" << endl;
		cout<<	" | 1) Dat ban                  |" << endl;
		cout<<	" | 2) Menu                     |" << endl;
		cout<<	" | 3) Oder them                |" << endl;
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
				khach.hienThiDanhSachBan();
				khach.datBan();
				_getch();
				system("cls");
				userMenu(nhom8, khach,tt, hd);
				break;
			case 2:
				nhom8.hienthimenu();
				
					
				
				_getch();
				system("cls");
				userMenu(nhom8, khach,tt, hd);
				break;
			case 3:
				cout << " ===============================" << endl;
				cout << " |                             |" << endl;
				cout << " | 1) Oder mon an              |" << endl;
				cout << " | 2) Oder them                |" << endl;
				cout << " | 3) Hien thi hoa don         |" << endl;
				cout << " | 4) Thoat                    |" << endl;
				cout << " |                             |" << endl;
				cout << " ===============================" << endl;
				int optionoder;
				cin>> optionoder;
				system("cls");
				switch(optionoder){
					case 1:
						khach.bandangdung();
						cout<<"Nhap ma ban ban muon ngoi:  ";
						int n;
						cin>> n;
						if(n<1||n>khach.laysoluongban()){
							cout<<"Ma ban khong hop le! Vui long thu lai"<< endl;
							khach.bandangdung();
						}
						if(khach.checktrangthaiban(n)==false){
							cout<<"Ban nay dang trong! Xin quy khach vui long quay lai dat ban truoc!!!";
							oderMenu(nhom8,khach,tt,hd);
						}
						else{
							hd.odermon();
						}
						_getch();
						system("cls");
						oderMenu(nhom8,khach,tt,hd);
						break;
					case 2:
						cout<<"Nhap ma hoa don ban muon oder them: ";
						int z;
						cin>>z;
						hd.oderthem(z);
						_getch();
						system("cls");
						oderMenu(nhom8,khach,tt,hd);
						break;
					case 3:
						hd.xemhoadon();
						_getch();
						system("cls");
						oderMenu(nhom8,khach,tt,hd);
						break;
					case 4:
						userMenu(nhom8,khach,tt, hd);
						break;
					default:
            		cout << "Lua chon khong hop le! Vui long chon lai\n";
            		userMenu(nhom8,khach,tt, hd);
            		break;
				}
				_getch();
				system("cls");
				userMenu(nhom8, khach,tt, hd);
				break;
			case 4:
				hd.xemhoadon();
				_getch();
				system("cls");
				oderMenu(nhom8,khach,tt,hd);
				break;
			case 5:
				khach.huyDatBan();
				_getch();
				system("cls");
				userMenu(nhom8,khach,tt, hd);				
				break;
			case 6:
				nhom8.nhapDanhGia();
				_getch();
				system("cls");
				userMenu(nhom8,khach,tt, hd);
				break;
			case 7:
				mainMenu(nhom8,khach,tt, hd);
				break;
			case 8:
				khach.trangThaiBan();
				_getch();
				system("cls");
				userMenu(nhom8,khach,tt, hd);
				break;
				
        	default:
            	cout << "Lua chon khong hop le! Vui long chon lai\n";
            	_getch();
				system("cls");
           		mainMenu(nhom8,khach, tt, hd);
            	break;
    }
    
};
return 0;
}
