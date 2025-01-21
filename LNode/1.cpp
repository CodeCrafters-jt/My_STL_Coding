//相交链表
//暴力解法
//暴力解法，不行的，反正的是值一样，应该是返回的节点，操作的是地址

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 查找两个链表相交的节点
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) 
        {
            return nullptr;
        }
        struct ListNode *Atemp;
        struct ListNode *Btemp;
        Atemp = headA;
        while (Atemp != nullptr) {
            Btemp = headB;
            while (Btemp != nullptr) {
                if (Btemp == Atemp) {
                    return Btemp;  // 找到交点，返回交点节点
                }
                Btemp = Btemp->next;
            }
            Atemp = Atemp->next;
        }
        return nullptr;  // 如果没有交点，返回nullptr
    }
};

ListNode *CreateList(vector<int> v)
{
    ListNode dummyHead(-1);
    ListNode *current = &dummyHead;
    // for (int val : v)
    // {
    //     current->next = new ListNode(v);
    //     current = current->next;
    // }
    for (int i = 0; i < v.size(); i++)
    {
        current->next = new ListNode(v[i]);
        current = current->next;
    }
    //返回 next是头节点，返回 dummyhead是哑头节点
    return dummyHead.next;
}
void PrintList(ListNode *Node) {
    while (Node != nullptr) {
        cout << Node->val << "->";
        Node = Node->next;
    }
    cout << "Null" << endl;
}

int main() {
    // 创建两个链表
    vector<int> list1 = {4, 1, 8, 4, 5};  // 链表 A
    vector<int> list2 = {5, 0, 1};        // 链表 B
    // 链表 A：4 -> 1 -> 8 -> 4 -> 5
    // 链表 B：5 -> 0 -> 1
    ListNode *headA = CreateList(list1);
    ListNode *headB = CreateList(list2);

    // 假设两个链表在节点 8 处相交
    ListNode *intersectNode = headA;
    while (intersectNode != nullptr && intersectNode->val != 8) {
        intersectNode = intersectNode->next;
    }
    // 让 list2 指向与 list1 相交的部分
    // A 链表： 4 -> 1 -> 8 -> 4 -> 5
    // B 链表： 5 -> 0 -> 1 -> 8 -> 4 -> 5
    ListNode *temp = headB;
    while (temp != nullptr && temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        temp->next = intersectNode;  // 强行让 B 链表与 A 链表相交
    }

    Solution solution;
    ListNode *intersection = solution.getIntersectionNode(headA, headB);

    if (intersection != nullptr) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection." << endl;
    }

    return 0;
}
