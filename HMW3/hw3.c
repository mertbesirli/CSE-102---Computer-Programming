#include <stdio.h>
#include <stdlib.h>

#define HMW_SIZE 10
#define LAB_SIZE 10
#define EXAM_SIZE 2
#define HMW_COEF 0.1
#define LAB_COEF 0.2
#define MID_COEF 0.3
#define FINAL_COEF 0.4
#define COUNT 1


void menu(void);
void take_grades(int hmw_grades[]);
void take_lab_grades(int lab_grade[]);
void take_exam_grades(int mid_final_grade[]);
double calculate_homework(int homework[HMW_SIZE]);
double calculate_lab(int labs[LAB_SIZE]);
double calculate_all(double average_homework,int mid_final_grade[EXAM_SIZE],double average_lab);
void print_shape(int x);
void menu_part1(void);
int doit(int func(),int first_num,int second_num);
int add(int number1,int number2);
int sub(int number1,int number2);
int multi(int number1,int number2);
int divi(int number1,int number2);
int mod(int number1,int number2);


int main(){
	menu();
	return 0;
}

void menu(void){
	int select_part;
	
	while(COUNT){
		printf("MENU\n");
		printf("1.Calculator\n");
		printf("2.Calculate Note\n");
		printf("3.Draw Diamond\n");
		printf("4.Exit\n");
		printf("Choice: ");
		scanf("%d",&select_part);
		if(select_part < 1 || select_part > 4){
			printf("This is an invalid choice.Try again!\n");
		}
		else{
			/*Part 2 variables*/
			int hmw_grades[HMW_SIZE];	//First array
			int lab_grades[LAB_SIZE];	//Second array
			int mid_final_grades[EXAM_SIZE];	//Third array
			int i;	//For loop
			double ave_hmw,	//Average homework and lab grade,respectively
		  		 ave_lab;
			double result;	//Printing value
			/*Part 3 variables*/
			int height;
			switch(select_part){
				case 1:
					menu_part1();
					break;
				case 2:
					/*Taken homework grades*/
					take_grades(hmw_grades);
					/*Taken lab grades */
					take_lab_grades(lab_grades);
					/*Taken mid and final grades*/
					take_exam_grades(mid_final_grades);
					/*Calculate average of homework and lab,respectively*/ 
					ave_hmw=calculate_homework(hmw_grades);
					ave_lab=calculate_lab(lab_grades);
					/*Calculate all values*/
					result=calculate_all(ave_hmw,mid_final_grades,ave_lab);
					/*Printing result*/
					printf("Result: %.2f\n",result);
					break;
				case 3:
					printf("Enter height of shape and positive number please: ");
					scanf("%d",&height);
					if(height<0){
						while(height>=0){
							printf("Enter height of shape positive number again,please: ");
							scanf("%d",&height);
						}
					}
					else	
						/*Printing shape*/
						print_shape(height);
					break;
				case 4:
					exit(0);
					break;
				
			
			}
		}
	}

}

void take_grades(int hmw_grades[]){
	int i;	//For loop
	/*Assignment array and return */
	for(i=0;i<HMW_SIZE;i++){
		printf("Enter homework grades please,respectively: ");
		scanf("%d",&hmw_grades[i]);
	}
}

void take_lab_grades(int lab_grade[]){
	int i;	//For loop
	/*Assignment array and return*/
	for(i=0;i<LAB_SIZE;i++){
		printf("Enter lab grades please,respectively: ");
		scanf("%d",&lab_grade[i]);
		
	}
}
	
void take_exam_grades(int mid_final_grade[]){
	int i;	//For loop
	/*Assignment array and return*/
	for(i=0;i<EXAM_SIZE;i++){
		printf("Enter mid and final grade please,respectively: ");
		scanf("%d",&mid_final_grade[i]);
	}
}

double calculate_homework(int homework[HMW_SIZE]){
	int add=0;
	int i;
	for(i=0;i<HMW_SIZE;i++)  
		add += homework[i];
	return add/HMW_SIZE;
}

double calculate_lab(int labs[LAB_SIZE]){
	int add=0;
	int i;
	for(i=0;i<LAB_SIZE;i++)
		add += labs[i];
	return add/LAB_SIZE;
}

double calculate_all(double average_homework,int mid_final_grade[EXAM_SIZE],double average_lab){
	double res;
	/*Calculate result*/
	res=(average_homework*HMW_COEF)+(average_lab*LAB_COEF)+(mid_final_grade[0]*MID_COEF)+
	(mid_final_grade[1]*FINAL_COEF);
	
	return res;
}

void print_shape(int x){
	int i,j;
	for(i=0;i<(x-1);i++)	
		printf(" ");
	printf("/\\");
	printf("\n");
	for(j=0;j<(x-1);j++){
		for(i=j;i<(x-2);i++)
			printf(" ");
		printf("/");
		for(i=0;i<(2*j+2);i++)
			printf("*");
		printf("\\");
		printf("\n");
	}
	for(j=0;j<(x-1);j++){
		for(i=0;i<j;i++)
			printf(" ");
		printf("\\");
		for(i=(2*j);i<(2*(x-1));i++)
			printf("*");
		printf("/");
		printf("\n");
	}
	for(i=0;i<(x-1);i++)	
		printf(" ");
	printf("\\/");
	printf("\n");
}

void menu_part1(void){
	char choice;	// For pick +,-,*,/,**,% 
	int first_number,second_number;
	int cp=0;
	while(COUNT){
		scanf(" %c",&choice);
		if(choice >= 'a' && choice <= 'z' || choice >= '1' && choice <= '9') break;
		scanf(" %d %d",&first_number,&second_number);
		int add(),sub(),multi(),divi(),mod();
		switch(choice){
			case '+':
				if(second_number == 0){
					second_number=first_number;
					first_number=cp;
					cp=doit(add,first_number,second_number);
				}
				else
					cp=doit(add,first_number,second_number);
				printf("%d\n",cp);
				break;
			case '-':
				if(second_number == 0){
					second_number=first_number;
					first_number=cp;
					cp=doit(sub,first_number,second_number);
				}
				else
					cp=doit(sub,first_number,second_number);
				printf("%d\n",cp);
				break;
			case '*':
				if(second_number == 0){
					second_number=first_number;
					first_number=cp;
					cp=doit(multi,first_number,second_number);
				}
				else
					cp=doit(multi,first_number,second_number);
				printf("%d\n",cp);
				break;
			case '/':
				if(second_number == 0){
					second_number=first_number;
					first_number=cp;
					cp=doit(divi,first_number,second_number);
				}
				else
					cp=doit(divi,first_number,second_number);
				printf("%d\n",cp);
				break;
			case '%':
				if(second_number == 0){
					second_number=first_number;
					first_number=cp;
					cp=doit(mod,first_number,second_number);
				}
				else
					cp=doit(mod,first_number,second_number);
				printf("%d\n",cp);
				break;
		}
		
	}
}

int doit(int func(),int first_num,int second_num){
	int res;
	res=func(first_num,second_num);
	return res;
}

int add(int number1,int number2){
	return (number1+number2);
}

int sub(int number1,int number2){
	return (number1-number2);
}

int multi(int number1,int number2){
	return (number1*number2);
}

int divi(int number1,int number2){
	return (number1/number2);
}

int mod(int number1,int number2){
	return (number1%number2);
}
	
