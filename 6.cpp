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

void reverse(Node ** ans){
  Node* curr = *ans;
  Node* prev = NULL;
  Node* next = NULL;
  while(curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *ans = prev;
}

void printRev(Node* ans){
  Node* temp = ans;
  while(temp != NULL){
    printf(" %d", temp->n);
    temp = temp->next;
  }
  printf("\n");
}

int main(){
  Node* ans = NULL;
  pushHead(5, &ans);
  pushHead(4, &ans);
  pushHead(3, &ans);
  pushHead(2, &ans);
  pushHead(1, &ans);

  reverse(&ans);
  printf("Reversed LinkedList : ");
  printRev(ans);

  return 0;
}