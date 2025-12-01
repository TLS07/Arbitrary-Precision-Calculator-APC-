/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1=*tail1;  // pointer to lsb of opreand 1
	Dlist *temp2=*tail2; // pointer to lsb of operand 2

	// temporary list
	// list to store  result of  repeated multiplication 
	Dlist *headR1 =NULL;
	Dlist *tailR1=NULL ;

	// list to store sum of multiplication products
	Dlist *headR2=NULL;
	Dlist *tailR2=NULL;

	// intialize result list (R2) with 0
	insert_at_first(&headR2,&tailR2,0);

	int count=0,i;
	while(temp2!=NULL){

		//after multiplicaton of each digit of operand 2 , we have to start again
		if(*tail1 !=NULL){
			temp1=*tail1;
		}


		// when multipliing with 10's ,100's adding correspoinding zero's
		for (i = 0; i < count; i++)
		{
	      insert_at_first(&headR1, &tailR1, 0);
        }       

		int digit=temp2->data;    // each digit of operand 2 for multiplication 
		int carry =0;

		// multiplication of operand 1 and each digit from lsb of operand 2
		while(temp1!=NULL){

			//product calcution
			int res=(temp1->data *digit)+carry;

			//updating carry 
			carry=res/10;
			res=res%10;

			//insertinf partial product
			insert_at_first(&headR1,&tailR1,res);
			// next digit of operand1 towards MSB
			temp1=temp1->prev;
		}

		// if carry leftout after final product of all digit move to result list
		if(carry >0){
			insert_at_first(&headR1,&tailR1,carry);
		}

		// adding the  partial product result of multiplication
		addition(&headR1, &tailR1, &headR2, &tailR2, headR, tailR);

		// Clean up  temporary list R1 and R2 as result moved to main resutl list
		delete_list(&headR1, &tailR1);
		delete_list(&headR2, &tailR2);

		// update R2 to current list
		headR2=*headR;
		tailR2=*tailR;

		//rest the result list for next iteration

		*headR=NULL;
		*tailR=NULL;

		//move to next digit of operand2

		temp2=temp2->prev;

		//incremetn count so the next partil product is shiftes by zerp's acording
		count ++;
	}

	// Final result is in R2 → assign it back to *headR, *tailR
	*headR = headR2;
	*tailR = tailR2;

	// Remove any leading zeros 
	delete_zeroes_present_at_first(headR);

	return SUCCESS;
}
