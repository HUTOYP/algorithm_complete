/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*
 * 24题和25题类似，这里提供一个特异化的处理方式
 * 24、25和92题都使用了虚拟头节点的方式统一处理流程，尝试不使用虚拟头节点怎么做？
 * 应该想想递归如何实现，应当重视递归思想的累计
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        
        ListNode* vir_head = new ListNode(0);
        vir_head->next = head;
        
        ListNode* pre = vir_head;
        ListNode* p = head;
        
        int i = 0;
        while (p->next != NULL) {
            if (i % 2 == 0) {
                ListNode* q = p->next;
                p->next = q->next;
                q->next = p;
                pre->next = q;
                
                if (i / 2 == 0) {
                    vir_head = pre;
                }
            } else {
                pre = p;
                p = p->next;
            }
            ++i;
        }
        
        return vir_head->next;
    }
};

// 执行用时 :4 ms, 在所有 cpp 提交中击败了88.86%的用户
// 内存消耗 :8.6 MB, 在所有 cpp 提交中击败了81.80%的用户
