#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct Heap
{
	int data;
	struct Heap *next;
}
node;
node *create();
int main()
{
	int choice,val;
	char ans;
	node *head;
	void display(node *);
	node *search(node *,int);
	node *insert(node *);
	void dele(node **);
	head=NULL;
	do
	{
		printf("Enter the operation to perform on heap using dynamic memory management\n");
		printf("1.Create\n");
		printf("2.Display\n");
		printf("3.Insert an element in a list\n");
		printf("4.Delete an element from list\n");
		printf("5.Quit\n");
		printf("Enter your choice(1-5): ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				head=create();
				break;
			case 2:
				display(head);
				break;
			case 3:
				head=insert(head);
				break;
			case 4:
				dele(&head);
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid choice, try again\n");
		}
	}
	while(choice!=5);
}
node* create()
{
	node *temp,*New,*head;
	int val,flag;
	char ans;
	node *get_node();
	temp=NULL;
	flag=TRUE;
	do
	{
		printf("Enter the element: ");
		scanf("%d",&val);
		New=get_node();
		if(New==NULL)
			printf("Memory is not allocated\n");
		New->data=val;
		if(flag==TRUE)
		{
			head=New;
			temp=head;
			flag=FALSE;
		}
		else
		{
			temp->next=New;
			temp=New;
		}
		printf("Do you want to enter more elements?(y/n): ");
		scanf("%s",&ans);
	}
	while(ans=='y');
	printf("The list is created\n");
	return head;
}
node *get_node()
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->next=NULL;
	return temp;
}
	void display(node *head)
{
	node *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("The list is empty\n");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL");
	printf("\n");
}
node *search(node *head,int key)
{
	node *temp;
	int found;
	temp=head;
	if(temp==NULL)
	{
		printf("The list is empty\n");
		return NULL;
	}
	found=FALSE;
	while(temp!=NULL && found==FALSE)
	{
		if(temp->data!=key)
			temp=temp->next;
		else
			found=TRUE;
	}
	if(found==TRUE)
	{
		printf("The element is present in the list\n");
		return temp;
	}
	else
	{
		printf("The element is not present in the list\n");
		return NULL;
	}
}
node *insert(node *head)
{
	int choice;
	node *insert_head(node *);
	void insert_after(node *);
	void insert_last(node *);
	printf("1. Insert a node as a head node\n");
	printf("n2. Insert a node as a head node\n");
	printf("n3. Insert a node at intermediate position in the list\n");
	printf("Enter your choice for insertion of node: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			head=insert_head(head);
			break;
		case 2:
			insert_last(head);
			break;
		case 3:
			insert_after(head);
			break;
	}
	return head;
}
node *insert_head(node *head)
{
	node *New,*temp;
	New=get_node();
	printf("Enter the element which you want to insert: ");
	scanf("%d",&New->data);
	if(head==NULL)
		head=New;
	else
	{
		temp=head;
		New->next=temp;
		head=New;
	}
	return head;
}
void insert_last(node *head)
{
	node *New,*temp;
	New=get_node();
	printf("Enter the element which you want to insert: ");
	scanf("%d",&New->data);
	if(head==NULL)
		head=New;
	else
	{
		temp=head;
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=New;
		New->next=NULL;
	}
}
void insert_after(node *head)
{
	int key;
	node *New,*temp;
	New=get_node();
	printf("Enter the elements which you want to insert: ");
	scanf("%d",&New->data);
	if(head==NULL)
	{
		head=New;
	}
	else
		{
		printf("Enter the element which you want to insert: ");
		scanf("%d",&key);
		temp=head;
		do
		{
			if(temp->data==key)
			{
				New->next-temp->next;
				temp->next=New;
				return;
			}
			else
				temp=temp->next;
		}
		while(temp!=NULL);
	}
}
node *get_prev(node *head,int val)
{
	node *temp,*prev;
	int flag;
	temp=head;
	if(temp==NULL)
		return NULL;
	flag=FALSE;
	prev=NULL;
	while(temp!=NULL && ! flag)
		{
		if(temp->data!=val)
		{
			prev=temp;
			temp=temp->next;
		}
		else
			flag=TRUE;
	}
	if(flag)
		return prev;
	else
		return NULL;
}
void dele(node **head)
{
	node *temp,*prev;
	int key;
	temp=*head;
	if(temp==NULL)
	{
		printf("The list is empty\n");
		return;
	}
	printf("Enter the element you want to delete: ");
	scanf("%d",&key);
	temp=search(*head,key);
	if(temp!=NULL)
	{
		prev=get_prev(*head,key);
		if(prev!=NULL)
		{
			prev->next=temp->next;
			free(temp);
		}
		else
		{
			*head=temp->next;
			free(temp);
		}
		printf("The element is deleted\n");
	}
}