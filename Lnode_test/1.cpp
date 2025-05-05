//相交链表
//PA指针遍历完A后，重新指向B节点，PB指针遍历完B后，重新指向A节点。
//PA和PB相遇的时候，这个节点就是相交的起始节点。如果不相交，这两个指针最后都会指向nullptr
#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) :val(x) , next(nullptr){}
}; 

ListNode* CreateNode(vector<int> v)
{
    ListNode dummmy(-1);
    //等价
    ListNode dummy = ListNode(-1);
    ListNode* current = &dummmy;
    int length = v.size();
    for(int i = 0; i < length ; i++)
    {
        ListNode* Node = new ListNode(v[i]);
        current->next = Node;
        current = current->next;
    }
    return dummmy.next;
}

void PrintNode(ListNode* list)
{
    while(list != nullptr)
    {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

ListNode*CrossNode(ListNode* headA, ListNode* headB)
{
    if(!headA || !headB)
    {
        return nullptr;
    }
    ListNode* pa = headA;
    ListNode* pb = headB;
    while(pa != pb)
    {
        pa = pa ? pa->next : headB;
        pb = pb ? pb->next : headA;
    }
    return pb;
}
int main()
{
    vector<int> v ={1,2,3,4,5};
    // ListNode* result = CreateNode(v);
    ListNode* HeadA = new ListNode(1);
    HeadA->next = new ListNode(3);
    HeadA->next->next = new ListNode(2);
    ListNode* HeadB = new ListNode(0);
    HeadB->next =  HeadA->next->next;
    ListNode*result = CrossNode(HeadA, HeadB);
    cout << result->val <<endl;
}
