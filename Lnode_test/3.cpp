//╩ьнда╢╠М
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* CreateListNode(vector<int> v)
{
    ListNode dummy(-1);
    ListNode* current = &dummy;
    for(int i = 0; i < v.size(); i++)
    {
        current->next = new ListNode(v[i]);
        current = current->next;
    }
    return dummy.next;
}

bool huiwen(ListNode* list)
{
    vector<int> v;
    while(list != nullptr)
    {
        v.push_back(list->val);
        list = list->next;
    }
    for(int i = 0, j = v.size()-1; i < v.size()/2; i++, j--)
    {
        if(v[i] != v[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(2);
    list->next->next->next->next = new ListNode(2);

    cout << huiwen(list) << endl;
}
