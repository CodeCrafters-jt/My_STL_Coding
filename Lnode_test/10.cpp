//��������
/*
�����Զ����¹鲢����
�ҵ�������е㣬���е�Ϊ�ֽ磬�������ֳ�����������Ѱ��������е����ʹ�ÿ���ָ�����������ָ��ÿ���ƶ� 2 ������ָ��ÿ���ƶ� 1 ��������ָ�뵽������ĩβʱ����ָ��ָ�������ڵ㼴Ϊ������е㡣
������������ֱ�����
������������������ϲ����õ���������������������ʹ�á�21. �ϲ��������������������������ķ��������������������������кϲ���
*/
//���󷽷���
//������������ָ�룩+ �ϲ�������������(�ݹ鷨)
//������������ָ�룩+ �ϲ�������������(������)
#include <iostream>
struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//�ϲ��������������ݹ飩
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

// �鲢����������
ListNode* sortList(ListNode* head) 
{
    if (!head || !head->next) return head;

    // ����ָ�����е�
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // �ֳ���������
    // �ҵ��м�ڵ� mid�����Ͽ� mid����ǰһ���ڵ������
    ListNode* mid = slow->next;
    slow->next = nullptr;

    // �ݹ�������������
    // ���� head=[4,2,1,3]����ô sortList ���ý����� left=[4,2] right=[1,3]
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);

    // �ϲ���������õ�����
    return merge(left, right);
}

// ��ӡ����
void printList(ListNode* head) 
{
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// �������
int main() 
{
    // ����һ����������: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    // ����
    head = sortList(head);

    // ���������
    printList(head);

    return 0;
}

//�ϲ�������������
//�����汾
// ListNode* merge(ListNode* head1, ListNode* head2) 
// {
//     // ����һ���ƽڵ���Ϊ�ϲ���������
//     ListNode* dummyHead = new ListNode(0);
//     ListNode* temp = dummyHead;

//     // temp1 �� temp2 ���ڱ�����������
//     ListNode* temp1 = head1;
//     ListNode* temp2 = head2;

//     // ������������Ϊ��ʱ�����бȽϺϲ�
//     while (temp1 != nullptr && temp2 != nullptr) 
//     {
//         if (temp1->val <= temp2->val) {
//             temp->next = temp1;       // �� temp1 �ӵ���������
//             temp1 = temp1->next;      // temp1 ǰ��һ��
//         } else {
//             temp->next = temp2;       // �� temp2 �ӵ���������
//             temp2 = temp2->next;      // temp2 ǰ��һ��
//         }
//         temp = temp->next;            // ���������һλ
//     }

//     // ��� temp1 ����ʣ�ֱ࣬�ӽ���
//     if (temp1 != nullptr) 
//     {
//         temp->next = temp1;
//     }
//     // ��� temp2 ����ʣ�ֱ࣬�ӽ���
//     else if (temp2 != nullptr) 
//     {
//         temp->next = temp2;
//     }

//     // ���غϲ��������ͷ�ڵ㣨���� dummyHead��
//     return dummyHead->next;
// }
