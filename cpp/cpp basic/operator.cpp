#include <iostream>
using namespace std;

struct Point {
    int x, y;

    // 加法运算符重载
    Point operator+(const Point& p) const {
        return {x + p.x, y + p.y};  // 当前对象的 x/y 加上传入参数 p 的 x/y
    }

    void print() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};


int main() {
    Point a{1, 2};
    Point b{3, 4};

    Point c = a + b;  // 会调用 a.operator+(b)

    c.print();  // 输出 (4, 6)
    return 0;
}
