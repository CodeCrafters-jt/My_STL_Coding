//94. 二叉树的中序遍历
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 辅助函数，执行递归遍历
void fun(TreeNode* root, vector<int>& p) 
{
    if (!root) 
    {
        return;
    }
    fun(root->left, p);   // 先递归左子树
    p.push_back(root->val); // 然后访问当前节点
    fun(root->right, p);    // 最后递归右子树
}

// 主函数，返回中序遍历的结果
vector<int> inorderTraversal(TreeNode* root) 
{
    vector<int> temp; 
    fun(root, temp); 
    return temp; 
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
    vector<int> result = inorderTraversal(root);
    
    // 输出结果
    for (int val : result) 
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
