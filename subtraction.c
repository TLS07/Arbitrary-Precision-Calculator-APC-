/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include<stdio.h>
#include<stdlib.h>

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
	int n1=0,n2=0,borrow=0,diff=0;

	// start frm lsb
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;

	while(temp1!=NULL || temp2!=NULL){
     // first digit frm lsb of operand 1
		if(temp1!=NULL){
			n1=temp1->data;
		}else{       // if no digit is present
			n1=0;
		}

    // first digit frm lsb of operand 2
		if(temp2!=NULL){
			n2=temp2->data;
		}else{     // if no digit is present
			n2=0;
		}

	// any previous borrow
		if(borrow){
			n1-=borrow;
		}

	// If n1 < n2, borrow 10 from next higher digit
		if(n1<n2){
			n1+=10;
			borrow=1;
		}else{
			borrow=0;
		}

	// calcute difference
		diff=n1-n2;
   
	// insert result at beggining of result list
		insert_at_first(headR,tailR,diff);

	// Move to next higher digits
		if(temp1!=NULL){
			temp1=temp1->prev;
		}
		if(temp2!=NULL){
			temp2=temp2->prev;
		}
	}

	// to remove leading zeros
	 while (*headR != NULL && (*headR)->data == 0 && (*headR)->next != NULL) {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(temp);
    }

	return SUCCESS;
}
