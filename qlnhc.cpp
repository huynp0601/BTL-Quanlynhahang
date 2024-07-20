#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_MENU_ITEMS 100
#define MAX_TABLES 10
#define MAX_DANH_GIAS 100

typedef struct {
    char tenMon[MAX_NAME_LENGTH];
    long long gia;
} MonAn;

typedef struct {
    MonAn danhSach[MAX_MENU_ITEMS];
    int soLuongMon=0;
} Menu;

typedef struct {
    char tenMon[MAX_NAME_LENGTH];
    int soLuong;
} DonHang;

typedef struct {
    int maBanAn;
    bool trangThaiBanAn;
    DonHang donHang[MAX_MENU_ITEMS];
    int soLuongMonDat;
} Ban;

typedef struct {
    Ban danhSachBan[MAX_TABLES];
    int soLuongBan;
} QuanLyBan;

typedef struct {
    char ten[MAX_NAME_LENGTH];
    long long sdt;
    double diem;
} DanhGia;

typedef struct {
    DanhGia danhSach[MAX_DANH_GIAS];
    int soLuongDanhGia;
} DanhGiaList;

void taoBan(Ban *ban, int maBanAn) {
    ban->maBanAn = maBanAn;
    ban->trangThaiBanAn = false;
    ban->soLuongMonDat = 0;
}

void themMon(Menu *menu, const char *tenMon, long long gia) {
    strcpy(menu->danhSach[menu->soLuongMon].tenMon, tenMon);
    menu->danhSach[menu->soLuongMon].gia = gia;
    menu->soLuongMon++;
}

void xoaMon(Menu *menu, const char *tenMon) {
    for (int i = 0; i < menu->soLuongMon; i++) {
        if (strcmp(menu->danhSach[i].tenMon, tenMon) == 0) {
            for (int j = i; j < menu->soLuongMon - 1; j++) {
                menu->danhSach[j] = menu->danhSach[j + 1];
            }
            menu->soLuongMon--;
            break;
        }
    }
}

void hienThiMenu(const Menu *menu) {
	printf("+----------------------------+------------+\n");
	printf("| Ten mon an                 | Gia tien   |\n");
	printf("+----------------------------+------------+\n");
    for (int i = 0; i < menu->soLuongMon; i++) {
        printf("| %-27s| %10lld |\n", menu->danhSach[i].tenMon, menu->danhSach[i].gia);
        printf("+----------------------------+------------+\n");
    }
}

void hienThiDanhSachBan(const QuanLyBan *qlb) {
    for (int i = 0; i < qlb->soLuongBan; i++) {
        printf("Ban %d - Trang thai: %s\n", qlb->danhSachBan[i].maBanAn, qlb->danhSachBan[i].trangThaiBanAn ? "Co nguoi" : "Trong");
    }
}



void datNhieuBan(QuanLyBan *qlb, int soLuong) {
    int maBanAn;
    int soLuongDaDat = 0;
    while (soLuongDaDat < soLuong) {
        printf("Nhap ma ban muon dat: ");
        scanf("%d", &maBanAn);

        bool timThay = false;
        for (int i = 0; i < qlb->soLuongBan; i++) {
            if (qlb->danhSachBan[i].maBanAn == maBanAn && !qlb->danhSachBan[i].trangThaiBanAn) {
                qlb->danhSachBan[i].trangThaiBanAn = true;
                soLuongDaDat++;
                timThay = true;
                printf("Ban %d da duoc dat thanh cong.\n", maBanAn);
                break;
            }
        }
        if (!timThay) {
            printf("Ban %d khong ton tai hoac da duoc dat. Vui long chon ban khac.\n", maBanAn);
        }
    }
}

void huyDatBan(QuanLyBan *qlb, int maBanAn) {
    for (int i = 0; i < qlb->soLuongBan; i++) {
        if (qlb->danhSachBan[i].maBanAn == maBanAn) {
            qlb->danhSachBan[i].trangThaiBanAn = false;
            break;
        }
        
    }
}

long long layGiaMon(const Menu *menu, const char *tenMon) {
    for (int i = 0; i < menu->soLuongMon; i++) {
        if (strcmp(menu->danhSach[i].tenMon, tenMon) == 0) {
            return menu->danhSach[i].gia;
        }
    }
    return -1;
}

void datMon(Menu *menu, Ban *ban) {
    int soLuongMon;
    printf("Nhap so luong mon an muon dat: ");
    scanf("%d", &soLuongMon);

    for (int i = 0; i < soLuongMon; i++) {
        char tenMon[MAX_NAME_LENGTH];
        int soLuong;
        printf("Nhap ten mon an: ");
        getchar();
        fgets(tenMon, sizeof(tenMon), stdin);
        tenMon[strcspn(tenMon, "\n")] = '\0';
        printf("Nhap so luong: ");
        scanf("%d", &soLuong);

        long long gia = layGiaMon(menu, tenMon);
        if (gia != -1) {
            strcpy(ban->donHang[ban->soLuongMonDat].tenMon, tenMon);
            ban->donHang[ban->soLuongMonDat].soLuong = soLuong;
            ban->soLuongMonDat++;
        } else {
            printf("Mon an khong co trong menu.\n");
        }
    }
}

void hienThiHoaDon(const Menu *menu, const QuanLyBan *qlb) {
    for (int i = 0; i < qlb->soLuongBan; i++) {
        if (qlb->danhSachBan[i].trangThaiBanAn) {
            long long tongTien = 0;
            for (int j = 0; j < qlb->danhSachBan[i].soLuongMonDat; j++) {
                long long gia = layGiaMon(menu, qlb->danhSachBan[i].donHang[j].tenMon);
                tongTien += gia * qlb->danhSachBan[i].donHang[j].soLuong;
            }
            printf("Hoa don cho ban %d: %lld\n", qlb->danhSachBan[i].maBanAn, tongTien);
            printf("+----------------------------+------------+------------+\n");
            printf("| Ten mon an                 | Gia tien   | So luong   |\n");
            printf("+----------------------------+------------+------------+\n");
            for (int j = 0; j < qlb->danhSachBan[i].soLuongMonDat; j++) {
                long long gia = layGiaMon(menu, qlb->danhSachBan[i].donHang[j].tenMon);
                printf("| %-27s| %10lld | %10d |\n", 
                       qlb->danhSachBan[i].donHang[j].tenMon, 
                       gia, 
                       qlb->danhSachBan[i].donHang[j].soLuong);
                printf("+----------------------------+------------+------------+\n");
            }
            printf("Tong tien: %lld\n", tongTien);
            printf("+----------------------------+------------+------------+\n");
        }
    }
}

void nhapDanhGia(DanhGiaList *dgList, const char *ten, long long sdt, double diem) {
    strcpy(dgList->danhSach[dgList->soLuongDanhGia].ten, ten);
    dgList->danhSach[dgList->soLuongDanhGia].sdt = sdt;
    dgList->danhSach[dgList->soLuongDanhGia].diem = diem;
    dgList->soLuongDanhGia++;
}

void hienThiDanhGia(const DanhGiaList *dgList) {
    printf("+--------------------------------+----------------+-----------+\n");
    printf("| Ten khach hang                 | SDT            | Diem      |\n");
    printf("+--------------------------------+----------------+-----------+\n");

    for (int i = 0; i < dgList->soLuongDanhGia; i++) {
        printf("| %-30s | %14lld | %9.2f |\n", 
               dgList->danhSach[i].ten, 
               dgList->danhSach[i].sdt, 
               dgList->danhSach[i].diem);
        printf("+--------------------------------+----------------+-----------+\n");
    }
}
void adminMenu(Menu &menu, QuanLyBan &qlb, DanhGiaList &danhGiaList, bool exitProgram);
void adminLogin(Menu &menu, QuanLyBan &qlb, DanhGiaList &danhGiaList, bool exitProgram);
void mainMenu(Menu &menu, QuanLyBan &qlb, DanhGiaList &danhGiaList, bool exitProgram);
void userMenu(Menu &menu, QuanLyBan &qlb, DanhGiaList &danhGiaList, bool exitProgram);
void orderMenu(Menu &menu, QuanLyBan &qlb, DanhGiaList &danhGiaList, bool exitProgram);

void adminMenu(Menu &menu, QuanLyBan &qlb, DanhGiaList &danhGiaList, bool exitProgram) {
    int adminOption;
    while (!exitProgram) {
        printf(" ===============================\n");
        printf(" |              Chu            |\n");
        printf(" |  Lua chon thao tac ban muon |\n");
        printf(" |      1) Hien thi danh gia   |\n");
        printf(" |      2) Hien thi menu       |\n");
        printf(" |      3) Them mon an         |\n");
        printf(" |      4) Xoa mon an          |\n");
        printf(" |      5) Quay lai            |\n");
        printf(" |                             |\n");
        printf(" ===============================\n");
        scanf("%d", &adminOption);
        system("cls");

        switch (adminOption) {
            case 1:
                hienThiDanhGia(&danhGiaList);
                printf("Nhan phim bat ky de quay lai menu chinh...");
                getchar();
                getchar();
                system("cls");
                break;
            case 2:
                hienThiMenu(&menu);
                printf("Nhan phim bat ky de quay lai menu chinh...");
                getchar(); 
                getchar(); 
                system("cls");
                break;
            case 3:
                {
                    char tenMon[MAX_NAME_LENGTH];
                    long long gia;
                    printf("Nhap ten mon an: ");
                    getchar();
                    fgets(tenMon, sizeof(tenMon), stdin);
                    tenMon[strcspn(tenMon, "\n")] = '\0';
                    printf("Nhap gia mon an: ");
                    scanf("%lld", &gia);
                    themMon(&menu, tenMon, gia);
                    printf("Mon an da duoc them. Nhan phim bat ky de quay lai menu chinh...");
                    getchar();
                    getchar();
                    system("cls");
                }
                break;
            case 4:
                {
                    char tenMon[MAX_NAME_LENGTH];
                    printf("Nhap ten mon an: ");
                    getchar();
                    fgets(tenMon, sizeof(tenMon), stdin);
                    tenMon[strcspn(tenMon, "\n")] = '\0';
                    xoaMon(&menu, tenMon);
                    printf("Mon an da duoc xoa. Nhan phim bat ky de quay lai menu chinh...");
                    getchar();
                    getchar();
                    system("cls");
                }
                break;
            case 5:
                mainMenu(menu, qlb, danhGiaList, exitProgram);
                break;
            default:
                printf("Lua chon khong hop le. Nhan phim bat ky de quay lai menu chinh...");
                getchar();
                getchar();
                system("cls");
                break;
        }
    }
}

void userMenu(Menu &menu, QuanLyBan &qlb, DanhGiaList &danhGiaList, bool exitProgram) {
    int userOption;
    while (!exitProgram) {
        printf(" ===============================\n");
        printf(" |             Khach           |\n");
        printf(" | Lua chon thao tac ban muon: |\n");
        printf(" | 1) Dat ban                  |\n");
        printf(" | 2) Huy dat ban              |\n");
        printf(" | 3) Hien thi danh sach ban   |\n");
        printf(" | 4) Order                    |\n");
        printf(" | 5) Hien thi hoa don         |\n");
        printf(" | 6) Nhap danh gia            |\n");
        printf(" | 7) Quay lai                 |\n");
        printf(" ===============================\n");
        scanf("%d", &userOption);
        system("cls");

        switch (userOption) {
            case 1:
                {
                    int soLuongBan;
                    hienThiDanhSachBan(&qlb);
                    printf("Nhap so luong ban muon dat: ");
                    scanf("%d", &soLuongBan);
                    datNhieuBan(&qlb, soLuongBan);
                    printf("Nhan phim bat ky de quay lai menu chinh...");
                    getchar();
                    getchar();
                    system("cls");
                }
                break;
            case 2:
                {
                	hienThiDanhSachBan(&qlb);
                    int maBan;
                    printf("Nhap ma ban: ");
                    scanf("%d", &maBan);
                    huyDatBan(&qlb, maBan);
                    printf("Dat ban da duoc huy. Nhan phim bat ky de quay lai menu chinh...");
                    getchar();
                    getchar();
                    system("cls");
                }
                break;
            case 3:
                hienThiDanhSachBan(&qlb);
                printf("Nhan phim bat ky de quay lai menu chinh...");
                getchar();
                getchar();
                system("cls");
                break;
            case 4:
                {
                    int maBan;
                    hienThiDanhSachBan(&qlb);
                    printf("Nhap ma ban muon dat mon: ");
                    scanf("%d", &maBan);
                    if(qlb.danhSachBan[maBan-1].trangThaiBanAn == true){
                    	system("cls");
                    	hienThiMenu(&menu);
                    	datMon(&menu, &qlb.danhSachBan[maBan - 1]);
                    	printf("Mon an da duoc dat. Nhan phim bat ky de quay lai menu chinh...");
                    	getchar();
                    	getchar();
                    	system("cls");	
					}
					else {
						printf("Vui long dat ban!");
						getchar();
						getchar();
                    	system("cls");
						userMenu(menu, qlb, danhGiaList,exitProgram);
					}                
                }
                break;
            case 5:
                hienThiHoaDon(&menu, &qlb);
                printf("Nhan phim bat ky de quay lai menu chinh...");
                getchar();
                getchar();
                system("cls");
                break;
            case 6:
                {
                    char ten[MAX_NAME_LENGTH];
                    long long sdt;
                    double diem;
                    printf("Nhap ten: ");
                    getchar();
                    fgets(ten, sizeof(ten), stdin);
                    ten[strcspn(ten, "\n")] = '\0';
                    printf("Nhap sdt: ");
                    scanf("%lld", &sdt);
                    printf("Nhap diem: ");
                    scanf("%lf", &diem);
                    nhapDanhGia(&danhGiaList, ten, sdt, diem);
                    printf("Danh gia da duoc nhap. Nhan phim bat ky de quay lai menu chinh...");
                    getchar();
                    getchar();
                    system("cls");
                }
                break;
            case 7:
                mainMenu(menu, qlb, danhGiaList,exitProgram);
                break;
            default:
                printf("Lua chon khong hop le. Nhan phim bat ky de quay lai menu chinh...");
                getchar();
                getchar();
                system("cls");
                break;
        }
    }
}
void mainMenu(Menu &menu, QuanLyBan &qlb, DanhGiaList &danhGiaList, bool exitProgram) {
    int choice;
    while (!exitProgram) {
        printf("===============================\n");
        printf("|                             |\n");
        printf("|   Truy cap voi tu cach:     |\n");
        printf("|         1) Chu nha hang     |\n");
        printf("|         2) Khach            |\n");
        printf("|         3) Thoat ra         |\n");
        printf("|                             |\n");
        printf("===============================\n");
        scanf("%d", &choice);
        system("cls");
        switch (choice) {
            case 1:
                adminLogin(menu, qlb, danhGiaList, exitProgram);
                break;
            case 2:
                userMenu(menu, qlb, danhGiaList, exitProgram);
                break;
            case 3:
                exitProgram = true;
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Nhan phim bat ky de quay lai menu chinh...");
                getchar();
                getchar();
                system("cls");
                break;
        }
    }
}
void adminLogin(Menu &menu, QuanLyBan &qlb, DanhGiaList &danhGiaList, bool exitProgram) {
    const char username[100] = "1";
    const char password[100] = "1";
    char _username[100];
    char _password[100];

    printf(" ===============================\n");
    printf("                              \n");
    printf("         - Dang nhap -        \n");
    printf("        Ten dang nhap: ");
    scanf("%s", _username);
    printf("        Mat khau: ");
    scanf("%s", _password);
    printf("                              \n");
    printf("                              \n");
    printf(" ===============================\n");

    if (strcmp(_username, username) == 0 && strcmp(_password, password) == 0) {
        system("cls");
		adminMenu(menu, qlb, danhGiaList, exitProgram);
    } else {
        printf("Sai ten dang nhap hoac mat khau. Nhan phim bat ky de quay lai...");
        getchar();
        getchar();
        system("cls");
        adminLogin(menu, qlb, danhGiaList, exitProgram);
    }
}
int main() {
    printf(" ===============================\n");
    printf(" |                             |\n");
    printf(" |                             |\n");
    printf(" |          He thong           |\n");
    printf(" |      Quan ly nha hang       |\n");
    printf(" |                             |\n");
    printf(" |                             |\n");
    printf(" ===============================\n");
    printf("An phim bat ky de tiep tuc...\n");
    getchar();
    system("cls");
    Menu menu;
    QuanLyBan qlb;
    DanhGiaList danhGiaList;
 
    const char username[100] = "1";
    const char password[100] = "1";
    char _username[100];
    char _password[100];
    bool exitProgram = false;

    qlb.soLuongBan = MAX_TABLES;
    for (int i = 0; i < qlb.soLuongBan; i++) {
        taoBan(&qlb.danhSachBan[i], i + 1);
    }
    danhGiaList.soLuongDanhGia = 0;
	mainMenu(menu,qlb,danhGiaList, exitProgram);
    return 0;
}
