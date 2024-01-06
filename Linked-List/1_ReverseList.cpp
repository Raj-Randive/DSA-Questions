/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
public:
  // Function to reverse a linked list.
  struct Node *reverseList(struct Node *head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    Node *prev, *curr, *currNext;
    prev = head;
    curr = head->next;

    if (curr->next == nullptr) {
      prev->next = nullptr;
      curr->next = prev;
      head = curr;
      return head;
    } else {
      currNext = curr->next;
    }

    // for first node
    prev->next = nullptr;

    while (currNext) {
      curr->next = prev;
      prev = curr;
      curr = currNext;
      currNext = currNext->next;
    }
    curr->next = prev;
    head = curr;

    return head;
  }
};
