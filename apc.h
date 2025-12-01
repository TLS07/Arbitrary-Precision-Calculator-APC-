#ifndef APC_H
#define APC_H
#define SUCCESS 1
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
int conversion(char *argv[],int *s_num1,int *s_num2,Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);
int insert_at_first(Dlist **head, Dlist **tail, int data);
int delete_list(Dlist **head, Dlist **tail);
int compare_list(Dlist **head1,Dlist **head2);
void delete_zeroes_present_at_first(Dlist **headR);
void print_list(Dlist **headR);
#endif
