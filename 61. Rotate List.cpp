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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *cur = dummy;
        int n = 0;
        while (cur->next)
        {
            cur = cur->next;
            n++;
        }
        if (n == 0)
            return head;
        k = k % n;
        ListNode *last = dummy, *first = dummy;
        while (k--)
            first = first->next;
        while (first->next)
        {
            first = first->next;
            last = last->next;
        }
        first->next = dummy->next;
        dummy->next = last->next;
        last->next = NULL;

        return dummy->next;
    }
};