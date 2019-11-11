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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* q = p->next;
        
        while (q != NULL) {
            p->next = q->next;
            q->next = head;
            head = q;
            q = p->next;
        }
        return head;
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
            for (int i = 1; i < k && last != NULL; ++i) { last = last->next; }
            if (last == NULL) break;
            
            // 记录局部反转链表的后一节点
            ListNode* post = last->next;
            
            last->next = NULL;
            pre->next = reverseList(first);
            first->next = post;
            pre = first;
        }
        
        return virtual_head->next;
    }
};
