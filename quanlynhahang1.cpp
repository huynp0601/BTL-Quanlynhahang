#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
class admin {
private:
	string const username = "nhahang08";
	string const password = "nhom8deptrai";
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

//    void datBan() {
//    	int maBan;
//		cout << "Nhap ma ban muon dat: ";
//    	cin >> maBan; 
//        if (maBan < 1 || maBan > soLuongBan) {
//            cout << "Ma ban khong hop le. Vui long thu lai!" << endl;
//            return;
//        }
//
//        if (danhSachBan[maBan - 1].getTrangThai()) {
//            danhSachBan[maBan - 1].setTrangThai(false);
//            cout << "Dat ban " << maBan << " thanh cong!" << endl;
//        } else {
//            cout << "Ban " << maBan << " dang co nguoi. Vui long chon ban khac!" << endl;
//        }
//    }

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
        } else {
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
};
class date
{
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
public:
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
	
};

void userMenu(QuanLyBan khach, int tt);
void adminLogin(nhahang phu, int tt);
void mainMenu(nhahang phu, int tt);
void adminMenu(nhahang phu, int tt);
int main() {
	nhahang nhom8;
	QuanLyBan khach;
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
            cout << " |      3) Thoat               |\n";
			cout << " |                             |" << endl;
			cout << " ===============================" << endl;
			cin >> adminOption;
			system("cls");
			switch (adminOption) {
			case 1:
				adminMenu(nhom8, tt);
				break;
			case 2:
				adminMenu(nhom8, tt);
				break;
			case 3:
				mainMenu(nhom8,tt);
				break;
			
			default:
				cout << " Vui long chon lai!" << endl;
				adminMenu(nhom8, tt);
				break;
			}
		}
		else {
			cout << " Thong tin dang nhap khong hop le, an phim bat ky de thu lai!" << endl;
			_getch();
			system("cls");
			adminLogin(nhom8, tt);
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
				userMenu(khach,tt);
				break;
			case 2:	
				break;
			case 5:
				khach.huyDatBan();
				_getch();
				system("cls");
				userMenu(khach,tt);				
				break;
			case 7:
				mainMenu(nhom8,tt);
				break;
			case 8:
				khach.trangThaiBan();
				_getch();
				system("cls");
				userMenu(khach,tt);
				
				
		
            
        case 3:
        cout << " ===============================" << endl;
		cout << " |                             |" << endl;
		cout << " |                             |" << endl;
		cout << " |          Cam on !!!         |" << endl;
		cout << " |                             |" << endl;
		cout << " |                             |" << endl;
		cout << " ===============================" << endl;
		break;
            return 0;
        default:
            cout << "Lua chon khong hop le! Vui long chon lai\n";
            mainMenu(nhom8, tt);
            break;
    }
    return 0;
};
}

void adminLogin(nhahang phu2, int tt2) {
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
        cout << " |      3) Thoat               |\n";
		cout << " |                             |" << endl;
		cout << " ===============================" << endl;
		cin >> adminOption;
		system("cls");
		switch (adminOption)
			{
			case 1:
				adminMenu(phu2, tt2);
				break;
			case 2:
				adminMenu(phu2, tt2);
				break;
			case 3:
				mainMenu(phu2, tt2);
				break;
			
			default:
				cout << " Vui long chon lai!" << endl;
				adminMenu(phu2, tt2);
				break;
			}
		}
		else {
			cout << " Thong tin dang nhap khong hop le, an phim bat ky de thu lai!" << endl;
			_getch();
			system("cls");
			adminLogin(phu2, tt2);
		}    
}
void userMenu(QuanLyBan phu2, int tt2);
void mainMenu(nhahang phu, int tt) {
	QuanLyBan phu2;
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
			int adminOption = 0;
			cout << " ===============================" << endl;
			cout << " |                             |" << endl;
			cout << " |  Lua chon muc muon truy cap |\n";
            cout << " |      1) Xem danh gia        |\n";
            cout << " |      2) Xem doanh thu       |\n";
            cout << " |      3) Thoat               |\n";
			cout << " |                             |" << endl;
			cout << " ===============================" << endl;
			cin >> adminOption;
			system("cls");
			switch (adminOption)
			{
			case 1:
				adminMenu(phu,tt);
				break;
			case 2:
				adminMenu(phu,tt);
				break;
			case 3:
				mainMenu(phu,tt);
				break;
			
			default:
				cout << " Vui long chon lai!!" << endl;
				adminMenu(phu, tt);
				break;
			}
		}
		else
		{
			cout << " Thong tin dang nhap khong hop le, an phim bat ky de thu lai thu lai!!" << endl;
			_getch();
			system("cls");
			adminLogin(phu, tt);
		}
	case 2:
		userMenu(phu2,tt);
		break;
		
	case 3:
		cout << " ===============================" << endl;
		cout << " |                             |" << endl;
		cout << " |                             |" << endl;
		cout << " |          Cam on !!!         |" << endl;
		cout << " |                             |" << endl;
		cout << " |                             |" << endl;
		cout << " ===============================" << endl;
		break;
	default:
		cout << "Lua chon khong hop le! Vui long chon lai\n";
		_getch();
		mainMenu(phu,orderSlot);
		break;
	};
}
void adminMenu(nhahang phu, int tt) {
	int adminOption = 0;

	cout << " ===============================" << endl;
	cout << " |                             |" << endl;
	cout << " |  Lua chon muc muon truy cap |\n";
    cout << " |      1) Xem danh gia        |\n";
    cout << " |      2) Xem doanh thu       |\n";
    cout << " |      3) Thoat               |\n";
	cout << " |                             |" << endl;
	cout << " ===============================" << endl;
	cin >> adminOption;
	system("cls");
	switch (adminOption)
	{
	case 1:
		
		adminMenu(phu, tt);
		break;
	case 2:
		
		adminMenu(phu, tt);
		break;
	case 3:
		
		mainMenu(phu, tt);
		break;
	
	default:
		cout << " Vui long chon lai!!" << endl;
		adminMenu(phu, tt);
		break;
	};
}
void userMenu(QuanLyBan phu, int tt){
	nhahang nhom8;
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
		userMenu(phu,tt);
		
	case 2:	
		break;
	case 5:
		phu.huyDatBan();
		_getch();
		system("cls");
		userMenu(phu,tt);				
		break;
	case 7:
		mainMenu(nhom8,tt);
		break;
	case 8:
		phu.trangThaiBan();
		_getch();
		system("cls");
		userMenu(phu,tt);
	};
}


