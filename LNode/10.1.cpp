//148. 排序链表
//归并排序  O(n^2)

#include <iostream>
#include <vector>
#include <unordered_map>
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



ListNode * mergeTwoLists(ListNode * l1, ListNode * l2)
{
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    if(l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }else
    {
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}

ListNode * findMid(ListNode * head)
{
    ListNode * slow = head;
    ListNode * fast = head;
    ListNode * previous = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        previous = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // split the list into two parts
    previous->next = NULL;
    return slow;
}

ListNode * mergeSort(ListNode * head)
{
    if (head->next == NULL) return head;
    ListNode * mid = findMid(head);
    ListNode * l1 = mergeSort(head);
    ListNode * l2 = mergeSort(mid);
    return mergeTwoLists(l1, l2);
}

ListNode * sortList(ListNode * head)
{
    return  (head == NULL)? NULL: mergeSort(head);
}



int main()
{
    vector<int> v1 = {1,3,11,7,8};
    ListNode* list1 = CreateList(v1);
    PrintList(list1);
    ListNode* mergeHead  = sortList(list1);
    PrintList(mergeHead);
}