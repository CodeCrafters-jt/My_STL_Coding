//两数相加
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){};
};

ListNode* TwoPlus(ListNode* list1, ListNode* list2)
{
    int l1 = 0;
    int l2 = 0;
    ListNode* pa = list1;
    ListNode* pb = list2;
    while(pa !=nullptr)
    {
        l1++;
        pa = pa->next;
    }

    while(pb !=nullptr)
    {
        l2++;
        pb = pb->next;
    }
    
    
    if(l1 - l2 > 0)
    {
        int chazhi = l1 - l2;
        while(chazhi--)
        {
            pb->next = new ListNode(0);
            pb = pb->next;
        }
    }
    else
    {
        int chazhi = abs(l1 - l2);
        while(chazhi--)
        {
            pa->next = new ListNode(0);
            pa = pa->next;
        }
    }

    pa = list1;
    pb = list2;
    ListNode dummy(-1);
    ListNode* merge = &dummy;
    int val = 0;
    while(pa != nullptr)
    {
        val = pa->val + pb->val + val/10;
        merge->next = new ListNode(val%10);
        merge = merge->next;
        pa = pa->next;
        pb = pb->next;
    }
    if(val >= 10)
    {
        merge->next = new ListNode(val/10);
        merge = merge->next;
    }
    merge->next = nullptr;
    return dummy.next;
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

int main()
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);

    ListNode* list2 = new ListNode(3);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(9);

    ListNode* result = TwoPlus(list1, list2);
    PrintNode(result);
    return 0;
}