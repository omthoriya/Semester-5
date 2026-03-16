#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(int item)
{
    if(rear == MAX-1)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1)
            front = 0;
        queue[++rear] = item;
    }
}

void delete()
{
    if(front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
        printf("Deleted: %d\n", queue[front++]);
}

void display()
{
    int i;
    if(front == -1)
        printf("Queue Empty\n");
    else
    {
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

int main()
{
    int ch, item;

    while(1)
    {
        printf("\n1 Insert\n2 Delete\n3 Display\n4 Exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;
        }
    }
}