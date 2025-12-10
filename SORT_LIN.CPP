#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct Link_list{
   int data;
   struct Link_list *next;
};
typedef struct Link_list node;
node *start=NULL;
int num;
int ct;

void create(node *);
void display (node *);
void sort(node *);
void reverse(node *);

/*Function Main*/
int main(){
  int ch;
  clrscr();
  do{
    printf("\nPress 1 for create : ");
    printf("\nPress 2 for Display : ");
    printf("\nPress 3 to sort linked list : ");
    printf("\nPress 4 to reverse : ");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch){
      case 1 : create(start);
	       break;
      case 2 : printf("\ncreated list is as follows :\n");
	       display (start);
	       break;
      case 3 : sort(start);
	       break;
      case 4 : reverse(start);
	       break;
      default:
	      ch = 0;
    }
  }while(ch!=0);
  return 0;
  getch();
}
/*Function Create*/
void create(node *ptr){
    int ch;
    num = 0;
    if(start == NULL){
       start = (node *)malloc(sizeof(node));
       ptr = start;
    }
    do{
      printf("\nInput the values of node : %d : ",(num+1));
      scanf("%d",&ptr->data);
      printf("\nTo continue press 1 : ");
      scanf("%d",&ch);
      if(ch==1){
	 ptr->next = (node *)malloc(sizeof(node));
	 ptr = ptr->next;
      }
      num++;
    }while(ch==1);
    ptr->next = NULL;
    printf("\nTotal nodes = %d",num);
}

/*Function to display*/
void display(node *ptr){
     while(ptr!=NULL){
	  printf("%d\n",ptr->data);
	  ptr = ptr->next;
     }
}

/*Function to sort linked list*/
void sort(node *ptr){
  int x;
  node *temp;
  for(;ptr->next!=NULL; ptr=ptr->next){
     for(temp = ptr->next; temp!=NULL; temp=temp->next){
	if(ptr->data > temp->data){
	    x = ptr->data;
	    ptr->data = temp->data;
	    temp->data = x;
	}
     }
  }
}

/*Function to reverse link list*/
void reverse(node *ptr)
{
       node *curr,*prev = NULL;
       curr=ptr->next;
       while( curr!=NULL)
       {
	   ptr->next=prev;
	   prev=ptr;
	   ptr=curr;
	   curr=curr->next;

       }
       ptr->next=prev;
       start=ptr;
}










