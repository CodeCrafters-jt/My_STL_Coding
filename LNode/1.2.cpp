// 1 首先判断链表是否相交
//    相交的标志：两个链表的尾结点的地址是一样的
//    不相交的标志：两个链表尾结点的地址不同，直接返回NULL

// 2 若是链表相交
//    a 求出两个链表长度的差
//    b 长链表先走差值步，使之与较短的链表处在同一起跑线上
//    c  长短链表同时遍历，当遍历到同一个结点时，找到相交的起始结点
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
        cout<<list->val<<"->";
        list = list->next;
    }
    cout<<"NULL"<<endl;
}

ListNode* CrossNode(ListNode* list1,ListNode* list2)
{
    if (list1 == nullptr || list2 == nullptr) 
    {
        return nullptr;
    }

    ListNode* temp1 = list1;
    ListNode* temp2 = list2;
    int a_num = 1;
    int b_num = 1;

    while(temp1->next != nullptr)
    {
        temp1 = temp1->next;
        a_num++;
    }

    while(temp2->next != nullptr)
    {
        temp2 = temp2->next;
        b_num++;
    }

    if(temp1 != temp2)
    {
        return nullptr;
    }

    temp1 = list1;
    temp2 = list2;
    int distance = b_num-a_num;
    
    if(distance > 0)
    {
        while(distance--)
        {
            temp2 = temp2->next;
        }
    }
    else
    {
        distance = abs(distance);
        while(distance--)
        {
            temp1 = temp1->next;
        }
    }

    while(temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return temp1;
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
    ListNode* result =  CrossNode(list1,list2);
    cout << "value:" << result->val << endl;
    return 0;
}