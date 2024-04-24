#include <iostream>
#include <ctype.h>
#include <mem.h>
#include <string.h>
#include <conio.h>
using namespace std;

#define MAX 100
#define TOAN 10
#define LY 1
#define HOA 2

struct sinhvien
{
    char mslop[5];
    char hoten[35];
    float diem[3];
} danhsach[MAX];

int n = 0;

void nhapmoi()
{
    char mslop[5], tmp[3];

    float diem[3];

    do
    {
        cout << "\n cho biet ma so lop: ";
        gets(mslop);
        if (strlen(mslop))
        {
            strcpy(danhsach[n].mslop, mslop);
            cout << "\n cho biet ho ten: ";
            gets(danhsach[n].hoten);
            cout << "\n cho biet diem so: ";
            for (int i = 0; i < 3; i++)
            {
                cin >> diem[i];
                danhsach[n].diem[i] = diem[i];
            }
            gets(tmp);
            n++;
        }
    } while (strlen(mslop));
}

void timkiem()
{
    char mslop[5];
    int i = 0, found = 0;
    cout << "\n cho biet ma so lop: ";
    gets(mslop);
    if (strlen(mslop))
        while (i < n)
            if (strcmp(danhsach[i].mslop, mslop) == 0)
            {
                cout << "\n ma so lop: " << danhsach[i].mslop;
                cout << "\n Ho va ten: " << danhsach[i].hoten;
                cout << "\n Diem toan: " << danhsach[i].diem[TOAN];
                cout << "\n Diem Ly: " << danhsach[i].diem[LY];
                cout << "\n Diem Hoa: " << danhsach[i].diem[HOA];
                found = 1;
                break;
            }
            else
                i++;
    if (!found)
        cout << "\n khong tim thay!";
}

void xoa()
{
    char mslop[5], traloi;
    int i = 0;
    cout << "\n cho biet ma so lop: ";
    gets(mslop);
    if (strlen(mslop))
        while (i < n)
            if (strcmp(danhsach[i].mslop, mslop) == 0)
            {
                cout << "\n ma so lop: " << danhsach[i].mslop;
                cout << "\n Ho va ten: " << danhsach[i].hoten;
                cout << "\n Diem toan: " << danhsach[i].diem[TOAN];
                cout << "\n Diem Ly: " << danhsach[i].diem[LY];
                cout << "\n Diem Hoa: " << danhsach[i].diem[HOA];
                cout << "\n co muon xoa khong (c/k)?";

                do
                {
                    traloi = toupper(getch());
                } while (traloi != 'c' && traloi != 'k');

                putc(traloi, stdout);

                if (traloi == 'c')
                {
                    n--;
                    memcpy(&danhsach[i], &danhsach[i + 1], sizeof(struct sinhvien) * (n - 1));
                    break;
                }
            }
            else
                i++;
}

void menu()
{
    cout << "\n ***********************";
    cout << " \n * 1.Them *";
    cout << "\n * 2.Xoa *";
    cout << "\n * 3.Tim kiem *";
    cout << "\n * 0. Thoat *";
    cout << "\n chon lua?";
}

int main()
{
    char traloi;
    do
    {
        menu();

        do
        {
            traloi = getch();
        } while (traloi < '0' || traloi > '3');

        putc(traloi, stdout);

        switch (traloi)
        {
        case '1':
            nhapmoi();
            break;
        case '2':
            xoa();
            break;
        case '3':
            timkiem();
            break;
        }
    } while (traloi != '0');

    return 0;
}