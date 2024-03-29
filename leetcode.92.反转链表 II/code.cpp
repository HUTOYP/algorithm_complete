/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 增加虚拟节点以统一代码处理逻辑
        ListNode* vir_head = new ListNode(0);
        vir_head->next = head;
        
        ListNode* pre = vir_head;
        ListNode* cur = head;
        
        int i = 1;
        while (i < m) {
            pre = pre->next;
            cur = cur->next;
            ++i;
        }
        
        ListNode* new_head = cur;
        while (i < n) {
            ListNode* p = cur->next;
            cur->next = p->next;
            p->next = new_head;
            new_head = p;
            ++i;
        }
        pre->next = new_head;
        
        return vir_head->next;
    }
};

// 执行用时 :4 ms, 在所有 cpp 提交中击败了89.10%的用户
// 内存消耗 :8.6 MB, 在所有 cpp 提交中击败了73.05%的用户
