#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_LEVEL = 16; // 最大层数
const float P = 0.5f;     // 每层晋升的概率

// 节点类
class SkipListNode {
public:
    int val;
    vector<SkipListNode*> forward;

    SkipListNode(int val, int level) : val(val), forward(level, nullptr) {}
};

// 跳表类
class SkipList {
private:
    SkipListNode* head;
    int level;

    // 随机生成层数
    int randomLevel() {
        int lvl = 1;
        while ((rand() % 100) < P * 100 && lvl < MAX_LEVEL) {
            lvl++;
        }
        return lvl;
    }

public:
    SkipList() {
        head = new SkipListNode(-1, MAX_LEVEL);
        level = 1;
        srand(time(nullptr));
    }

    // 查找
    bool search(int target) {
        SkipListNode* curr = head;

        // curr 是当前要查找的节点的前驱节点, curr->val < target, 
        for (int i = level - 1; i >= 0; --i) {
            // 循环到 curr 是小于 target 的最大值
            while (curr->forward[i] && curr->forward[i]->val < target) {
                curr = curr->forward[i];
            }
        }
        curr = curr->forward[0];
        return curr && curr->val == target;
    }

    // 插入
    void insert(int num) {
        // 存储所有前驱节点的地址
        vector<SkipListNode*> update(MAX_LEVEL);
        SkipListNode* curr = head;
        // 查找算法
        for (int i = level - 1; i >= 0; --i) {
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }

        curr = curr->forward[0];
        if (curr && curr->val == num) return; // 已存在，不插入

        int newLevel = randomLevel();
        if (newLevel > level) {
            // 新增的层数只由head指向
            for (int i = level; i < newLevel; ++i) {
                update[i] = head;
            }
            level = newLevel;
        }

        SkipListNode* newNode = new SkipListNode(num, newLevel);
        for (int i = 0; i < newLevel; ++i) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    // 删除
    bool erase(int num) {
        vector<SkipListNode*> update(MAX_LEVEL);
        SkipListNode* curr = head;

        // 查找
        for (int i = level - 1; i >= 0; --i) {
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }

        curr = curr->forward[0];
        // 并没有找到，无法删除
        if (!curr || curr->val != num) return false;


        // 从底到顶删除跳表中的跳跃
        for (int i = 0; i < level; ++i) {
            if (update[i]->forward[i] != curr) break;
            update[i]->forward[i] = curr->forward[i];
        }

        delete curr;

        // 调整当前层数
        // !head->forward[level - 1] `level`层的跳跃结构不存在
        // 等价于 while (level > 1 && head->forward[level - 1] == nullptr)
        while (level > 1 && !head->forward[level - 1]) {
            level--;
        }
        return true;
    }

    // 打印跳表（调试用）
    void printList() {
        for (int i = level - 1; i >= 0; --i) {
            SkipListNode* curr = head->forward[i];
            cout << "Level " << i << ": ";
            while (curr) {
                cout << curr->val << " ";
                curr = curr->forward[i];
            }
            cout << "\n";
        }
    }
};

// 测试函数
int main() {
    SkipList list;

    vector<int> nums = {3, 6, 7, 9, 12, 19};
    for (int x : nums) {
        list.insert(x);
    }

    cout << "初始跳表：\n";
    list.printList();

    cout << "\n查找 6：" << (list.search(6) ? "找到" : "未找到") << endl;
    cout << "查找 15：" << (list.search(15) ? "找到" : "未找到") << endl;

    cout << "\n插入 15。\n";
    list.insert(15);
    list.printList();

    cout << "\n删除 3 和 7。\n";
    list.erase(3);
    list.erase(7);
    list.printList();

    return 0;
}
