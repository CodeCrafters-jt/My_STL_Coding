//相交链表
//暴力解法
//暴力解法，不行的，反正的是值一样，应该是返回的节点，操作的是地址

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode* CreateList(vector<int>v)
{
    ListNode dummyHead(-1);
    ListNode* current = &dummyHead;
    for(int i = 0; i < v.size(); i++)
    {
        current->next = new ListNode(v[i]);
        current = current->next;
    }
    return dummyHead.next;
}

void PrintList(ListNode* list)
{
    while(list!=nullptr)
    {
        cout<<list->val<<"->";
        list = list->next;
    }
    cout<<"NULL"<<endl;
}

ListNode* CrossNode(ListNode*list1,ListNode*list2)
{
    if (list1 == nullptr || list2 == nullptr) 
    {
        return nullptr;
    }

    ListNode* temp1 = list1;
    while(temp1 != nullptr)
    {
        ListNode* temp2 = list2;
        while(temp2 != nullptr)
        {
            if(temp1 == temp2)
            {
                return temp1;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
    return nullptr;
}

int main()
{
    vector<int>v1 = {1,2,3,4,5};
    vector<int>v2 = {7,8,9};

    ListNode* list1 = CreateList(v1);
    ListNode* list2 = CreateList(v2);

    ListNode* temp2 = list2;
    while(temp2->next != nullptr) 
    {
        temp2 = temp2->next;
    }
    temp2->next = list1;
    // PrintList(list2);

    ListNode* result = CrossNode(list1,list2);

    cout<<result->val<<endl;
    return 0;
}