#include "apc.h"
#include<stdlib.h>
#include<stdio.h>

int conversion(char *argv[],int *s_num1,int *s_num2,Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR){
    int i=0,j=0;

    //sign identifaction of operands

    //operand num1
    if(argv[1][i]=='-'){
        *s_num1=-1;       //-1 for -ve
        i++;
    }else {
        *s_num1=1;      // 1 for +ve
        if(argv[1][i]=='+'){ 
            i++;
        }
    }



    // opernad num2
    if(argv[3][j]=='-'){
        *s_num2=-1;       //-1 for -ve
        j++;
    }else {
        *s_num2=1;      // 1 for +ve
        if(argv[3][j]=='+'){ 
            j++;
        }
    }

    //num1 into DLL
    while(argv[1][i]!='\0'){
        Dlist *new=malloc(sizeof(Dlist));

        if(new==NULL){
            return FAILURE;
        }
        new->data=argv[1][i]-'0';
        new->next=NULL;
        new->prev=NULL;

        if(*head1==NULL){           // first DLL node
            *head1=new;
            *tail1=new;
        }
        else{                       //other than first DLL node
            (*tail1)->next=new;     //linking prev and new node
            new->prev=*tail1;
            *tail1=new;              //update tail node
        }
        i++;
    }



    //num2 into DLL
    while(argv[3][j]!='\0'){
        Dlist *new=malloc(sizeof(Dlist));

        if(new==NULL){
            return FAILURE;
        }
        new->data=argv[3][j]-'0';
        new->next=NULL;
        new->prev=NULL;

        if(*head2==NULL){           // first DLL node
            *head2=new;
            *tail2=new;
        }
        else{                       //other than first DLL node
            (*tail2)->next=new;     // linking  previous and new node
            new->prev=*tail2;       
            *tail2=new;             // shifting tail to new node
        }
        j++;
    }
    return SUCCESS;
}



// function to insert data at the beginning node of linked list
int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    // Create a new node
    Dlist *new = (Dlist *)malloc(sizeof(Dlist));

    // Validate memory allocation
    if (new == NULL)
    {
        return FAILURE;
    }

    // Assign data to new node
    new->data = data;
    new->prev = NULL;  
    new->next = *head; 

    // If list is empty (head is NULL)
    if (*head == NULL)
    {
        *head = new; // Both head and tail point to new node
        *tail = new;
        return SUCCESS;
    }
    else{
        // If list not empty → update links
        (*head)->prev = new; 
        *head = new; 
    }

    return SUCCESS;
}








// function to delete entire list
int delete_list(Dlist **head, Dlist **tail)
{
    // If list already empty
    if (*head == NULL)
    { 
        return FAILURE;
    }

    Dlist *temp = *head;

    // Free nodes one by one until end
    while (temp!= NULL)
    {
        *head=(*head)->next;   // Move head forward
        free(temp);           // Free current node
        temp = *head;         // Update temp to new head
    }

    // Finally mark list as empty
    *head = NULL;
    *tail = NULL;

    return SUCCESS;
}


int compare_list(Dlist **head1,Dlist **head2){

    Dlist *temp1=*head1;
    Dlist *temp2=*head2;

    int list1_len=0;
    int list2_len=0;

    // calcuting length of list 1 
    while(temp1!=NULL){
        list1_len++;
        temp1=temp1->next;
    }

    // calcuting length of list 2
    while(temp2!=NULL){
        list2_len++;
        temp2=temp2->next;
    }

    if(list1_len>list2_len){
        return 1;  //list 1 is larger
    }
    else if(list1_len<list2_len){
        return -1;  // list 2 is larger
    }
    else{
        // both length of list are equal
        // then look for MSb digit
         int digit1,digit2;
         temp1=*head1;
         temp2=*head2;
        while(list1_len){
            digit1=temp1->data;
            digit2=temp2->data;

            if(digit1>digit2){
                return 1;//list1 is larger
            }
            else if(digit1<digit2){
                return -1; // list2 is larger
            }

            // if again are same move to next node
            temp1=temp1->next;
            temp2=temp2->next;

            list1_len--;
        }
    }
    return 0; // if complety equal
}


void delete_zeroes_present_at_first(Dlist **headR)
{
    Dlist *temp;

    // Remove all leading zeros until a non-zero digit is found
    while ((*headR)->data == 0)
    {
        if ((*headR)->next != NULL) // If there are more nodes
        {
            temp = *headR;         // Store current head
            *headR = temp->next;   // Move head to next node
            (*headR)->prev = NULL; // Update prev of new head
            free(temp);            // Free old head
        }
        else
        {
            break; // Stop if last node reached 
        }
    }
}



void print_list(Dlist **headR){
    Dlist *temp=*headR;
    if(temp==NULL){
        printf("List is Empty\n");
    }
    else{
        //traverse and print data
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

