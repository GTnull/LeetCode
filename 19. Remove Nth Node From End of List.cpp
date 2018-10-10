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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *last = dummy, *first = dummy;
        while (n--)
            first = first->next;
        while (first->next)
        {
            first = first->next;
            last = last->next;
        }
        last->next = last->next->next;

        return dummy->next;
    }
};