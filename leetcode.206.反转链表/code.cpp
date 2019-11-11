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
    ListNode* reverseList(ListNode* head) {
        // 需要掌握递归实现的方法
        if (head == NULL || head->next == NULL) return head;

        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return last;
    }
};

// 执行用时 :8 ms, 在所有 cpp 提交中击败了97.11%的用户
// 内存消耗 :9.3 MB, 在所有 cpp 提交中击败了5.08%的用户
