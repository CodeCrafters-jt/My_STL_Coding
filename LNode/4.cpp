// 141环形链表
//快慢指针
//fast != nullptr && fast->next != nullptr) 这个条件是确保在链表遍历过程中不会访问到空指针
#include <iostream>
#include <vector>
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

bool hasCycle(ListNode *head) {
    ListNode*fast = head;
    ListNode*slow = head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> v = {1,3,5,3,1};
    ListNode* list = CreateList(v);
    PrintList(list);
    cout << hasCycle(list) << endl;
}