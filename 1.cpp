#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

int main(int argc, char const *argv[])
{
    int n, a[200], insert, trans;
    struct node *head, *p, *q, *t, *flag;
    head = NULL;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (a[j] < a[j+1])
            {
                trans = a[j];
                a[j] = a[j+1];
                a[j+1] = trans;
            }
            
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a[i];
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            q->next = p;
        }
        q = p;
    }
    //test
    // t = head;
    // while (t != NULL)
    // {
    //     printf("%d ", t->data);
    //     t = t->next;
    // }
    
    printf("\nPlease input the number you want to insert:\n");
    scanf("%d", &insert);
    
    for (t = head; t != NULL; t = t->next)
    {
        if (t->next == NULL || t->next->data < insert)
        {
            if (head->data < insert)
            {
                p = (struct node *)malloc(sizeof(struct node));
                p->data = insert;
                p->next = head;
                flag = p;
            }
            else
            {
                flag = head;
                p = (struct node *)malloc(sizeof(struct node));
                p->data = insert;
                p->next = t->next;
                t->next = p;
                break;
            }
        }
    }

    for (t = flag; t != NULL; t = t->next)
    {
        printf("%d ", t->data);
    }

    printf("\n");
    system("pause");

    return 0;
}
