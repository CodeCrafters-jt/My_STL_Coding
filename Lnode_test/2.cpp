//反转链表
// pre指向当前节点的前一个节点，next指向当前节点的后一个节点
// pre = current; current = next; 然后pre以及current分别像后移一位，最后返回pre
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode (int x) : val(x), next(nullptr) {}
};

ListNode* CreateList(vector<int> v)
{
    ListNode dummy(-1);
    //等价
    ListNode dummy = ListNode(-1);
    ListNode* current = &dummy;
    for(int i = 0; i < v.size(); i++)
    {
        current->next = new ListNode(v[i]);
        current = current->next;
    }
    return dummy.next;
}

ListNode* reverse(ListNode* list)
{
    ListNode* pre = nullptr;
    ListNode* current = list;
    while(current != nullptr)
    {
        ListNode* next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    } 
    return pre;
}


int main()
{
    vector<int> v{1,2,3,4};
    ListNode* list = CreateList(v);
    ListNode* result = reverse(list);
    while(result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
}