//138. 随机链表的复制
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

class Node 
{
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) 
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
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

unordered_map<Node*, Node*> cachedNode;

Node* copyRandomList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (!cachedNode.count(head)) {
        Node* headNew = new Node(head->val);
        cachedNode[head] = headNew;
        headNew->next = copyRandomList(head->next);
        headNew->random = copyRandomList(head->random);
    }
    return cachedNode[head];
}

int main()
{
    vector<int> v1 = {1,3,5,7,8};
    ListNode* list1 = CreateList(v1);
    PrintList(list1);
    // ListNode* swapHead  = swapPairs(list1);
    // PrintList(swapHead);
}