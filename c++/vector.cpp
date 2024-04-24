//Dev ơi mình đi đâu thê
//vd1: tạo vector và truy cập phần tử
#include<iostream>
#include<vector>
using namespace std;

int main(){
    //tạo vector và thêm phần tử vào vector
    vector<int> vec{10, 20, 30, 40, 50};
    vec.push_back(60);

    //truy cập và in ra các phần tử của vector
    cout << "cac phan tu cua vector la: ";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }

    return 0;
}

//Dev ơi mình đi đâu thế
//vd2: sắp xếp và xoá phần tử của vector
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    //tạo vector và thêm phần tử vào vector
    vector<int> vec{30, 10, 50, 20, 40};
    vec.push_back(60);

    //sắp xếp các phần tử của vector theo thứ tự tăng dần
    sort(vec.begin(), vec.end());

    //xoá phần tử thứ 2 của vector
    vec.erase(vec.begin() + 1);

    //truy cập và in ra các phần tử của vector
    cout << "cac phan tu cua vector la: ";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }

    return 0;
}


//Dev ơi mình đi đâu thê
//vd3: tìm kiếm phần tử trong vector
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
   //tạo vector và thêm phần tử vào vector
    vector<int> vec{10, 20, 30, 40, 50, 60}; 

    //tìm kiếm phần tử 30 trong vector
    auto it = find(vec.begin(), vec.end(), 30);

    //kiểm tra xem phần tử 30 có tồn tại trong vector hay không
    if(it != vec.end()){
        cout << "phan tu 30 ton tai trong vector." << endl;
    }

return 0;
}