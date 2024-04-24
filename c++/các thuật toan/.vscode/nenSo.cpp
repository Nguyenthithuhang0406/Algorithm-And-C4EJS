// //Dev ơi mình đi đâu thế
// //Simple compression
// //Cách 1: sau khi nén, các số vẫn giữ quan hệ so sánh của các số tương ứng trước khi nén

// #include<bits/stdc++.h>
// using namespace std;

// vector<int> v;

// void compress(){
//     vector<int> tmp ;
//     tmp = v;
//     sort(tmp.begin(), tmp.end());  //sắp xếp vector tmp;

//     //dùng hàm unique để di chuyển phần tử trùng lặp tới cuối vector => trả về iterator tới phần tử cuối không trùng lặp
//     //sau đó sử dụng hàm erase để xoá bỏ các phần tử trùng lặp
//     tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

//     for(int i = 0; i < v.size(); ++i){
//         //v[i] =  vị trí số lớn hơn hoặc bằng  v[i]
//         v[i] = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
//     }
// }

// int main(){
//     int n;
//     cout << "moi ban nhap so luong phan tu cua vector: \n";
//     cin >> n;
//     cout << "nhap cac phan tu cua vector: ";
//     for(int i = 0; i < n; i++){
//         int a; cin >> a; v.push_back(a);
//     }
//     cout << "vector sau khi nen la: ";
//     compress();
//     for(int x : v){
//         cout << x << " ";
//     }
//     return 0;
// }

// // Dev ơi mình đi đâu thế?
// // Cách 2
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> v;
// vector<int> tmp;

// void compress()
// {
//     sort(tmp.begin(), tmp.end());

//     int num = 0;
//     int last = tmp[0];
//     tmp[0] = num;

//     for (int i = 1; i < v.size(); ++i)
//     {
//         if (last != tmp[i])
//         {
//             num++;
//             last = tmp[i];
//         }
//         tmp[i] = num;
//     }
// }

// int main()
// {
//     int n;
//     cout << "moi ban nhap so luong phan tu cua vector: \n";
//     cin >> n;
//     cout << "nhap cac phan tu cua vector: ";
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         v.push_back(a);
//     }
//     tmp = v;
//     cout << "vector sau khi nen la: ";
//     compress();
//     for (int x : tmp)
//     {
//         cout << x << " ";
//     }
//     return 0;
// }

// Dev ơi mình đi đâu thế?
// Cách 3: deep compression
 #include<bits/stdc++.h>
 using namespace std;

vector<int> v;
vector<int> tmp ;

void deepCompress(){
    sort(tmp.begin(), tmp.end());

    int num  = 0;
    int last = tmp[0];
    tmp[0] = num;

    for(int i = 1; i < v.size(); ++i){
        if(last != tmp[i]){
            num += 1+ (tmp[i] - last > 1);
            last = tmp[i];
        }
        tmp[i] = num;
    }
}

int main(){
    int n;
    cout << "moi ban nhap so luong phan tu cua vector: \n";
    cin >> n;
    cout << "nhap cac phan tu cua vector: ";
    for(int i = 0; i < n; i++){
        int a; cin >> a; v.push_back(a);
    }
    tmp = v;
    cout << "vector sau khi nen la: ";
    deepCompress();
    for(int x : tmp){
        cout << x << " ";
    }
    return 0;
}
