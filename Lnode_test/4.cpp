//��������
//����㣺�ж�����Ӧ���� while(fast!=nullptr && fast->next!=nullptr)

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

bool CircleList(ListNode* list)
{
    if(!list || !list->next) return false;
    ListNode* slow = list;
    ListNode* fast = list;
    //��� fast �ǿգ��� fast->next �� nullptr���������� fast = fast->next->next �ᵼ�� ��ָ������ñ�����
    // ���Բ����� while(fast != nullptr && slow != nullptr)
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = list;
    cout << CircleList(list) << endl;
    return 0;
}