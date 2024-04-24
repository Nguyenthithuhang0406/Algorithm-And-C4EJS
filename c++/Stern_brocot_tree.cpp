

//Xây dựng cây
void build(int a = 0, int b = 1,int c = 1, int d = 0, int level = 1){
    int x = a+c, y = b+d;
    //in ra phân số ở cấp độ level
    cout << x << "/" << y << " ";
    build(a, b, x, y, level + 1);
    build(x, y, c, d, level + 1);
}

//tìm kiếm phân số x/y (trả về đường dẫn đến phân số x/y)
//'L' : sang con trái
//'R': sang con phải

string find(int x, int y, int a = 0, int b = 1, int c = 1, int d = 0){
    int m = a+c, n = b+d;
    if(x == m && y == n) return "";
    if(x*n < y*m) return 'L' + find(x, y, a, b, m, n);
    else return 'R' + find(x, y, m, n, c, d);
}