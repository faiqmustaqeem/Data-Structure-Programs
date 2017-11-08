#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void deleteNode(struct Node **start,int vtd);
int main()
{
    struct Node *start1=NULL;
    insert(&start1,1);
    insert(&start1,2);
    insert(&start1,3);
    insert(&start1,4);
    insert(&start1,5);
    print(start1);
    deleteNode(&start1,2);
    print(start1);
    return 0;
}
void insert(struct Node **start,int data)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=*start;
    *start=temp;

}
void unionOfLists(struct Node *list1,struct Node *list2)
{

}
void deleteNode(struct Node **start,int vtd)
{
    struct Node *curr=*start;
    if(curr->data==vtd)
    {
        *start=(*start)->next;
        free(curr);
    }
    else
    {
        struct Node *prev=curr;

        while(curr->next!= NULL)
        {
            prev=curr;
              curr=curr->next;
            if(curr->data == vtd)
            {
                prev->next=curr->next;
                free(curr);
                break;
            }

        }

    }
}
void print(struct Node *start)
{
    printf("\n");
    while(start!=NULL)
    {
        printf(" %d ",start->data);
        start=start->next;
    }


}
