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

void adminLogin(nhahang phu, int tt);
void mainMenu(nhahang phu, int tt);
void adminMenu(nhahang phu, int tt);
int main() {
    nhahang nhom8;
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
			switch (adminOption)
			{
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
            cout << "Chuc nang dang duoc phat trien.\n";
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
            return 0;
        default:
            cout << "Lua chon khong hop le! Vui long chon lai\n";
            mainMenu(nhom8, tt);
            break;
    }
    return 0;
}

void adminLogin(nhahang phu, int tt) {
    string username, password;
    cout << " ===============================\n";
    cout << "                              \n";
    cout << "         - Dang nhap -        \n";
    cout << "        Ten dang nhap: "; cin >> username;
    cout << "        Mat khau: "; cin >> password;
    cout << "                              \n";
    cout << "                              \n";
    cout << " ===============================\n";
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
				adminMenu(phu, tt);
				break;
			case 2:
				adminMenu(phu, tt);
				break;
			case 3:
				mainMenu(phu, tt);
				break;
			
			default:
				cout << " Vui long chon lai!" << endl;
				adminMenu(phu, tt);
				break;
			}
		}
		else {
			cout << " Thong tin dang nhap khong hop le, an phim bat ky de thu lai!" << endl;
			_getch();
			system("cls");
			adminLogin(phu, tt);
		}    
}
void mainMenu(nhahang phu2, int tt2)
{
	int loginOption = 0;
	int userOption = 0;
	int orderSlot = tt2;

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

	switch (loginOption)
	{
	case 1:

		cout << " ===============================" << endl;
		cout << "                              " << endl;
	  	cout << "         - Dang nhap -        \n";
    	cout << "        Ten dang nhap: "; cin >> username;
    	cout << "        Mat khau: "; cin >> password;
		cout << "                              " << endl;
		cout << "                              " << endl;
		cout << " ===============================" << endl;
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
				adminMenu(phu2,tt2);
				break;
			case 2:
				adminMenu(phu2,tt2);
				break;
			case 3:
				mainMenu(phu2,tt2);
				break;
			
			default:
				cout << " Vui long chon lai!!" << endl;
				adminMenu(phu2, tt2);
				break;
			}
		}
		else
		{
			cout << " Thong tin dang nhap khong hop le, an phim bat ky de thu lai thu lai!!" << endl;
			_getch();
			system("cls");
			adminLogin(phu2, tt2);
		}
	case 2:
	
		
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
		mainMenu(phu2,orderSlot);
		break;
	}
}
void adminMenu(nhahang phu, int tt)
{
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
	}
}

