#include <bits/stdc++.h>
using namespace std;

// 题目1：A + B Problem
void problem1() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
}

// 题目2：多组输入的 A + B
void problem2() {
    int a, b;
    while (cin >> a >> b && (a != 0 || b != 0)) {
        cout << a + b << endl;
    }
}

// 题目3：字符串反转
void problem3() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    cout << s << endl;
}

// 题目4：数组排序
void problem4() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// 题目5：矩阵转置
void problem5() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            cout << mat[i][j] << (i == m-1 ? '\n' : ' ');
        }
    }
}

// 题目6：整行输入
void problem6() {
    cin.ignore(); // 如果之前有 cin >>，先清掉换行符
    string line;
    cout << "请输入一行文本: ";
    getline(cin, line);  // 读取整行，包括空格
    cout << "你输入的内容是: " << line << endl;
}

int main() {
    // 调用题目函数
    // problem1();
    // problem2();
    // problem3();
    // problem4();
    // problem5();
    // problem6();

    return 0;
}
