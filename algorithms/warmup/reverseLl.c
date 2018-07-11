#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int data;
  struct node * next;
}node_t, *pnode_t;

void push (pnode_t * head, int val)
{
  pnode_t new = malloc(sizeof(node_t));
  new->data = val;
  new->next = *head;

  *head = new;
}

void pop(pnode_t * head)
{
  pnode_t trash = * head;
  if (trash == NULL)
    return;

  *head = trash->next;
  free(trash);
}

void print (pnode_t head)
{
  while (head)
  {
    printf("%d->", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

void reverse(pnode_t * head)
{
  pnode_t prev, curr, next;

  if (head == NULL || *head == NULL)
    return;

  curr = *head;
  prev = NULL;

  while(curr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  *head = prev;
}

int main(int argc, const char * argv[])
{
  pnode_t head = NULL;
  int i;

  if (argc < 2)
    printf("Pass a list of integer elements to be added to the linked list\n");

  for (i = 1; i < argc; i++)
  {
    push(&head, atoi(argv[i]));
  }

  print(head);
  reverse(&head);
  print(head);

  return 0;
}
