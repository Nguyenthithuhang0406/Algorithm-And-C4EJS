struct person{
    string name;
    int age;
    int height;
};

//định nghĩa toán tử so sánh nội bộ của struct
bool operator<(const person &a, const person &b){
    return a.height < b.height; //sắp xếp theo chiều cao tăng dần
}

//khai báo multiset thuộc kiểu struct
multiset<person> Person1;