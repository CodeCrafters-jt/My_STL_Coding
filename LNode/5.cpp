//21 合并两个升序链表为一个升序链表
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


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    ListNode dummyNode(-1);
    ListNode* current = &dummyNode;
    while(list1 != nullptr && list2 != nullptr)
    {
        if(list1->val < list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if(list1 == nullptr)
    {
        current->next = list2;
    }

    if(list2 == nullptr)
    {
        current->next = list1;
    }

    return dummyNode.next;

}

int main()
{
    vector<int> v1 = {1,3,5,7,11};
    vector<int> v2 = {2,7,8};
    ListNode* list1 = CreateList(v1);
    ListNode* list2 = CreateList(v2);
    PrintList(list1);
    PrintList(list2);
    ListNode* merged = mergeTwoLists(list1,list2);
    PrintList(merged);
}