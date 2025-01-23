//回文链表

//复制链表值到数组中。
//使用双指针法判断是否为回文。
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode (int x): val(x),next(nullptr){}
};

ListNode* CreateList(vector<int>v)
{
    ListNode dummyNode(-1);
    ListNode* current = &dummyNode;
    for(int i = 0;i < v.size();i++)
    {
        current->next = new ListNode(v[i]);
        current = current->next;
    }
    return dummyNode.next;
}

void PrintList(ListNode* list)
{
    while(list!=nullptr)
    {
        cout << list->val << "->";
        list = list->next;
    }
    cout << "NULL" << endl;
}

bool isPalindrome(ListNode* head) 
{
    vector<int> v;
    ListNode* list = head;
    while(list!=nullptr)
    {
        v.push_back(list->val);
        list = list->next;
    }
    for(int i = 0, j = v.size()-1; i < v.size() / 2; i++, j--)  //i < j
    {
        if(v[i] != v[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> v = {1,3,5,3,1};
    ListNode* list = CreateList(v);
    PrintList(list);
    cout << isPalindrome(list) << endl;
}