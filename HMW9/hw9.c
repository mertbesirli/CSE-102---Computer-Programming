#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

struct person{
	char name[SIZE];
	char surname[SIZE];
	char musical_work[SIZE];
	int age;
	struct person *next;
}person;

struct person *top=NULL;


void menu(void);
void addNode(char first_name[SIZE],char second_name[SIZE],char creation[SIZE],int ages);
void print_stack();
void deleteNode();
void sort_alphabetically();
void sort_increasingly();

int main(){
	menu();	
	free(top);
	return 0;
}

void menu(){
	int choice,	//For chosing variables
		flag=0;	//For exit 
	char first_name[SIZE],
		second_name[SIZE],
		creation[SIZE];
	int num;	//Age
	while(1){
		printf("****MENU****\n");
		printf("1-Add a Person to the Stack\n");
		printf("2-Pop a Person from the Stack\n");
		printf("3-Sort Alphabetical Order\n");
		printf("4-Sort Age in Increasing Order\n");
		printf("5-Exit Menu\n");
		printf("************\n");
		printf("Select your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("Enter first name: ");
				scanf(" %[^\n]s",first_name);
				printf("Enter second name: ");
				scanf(" %[^\n]s",second_name);
				printf("Enter creation: ");
				scanf(" %[^\n]s",creation);
				printf("Enter age: ");
				scanf("%d",&num);
				addNode(first_name,second_name,creation,num);
				print_stack();
				break;
			case 2:
				deleteNode();
				print_stack();
				break;
			case 3:
				sort_alphabetically();
				print_stack();
				break;
			case 4:
				sort_increasingly();
				print_stack();
				break;
			case 5:
				/*For exit*/
				flag=1;
				break;
		}
		if(flag == 1){
			printf("Exit....\n");
			break;
		}	
	}




}

void addNode(char first_name[SIZE],char second_name[SIZE],char creation[SIZE],int ages){
	/*Create new node */
	struct person *root;
	root=(struct person*)malloc(sizeof(person));
	/*We copied */
	strcpy(root->name,first_name);
	strcpy(root->surname,second_name);
	strcpy(root->musical_work,creation);
	root->age=ages;
	root->next=top;
	top=root;
}

void print_stack(){
	struct person *temp;
	temp=top;
	int count=1;
	if(top == NULL)
		printf("List is empty...\n");
	else{
		/*Doing For node didn't get lost*/
		while(temp->next != NULL){
			printf("%d)%s\n%s\n%s\n%d\n",count,temp->name,temp->surname,temp->musical_work,temp->age);
			temp=temp->next;
			count++;
		}
		/*Last element printing*/
		printf("%d)%s\n%s\n%s\n%d\n",count,temp->name,temp->surname,temp->musical_work,temp->age);
	}
}

void deleteNode(){
	if(top == NULL)
		printf("List is empty...\n");
	else{
		struct person *tmp;
		tmp=top;
		top=top->next;
		free(tmp);
	}
}

void sort_alphabetically(){
	struct person *tmp;
	tmp=top;
	
	char m[SIZE];	//For store name,surname,work
	int x,count=0;
	/*We found out how many nodes*/
	while(tmp != NULL){
		count+=1;
		tmp=tmp->next;
	}
	/*Return top*/
	tmp=top;
	/*Compare alphabetically*/
	for(int i=0;i<count;i++){	
		while(tmp->next != NULL){
			if(strcmp(tmp->name,tmp->next->name) > 0){
				/*Change place for name*/
				strcpy(m,tmp->next->name);
				strcpy(tmp->next->name,tmp->name);
				strcpy(tmp->name,m);
				/*Change place for surname*/
				strcpy(m,tmp->next->surname);
				strcpy(tmp->next->surname,tmp->surname);
				strcpy(tmp->surname,m);
				/*Change place for work*/
				strcpy(m,tmp->next->musical_work);
				strcpy(tmp->next->musical_work,tmp->musical_work);
				strcpy(tmp->musical_work,m);
				/*Change place for age*/
				x=tmp->age;
				tmp->age=tmp->next->age;
				tmp->next->age=x; 	
			}
			tmp=tmp->next;
		}
		/*Return top*/
		tmp=top;
	}

	
}

void sort_increasingly(){
	struct person *tmp;
	tmp=top;
	int temp, //For change age
		count=0;
	char m[SIZE];	//For store name,surname,work
	
	/*We found out how many nodes*/
	while(tmp != NULL){
		count+=1;
		tmp=tmp->next;
	}
	/*Return top*/
	tmp=top;
	/*Compare age increasingly*/
	for(int i=0;i<count;i++){
		while(tmp->next != NULL){
			if(tmp->age > tmp->next->age){
				/*Change place for age*/
				temp=tmp->age;
				tmp->age=tmp->next->age;
				tmp->next->age=temp;
				/*Change place for name*/
				strcpy(m,tmp->next->name);
				strcpy(tmp->next->name,tmp->name);
				strcpy(tmp->name,m);
				/*Change place for surname*/
				strcpy(m,tmp->next->surname);
				strcpy(tmp->next->surname,tmp->surname);
				strcpy(tmp->surname,m);
				/*Change place for work*/
				strcpy(m,tmp->next->musical_work);
				strcpy(tmp->next->musical_work,tmp->musical_work);
				strcpy(tmp->musical_work,m);
		
			}
			tmp=tmp->next;
		}
		/*Return top*/
		tmp=top;
	}
	
}

