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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *A = headA, *B = headB;

    if (A == nullptr || B == nullptr)
      return nullptr;
    while (A != nullptr && B != nullptr && A != B) {
      A = A->next;
      B = B->next;

      if (A == B)
        return A;

      // To make them at equidistant from each other
      if (A == nullptr)
        A = headB;
      if (B == nullptr)
        B = headA;
    }
    return A;
  }
};