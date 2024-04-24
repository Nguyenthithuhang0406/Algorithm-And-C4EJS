

int main(){
    int rows, cols;
    cout << "nhap so hang : ";
    cin >> rows;
    cout << "\n nhap so cot : ";
    cin >> cols;
    cout << "\n nhap ma tran:" << endl;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++){
            cin >> a[i][j];
        }
    prinfspiral(a,rows,cols);
}

//vd
//so hang: 6
//so cot: 5
//ma tran
//  H F W Y J
//  T D S E J
//  J F S J F
//  O R H C S
//  O G W F C
//  H D E T B

//out: H F W Y J J F S C B T E D H O O J T D S E J C F W G R F S H