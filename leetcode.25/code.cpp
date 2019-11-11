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
    /**
     * 给定头尾指针的链表反转函数
     * 需要定义二级指针或使用引用，否则ListNode* 仍然是一个值传递
     **/
    void reverseList(ListNode*& head, ListNode*& tail) {
        // 头尾节点相同时，直接返回即可
        if (head == tail) return;
        
        ListNode* p = head;
        ListNode* q = p->next;
        
        while (q != tail) {
            p->next = q->next;
            q->next = head;
            head = q;
            q = p->next;
        }
        
        q->next = head;
        head = q;
        tail = p;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 定义一个虚拟头结点可以实现处理统一化
        ListNode* virtual_head = new ListNode(0);
        virtual_head->next = head;
        // 记录局部反转链表的前一节点
        ListNode* pre = virtual_head;
        
        while (pre->next != NULL) {
            // 找到局部反转的头和尾
            ListNode* first = pre->next;
            ListNode* last = pre->next;
            for (int i = 1; i < k; ++i) {
                if (last == NULL) break;
                last = last->next;
            }
            if (last == NULL) break;
            
            // 记录局部反转链表的后一节点
            ListNode* post = last->next;
            
            reverseList(first, last);
            
            // 状态推进
            pre->next = first;
            last->next = post;
            pre = last;
        }
        
        return virtual_head->next;
    }
};


// 执行结果：
// 通过
// 显示详情
// 执行用时 :24 ms, 在所有 cpp 提交中击败了90.35%的用户
// 内存消耗 :9.6 MB, 在所有 cpp 提交中击败了97.03%的用户
