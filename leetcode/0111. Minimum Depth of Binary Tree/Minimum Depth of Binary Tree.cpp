#include <iostream>
#include "Minimum Depth of Binary Tree.h"
using namespace std;

int main() {

    Solution solution;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << solution.minDepth(root) << endl;
    return 0;
}