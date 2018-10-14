/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return NULL;
        ListNode *slow = head->next, *fast = head->next->next;
        while (slow != fast)
        {
            if (!fast->next || !fast->next->next)
                return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }
        while (slow != head)
        {
            slow = slow->next;
            head = head->next;
        }
        return head;
    }
};