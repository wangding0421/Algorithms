#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void printLinkedList(ListNode* head){
  ListNode* p = head;
  while (p){
    cout << p->val << endl;
    p = p->next;
  }
}

ListNode* initLinkedList(int len, int initNum){
  if (!len) return nullptr;
  ListNode* head = new ListNode(initNum);
  ListNode* p = head;
  for (int i = 1; i < len; i++){
    p->next = new ListNode(initNum + i);
    p = p->next;
  }
  return head;
}

#endif /* LINKEDLIST_H */
