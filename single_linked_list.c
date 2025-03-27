#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *create(){
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	printf("enter element to insert");
	scanf("%d",&temp->data);
	temp->link = NULL;
	return temp;
}
void print(struct node * head){
	struct node* ptr = NULL;
	ptr=head;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
		printf("\n");
}
   struct node* insertatbegin(struct node *head){
	struct node *temp = create();
	temp->link = head;
	head  = temp;

	return temp;
}
   struct node * insertatEND(struct node *head){
   	struct node *temp = create();
   	 struct node *ptr = NULL;
   	 ptr = head;
   	 while(ptr->link!=NULL){
   	 	ptr = ptr->link;
		}
		ptr->link = temp;
	   return head;
   }
   struct node * insertatanywhere(struct node *head){
   	int p,loc=0;
   	printf("enter position to insert element:");
   	scanf("%d",&p);
   	struct node * temp = create();
   	struct node *ptr,*pre;
   	ptr=pre=head;
   	while(ptr->link!=NULL){
   		loc++;
   	   if(loc==p){
   	   	break;
		  }
		  pre = ptr;
		  ptr= ptr->link;
	   }
	   temp->link = ptr;
	   pre->link = temp;
	  
	   return head;
   }
   struct node *deleatbegin(struct node*head){
   	struct node *temp = NULL;
   	temp = head;
   	head = head->link;
   	temp->link = NULL;
   	
   	free(temp);
   	
   	return head;
   }
   struct node * deleatEND(struct node* head){
   	struct node *ptr ,*temp,*pre;
   	ptr = pre = head;
   	while(ptr->link!=NULL){
   		pre = ptr;
   		ptr = ptr->link;
	   }
	   temp = ptr ;
	   pre->link  = NULL;
	   free(temp);
	   
     return head;
   }
   struct node *deletatanywhere(struct node*head){
   	struct node *ptr ,*temp,*pre;
   	ptr = pre = head;
   	int loc = 0;
   	int p;
   	printf("enter position to delete element");
   	scanf("%d",&p);
   	while(ptr->link!=NULL){
   		loc++;
   		if(loc==p){
   			break;
		   }
		   pre = ptr;
		   ptr = ptr->link;
	   }
	   temp = ptr ;
	   pre->link = ptr->link;
	   free(temp);
	   return head;
   }
int main(){
	struct node *head = NULL;
	head = (struct node *)malloc(sizeof(struct node));
	head->data = 10;
	head->link = NULL;
	struct node *create = NULL;
	create = (struct node *)malloc(sizeof(struct node));
	create->data = 20;
	create->link = NULL;
	head->link = create;
	create = (struct node*)malloc(sizeof(struct node));
	create->data = 30;
	create->link = NULL;
	head->link->link= create;
	print(head);
   int ch;
	do{
       printf("1.insert at begin\n 2.insert at end\n 3. insert at any where\n 4.delete at begin \n 5.delete at end \n 6. delete at any where\n");
       printf("select your choice :\n");
        scanf("%d",&ch);
      switch(ch){
   	case 1 :head = insertatbegin(head);
           print(head);
            break;
    case 2 : head = insertatEND(head);
            print(head);
           break;
    case 3 : head = insertatanywhere(head);
              print(head);
              break;
    case 4 :  head =  deleatbegin(head);
                print(head);
				break;
	  case 5 :   head = deleatEND(head);
               print(head);
                 break;
    case 6 :  head = deletatanywhere(head);
                 print(head);
                 break;
    default: printf("select valid choice");
				 exit(0);
   }
		  }while(1);
     return 0;  
}
