//�������ĸ���
/*
ʹ��һ����ϣ�� unordered_map<Node*, Node*> cachedNode ����¼��
ԭ�ڵ� �� �½ڵ��ӳ��
��һ��������ÿ���ڵ㣨�������ߣ�
�ڶ��������� next �� random ָ��
*/
/*ע�⣺���� next �� random ָ��ʱ��
NodeMap[pa]->next = pa->next;        // ���� ?
NodeMap[pa]->random = pa->random;    // ���� ?
NodeMap[pa]->next = NodeMap[pa->next];       // ��ȷ ?
NodeMap[pa]->random = NodeMap[pa->random];   // ��ȷ ?
*/  
#include <iostream>
#include<unordered_map>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* random;
    Node(int x)
    {
        val = x;
        next = nullptr;
        random = nullptr;
    }
};

unordered_map<Node*, Node*> NodeMap;
Node* RandomNode(Node* list)
{
    Node* pa = list;
    while(pa != nullptr)
    {
        NodeMap[pa] = new Node(pa->val);
        pa = pa->next;
    }

    pa = list;
    while(pa != nullptr)
    {
        NodeMap[pa]->next = NodeMap[pa->next];       
        NodeMap[pa]->random = NodeMap[pa->random];   
        pa = pa->next;
    }
    return NodeMap[list];
}