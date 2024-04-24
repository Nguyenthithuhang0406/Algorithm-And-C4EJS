//danh sách liên kết cài bằng mảng
#include<bits/stdc++.h>
using namespace std;

//cài đặt sanh sách
const int N = 100;
typedef int item;
typedef struct 
{
   item Elems[N]; //mảng kiểu item
   int size;  //số phần tử của mảng
} List; //kiểu danh sách list


//khởi tạo danh sách rỗng
void init(List *L)    //danh sách L được khai báo kiểu con trỏ để khi ra khỏi hàm nó có thể thay đổi được
{
    (*L).size = 0;  //size = 0;
}


//kiểm tra danh sách rỗng, danh sách đầy
int isempty(List L){
    return (L.size == 0);
}

int isfull(List L){
    return (L.size == N);
}

//chèn phần tử vào vị trí k trong danh sách
item init_x()  //khởi tạo giá trị x
{
    int temp;
    cin >> temp;
    return temp;
}

int Insert_k(List *L, item x, int k) // chèn x vào vị trí k
{
    if(isfull(*L)) //kiểm tra danh sách đầy
    {
        cout << "danh sach day";
        return 0;

    }

    if(k < 1 || k > (*L).size + 1) //kiểm tra điều kiện vị trí chèn
    {
        cout << "vi tri chen khong hop le \n";
        return 0;
    }
    cout << "nhap thong tin can chen: ";
    x = init_x() ; //gán x bằng hàm khởi tạo x
    //di chuyển các phần tử về cuối danh sách
    for(int i = (*L).size; i >= k; i--){
        (*L).Elems[i] = (*L).Elems[i-1];
    }
    (*L).Elems[k-1] = x; //chèn x vào vị trí k
    (*L).size ++; //tăng size lên 1 đơn vị
    return 1;

}

//nhập danh sách
void Input(List *L){
    cout << "nhap so phan tu cua danh sach: ";
    cin >> (*L).size;
    for (int i = 0; i < (*L).size; i++)
    {
        cout<< "nhap phan tu thu " << i+1 << " : ";
        (*L).Elems[i] = init_x();
    }
}

//in danh sách
void Output(List L){
    cout << "danh sach: ";
    for(int i = 0; i < L.size; i++)
         cout << L.Elems[i] <<" ";
    cout << "\n";
}

//tìm phần tử x trong danh sách
int search(List L, item x){
    for(int i = 0; i < L.size; i++){
        if(L.Elems[i] == x) return i+1;
    }
    return 0;
}

//xoá phần tử thứ k trong danh sách
int Del_k(List *L, item *x, int k){
    if(isempty(*L)){
        cout << "danh sach rong!";
        return 0;
    }

    if(k < 1 || k > (*L).size){
        cout << "vi tri xoa khong hop le!";
        return 0;
    }

    *x = (*L).Elems[k-1]; //lưu lại giá trị của phần tử cần xoá
    for(int i = k-1; i < (*L).size - 1; i++){
        (*L).Elems[i] = (*L).Elems[i+1];
        (*L).size --;  //giảm size
        return 1;
    }
}

//xoá phần tử có nội dung x trong danh sách
int Del_x(List *L, item x){
    if(isempty(*L)){
        cout << "danh sach rong!";
        return 0;
    }

    int i = search(*L, x);
    if(!i){
        cout << "danh sach khong chua " << x;
        return 0;
    }

    do{
        Del_k(L, &x, i);
        i = search(*L, x);
    }while (i);

    return 1;
    
}

int main(){
    List L;
     init(&L);
    Input(&L);
   Output(L);


    int choose;
    cout << "moi ban nhap lua chon thuc hien phep toan: \n";
    cout << "1. kiem tra danh sach rong \n";
    cout << "2. đo dai danh sach: \n";
    cout << "3. chen phan tu x vao vi tri k trong danh sach: \n";
    cout << "4.Tim mot phan tu trong danh sach: \n";
    cout << "5. xoa phan tu tai vi tri k: \n";
    cout << "6. xoa phan tu x trong danh sach:  \n";
    cout << "7. thoat \n";

    do {
        cout << "ban chon: \n";
        cin >> choose;

        switch(choose){
            case 1:
            {
                if(isempty(L)) cout << "danh sach rong! \n";
                else cout << "danh sach khong rong! \n";
                break;
            }
            case 2:
            {
                cout << "đo dai cua danh sach la: " << L.size << "\n";
                break;
            }
            case 3:
            {
                item x;
                int k;
                cout << "nhap vi tri can chen: \n";
                cin >> k;
                if(Insert_k(&L, x, k)){
                    cout << "danh sach sau khi chen là: \n";
                    Output(L);
                }
                break;
            }
            case 4:
            {
                item x;
                cout << "nhap phan tu can tim: \n";
                cin >> x;
                int k = search(L,x);
                if(k)  cout << "tim thay " << x << " trong danh sach tai vi tri thu " << k << "\n";
                else{
                    cout << "khong tim thay " << x << " trong danh sach! \n";
                }
                break;
            }

            case 5:
            {
                int k;
                item x;
                cout << "nhap vi tri can xoa: \n";
                cin >> k;
                if(Del_k(&L, &x, k)){
                    cout << "danh sach sau khi xoa la: \n";
                    Output(L);
                }
                break;
            }
            case 6:
            {
                item x;
                cout << "nhap phan tu can xoa: \n";
                cin >> x;
                if(Del_x(&L, x)){
                    cout << "danh sach sau khi xoa la: ";
                    Output(L);
                }
                break;
            }
            case 7:
             break;
        }
    } while (choose != 7);

    return 0;
}