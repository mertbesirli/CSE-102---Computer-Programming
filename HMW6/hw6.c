#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 100

void menu(void);
int common(int x,int y);
void sorting_list(int array[ARR_LEN],int str,int end);
void sort_r(int array[ARR_LEN],int s,int m,int e);
void print_array(int list[ARR_LEN],int length);
void calculate_formula(int num);
int find_digit(int x);
int check_formula(int num,int digit);
char capital_letter(char str[ARR_LEN],int len,int count);


int main(){
	menu();

	return 0;
}

void menu(void){
	int choice;
	while(1){
		printf("MENU\n");
		printf("1.Part1\n");
		printf("2.Part2\n");
		printf("3.Part3\n");
		printf("4.Part4\n");
		printf("5.Part5\n");
		printf("6.Exit\n");
		printf("Choice: ");
		scanf("%d",&choice);
		if(choice < 1 || choice > 6){
			printf("This is an invalid choice.Try again!\n");
		}
		else{
			int number1,number2,result;	//Part1 values
			/*Part2 values*/
			int len,	//Array length
				i;	//For loop
			int array[ARR_LEN];	
			/*Part3 value*/
			int number;	
			/*Part4 values*/
			int numbers,num_digits,add;	
			/*Part5 values*/
			char letter;	//Return value
			char str[ARR_LEN];	//Using  string
			int lenn=0,j=0;	
			int count=0;

			switch(choice){
				case 1:
					/*Takes two numbers */
					printf("Enter two number : ");
					scanf("%d%d",&number1,&number2);
					/*Result value*/
					result=common(number1,number2);
					/*Printing result value*/
					printf("Result is: %d\n\n",result);
					break;
				case 2:
					printf("Enter length of list: ");
					scanf("%d",&len);
					/*Situation of less than zero or zero*/
					if(len <= 0){
						printf("Invalid length!!\n\n");
						break;
					}
					/*Taken list numbers*/
					for(i=0;i<len;i++){
						printf("Enter list of numbers : ");
						scanf("%d",&array[i]);
					}
					sorting_list(array,0,len-1);
					printf("Sorted array is: ");
					print_array(array,len);
					break;
				case 3:
					/*Takes number */
					printf("Enter number: ");
					scanf("%d",&number);
					/*Calculate formula with function*/
					calculate_formula(number);
		
					printf("\n\n");
					break;
				case 4:
					/*Taken number of check formula*/
					printf("Please enter number : ");
					scanf("%d",&numbers);
					/*Find digits*/
					num_digits=find_digit(numbers);
					add=check_formula(numbers,num_digits);
	
					if(add == numbers)
						printf("Equal\n\n");
					else
						printf("Not Equal\n\n");
					break;
				case 5:
					/*Taken string*/
					printf("Enter string: ");
					scanf("%s",str);
					/*Find string length*/
					while(str[j] != '\0'){
						lenn++;
						j++;
					}
					/*Find first capital letter function*/
					letter=capital_letter(str,lenn,count);

					/*According to return value , checking situation and printing*/
					if(letter == 0)
						printf("No capital letter is this string\n\n");
					else
						printf("The first capital letter is : %c \n\n",letter);
					break;
				case 6:
					exit(0);
					break;

			}
		}
	}

}

/*Find gcd function */
int common(int x,int y){
	/*For special situation*/
	if(x == 0 && y == 0 || x == 1 && y == 0 || x == 0  && y == 1)
		return 0;
	else if(x % y == 0)
		return y;
	else
		return common(y,x % y);
}

void sorting_list(int array[ARR_LEN],int str,int end){
	int med;
	/*Check array index for divided sort*/
	if(str < end){
		/*Array middle point*/
		med=str+((end-str)/2);
		/*Sorting divided first and second array,respectively*/
		sorting_list(array,str,med);
		sorting_list(array,med+1,end);
		/*Sort function send array start,middle and end element*/
		sort_r(array,str,med,end);
	}

}

void sort_r(int array[ARR_LEN],int s,int m,int e){
	int i; //For loop
	/*Size of for temp array*/
	int size1,size2;
	size1=m-s+1;
	size2=e-m;
	/*Temp array*/
	int temp[size1],temp_p[size2];
	/*Create temp array with loop*/
	for(i=0;i<size1;i++)
		temp[i]=array[s+i];
	for(i=0;i<size2;i++)
		temp_p[i]=array[m+1+i];
	/*Update value*/
	i=0;
	int j=0;
	int k=s;
	/*If you have array element,continue to combining*/
	while(i < size1 && j < size2){
		if(temp[i] <= temp_p[j]){
			array[k]=temp[i];
			i++;
		}	
		else{
			array[k]=temp_p[j];
			j++;
		}
		/*All situation k increasing*/
		k++;
	}
	/*Placing the remaining elements left and right array*/
	while(i < size1){
		array[k]=temp[i];
		i++;
		k++;
	}
	while(j < size2){
		array[k]=temp_p[j];
		j++;
		k++;
	}
}

void print_array(int list[],int length){
	for(int i=0;i<length;i++)
		printf("%d ",list[i]);
	printf("\n\n");
}

void calculate_formula(int num){
	if(num == 0){
		printf("%d ",num);
		return;
	}
	if(num == 1){
		printf("%d ",num);
		return;
	}
	else if(num % 2 == 0){
		printf("%d ",num);
		return calculate_formula(num/2);
	}		
	else if(num % 2 == 1){
		printf("%d ",num);
		return  calculate_formula(3*num+1);
	}
}	

/*Find digits of taken number*/
int find_digit(int x){
	if(x == 0)
		return 0;
	return 1+find_digit(x/10);
}

/*According to formula check number*/
int check_formula(int num,int digit){
	int res=1;
	int result=num%10;

	if(num == 0)
		return 0;
	else if (result < 10){
		for(int i=0;i<digit;i++)
			res*=result;
		return res+check_formula(num/10,digit);						
	}	
			
}

char capital_letter(char str[ARR_LEN],int len,int count){
	
	if(count < len){
		if(str[count] >= 65 && str[count] <= 90)
			return str[count];
		else
			return capital_letter(str,len,count+1);
	}
	else
		return 0;
}
