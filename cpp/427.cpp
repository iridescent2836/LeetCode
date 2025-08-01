#include "header.h"


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// a wrong answer, but i don't see any mistake in this logic. 
class Solution {
public:
    
    Node* helper(int left, int right, int top, int bottom, const vector<vector<int>>& grid){
        if(left == right && top == bottom) return new Node(grid[left][top], true);
        
        int colMid = (left + right) >> 1;
        int rowMid = (top + bottom) >> 1;
        Node* topLeft = helper(left,colMid,top,rowMid,grid);
        Node* topRight = helper(colMid+1,right,top,rowMid,grid);
        Node* bottomLeft = helper(left,colMid,rowMid+1,bottom,grid);
        Node* bottomRight = helper(colMid+1,right,rowMid+1,bottom,grid);
        
        //如果所有子节点均为值相同的叶子节点，则删除这些子节点，将当前节点作为叶子节点
        if(topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf 
        && topLeft->val == topRight->val && topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val){
            Node* ret = new Node(topLeft->val, true);
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;

            return ret;
        }

        else return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);     
    }
    Node* construct(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0)  return nullptr;
        int col = grid[0].size();
        if(col != row)
        {
            cerr << "Invalid input: grid must be N x N."  << endl;
            exit(1);
        }
        return helper(0,row-1,0,row-1,grid);
    }
};


// workable solution given by GPT. ChatGPT is so powerful!
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }

    Node* build(const vector<vector<int>>& grid, int x, int y, int length) {
        if (isUniform(grid, x, y, length)) {
            return new Node(grid[x][y], true);
        }

        int half = length / 2;
        Node* topLeft = build(grid, x, y, half);
        Node* topRight = build(grid, x, y + half, half);
        Node* bottomLeft = build(grid, x + half, y, half);
        Node* bottomRight = build(grid, x + half, y + half, half);

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    bool isUniform(const vector<vector<int>>& grid, int x, int y, int length) {
        int val = grid[x][y];
        for (int i = x; i < x + length; ++i) {
            for (int j = y; j < y + length; ++j) {
                if (grid[i][j] != val) {
                    return false;
                }
            }
        }
        return true;
    }
};
    