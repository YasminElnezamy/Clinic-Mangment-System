#include <stdio.h>
#include "STD_TYPES.h"
#include <stdlib.h>
#include <string.h>

void option(void);
void User(void);
void Add(void);
void edit(void);
void reserve(void);
void cancel(void);
void ViewList(void);
void view_reservation(void);

typedef struct node{
	u8 name[127];
	u32 age;
	u8 gender;
	u8 reser_data;
	u32 id;
	
	struct node * next;
}mynode;

#define null (void*)0
mynode * head = null;

typedef struct reserv{
	u32 data;
	struct reserv * next_res;
}myreserve;

myreserve * head_res = null;


void main(void)
{	
	for(u8 i = 1 ; i <6 ; i++)
	{		
		myreserve * ptr =(myreserve *) malloc(sizeof(myreserve));
		ptr->data= i;
		ptr->next_res = head_res ;
		head_res = ptr;
	}
	view_reservation();
	while(1)
	{	
		
		u32 mode;
		printf("Hello, please enter the mode (1) for Admin , (2) for User = ");
		scanf("%d",&mode);fflush(stdin);
		u32  pw ,i=0 ;
		if (mode==1)
		{
			printf(" The Admin Mode \n");
			printf("Please enter the password = \n");
			for (i = 0; i <3; i++)
			{	
				scanf("%d",&pw);fflush(stdin);
				if (pw == 1234)
				{
					printf("correct password \n");
					break;
				}
				else 
				{
					if ( i == 2)
					{
						printf("you used 3 trials \n");
						break;
					}
					printf("Enter the correct password = \n");	
				}
			}
			if (pw == 1234)
			{
				option();
			}
		}
		else if (mode ==2)
		{
			printf("The User Mode \n");
			User();
		}

		else
		{
			printf("The entry is incorrect\n");	
		}
	}
}

void option(void)
{	
	u32 press;
	printf(" For Adding new patient press 1 = \n For editing press 2 = \n For reservisions press 3 = \n For cancelling press 4 = \n");
	scanf("%d",&press);fflush(stdin);
	if (press ==1)
	{
		Add();
	}
	else if (press ==2)
	{
		edit();
	}
	else if (press ==3)
	{
		reserve();
	}
	else if (press ==4) 
	{
		cancel();
	}
	else
	{
		printf("Incorrect selection\n");
	}	
	

}
void Add(void)
{	
	u8 flag1=0,flag2=0;
    u8 NAME[127] ;
	u32 AGE;
	u8 GENDER;
	u32 ID;

	mynode * ptr = (mynode *) malloc(sizeof(mynode));

	printf("please enter your name = \n");
	scanf("%s", NAME);fflush(stdin);
	
	
	printf("please enter your gender = \n");
	scanf("%c", &GENDER);fflush(stdin);
	
	printf("please enter your age = \n");
	scanf("%d", &AGE);fflush(stdin);
	
	printf("please enter your ID = \n");
	scanf("%d", &ID);fflush(stdin);
	mynode *temp =head;
	if (temp==null)
	{
		flag1=1;
	}
	else
	{
		flag1=1;
		while (temp != null)
		{
			if (ID==temp->id)
			{	printf("____________\n");
				printf("\n\n");
				printf("id exists\n");
				printf("\n\n");
				flag2=1;
				break;
			}
			temp=temp->next;
		}
	}
	
	if (flag1==1&&flag2==0)
	{
		strcpy(ptr->name, NAME);
		ptr-> gender = GENDER;
		ptr-> age = AGE;
		ptr-> id = ID;
		ptr -> next = head;
		ptr->reser_data =0;
		head = ptr;
	}

	ViewList();
}


void ViewList(void)
{ 	
	if( head !=null)
	{   mynode * temp = head;
		do
		{ 
			printf("____________\n");
			printf("Name is %s\n",temp->name);
			printf("Gender is %c\n",temp->gender);
			printf("Age is %d\n",temp->age);
			printf("ID %d\n",temp->id);
			printf("reservation data = %d \n",temp->reser_data);
			printf("____________\n");
			
			temp= temp ->next;
		}
		while(temp !=null);
	}
	else 
	{
		printf("Empty List\n");
	}
}

void edit(void)
{	
	u8 NAME[127] ;
	u32 AGE;
	u8 GENDER;
	u32 ID;
	u32 id_edit;
	printf("Enter your ID= ");
	scanf("%d",&id_edit);
	
	if(head != null)
	{
		mynode * temp = head;
		if(temp->id != id_edit)
		{
			temp = temp->next;
		}
		printf("Hello %s \n",temp -> name);
		printf("Edit your profile\n");
		
		printf("Edit name = \n");
		scanf("%s", NAME);fflush(stdin);
		strcpy(temp->name, NAME);
		
		printf("Edit your gender = \n");
		scanf("%c", &GENDER);fflush(stdin);
		temp-> gender = GENDER;
		
		printf("Edit your age = \n");
		scanf("%d", &AGE);fflush(stdin);
		temp-> age = AGE;
		
		ViewList();
	}

}
void view_reservation(void)
{
	if(head_res !=null)
	{
	myreserve * temp = head_res;
	printf("The available reservation = \n");
		do
		{
			printf("%d\n",temp->data);
			temp = temp->next_res;
		}
		while(temp !=null);
		
	}
	else
	{
		printf("All data's reserved \n");
	}
	
	
}
void reserve(void)
{
	u32 press, ID;
	view_reservation();
	printf("please enter your ID = \n");
	scanf("%d",&ID);fflush(stdin);
	
	mynode *temp =head;
	while (temp != null)
	{
		if (ID==temp->id)
		{
			printf("Correct ID \n");
			printf("Choose suitable data\n");
			printf("For 2pm : 2:30pm press 1  \nFor 2:30pm : 3pm press 2  \nFor 3:30pm : 4pm press 3  \nFor 4pm : 4:30pm press 4  \nFor 4:30pm : 5pm press 5  \n");
			scanf("%d",&press);fflush(stdin);
			if(press >=1 && press <=5)
			{
				if (head != null)
					{
					myreserve * temp1 = head_res;
					myreserve * temp2 = temp1 ->next_res;
					if (head_res==null)
					{
						printf("No Res Available\n");
					}
					else
					{
						if (temp1->data==press)
						{	
							temp->reser_data=press;
							temp = temp ->next;
							head_res=temp1->next_res;
							free(temp1);
						}
						else
						{
							while (temp2 != null)
							{
								if (press==temp2->data)
								{	temp->reser_data=press;
									temp = temp ->next;
									temp1-> next_res=temp2-> next_res;
									free(temp2);
									break;
								}
								temp1 = temp1-> next_res;
								temp2= temp2->next_res;
							}
						}
					}			
				}
				else
				{
					printf("No Patient Available\n");
				}
			}
			else
			{
				printf("Incorrect entry\n");
			}
			view_reservation();	
			break;
		}
		else{		
				temp=temp->next;
			}
	}	
			
		
}
	
	
void cancel(void)
{
	u32 press,ID;
	printf("please enter your ID = \n");
	scanf("%d",&ID);fflush(stdin);
	mynode *temp =head;
	myreserve * ptr = (myreserve *)malloc(sizeof(myreserve));
	while(temp != null)
	{
		if (ID==temp->id)
		{	printf("welcome %s\n",temp->name);
			printf("Do you want to cancel your reservation ? \n");
			printf(" 1 for yes , 2 for no = \n");
			scanf("%d",&press);fflush(stdin);	
			myreserve * temp1 = head_res;
			myreserve * temp2 = temp1 ->next_res;
			if(press == 1)
			{	
				u8 value= (temp->reser_data)+1 ;
				printf("%d\n",value);
				if (temp1->data == value )
				{	
					printf("FFFFFFF\n");
					temp1->next_res=ptr;
					ptr->next_res=temp2;
					ptr->data=temp->reser_data;
					temp->reser_data =0;
					printf("The available NOW = \n");
					view_reservation();
					break;
				}
				
				temp1=temp1->next_res;
				temp2=temp2->next_res;
			}
			else
			{
				printf("okay\n");
				break;
			}
		}
		else
		{
			temp=temp->next;
		}
	}
	if(temp == null)
	{
	printf("No patient until now \n");	
	}
}

void User (void)
{	u32 entery;
	printf("For patient record press 1 = \n");
	printf("For Viewing the reservations of today press 2 = \n");
	scanf("%d",&entery);
	if(entery ==1)
	{
		ViewList();
	}
	else if (entery == 2)
	{
		view_reservation();
	}
	else
	{
		printf("Incorrect entry\n");
	}
}