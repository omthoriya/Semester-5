#include <stdio.h>
#define SIZE 5

struct stack
{
    int a[SIZE];
    int top;
} s;

void push(int item)
{
    if(s.top == SIZE-1)
        printf("Stack Overflow\n");
    else
        s.a[++s.top] = item;
}

void pop()
{
    if(s.top == -1)
        printf("Stack Underflow\n");
    else
        printf("Deleted: %d\n", s.a[s.top--]);
}

void display()
{
    int i;
    if(s.top == -1)
        printf("Stack Empty\n");
    else
    {
        printf("Stack:\n");
        for(i = s.top; i >= 0; i--)
            printf("%d\n", s.a[i]);
    }
}

void peep()
{
    if(s.top == -1)
        printf("Stack Empty\n");
    else
        printf("Top Element: %d\n", s.a[s.top]);
}

void change(int pos, int val)
{
    if(pos > s.top || pos < 0)
        printf("Invalid Position\n");
    else
        s.a[pos] = val;
}

int main()
{
    int ch, item, pos, val;
    s.top = -1;

    while(1)
    {
        printf("\n1 Push\n2 Pop\n3 Display\n4 Peep\n5 Change\n6 Exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peep();
                break;

            case 5:
                printf("Enter position and new value: ");
                scanf("%d %d", &pos, &val);
                change(pos, val);
                break;

            case 6:
                return 0;
        }
    }
}