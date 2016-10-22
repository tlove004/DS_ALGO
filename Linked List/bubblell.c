#include<stdio.h>
#include<malloc.h>

/* Link list node */
typedef struct node
{
    int data;
    struct node *next;
}node;

node *head=NULL;

/*Function to create a linked list*/
void createll()
{
	int i,n;
	node *tail; // keeps track of the last element
	tail=head; //atm head is the last element
	printf("Enter the size:");
	scanf("%d",&n);
	printf("Enter the data:\n");
	for(i=1;i<=n;i++)
	{
			node *newn;
			newn=(node*)malloc(sizeof(node)); //creates a new node in every iteration
			
		
			scanf("%d",&newn->data);
			newn->next = NULL;
			if(head==NULL)
			{
				head=newn; 
				tail=head; 
			}
			else
			{
				tail->next=newn; //linking the previous last element to new last element
				tail=newn; //making the new element as the last element
			}
	}
}

/* Function to print linked list */
void display()
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
    printf("\n");
}    

/*Function to bubble sort*/
void bubble()
{
	int temp;
	node *t1,*t2;
	t1=head;
	while(t1->next!=NULL)
	{
		t2=head;
		while(t2->next!=NULL)
		{
			if(t2->data > t2->next->data)
			{
				temp=t2->data; 
				t2->data=t2->next->data;
				t2->next->data=temp;
			}
			t2=t2->next;
		}
		t1=t1->next;
	}
}
void main()
{
	createll();
	printf("\nBefore Sorting: ");
	display();
	bubble();
	printf("\nAfter Sorting: ");
	display();
}
