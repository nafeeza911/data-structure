#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *left,*right;
};
struct node *insert(struct node *, int);
struct node *delete(struct node *, int);
struct node *search(struct node *, int);
void display(struct node *);
int main(void)
{
struct node *start = NULL;
int item, opt;
 while (1)
{
printf("\n1. Insert \n2. Delete \n3. Search \n4. Display \n5. Exit");
printf("\n\nEnter your choice: ");
scanf("%d", &opt);
switch (opt)
{
case 1:
printf("Enter element to insert: ");
scanf("%d", &item);
start = insert(start, item);
break;
case 2:
 printf("Enter element to delete: ");
scanf("%d", &item);
start = delete(start, item);
break;
case 3:
printf("Enter the element to be searched: ");
scanf("%d", &item);
 if (search(start, item) == NULL)
printf("Element not found.\n");
else
printf("Element found.\n");
 break;
case 4:
display(start);
break;
case 5:
exit(0);
default:
printf("Invalid choice!\n");
 }
}
 return 0;
}
/* Function to insert an element into the doubly linked list */
struct node *insert(struct node *start, int data)
{
struct node *temp;
 temp = (struct node *)malloc(sizeof(struct node));
 if (temp == NULL)
{
printf("Memory allocation failed!\n");
return start;
    }
temp->data = data;
temp->left = NULL;
temp->right = start;
if (start != NULL)
start->left = temp;
 start = temp;
return start;
}
/* Function to display the doubly linked list */
void display(struct node *start)
{
struct node *s = start;
if (s == NULL)
{
printf("\nList is empty!\n");
 return;
}
printf("\nList elements are:\n");
while (s != NULL)
{
printf("%d ", s->data);
 s = s->right;
}
printf("\n");
}
/* Function to search an element */
struct node *search(struct node *start, int data)
{
while (start != NULL && data != start->data)
{
start = start->right;
}
return start;
}
/* Function to delete an element from the doubly linked list */
struct node *delete(struct node *start, int data)
{
struct node *temp;
temp = search(start, data);
if (temp == NULL)
{
 printf("Data not found.\n");
return start;
}
/* If the node is the first node */
if (temp->left == NULL)
{
start = temp->right;
if (start != NULL)
 start->left = NULL;
 }
else
{
 /* Connect previous node to next node */
 temp->left->right = temp->right;
/* If it is not the last node */
if (temp->right != NULL)
temp->right->left = temp->left;
}
free(temp);
printf("Element deleted successfully.\n");
return start;
}

