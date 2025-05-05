//ɾ������ĵ����� N �����  
//ע�⣺ pa->next= pa->next->next������ ����pa= pa->next->next
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

ListNode* DeleteNode(ListNode* list, int n)
{
    int length = 0;
    ListNode* pa = list;
    while(pa != nullptr)
    {
        length++;
        pa = pa->next;
    }
    ListNode dummy(-1);
    dummy.next = list;
    pa = &dummy;
    int order = length - n;
    while(order--)
    {
        pa = pa->next;
    }
    ListNode* temp = pa->next;
    pa->next= pa->next->next;
    delete temp;
    return dummy.next;
}

void PrintNode(ListNode* list)
{
    while(list !=nullptr)
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
    list->next->next->next->next = new ListNode(5);
    ListNode*result = DeleteNode(list,1);
    PrintNode(result);
}
