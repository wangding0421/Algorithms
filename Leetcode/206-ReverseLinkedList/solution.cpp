#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* result = new ListNode(0);
    if (!head) return result->next;
    result->next = head;
    for (ListNode* p = head; p->next != nullptr; ){
      ListNode* temp = p->next;
      p->next = p->next->next;
      temp->next = result->next;
      result->next = temp;
    }
    return result->next;
  }
};

void printLinkedList(ListNode* head){
  ListNode* p = head;
  while (p){
    cout << p->val << endl;
    p = p->next;
  }
}

int main()
{
  ListNode* head = new ListNode(1);
  ListNode* p = head;
  for (int i = 0; i < 4; i++){
    p->next = new ListNode(i+2);
    p = p->next;
  }

  printLinkedList(head);

  Solution s;
  printLinkedList(s.reverseList(head));

  return 0;
}
