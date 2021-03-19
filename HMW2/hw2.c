#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 1
#define FIRST_MIN 1
#define MAX_VALUE 1024

void menu(void);
int RNG(void);
int make_a_guess(int trial,int min,int max);
int make_a_guess_two(int tri,int min,int max,int min2);
void show_scores(int score_human,int score_program);
void draw_hourglass(int height);
void draw_mountain_road(int length,int max_radius);
int RNG2(int max_rad);

int main(){
	menu();
	return 0;
}

void menu(void){
	int choice;

	while(COUNT){
		printf("MENU\n");
		printf("1.Play Lucky Number\n");
		printf("2.Draw Hourglass\n");
		printf("3.Draw Mountain Road\n");
		printf("4.Exit\n");
		printf("Choice: ");
		scanf("%d",&choice);
		if(choice < 1 || choice > 4){
			printf("This is an invalid choice.Try again!\n");
		}
		else{
			int count=0;	//For score
			int trial=10;
			int index;	//To keep constant to trial
			int trial2;		//Begin trial number
			int guess;		//Guess value
			int lucky,min,max,min2;		//Index values
			int length,max_radius;		//Case 3(draw mountain road) variables
			int height;				//Case 2(draw hourglass) variables
			int ccp;				//Score value
			switch(choice){
				case 1:
					lucky=RNG();	//Generates random number
					for(trial2=1;trial2<=trial;trial2++){
						if(trial2==1){
							max=lucky;
							guess=make_a_guess(trial2,min,max);
							count++;
							min=guess;
							min2=guess;
						}
						else{
							if(guess<lucky){
								min=guess;
								min2=guess;
								max=lucky;
								guess=make_a_guess(trial2,min,max);
								count++;
							}
							else if(guess>lucky){
								min=guess;
								max=lucky;
								guess=make_a_guess_two(trial2,min,max,min2);
								count++;
							}
							else{
								ccp=trial-count;
								show_scores(ccp,count);
								break;		
							}
						}
					}
					if(count == trial)
						show_scores(0,count);
					break;			
				case 2:
					printf("Enter height of the hourglass(positive odd number): ");
					scanf("%d",&height);
					if(height >= 0){
						if(height%2 != 0)
							draw_hourglass(height);
						else{
							printf("Wrong number,you must be enter odd number\n");
							printf("Enter height of the hourglass again: ");
							scanf("%d",&height);
							while((height%2) ==0){
								printf("Wrong number,you must be enter odd number\n");
								printf("Enter height of the hourglass again: ");
								scanf("%d",&height);
							}
							draw_hourglass(height);
						}
					}
					else
						printf("Wrong!!You enter negative number\n");
	
					break;
				case 3:
					/*Take length and radius */
					printf("Enter length and max radius of half circles: ");
					scanf("%d%d",&length,&max_radius);
					draw_mountain_road(length,max_radius);
					break;
				case 4:
					exit(0);

			}
		}
	}			



}

int RNG(void){
	int num;
	srand(time(NULL));	//Random generates number
	num=rand()%1025;
	return num;	
}

int make_a_guess(int trial,int min,int max){
	int guess,between;
	if(trial == COUNT)
		printf("(Trial: %d) Make a guess between %d and %d: ",trial,FIRST_MIN,MAX_VALUE);
	else
		printf("(Trial: %d) Make a guess between %d and %d: ",trial,min,MAX_VALUE);
	printf("Guess: ");
	scanf("%d",&guess);
	printf("%d\n",guess);
	/*Check big or small */
	if(max>guess)
		between=max-guess;
	else
		between=guess-max;
	/*Check distance */
	if(between >= 512 && between < 1024)
		printf("Distance: 10\n");
	else if(between >= 256 && between < 512)
		printf("Distance: 9\n");
	else if(between >= 128 && between < 256) 
		printf("Distance: 8\n");
	else if(between >= 64 && between < 128)
		printf("Distance: 7\n");
	else if(between >= 32 && between < 64)
		printf("Distance: 6\n");
	else if(between >= 16 && between < 32)
		printf("Distance: 5\n");
	else if(between >= 8 && between < 16)
		printf("Distance: 4\n");
	else if (between >= 4 && between < 8)
		printf("Distance: 3\n");
	else if(between >= 2 && between < 4)
		printf("Distance: 2\n");
	else if(between == 1)
		printf("Distance: 1\n");
	else
		printf("Distance: 0.You win!\n");
	return guess;
}

int make_a_guess_two(int trial,int min,int max,int min2){
	int guess,between;	

	if(min2<min)  
		printf("(Trial: %d) Make a guess between %d and %d: ",trial,min2,min);
	else	
		printf("(Trial: %d) Make a guess between %d and %d: ",trial,min,min2);
	printf("Guess: ");
	scanf("%d",&guess);
	printf("%d\n",guess);

	/*Check big or small */
	if(max>guess)
		between=max-guess;
	else
		between=guess-max;
	/*Check distance */
	if(between >= 512 && between < 1024)
		printf("Distance: 10\n");
	else if(between >= 256 && between < 512)
		printf("Distance: 9\n");
	else if(between >= 128 && between < 256) 
		printf("Distance: 8\n");
	else if(between >= 64 && between < 128)
		printf("Distance: 7\n");
	else if(between >= 32 && between < 64)
		printf("Distance: 6\n");
	else if(between >= 16 && between < 32)
		printf("Distance: 5\n");
	else if(between >= 8 && between < 16)
		printf("Distance: 4\n");
	else if (between >= 4 && between < 8)
		printf("Distance: 3\n");
	else if(between >= 2 && between < 4)
		printf("Distance: 2\n");
	else if(between == 1)
		printf("Distance: 1\n");
	else
		printf("Distance: 0.You win!\n");
	return guess;
	
}		
void show_scores(int score_human,int score_program){
	printf("Your score: %d Program score: %d\n",score_human,score_program);

}

void draw_hourglass(int height){
	int i,j;
	/*Draw Hourglass */
	for(j=0;j<(((height+1)/2)-1);j++){
			for(i=0;i<j;i++)
				printf(" ");
			for(i=(2*j);i<height;i++)
				printf("*");
			printf("\n");
		}
	for(i=0;i<(((height+1)/2)-1);i++)
		printf(" ");
	printf("*\n");
	for(j=0;j<(((height+1)/2)-1);j++){
		for(i=j;i<(((height-1)/2)-1);i++)
			printf(" ");
		for(i=0;i<(2*j+3);i++)
			printf("*");
		printf("\n");
	}
}

void draw_mountain_road(int length,int max_radius){
	int rad;
	int i,j,k;	//For loop
	/*Draw mountain road */
	for(k=0;k<length;k++){
		rad=RNG2(max_radius);
		for(j=0;j<rad;j++){
			for(i=j;i<rad;i++)
				printf(" ");
			printf("/\n");
		}
		printf("|\n");
		for(j=0;j<rad;j++){
			for(i=0;i<(j+1);i++)
				printf(" ");
			printf("\\");
			printf("\n");
		}
	}


}

int RNG2(int max_rad){
	int num;
	srand(time(NULL));	//Generates random number
	num=rand()%max_rad;
	return num;
}
		










	


	





