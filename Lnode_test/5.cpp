//合并两个有序链表
//错误点： 中间是&&      while(pa != nullptr && pb != nullptr)
//一种是迭代的解法，一种是递归的解法
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {};
};

//合并两个有序链表（递归法）
ListNode* merge(ListNode* l1, ListNode* l2) 
{
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) 
    {
        l1->next = merge(l1->next, l2);
        return l1;
    } 
    else 
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

//合并两个有序链表（迭代法）
ListNode* merge(ListNode* list1, ListNode* list2)
{
    // 如果其中一个链表为空，直接返回另一个链表
    if (!list1) return list2;
    if (!list1) return list2;

    ListNode dummy(-1);
    ListNode* mergelist = &dummy;
    ListNode* pa = list1;
    ListNode* pb = list2;
    while(pa != nullptr && pb != nullptr)
    {
        if(pa->val < pb->val)
        {
            mergelist->next = pa;
            mergelist = mergelist->next;
            pa = pa->next;
        }
        else
        {
            mergelist->next = pb;
            mergelist = mergelist->next;
            pb = pb->next;
        }
    }
    if(pa)
    {
        mergelist->next = pa;
    }
    if(pb)
    {
        mergelist->next = pb;
    }
    return dummy.next;
}

void PrintList(ListNode* list)
{
    while(list != nullptr)
    {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

int main()
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    // ListNode* list2 = nullptr;
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);
    ListNode* result = merge(list1, list2);
    PrintList(result);

}