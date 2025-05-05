//�ཻ����
//PAָ�������A������ָ��B�ڵ㣬PBָ�������B������ָ��A�ڵ㡣
//PA��PB������ʱ������ڵ�����ཻ����ʼ�ڵ㡣������ཻ��������ָ����󶼻�ָ��nullptr
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
    //�ȼ�
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
