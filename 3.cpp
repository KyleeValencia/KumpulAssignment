#include <stdio.h>
#include <stdlib.h>

struct Node{
  int n;
  Node *next;
}*head, *tail;

Node *createNode(int n) {
  Node *newNode = (Node*)malloc(sizeof(Node)); 
  newNode->n = n;
  newNode->next = NULL; 
  return newNode;
}

void pushHead(int n) {
  Node *temp = createNode(n);
  if(!head) head = tail = temp;
   else{
    temp->next = head; 
    head = temp; 
   }
}

void findMid(){
  int len = 1;
  Node* ans = head;
  if(!head) return;

  while(ans->next){
    len++;
    ans = ans->next;
  }
  len /= 2;
  Node* temp = head;
  while(len > 0){
    temp = temp->next;
    len--;
  }
  printf("Middle Element is : %d\n", temp->n);
  return;
}

int main(){

  Node* ans = NULL;
  pushHead(1);
  pushHead(2);
  pushHead(3);
  pushHead(4);
  pushHead(5);
  findMid();

  return 0;
}