#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
