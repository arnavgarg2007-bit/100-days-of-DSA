#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Create list
struct node* createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode;
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

// Delete first occurrence of key
struct node* deleteKey(struct node *head, int key)
{
    struct node *temp = head, *prev = NULL;

    // If key is at first node
    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search key
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key found
    if (temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }

    return head;
}

// Traverse
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
    int n, key;

    scanf("%d", &n);
    struct node *head = createList(n);

    scanf("%d", &key);

    head = deleteKey(head, key);

    traverse(head);

    return 0;
}