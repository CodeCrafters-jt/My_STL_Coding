//反转链表

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

ListNode* ReverseList(ListNode* list)
{
    ListNode* prev = NULL;  // 前一个节点
    ListNode* curr = list; // 当前节点
    
    while (curr != NULL) {
        ListNode* next = curr->next; // 暂存下一个节点
        curr->next = prev;          // 当前节点指向前一个节点
        prev = curr;                // 前一个节点移动到当前节点
        curr = next;                // 当前节点移动到下一个节点
    }
    
    return prev; // prev 最终指向反转后的头节点
}

int main()
{
    vector<int> v = {1,2,3,4,5};
    ListNode* list = CreateList(v);
    PrintList(list);
    PrintList(ReverseList(list));
}