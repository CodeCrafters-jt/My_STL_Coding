//94. ���������������
#include <iostream>
#include <vector>
#include <algorithm> //��Ҫʹ��max��
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

// �������������ڴ���һ���򵥵Ķ�����
TreeNode* createSampleTree() 
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

int main() 
{
    
    // ����һ��ʾ��������
    TreeNode* root = createSampleTree();
    
    // ��ȡ��������Ľ��
    int result = maxDepth(root);
    
    // ������
    cout << result <<endl;

    return 0;
}
