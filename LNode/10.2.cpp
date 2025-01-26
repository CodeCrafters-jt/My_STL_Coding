//148. 排序链表
//冒泡排序，O(n log n)
//链表长度小，链表已经接近有序的

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

ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) 
    {
        return head;  // 链表为空或只有一个节点，直接返回
    }

    ListNode* curr = head;
    bool swapped;
    
    // 外层循环，控制遍历次数
    do 
    {
        swapped = false;
        curr = head;

        // 内层循环进行相邻节点的比较和交换
        while (curr && curr->next) 
        {
            if (curr->val > curr->next->val) 
            {
                // 交换值而不是交换节点
                swap(curr->val, curr->next->val);
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped); // 如果发生了交换，继续遍历

    return head;
}


int main()
{
    vector<int> v1 = {1,3,11,7,8};
    ListNode* list1 = CreateList(v1);
    PrintList(list1);
    ListNode* mergeHead  = sortList(list1);
    PrintList(mergeHead);
}