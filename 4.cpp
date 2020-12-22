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

void pushHead(int n, Node** curr) {
  Node *temp = createNode(n); 
    temp->next = *curr; 
    *curr = temp; 
}

void print(Node* curr){                                       
  while(curr) { 
    if(curr->next == NULL){
      printf("%d\n", curr->n); 
      curr = curr->next; 
    }
    else{
      printf("%d -> ", curr->n);
      curr = curr->next;
    }
  }
}

void rmDupe(Node* ans){
  Node* curr = ans;
  Node* afterNext;

  if(curr == NULL) return;

  while(curr->next != NULL){
    if(curr->n == curr->next->n){
      afterNext = curr->next->next;
      free(curr->next);
      curr->next = afterNext;
    }
    else curr = curr->next;
  }
}

int main(){

  Node* ans = NULL;
  pushHead(5, &ans);
  pushHead(5, &ans);
  pushHead(5, &ans);
  pushHead(4, &ans);
  pushHead(4, &ans);
  pushHead(3, &ans);
  pushHead(2, &ans);
  pushHead(1, &ans);
  pushHead(1, &ans);
  rmDupe(ans);
  print(ans);
  return 0;
}
