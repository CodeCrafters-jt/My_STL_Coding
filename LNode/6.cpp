// 2 两数相加

// 获取两个链表所对应的长度
// 在较短的链表末尾补零
// 对齐相加考虑进位

/*两数逆序存储，相加的话还是向后进位的
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
    9,9,9,9,9,9,9
   +9,9,9,9,0,0,0
    8,9,9,9,0,0,0,1
*/

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode* p = l1;
    ListNode* q = l2;
    int l1_len = 1;
    int l2_len = 1;
    while(p->next != nullptr)
    {
        l1_len++;
        p = p->next;
    }

    while(q->next != nullptr)
    {
        l2_len++;
        q = q->next;
    }

    int diff = l1_len - l2_len;
    if(diff > 0)
    {
        while(diff--)
        {
            ListNode* node = new ListNode(0);
            q->next = node;
            q = q->next;
        }
    }
    else
    {
        int a_diff = abs(diff);
        while(a_diff--)
        {
            ListNode* node = new ListNode(0);
            p->next = node;
            p = p->next;
        }
    }

    // return l2;
    int val = 0;
    int val_next = 0;
    ListNode dummyNode(-1);
    ListNode* current = &dummyNode;
    
    while(l1 != nullptr)
    {
        val = l1->val + l2->val + val_next;
        ListNode* node = new ListNode(val%10);
        val_next = val / 10;
        current->next = node;
        current = current->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    if(val_next > 0)
    {
        ListNode* node = new ListNode(val_next);
        current->next = node;
    }

    return dummyNode.next;
}

int main()
{
    vector<int> v1 = {1,3,5,7,8};
    vector<int> v2 = {2,7,8};
    ListNode* list1 = CreateList(v1);
    ListNode* list2 = CreateList(v2);
    PrintList(list1);
    PrintList(list2);
    ListNode* merged = addTwoNumbers(list1,list2);
    PrintList(merged);
}