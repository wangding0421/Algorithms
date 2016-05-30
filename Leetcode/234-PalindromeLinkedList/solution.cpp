#include "linkedlist.h"

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode* slow = new ListNode(0);
    slow->next = head;
    ListNode* fast = slow;
    while (fast && fast->next){
      slow = slow->next;
      fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    ListNode* head2 = slow->next;
    while (head2){
      if (head2->val != head->val) return false;
      head2 = head2->next;
      head = head->next;
    }
    return true;
  }
private:
  ListNode* reverseList(ListNode* head){
    ListNode* result = new ListNode(0);
    result->next = head;
    if (!head) return result->next;
    for (ListNode* p = head; p->next; ){
      ListNode* temp = p->next;
      p->next = p->next->next;
      temp->next = result->next;
      result->next = temp;
    }
    return result->next;
  }
};

int main()
{
  ListNode* head = initLinkedList(5,1);
  printLinkedList(head);

  Solution s;
  cout << s.isPalindrome(head);

  return 0;
}

