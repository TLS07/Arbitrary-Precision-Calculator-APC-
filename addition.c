/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
	int n1=0,n2=0,carry=0;
	int sum=0;
	Dlist *temp1= *tail1;
	Dlist *temp2= *tail2;

	while(temp1!=NULL || temp2!=NULL){

		// to take digit of operand 1
		if(temp1!= NULL){
			n1=temp1->data;
		}
		else{      // if no more digits are present
			n1=0;
		}

        // to take digit of operand 1 
		if(temp2!=NULL){
			n2=temp2->data;
		}
		else{    // if no more digits are present
			n2=0;
		}

		sum=n1+n2+carry;     // to calculate sum
		carry=sum/10;        // to calculte carry
		sum=sum%10;    

		// inserting result digit at the beginning of the result list
		insert_at_first(headR,tailR,sum);

		// to move to next digit(node)
		if(temp1!=NULL){
			temp1=temp1->prev;
		}

		if(temp2!=NULL){
			temp2=temp2->prev;
		}
	}

   // inserting final carry
	if(carry!=0){
		insert_at_first(headR,tailR,carry);
	}

	return SUCCESS;

}
