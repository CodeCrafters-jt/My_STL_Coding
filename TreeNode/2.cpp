//94. 二叉树的中序遍历
#include <iostream>
#include <vector>
#include <algorithm> //需要使用max库
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) 
{
    if (root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// 辅助函数，用于创建一个简单的二叉树
TreeNode* createSampleTree() 
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

int main() 
{
    
    // 创建一个示例二叉树
    TreeNode* root = createSampleTree();
    
    // 获取中序遍历的结果
    int result = maxDepth(root);
    
    // 输出结果
    cout << result <<endl;

    return 0;
}
