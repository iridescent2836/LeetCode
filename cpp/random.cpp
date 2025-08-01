#include <iostream>
#include <random>

int main() {
    // 1. 创建随机数种子
    std::random_device rd;  // 非确定性随机数
    std::mt19937 gen(rd()); // 梅森旋转引擎（常用）

    // 2. 设置分布范围：比如 1 到 100 的整数
    std::uniform_int_distribution<> dist(1, 100);

    // 3. 生成随机数
    int random_number = dist(gen);

    std::cout << "随机数是: " << random_number << std::endl;

    return 0;
}
