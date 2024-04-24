
#include <iostream>
#include <vector>

using namespace std;

//zAlgorithm nhận vào một xâu kí tự s và trả về vector z
//trong đó z[i] là độ dài của phần tiếp xúc giữa xâu s và xâu bắt đầu từ vị trí i
vector<int> zAlgorithm(const string& s) {
    int n = s.length();
    vector<int> z(n, 0);
    //l, r là biên trái và biên phải của phần tiếp xúc hiện tại
    int l = 0, r = 0;

    for (int i = 1; i < n; ++i) {
        //nếu i <= r, sử dụng giá trị đã tính trước đó
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        //mở rộng phần tiếp xúc  và cập nhật z[i]
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];

        //nếu i + z[i] -1 > r , cập nhật lại l, r
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

//hàm nhận vào 1 xâu lớn text và 1 xâu con pattern
//trả về vector chứa vị trí xuất hiện của pattern trong text
vector<int> findPatternOccurrences(const string& text, const string& pattern) {
    //nối 2 xâu lại bằng kí tự *
    string concat = pattern + "*" + text;
    vector<int> z = zAlgorithm(concat);

    vector<int> occurrences;
    int patternLength = pattern.length();

    for (int i = patternLength + 1; i < z.size(); ++i) {
        //nếu z[i] bằng độ dài của pattern thì i - patternLenght - 1 chính là vị trí xuất hiện của pattern trong text
        if (z[i] == patternLength) {
            occurrences.push_back(i - patternLength - 1);
        }
    }

    return occurrences;
}

int main() {
    string text, pattern;
    cout << "nhập xâu lớn: \n";
    cin >> text;
    cout << "nhập xâu con: \n";
    cin >> pattern;

    vector<int> result = findPatternOccurrences(text, pattern);

    cout << "Pattern xuất hiện ở các vị trí: ";
    for (int pos : result) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
