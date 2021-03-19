#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3
#define RED 0
#define YELLOW 1
#define BLUE 2
#define BLACK 3
#define WHITE 4
#define SQUARE 1
#define RECTANGULAR 2
#define CIRCULAR 3

double CreateBody(int shape);
int SetColor(int color);
double LoadMoves(int shape,double body_size);
int SetAttackPower(int lower_bound,int upper_bound);
void ShowPokemon(int shape,double body_size,int color,double move_length,int attack_power);


int main(){
	int shape,	//Shape number
		color, //Color code
		attack_power;	
	double body_size,	//Return calculate shape area
		move_length;	//Return calculate one move of the pokemon length
	
	int lower_bound=0;	//For Attack power
	int upper_bound=150;
	
	/*Takes a shape number */
	/*printf("Please enter shape number between 1 and 3: ");
	scanf("%d",&shape);*/
	shape=SQUARE;

	/*Calculate area function */
	body_size=CreateBody(shape);

	/*Takes and calculate color code*/
	/*printf("Please enter color code between 0 and 1000: ");
	scanf("%d",&color);*/
	color=21;
	color=SetColor(color);
	
	/*Calculate perimeter */
	move_length=LoadMoves(shape,body_size);	
	
	/*Calculate attack power */
	attack_power=SetAttackPower(lower_bound,upper_bound);
	
	/*Print information */
	ShowPokemon(shape,body_size,color,move_length,attack_power);
	


	return 0;	
}

double CreateBody(int shape){
	int edges,	//For square values
		edgers,edgerl,	//For rectangular values, first shorter,second longer edge
		rad;		//For circular radius
	
	/*According to shape check being square , rectangular ,circular */
	if(shape == SQUARE){
		printf("Square edge: ");
		scanf("%d",&edges);
		/*Check negative or positive */
		if(edges>0)
			return edges*edges;
		else{	
			printf("Please positive number: ");
			scanf("%d",&edges);
			return edges*edges;
		}	
	}
	else if(shape == RECTANGULAR){
		printf("Rectangular edges(shorter edge is 5): ");
		scanf("%d%d",&edgers,&edgerl);
		return edgers*edgerl;
	}
	else{
		printf("Circular radius: ");
		scanf("%d",&rad);
		return PI*rad*rad;
	}
}

int SetColor(int color){
	int res;	//Return values
	if(0<color && color<1000){
		res=color%5;
		return res;
	}
	else{
		res=1;
		return res;
	}
}		
	
double LoadMoves(int shape,double body_size){
	int edgers,edgerl;	//For rectangular
	int res;			//For square
	double rad,rad2;		//For circular
	
	edgers=5;	
	
	if(shape == SQUARE){
		res=sqrt(body_size);
		return 4*res;
	}
	else if(shape == RECTANGULAR){
		edgerl=(body_size/edgers);
		return 2*(edgers+edgerl);
		
	}
	else{
		rad=(body_size/PI);
		rad2=sqrt(rad);
		return 2*PI*rad2;
	}
}	

int SetAttackPower(int lower_bound,int upper_bound){
	int power;
	srand(time(NULL));	//Generates random number
	power=(lower_bound+(rand()%upper_bound));
	return power;
}

void ShowPokemon(int shape,double body_size,int color,double move_length,int attack_power){
	int i,j;	//For loop
	int edgers=5,	//For rectangular
		edgerl;
	int edges;		//For square
	double r;	//For circular
	
	if(shape == SQUARE){
		edges=(body_size/edges);	//Find square edge
		
		for(i=0;i<edges;i++){ 		//Draw picture
			for(j=0;j<edges;j++){
				printf("X");
			}
			printf("\n");
		}
	
		printf("Name: Square Pokemon\n");
		printf("Size: %.2f\n",body_size);
		
		/*Check color */
		if(color == RED)			
			printf("Color: Red\n");
		else if(color == YELLOW)
			printf("Color: Yellow\n");
		else if(color == BLUE)
			printf("Color: Blue\n");
		else if(color == BLACK)
			printf("Color: Black\n");
		else
			printf("Color: White\n");
		
		printf("Move: %.2f\n",move_length);
		printf("Attack Power: %d\n",attack_power);
	}
	else if(shape == RECTANGULAR){
		edgerl=(body_size/edgers);	//Find short edge
		
		for(i=0;i<edgers;i++){		//Draw picture
			for(j=0;j<edgerl;j++){
				printf("X");
			}
			printf("\n");
		}
		
		printf("Name: Rectangular Pokemon\n");
		printf("Size: %.2f\n",body_size);

		/*Check color */
		if(color == RED)
			printf("Color: Red\n");
		else if(color == YELLOW)
			printf("Color: Yellow\n");
		else if(color == BLUE)
			printf("Color: Blue\n");
		else if(color == BLACK)
			printf("Color: Black\n");
		else
			printf("Color: White\n");
	
		printf("Move: %.2f\n",move_length);
		printf("Attack power: %d\n",attack_power);
	}	
	else{
		r=body_size/PI;
		r=sqrt(r);
		if((int)r%2 == 0){		//Draw picture
			for(i=0;i<((r/2)-1);i++)
				printf("\t");
			for(i=0;i<((r/2)+2);i++)
				printf(" ");
			printf("X\n");
		
			for(j=0;j<(r/2);j++){
				for(i=j;i<((r/2)-1);i++){
					printf("\t");
					printf(" ");
				}		
				printf("X");
				for(i=0;i<(2*j);i++)
					printf("\t");
				for(i=0;i<(2*j+7);i++)
					printf(" ");
				printf("X\n");
			}
			for(j=0;j<((r/2)-1);j++){
				for(i=0;i<(j+1);i++){
					printf("\t");
					printf(" ");
				}
				printf("X");
				for(i=(2*j);i<(r-4);i++)
					printf("\t");
				for(i=(2*j);i<(r+3);i++)
					printf(" ");
				printf("X\n");
			}
			for(i=0;i<((r/2)-1);i++)
				printf("\t");
			for(i=0;i<((r/2)+2);i++)
				printf(" ");
			printf("X\n");		

		}
		else{
			if(r==1)
				printf("X\n");
			else{
				for(i=0;i<(((r+1)/2)-1);i++)
					printf("\t");
				printf("X\n");
				for(j=0;j<(((r+1)/2)-1);j++){
					for(i=j+1;i<(((r+1)/2)-1);i++)
						printf("\t");	
					printf("X");
					for(i=0;i<(2*j)+2;i++)
						printf("\t");
					for(i=0;i<(2*j)+1;i++)
						printf(" ");
					printf("X\n");
				}
				for(j=0;j<(((r+1)/2)-2);j++){
					for(i=0;i<(j+1);i++)
						printf("\t");
					printf("X");
					for(i=(r-3);i>(2*j);i--)
						printf("\t");
					for(i=(r-4);i>(2*j);i--)
						printf(" ");
					printf("X\n");
				}
				for(i=0;i<(((r+1)/2)-1);i++)
					printf("\t");
				printf("X\n");
			}
		
		}

		printf("Name: Circular Pokemon\n");
		printf("Size: %.2f\n",body_size);
	
		/*Check color */
		if(color == RED)
			printf("Color: Red\n");
		else if(color == YELLOW)
			printf("Color: Yellow\n");
		else if(color == BLUE)
			printf("Color: Blue\n");
		else if(color == BLACK)
			printf("Color: Black\n");
		else
			printf("Color: White\n");
		
		printf("Move: %.2f\n",move_length);
		printf("Attack power: %d\n",attack_power);
	}
}

		

				
		


						





			
	
	

	


	





