#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* newNode() //make a new node//
{
    struct node *n = ((struct node *)malloc(sizeof(struct node)));
    return n;
}
int loop = 0;
int no,players,c = 1;
struct node *head=NULL;
void create()
{
    struct node *item,*end;

    printf("\nEnter the no of players you want in the circle: ");
    scanf("%d",&players);
    do
    {
        no = c;
        item=newNode();
        item->data=no;
        item->next=NULL;

        if(head == NULL)
        {
            head = item;
            item->next = head;
        }
        else
        {
            end = head;
            while(end->next != head)
            {
                end = end->next;
            }
            end->next = item;
            item->next = head;
        }
        c ++;
    }while(c != players + 1);
}
void display()
{
    struct node *item;
    item=head;
    do
    {
        printf("\t%d",item->data);
        item=item->next;
    }
    while(item!=head);
}
void jos(int j)
{
    struct node *ptr, *preptr, *postptr;
    ptr = newNode();
    preptr = newNode();
    postptr = newNode();
    ptr = preptr = postptr = head;
    do
    {
        preptr = ptr;
        ptr = ptr->next;
        printf("\n%d was killed by %d",ptr->data,preptr->data);
        preptr->next = ptr->next;
        free (ptr);
        ptr = preptr->next;
        head = ptr;
        players --;
        loop ++;
    }while(ptr != preptr);
}
int main()
{
    printf("\nJust a temporary change for learning git bash.");
    create();
    display();
    jos(players);
    printf("\nThe last man standing is: ");
    display();
//    printf("\n%d",loop);
    return 0;
}
