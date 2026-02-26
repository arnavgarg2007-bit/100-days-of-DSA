#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Function to create list
struct node* createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int x;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

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
    return head;
}

// Function to merge two sorted lists
struct node* merge(struct node *l1, struct node *l2)
{
    struct node *result = NULL, *temp = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));

        if (l1->data < l2->data)
        {
            newnode->data = l1->data;
            l1 = l1->next;
        }
        else
        {
            newnode->data = l2->data;
            l2 = l2->next;
        }
        newnode->next = NULL;

        if (result == NULL)
        {
            result = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Remaining elements
    while (l1 != NULL)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = l1->data;
        newnode->next = NULL;

        if (result == NULL)
        {
            result = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        l1 = l1->next;
    }

    while (l2 != NULL)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = l2->data;
        newnode->next = NULL;

        if (result == NULL)
        {
            result = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        l2 = l2->next;
    }

    return result;
}

// Traverse list
void traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, m;

    scanf("%d", &n);
    struct node *list1 = createList(n);

    scanf("%d", &m);
    struct node *list2 = createList(m);

    struct node *merged = merge(list1, list2);

    traverse(merged);

    return 0;
}