/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */

	Dlist* num1=*head1;
	Dlist* num2=*head2;
	int len1=0,len2=0;

	while(num1!=NULL){
		len1++;
		num1=num1->next;
	}

	while(num2!=NULL){
		len2++;
		num2=num2->next;
	}

	if(len2>len1){
		printf("Divisor is greater than divident results in floating\n");
		return FAILURE;
	}


	int div=0;


	// to check operand2 is 1
	if((*head2)->next==NULL){
		if((*head2)->data==1){

			*headR=*head1;
			*tailR=*tail1;

			return SUCCESS;
		}
       // to check if operand 2 is Zero
		else if((*head2)->data==0){
			printf("Error : Division by zero is not allowed.\n");
			return FAILURE;
		}
	}

	//compute the repeated difference until list2>list1 
	/*if list1<list  2=-1
	  if list 1>list 2= 1
	  if list1==list 2= 0  */

	  while (compare_list(head1, head2) != -1)
	{
		// Call Subtraction Function
		subtraction(head1, tail1, head2, tail2, headR, tailR);

		// Increment div
		div++;

		// Delete the List 1
		delete_list(head1, tail1);

		// Update List 1 with Resultant List
		*head1 = *headR;
		*tail1 = *tailR;

		// Update The Resultant List
		*headR = NULL;
		*tailR = NULL;
	}
	insert_at_first(headR,tailR,div);

	return SUCCESS;
	
}




