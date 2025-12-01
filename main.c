/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"
#include<stdio.h>
#include<stdlib.h>

int main(int count, char* argv[])
{
	if(count<4){
		printf("insufficent input\nEnter again.\n");
		return FAILURE;
	}
	/* Declare the pointers */
	Dlist *head1, *tail1, *head2, *tail2, *headR,*tailR;
	head1=NULL,tail1=NULL;
	head2=NULL,tail2=NULL;
	headR=NULL,tailR=NULL;
	int s_num1,s_num2;
	char operator;

	/* Code for reading the inputs */
	if(!conversion(argv,&s_num1,&s_num2,&head1,&tail1,&head2,&tail2,&headR,&tailR)){
	printf("Conversion of string to DLL of oprenads failed\n");
	return FAILURE;
	}

	operator=argv[2][0];

	/* Function for extracting the operator */

	switch (operator)
	{ 
		case '+':
		{
			/* call the function to perform the addition operation */
			printf("sum of operand 1 and operand 2 :\n");
                
			// if sign of both operand are same
			if(s_num1==s_num2){
				addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                    
				// if both operand are -ve
				if(s_num1==-1){
					headR->data=-(headR->data);
				}

			}
			else{
				int res=compare_list(&head1,&head2);
				if(res==0){   // both operand are same
					insert_at_first(&headR,&tailR,0);
				}

				else if(res>0){  // operand 1>operand 2
                    subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);

					if(s_num1==-1){
						headR->data=-(headR->data);
					}
				}
				else{

					subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);

				    if (s_num2 == -1) // If second operand was negative
				    {     
					headR->data = -(headR->data);
				    }
				}
			}
			printf("%s + %s = ",argv[1],argv[3]);
			print_list(&headR); // to print result
			break;

		}
			    
	
				
		case '-':	
		{
			/* call the function to perform the subtraction operation */
			printf("Difference of operand 1 and operand 2 is:\n");

			// for subtraction
			s_num2=-s_num2;

			if(s_num1==s_num2){
				addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);

				if(s_num1==-1){ // if both are -ve
					headR->data=-(headR->data);
				}
			}
			else{
			int res=compare_list(&head1,&head2);

				if(res==0)//number are eqaul res=0
				{
					insert_at_first(&headR,&tailR,0);
				}
				else if(res>0){ // operand1 >operand 2
					subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
					if(s_num1==-1){
						headR->data=-(headR->data);
					}		
				}
				else{  //operand 2>operand 1
					subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
					if(s_num2==-1){
						headR->data=-(headR->data);
					}
				}
			}
			printf("%s - %s = ", argv[1], argv[3]);
			print_list(&headR);
			break;
		}
		case 'X':
		{	
			/* call the function to perform the multiplication operation */
			printf("product of operand 1 and operand 2 :\n");
		    multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);

		    // If operands have opposite signs → result negative
		    if (s_num1 * s_num2 == -1)
		    {
			    headR->data = -(headR->data);
		    }
		    printf("%s x %s = ", argv[1], argv[3]);
		    print_list(&headR);
			break;
	    }
		case '/':	
			/* call the function to perform the division operation */
			{
		    printf("Divison of operand 1 and operand 2 :\n");
		    if (division(&head1, &tail1, &head2, &tail2, &headR, &tailR) != FAILURE)
		        {
			    // If operands have opposite signs → result negative
			    if (s_num1 * s_num2== -1)
			    {
				    headR->data = -(headR->data);
			    }
			        printf("%s / %s = ", argv[1], argv[3]);
			        print_list(&headR);
			       
		        }
				break;
		
	        }

		default:
			printf("Invalid Input:-( Try again...\n");
			break;
		}
	return 0;
}
