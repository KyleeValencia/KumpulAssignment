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

void print(Node* ans, int num){
  int len = 0;
  Node* temp = ans;
  while(temp != NULL){
    temp = temp->next;
    len++;
  }
  if(len < num) printf("The %d'th element from the back doesn't exist\n", num);
  temp = ans;

  for(int i=1; i<len-num+1; i++){
    temp=temp->next;
  }
  printf("%d is the %d'th element from the back\n", temp->n, num);
}

int main(){

  Node* ans = NULL;
  pushHead(5, &ans);
  pushHead(4, &ans);
  pushHead(3, &ans);
  pushHead(2, &ans);
  pushHead(1, &ans);
  int num;
  scanf("%d", &num); // insert n

  print(ans, num);
  return 0;
}