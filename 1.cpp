#include <stdio.h>
#include <stdlib.h>

struct Node {
  int n;
  Node *next; 
} *head, *tail; 

Node *createNode(int n) {
  Node *newNode = (Node*)malloc(sizeof(Node)); 
  newNode->n = n;
  newNode->next = NULL; 
  return newNode;
}

void pushHead(int n, Node** curNode) {
  Node *temp = createNode(n); 
    temp->next = *curNode; 
    *curNode = temp; 
  
}

void printLinkedList(Node* curNode){                                       
  while(curNode) { 
    if(curNode->next == NULL){
      printf("%d\n", curNode->n); 
      curNode = curNode->next; 
    }
    else{
      printf("%d -> ", curNode->n);
      curNode = curNode->next;
    }
  }
}

Node* merge(Node *l1, Node *l2){
  Node* ans = NULL;
  if(l1 == NULL) return l2;
  else if(l2 == NULL) return l1;

  if(l1->n <= l2->n){
    ans = l1;
    ans->next = merge(l1->next, l2);
  }
  else{
    ans = l2;
    ans->next = merge(l1, l2->next);
  }
  return ans;
}

int main(){

  Node* l1 = NULL;
  Node* l2 = NULL;
  Node* ans = NULL;
  int n,m,temp;
  scanf("%d %d", &m, &n);

  for(int i=0; i<m; i++){
    scanf("%d", &temp);
    pushHead(temp, &l1);
  }
  for(int i=0; i<n; i++){
    scanf("%d", &temp);
    pushHead(temp, &l2);
  }

  ans = merge(l1, l2);
  printLinkedList(ans);
  return 0;
}