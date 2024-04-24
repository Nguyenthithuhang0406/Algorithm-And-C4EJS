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
   float toan, ly, hoa;
} danhsach[MAX];

struct node
{
   sinhvien info;
   node *next;
}*first, *last, *L, *p;

int n = 0;

void nhapmoi()
{
    char mslop[5], tmp[3];

    do
    {
        cout << "\n cho biet ma so lop: ";
        gets(mslop);
        if (strlen(mslop))
        {
            p = new node; //xin cap phat node moi

            strcpy(p->info.mslop, mslop);
            cout << "\n cho biet ho ten: ";
            gets(p->info.hoten);
            cout << "\n cho biet diem so: ";
            cout << "\n cho biet diem toan: ";
            cin >> p->info.toan;
            cout << "\n cho biet diem ly: ";
            cin >> p->info.ly;
            cout << "\n cho biet diem hoa: ";
            cin >> p->info.hoa;
            gets(tmp);
            n++;
            p->next = NULL;
            if(L == NULL)
                L = last = p;
            else{
                last->next = p;
                last = last->next;
            }
        }
    } while (strlen(mslop));
}


// void xoa()
// {
//     char mslop[5], traloi;
//     int i = 0;
//     struct sinhvien *p, *before = NULL;
//     if(first == NULL){
//         cout << "\n danh sach rong!";
//         return;
//     }
    
//     p = first;

//     cout << "\n cho biet ma so lop: ";
//     gets(mslop);
//     if (strlen(mslop))
//         while (i < n)
//             if (strcmp(p->mslop, mslop) == 0)
//             {
//                 cout << "\n ma so lop: " << p->mslop;
//                 cout << "\n Ho va ten: " << p->hoten;
//                 cout << "\n Diem toan: " << p->toan;
//                 cout << "\n Diem Ly: " << p->ly;
//                 cout << "\n Diem Hoa: " << p->hoa;
//                 cout << "\n co muon xoa khong (c/k)?";

//                 do
//                 {
//                     traloi = toupper(getch());
//                 } while (traloi != 'c' && traloi != 'k');

//                 if (traloi == 'c')
//                 {
//                     n--;
//                     if(before == NULL){
//                         before = first;
//                         first = first->next;
//                     }else   before->next = p->next;
//                     free(p);
//                     break;
//                 }
//             }
//             else
//                 i++;
// }

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
        break;
        
        }
    } while (traloi != '0');

    return 0;
}