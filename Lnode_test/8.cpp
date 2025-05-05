//两两交换链表中的节点
//没写出来，while里面的东西要看一下
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* SwapNode(ListNode* list)
{
    ListNode dummy(-1);
    dummy.next = list;
    ListNode* current = &dummy;
    while(current->next != nullptr && current->next->next != nullptr)
    {
        ListNode* Node1 = current->next;
        ListNode* Node2 = current->next->next;
        current->next = Node2;
        Node1->next = Node2->next;
        Node2->next = Node1;
        current = Node1;
    }
    return dummy.next;
}

void PrintNode(ListNode* list)
{
    while(list!=nullptr)
    {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

int main()
{
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    ListNode* result = SwapNode(list);
    PrintNode(result);
}