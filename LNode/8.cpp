// 24. 两两交换链表中的节点
#include <iostream>
#include <vector>
#include <math.h>
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

ListNode* swapPairs(ListNode* head) 
{
    ListNode dummyHead(-1);
    dummyHead.next = head;
    ListNode* temp = &dummyHead;
    while (temp->next != nullptr && temp->next->next != nullptr) {
        ListNode* node1 = temp->next;
        ListNode* node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }
    return dummyHead.next;
}

int main()
{
    vector<int> v1 = {1,3,5,7,8};
    ListNode* list1 = CreateList(v1);
    PrintList(list1);
    ListNode* swapHead  = swapPairs(list1);
    PrintList(swapHead);
}