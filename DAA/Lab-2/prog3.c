#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void insert_begin(int val)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = start;
    start = temp;
}

void insert_end(int val)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *p = start;

    temp->data = val;
    temp->next = NULL;

    if(start == NULL)
        start = temp;
    else
    {
        while(p->next != NULL)
            p = p->next;
        p->next = temp;
    }
}

void delete_begin()
{
    if(start == NULL)
        printf("List Empty\n");
    else
    {
        struct node *temp = start;
        start = start->next;
        free(temp);
    }
}

void display()
{
    struct node *p = start;
    while(p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch, val;

    while(1)
    {
        printf("\n1 Insert Begin\n2 Insert End\n3 Delete Begin\n4 Display\n5 Exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_begin(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_end(val);
                break;

            case 3:
                delete_begin();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;
        }
    }
}