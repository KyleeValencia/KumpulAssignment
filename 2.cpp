#include <stdio.h>
#include <stdlib.h>

struct Node{
  int n;
  int flag;
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

bool findLoop(Node* f){
  while(f != NULL){
    if(f->flag == 1) return true;
    else{
      f->flag = 1;
      f = f->next;
    }
  }
  return false;
}

int main(){
  Node* ans = NULL;

  pushHead(20, &ans);
  pushHead(15, &ans);
  pushHead(10, &ans);
  pushHead(5, &ans);

  ans->next->next->next->next = ans;

  if(findLoop(ans)) printf("Loop Detected\n");
  else printf("Loop Not Found\n");
  return 0;
}