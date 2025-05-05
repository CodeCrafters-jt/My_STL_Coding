//随机链表的复制
/*
使用一个哈希表 unordered_map<Node*, Node*> cachedNode 来记录：
原节点 → 新节点的映射
第一步：复制每个节点（但不连线）
第二步：复制 next 和 random 指针
*/
/*注意：复制 next 和 random 指针时：
NodeMap[pa]->next = pa->next;        // 错误 ?
NodeMap[pa]->random = pa->random;    // 错误 ?
NodeMap[pa]->next = NodeMap[pa->next];       // 正确 ?
NodeMap[pa]->random = NodeMap[pa->random];   // 正确 ?
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