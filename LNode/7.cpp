// 19. 删除链表的倒数第 N 个结点

//在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 next 指针指向链表的头节点。这样一来，我们就不需要对头节点进行特殊的判断了。

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

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* current = head;
    int length = 0;
    while(current != nullptr)
    {
        length++;
        current = current->next;
    }

    //指向哑节点，这样处理第一个节点就跟处理其他节点的操作是一样的了！！！
    ListNode dummyNode(-1);
    dummyNode.next = head;
    current = &dummyNode;
    int order = length - n;

    while(order--)
    {
        current = current->next;
    }
    current->next = current->next->next;

    return dummyNode.next;
}

int main()
{
    vector<int> v1 = {1,3,5,7,8};
    ListNode* list1 = CreateList(v1);
    PrintList(list1);
    ListNode* merged = removeNthFromEnd(list1,2);
    PrintList(merged);
}