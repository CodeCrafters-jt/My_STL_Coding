//排序链表
/*
链表自顶向下归并排序
找到链表的中点，以中点为分界，将链表拆分成两个子链表。寻找链表的中点可以使用快慢指针的做法，快指针每次移动 2 步，慢指针每次移动 1 步，当快指针到达链表末尾时，慢指针指向的链表节点即为链表的中点。
对两个子链表分别排序。
将两个排序后的子链表合并，得到完整的排序后的链表。可以使用「21. 合并两个有序链表」的做法（迭代的方法），将两个有序的子链表进行合并。
*/
//两大方法：
//环形链表（快慢指针）+ 合并两个有序链表(递归法)
//环形链表（快慢指针）+ 合并两个有序链表(迭代法)
#include <iostream>
struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//合并两个有序链表（递归）
ListNode* merge(ListNode* l1, ListNode* l2) 
{
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) 
    {
        l1->next = merge(l1->next, l2);
        return l1;
    } 
    else 
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// 归并排序主函数
ListNode* sortList(ListNode* head) 
{
    if (!head || !head->next) return head;

    // 快慢指针找中点
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 分成左右两段
    // 找到中间节点 mid，并断开 mid与其前一个节点的连接
    ListNode* mid = slow->next;
    slow->next = nullptr;

    // 递归排序左右两段
    // 比如 head=[4,2,1,3]，那么 sortList 调用结束后 left=[4,2] right=[1,3]
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);

    // 合并两个排序好的链表
    return merge(left, right);
}

// 打印链表
void printList(ListNode* head) 
{
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// 构造测试
int main() 
{
    // 创建一个无序链表: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    // 排序
    head = sortList(head);

    // 输出排序结果
    printList(head);

    return 0;
}

//合并两个有序链表
//迭代版本
// ListNode* merge(ListNode* head1, ListNode* head2) 
// {
//     // 创建一个哑节点作为合并链表的起点
//     ListNode* dummyHead = new ListNode(0);
//     ListNode* temp = dummyHead;

//     // temp1 和 temp2 用于遍历两个链表
//     ListNode* temp1 = head1;
//     ListNode* temp2 = head2;

//     // 当两个链表都不为空时，进行比较合并
//     while (temp1 != nullptr && temp2 != nullptr) 
//     {
//         if (temp1->val <= temp2->val) {
//             temp->next = temp1;       // 把 temp1 接到新链表上
//             temp1 = temp1->next;      // temp1 前进一步
//         } else {
//             temp->next = temp2;       // 把 temp2 接到新链表上
//             temp2 = temp2->next;      // temp2 前进一步
//         }
//         temp = temp->next;            // 新链表后移一位
//     }

//     // 如果 temp1 还有剩余，直接接上
//     if (temp1 != nullptr) 
//     {
//         temp->next = temp1;
//     }
//     // 如果 temp2 还有剩余，直接接上
//     else if (temp2 != nullptr) 
//     {
//         temp->next = temp2;
//     }

//     // 返回合并后的链表头节点（跳过 dummyHead）
//     return dummyHead->next;
// }
