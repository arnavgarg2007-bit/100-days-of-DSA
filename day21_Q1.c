#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node {
    int data;
    struct node *next;
};

// Function to traverse list
void traverse(struct node *head)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, x;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    // Input number of elements
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        // Create new node
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        // If first node
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Traverse and print
    traverse(head);

    return 0;
}