//94. ���������������
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

// ����������ִ�еݹ����
void fun(TreeNode* root, vector<int>& p) 
{
    if (!root) 
    {
        return;
    }
    fun(root->left, p);   // �ȵݹ�������
    p.push_back(root->val); // Ȼ����ʵ�ǰ�ڵ�
    fun(root->right, p);    // ���ݹ�������
}

// ��������������������Ľ��
vector<int> inorderTraversal(TreeNode* root) 
{
    vector<int> temp; 
    fun(root, temp); 
    return temp; 
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
    vector<int> result = inorderTraversal(root);
    
    // ������
    for (int val : result) 
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
