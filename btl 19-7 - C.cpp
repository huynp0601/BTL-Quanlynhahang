#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX_NAME_LENGTH 100
#define MAX_MENUS 100
#define MAX_ORDERS 100
#define MAX_TABLES 10



typedef struct {
    char tenMon[MAX_NAME_LENGTH];
    long long gia;
} MonAn;

typedef struct {
    MonAn danhSachMonAn[MAX_MENUS];
    int soLuongMonAn;
} Menu;

typedef struct {
    char tenMon[MAX_NAME_LENGTH];
    int soLuong;
} DonHang;

typedef struct {
    int maBanAn;
    bool trangThaiBanAn;
    DonHang donHang[MAX_ORDERS];
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
    DanhGia danhSachDanhGia[MAX_MENUS];
    int soLuongDanhGia;
} DanhGiaList;


void taoMenu(Menu *menu);
void themMon(Menu *menu, const char *tenMon, long long gia);
void xoaMon(Menu *menu, const char *tenMon);
void hienThiMenu(const Menu *menu);
void taoBan(Ban *ban, int maBanAn);
void hienThiDanhSachBan(const QuanLyBan *qlb);
void datBan(QuanLyBan *qlb, int maBanAn);
void datNhieuBan(QuanLyBan *qlb, int soLuong);
void huyDatBan(QuanLyBan *qlb, int maBanAn);
void nhapDanhGia(DanhGiaList *dgList, const char *ten, long long sdt, double diem);
void hienThiDanhGia(const DanhGiaList *dgList);
void hienThiDiemTrungBinh(const DanhGiaList *dgList);
long long layGiaMon(const Menu *menu, const char *tenMon);
void datMon(Menu *menu, Ban *ban);
void hienThiHoaDon(const Menu *menu, const QuanLyBan *qlb);



void taoMenu(Menu *menu) {
    menu->soLuongMonAn = 0;
}

void themMon(Menu *menu, const char *tenMon, long long gia) {
    if (menu->soLuongMonAn < MAX_MENUS) {
        strcpy(menu->danhSachMonAn[menu->soLuongMonAn].tenMon, tenMon);
        menu->danhSachMonAn[menu->soLuongMonAn].gia = gia;
        menu->soLuongMonAn++;
    }
}

void xoaMon(Menu *menu, const char *tenMon) {
    for (int i = 0; i < menu->soLuongMonAn; i++) {
        if (strcmp(menu->danhSachMonAn[i].tenMon, tenMon) == 0) {
            for (int j = i; j < menu->soLuongMonAn - 1; j++) {
                menu->danhSachMonAn[j] = menu->danhSachMonAn[j + 1];
            }
            menu->soLuongMonAn--;
            break;
        }
    }
}

void hienThiMenu(const Menu *menu) {
	printf("+----------------------------+------------+\n");
	printf("| Ten mon an                 | Gia tien   |\n");
	printf("+----------------------------+------------+\n");
    for (int i = 0; i < menu->soLuongMonAn; i++) {
        printf("| %-27s| %10d |\n", menu->danhSachMonAn[i].tenMon, menu->danhSachMonAn[i].gia);
        printf("+----------------------------+------------+\n");
    }
}

void taoBan(Ban *ban, int maBanAn) {
    ban->maBanAn = maBanAn;
    ban->trangThaiBanAn = false;
    ban->soLuongMonDat = 0;
}

void hienThiDanhSachBan(const QuanLyBan *qlb) {
    for (int i = 0; i < qlb->soLuongBan; i++) {
        printf("Ban %d - Trang thai: %s\n", qlb->danhSachBan[i].maBanAn, qlb->danhSachBan[i].trangThaiBanAn ? "Co nguoi" : "Trong");
    }
}

void datBan(QuanLyBan *qlb, int maBanAn) {
    for (int i = 0; i < qlb->soLuongBan; i++) {
        if (qlb->danhSachBan[i].maBanAn == maBanAn) {
            qlb->danhSachBan[i].trangThaiBanAn = true;
            break;
        }
    }
}

void datNhieuBan(QuanLyBan *qlb, int soLuong) {
    int maBanAn;
    int soLuongDaDat = 0;
    while (soLuongDaDat < soLuong) {
        printf("Nhap ma ban muon dat (ban %d/%d): ", soLuongDaDat + 1, soLuong);
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
            qlb->danhSachBan[i].soLuongMonDat = 0; 
            break;
        }
    }
}

void nhapDanhGia(DanhGiaList *dgList, const char *ten, long long sdt, double diem) {
    if (dgList->soLuongDanhGia < MAX_MENUS) {
        strcpy(dgList->danhSachDanhGia[dgList->soLuongDanhGia].ten, ten);
        dgList->danhSachDanhGia[dgList->soLuongDanhGia].sdt = sdt;
        dgList->danhSachDanhGia[dgList->soLuongDanhGia].diem = diem;
        dgList->soLuongDanhGia++;
    }
}

void hienThiDanhGia(const DanhGiaList *dgList) {
    for (int i = 0; i < dgList->soLuongDanhGia; i++) {
        printf("Danh gia cua %s (SDT: %lld) - Diem: %.2f\n", dgList->danhSachDanhGia[i].ten, dgList->danhSachDanhGia[i].sdt, dgList->danhSachDanhGia[i].diem);
    }
}

void hienThiDiemTrungBinh(const DanhGiaList *dgList) {
    double tongDiem = 0;
    for (int i = 0; i < dgList->soLuongDanhGia; i++) {
        tongDiem += dgList->danhSachDanhGia[i].diem;
    }
    if (dgList->soLuongDanhGia > 0) {
        printf("Diem trung binh: %.2f\n", tongDiem / dgList->soLuongDanhGia);
    } else {
        printf("Chua co danh gia nao.\n");
    }
}

long long layGiaMon(const Menu *menu, const char *tenMon) {
    for (int i = 0; i < menu->soLuongMonAn; i++) {
        if (strcmp(menu->danhSachMonAn[i].tenMon, tenMon) == 0) {
            return menu->danhSachMonAn[i].gia;
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
        scanf("%s", tenMon);
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
        const Ban *ban = &qlb->danhSachBan[i];
        printf("Hoa don ban %d:\n", ban->maBanAn);
        if (ban->trangThaiBanAn && ban->soLuongMonDat > 0) {
            long long tongTien = 0;
            for (int j = 0; j < ban->soLuongMonDat; j++) {
                const DonHang *dh = &ban->donHang[j];
                long long gia = layGiaMon(menu, dh->tenMon);
                printf("%s x%d - %lld VND\n", dh->tenMon, dh->soLuong, gia * dh->soLuong);
                tongTien += gia * dh->soLuong;
            }
            printf("Tong tien: %lld VND\n\n", tongTien);
        } else {
            printf("0 VND\n\n");
        }
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
    int choice;
    bool exitProgram = false;

    taoMenu(&menu);
    qlb.soLuongBan = MAX_TABLES;
    for (int i = 0; i < qlb.soLuongBan; i++) {
        taoBan(&qlb.danhSachBan[i], i + 1);
    }

    danhGiaList.soLuongDanhGia = 0;

    while (!exitProgram) {
        printf("===============================\n");
        printf("|                             |\n");
        printf("|1) Hien thi menu             |\n");
        printf("|2) Them mon an               |\n");
        printf("|3) Xoa mon an                |\n");
        printf("|4) Dat ban                   |\n");
        printf("|5) Huy dat ban               |\n");
        printf("|6) Hien thi danh sach ban    |\n");
        printf("|7) Dat mon                   |\n");
        printf("|8) Hien thi hoa don          |\n");
        printf("|9) Nhap danh gia             |\n");
        printf("|10) Hien thi danh gia        |\n");
        printf("|11) Hien thi diem trung binh |\n");
        printf("|0) Thoat                     |\n");
        printf("|                             |\n");
        printf("===============================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        system("cls");

        switch (choice) {
            case 1:
                hienThiMenu(&menu);
                printf("Nhan phim bat ky de quay lai menu chinh...");
                getchar(); 
                getchar(); 
                system("cls");
                break;
            case 2: {
                char tenMon[MAX_NAME_LENGTH];
                long long gia;
                printf("Nhap ten mon an: ");
                scanf("%s", tenMon);
                printf("Nhap gia mon an: ");
                scanf("%lld", &gia);
                themMon(&menu, tenMon, gia);
                printf("Mon an da duoc them. Nhan phim bat ky de quay lai menu chinh...");
                getchar(); 
                getchar(); 
                system("cls");
                break;
            }
            case 3: {
                char tenMon[MAX_NAME_LENGTH];
                printf("Nhap ten mon an: ");
                scanf("%s", tenMon);
                xoaMon(&menu, tenMon);
                printf("Mon an da duoc xoa. Nhan phim bat ky de quay lai menu chinh...");
                getchar(); 
                getchar(); 
                system("cls");
                break;
            }
            case 4: {
                int soLuongBan;
                printf("Nhap so luong ban muon dat: ");
                scanf("%d", &soLuongBan);
                datNhieuBan(&qlb, soLuongBan);
                printf("Nhan phim bat ky de quay lai menu chinh...");
                getchar(); 
                getchar(); 
                system("cls");
                break;
            }
            case 5: {
                int maBan;
                printf("Nhap ma ban: ");
                scanf("%d", &maBan);
                huyDatBan(&qlb, maBan);
                printf("Dat ban da duoc huy. Nhan phim bat ky de quay lai menu chinh...");
                getchar(); 
                getchar(); 
                system("cls");
                break;
            }
            case 6:
                hienThiDanhSachBan(&qlb);
                printf("Nhan phim bat ky de quay lai menu chinh...");
                getchar(); 
                getchar(); 
                system("cls");
                break;
            case 9: {
                char ten[MAX_NAME_LENGTH];
                long long sdt;
                double diem;
                printf("Nhap ten: ");
                scanf("%s", ten);
                printf("Nhap sdt: ");
                scanf("%lld", &sdt);
                printf("Nhap diem: ");
                scanf("%lf", &diem);
                nhapDanhGia(&danhGiaList, ten, sdt, diem);
                printf("Danh gia da duoc nhap. Nhan phim bat ky de quay lai menu chinh...");
                getchar(); 
                getchar(); 
                system("cls");
                break;
            }
            case 10:
                hienThiDanhGia(&danhGiaList);
                printf("Nhan phim bat ky de quay lai menu chinh...");
                getchar(); 
                getchar(); 
                system("cls");
                break;
            case 11:
                hienThiDiemTrungBinh(&danhGiaList);
                printf("Nhan phim bat ky de quay lai menu chinh...");
                getchar(); 
                getchar(); 
                system("cls");
                break;
            case 7: {
                int maBan;
                hienThiDanhSachBan(&qlb);
                printf("Nhap ma ban muon dat mon: ");
                scanf("%d", &maBan);
                datMon(&menu, &qlb.danhSachBan[maBan - 1]);
                printf("Mon an da duoc dat. Nhan phim bat ky de quay lai menu chinh...");
                getchar(); 
                getchar(); 
                system("cls");
                break;
            }
            case 8:
                hienThiHoaDon(&menu, &qlb);
                printf("Nhan phim bat ky de quay lai menu chinh...");
                getchar(); 
                getchar(); 
                system("cls");
                break;
            case 0:
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

    return 0;
}
