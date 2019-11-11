/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * 同类型题目还有24、25、92...，都需要考虑递归实现思路
 * 参考：
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/bu-bu-chai-jie-ru-he-di-gui-di-fan-zhuan-lian-biao/
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/di-gui-si-wei-ru-he-tiao-chu-xi-jie-by-labuladong/
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
