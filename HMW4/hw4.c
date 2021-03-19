#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 1
#define P_SIZE 10
#define P_LEN 11
#define ATTACK_SIZE 2
#define SPECIAL_SIZE 10
#define AREA_SIZE 8

/*Cha=Charmander,Pika=Pikachu,Squi=Squirtle,Bul=Bulbasaur,
Pid=Pidgeotto,Rat=Ratata,Mug=Mug,Cat=Caterpie,Zub=Zubat,Kra=Krabby*/
typedef enum{Cha,Pika,Squi,Bul,Pid,Rat,Mug,Cat,Zub,Kra} pokemon;
typedef enum{quadratic,linear} attack_type;


void menu();
void pokedex(char Pokemon_name[P_SIZE][P_LEN],int range[SPECIAL_SIZE],attack_type type[ATTACK_SIZE],int attack_power[SPECIAL_SIZE],int stamina[SPECIAL_SIZE]);
void oaks_laboratory(char Pokemon_name[P_SIZE][P_LEN],pokemon Pokemons[10],pokemon *my_Pokemons);
void show_Pokemons(char Pokemon_name[P_SIZE][P_LEN],pokemon Pokemons[10],int pokemon_count);
void catch_a_pokemon(char Pokemon_name[P_SIZE][P_LEN],pokemon Pokemons[10],pokemon *my_pocket);
void release_a_pokemon(char Pokemon_name[P_SIZE][P_LEN],pokemon Pokemons[10],pokemon *my_pocket);
void show_my_pocket(char Pokemon_name[P_SIZE][P_LEN],pokemon Pokemons[10],pokemon *my_pocket);
void battle(char Pokemon_name[P_SIZE][P_LEN],int range[SPECIAL_SIZE],attack_type type[ATTACK_SIZE],int attack_power[SPECIAL_SIZE],int stamina[SPECIAL_SIZE],pokemon user_Pokemons[10]);
void show_area(char Pokemon_name[P_SIZE][P_LEN],int area[AREA_SIZE][AREA_SIZE],int pokemon_stamina_view[8][8]);

int main(){
	menu();
	return 0;
}

void menu(){
	int choice; //Option for menu
	
	while(COUNT){
		printf("MENU\n");
		printf("1.Open Pokedex\n");
		printf("2.Go to Oak's Laboratory\n");
		printf("3.Enter the tournament\n");
		/*For menu choose option */
		printf("Choice: ");
		scanf("%d",&choice);
		/*Check option range*/
		if(choice < 1 || choice > 4) 
			printf("This is an invalid choice.Try again!\n");
		else{
			/*Information enter manually */ 
			char Pokemon_name[P_SIZE][P_LEN]={"Charmander","Pikachu","Squirtle","Bulbasaur","Pidgeotto","Ratata",
								"Mug","Caterpie","Zubat","Krabby"};
			int range[SPECIAL_SIZE]={1,3,4,3,2,2,1,2,3,2};
			int i;
			attack_type type[ATTACK_SIZE]={quadratic,linear};
			int attack_power[SPECIAL_SIZE]={500,350,300,400,250,250,350,200,350,300};
			int stamina[SPECIAL_SIZE]={2200,1500,1700,2500,1900,2500,3000,1200,1250,2600};
			pokemon Pokemons[10]={Cha,Pika,Squi,Bul,Pid,Rat,Mug,Cat,Zub,Kra};
			pokemon my_Pokemons[10]={Cha,Pika,Squi,Bul,Pid,Rat,Mug,Cat,Zub,Kra};
			/*Menu Option */
			switch(choice){
				case 1:
					pokedex(Pokemon_name,range,type,attack_power,stamina);
					break;
				case 2:
					oaks_laboratory(Pokemon_name,Pokemons,my_Pokemons);
					break;
				case 3:
					battle(Pokemon_name,range,type,attack_power,stamina,my_Pokemons);
					break;
			}
		}
	}

}						

/*Show the specifications of the choose Pokemon */						
void pokedex(char Pokemon_name[P_SIZE][P_LEN],int range[SPECIAL_SIZE],attack_type type[ATTACK_SIZE],int attack_power[SPECIAL_SIZE],int stamina[SPECIAL_SIZE]){
	
	int i=0,j=0,flag=0;	//For loop
	char option[11];	//Feature the display pokemon name
	/*Taken pokemon name */
	printf("Please type name of the Pokémon (type exit to close Pokedex): ");
	scanf("%s",option);
	
	/*Check character to character and print choose pokemon specifications*/
	for(i=0;i<11;i++){
      	for(j=0; j<Pokemon_name[i][j] != '\0';j++){
                	if(Pokemon_name[i][j] == option[j]){
                		flag++;
                	}
        	}
		if(flag == j){
			printf("Name: ");
			for(j=0;j< Pokemon_name[i][j] != '\0';j++){
           			printf("%c",Pokemon_name[i][j]);
            	}
            	printf("\n");
			printf("Range: %d block\n",range[i]);
			printf("Attack Power: %d\n",attack_power[i]);
			if(i==0 || i==4 || i== 6 || i==7){
				type[0]=quadratic;
				printf("Attack type: Quadratic\n");
			}
			else{
				type[1]=linear;
				printf("Attack type: Linear\n");
			}
			printf("Stamina: %d\n",stamina[i]);
            	break;
        	}
		flag=0;
	}


}

/*Go to Oaks Labaratory Menu */
void oaks_laboratory(char Pokemon_name[P_SIZE][P_LEN],pokemon Pokemons[10],pokemon *my_Pokemons){
	int choice;
	while(COUNT){
		printf("Welcome to Laboratory of Professor Oak.How can I help you?\n");
		printf("1)Show Pokemons\n");
		printf("2)Catch a Pokemon\n");
		printf("3)Release a Pokemon\n");
		printf("4)Show my pocket\n");
		printf("5)Back\n");
		printf("Choice: ");
		scanf("%d",&choice);
		/*Check choice range */
		if(choice < 1 || choice > 5) 
			printf("This is an invalid choice.Try again!\n");
		else{
			int count=0;
		
			switch(choice){
				case 1:
					show_Pokemons(Pokemon_name,Pokemons,count);
					break;
				case 2:
					catch_a_pokemon(Pokemon_name,Pokemons,my_Pokemons);
					break;
				case 3:
					release_a_pokemon(Pokemon_name,Pokemons,my_Pokemons);
					break;
				case 4:
					show_my_pocket(Pokemon_name,Pokemons,my_Pokemons);
					break;
				case 5:
					menu();
					break;
			}
		}
	}
	


}
/*Show all pokemons,respectively */
void show_Pokemons(char Pokemon_name[P_SIZE][P_LEN],pokemon Pokemons[10],int pokemon_count){
	int i; //For loop
	/*prints all the Pokémons */
	for(i=0;i<10;i++){
		printf("%d - %s\n",pokemon_count,Pokemon_name[i]);
		pokemon_count++;
	}
}

void catch_a_pokemon(char Pokemon_name[P_SIZE][P_LEN],pokemon Pokemons[10],pokemon *my_pocket){
	/*First show all pokemon */
	int count=0;
	show_Pokemons(Pokemon_name,Pokemons,count);
	
	int i=1,j,temp[10],index=0;
	int option;
	/*Name of catch of the pokemon */
	printf("Choose the pokemon you want to catch: ");
	scanf("%d",&option);
	/*For first element*/
	switch(option){
		case 0: *(my_pocket)=Cha; break;
		case 1: *(my_pocket)=Pika; break;
		case 2: *(my_pocket)=Squi; break;
		case 3: *(my_pocket)=Bul; break;
		case 4: *(my_pocket)=Pid; break;
		case 5: *(my_pocket)=Rat; break;
		case 6: *(my_pocket)=Mug; break;
		case 7: *(my_pocket)=Cat; break;
		case 8: *(my_pocket)=Zub; break;
		case 9: *(my_pocket)=Kra; break;
		default: break;
	}
	temp[0]=option;
	/*For other elements */
	while(i<4){
		printf("Choose the pokemon you want to catch: ");
		scanf("%d",&option);
		/*Check whether more than one is entered*/
		for(j=0;j<i;j++){
			if(option == temp[j])
				index=1;
		}
		if(index==0){
			switch(option){
				case 0: *(my_pocket+i)=Cha; break;
				case 1: *(my_pocket+i)=Pika; break;
				case 2: *(my_pocket+i)=Squi; break;
				case 3: *(my_pocket+i)=Bul; break;
				case 4: *(my_pocket+i)=Pid; break;
				case 5: *(my_pocket+i)=Rat; break;
				case 6: *(my_pocket+i)=Mug; break;
				case 7: *(my_pocket+i)=Cat; break;
				case 8: *(my_pocket+i)=Zub; break;
				case 9: *(my_pocket+i)=Kra; break;
				default: break;
			}
			temp[i]=option;
			i++;
		}
		index=0;
	}

}
/*Release a Pokémon option removes a Pokemon*/		
void release_a_pokemon(char Pokemon_name[P_SIZE][P_LEN],pokemon Pokemons[10],pokemon *my_pocket){
	int count=0; //Show Pokemon count
	/*First show all pokemon */
	show_Pokemons(Pokemon_name,Pokemons,count);
	int del,i,j=0;
	/*Taken remove pokemon number*/
	printf("Enter remove the pokemon number: ");
	scanf("%d",&del);
	
	int n=sizeof(my_pocket); //According to size return loop
	/*Release Pokemon loop*/
	for(i=0;i<n;i++){
		if(*(my_pocket+i)==del){
			for(j=i;j<n;j++)
				*(my_pocket+j)=*(my_pocket+(j+1));
			n--;
		}
	}

}

void show_my_pocket(char Pokemon_name[P_SIZE][P_LEN],pokemon Pokemons[10],pokemon *my_pocket){
	int i;	/*For loop */
	/*Show my pocket */
	for(i=0;i<sizeof(*my_pocket);i++){
		switch(*(my_pocket+i)){
			case Cha: printf("Charmander\n");  break;
			case Pika: printf("Pikachu\n"); break;
			case Squi: printf("Squirtle\n"); break;
			case Bul: printf("Bulbasaur\n"); break;
			case Pid: printf("Pidgeotto\n"); break;
			case Rat: printf("Ratata\n"); break;
			case Mug: printf("Mug\n"); break;
			case Cat: printf("Caterpie\n"); break;
			case Zub: printf("Zubat\n"); break;
			case Kra: printf("Krabby\n"); break;
			default: break;
		}
	} 
	
}

void battle(char Pokemon_name[P_SIZE][P_LEN],int range[SPECIAL_SIZE],attack_type type[ATTACK_SIZE],int attack_power[SPECIAL_SIZE],int stamina[SPECIAL_SIZE],pokemon user_Pokemons[10]){
	int area[AREA_SIZE][AREA_SIZE];
	int pokemon_staminas_view[8][8];
	int i=0,j,temp,k;
	int temp_AI;	//For AI store variable
	int flag=0;
	int current_x[4],current_y[4];	//User First coordinate
	int new_x,new_y;	//User Update coordinate
	int move_x=0,move_y=0; //User move coordinate
	int current_x_AI[4],current_y_AI[4];	//AI First coordinate
	int new_x_AI,new_y_AI;	//AI first coordinate
	int move_x_AI=0,move_y_AI=0;	//AI move coordinate
	int pokemon_number,AI_number;	//Choose pokemon for battle,User and AI,respectively
	pokemon AI_pokemons[10];
	
	/*Which pokemon is in which coordinate*/
	while(i<4){
		printf("Enter of X coordinate: ");
		scanf("%d",&temp);
		if(temp == 1 || temp == 0){
			current_x[i]=temp;
			printf("Enter of y coordinate: ");
			scanf("%d",&current_y[i]);
			i++;
		}
	}
	/*For didn't give a randoom value */
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			pokemon_staminas_view[i][j]=0;
		}
	}
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			area[i][j]=15;
		}
	}
	
	/*User Pokemon placement in the arena with place and stamina*/
	for(i=0;i<4;i++){
		area[current_x[i]][current_y[i]]=user_Pokemons[i];
		pokemon_staminas_view[current_x[i]][current_y[i]]=stamina[user_Pokemons[i]];
	}
	/*AI choose random pokemons*/
	for(i=0;i<4;i++){
		srand(time(NULL));	
		AI_pokemons[i]=rand()%4;
	}
	/*AI first coordinte*/
	srand(time(NULL));
	for(i=0;i<4;i++){
		current_x_AI[i]=(6+rand()%8);
		current_y_AI[i]=(rand()%8);
	}

	for(i=0;i<4;i++){
		area[current_x_AI[i]][current_y_AI[i]]=AI_pokemons[i];
		pokemon_staminas_view[current_x_AI[i]][current_y_AI[i]]=stamina[AI_pokemons[i]];
	}
	/*Show area*/
	show_area(Pokemon_name,area,pokemon_staminas_view);
	
	/*Enter battle pokemon number*/
	printf("Enter battle of pokemon number(by number in my pocket): ");	
	scanf("%d",&pokemon_number);
	/*Situation of number greater than pokemons number */
	/*Take again value until possible*/
	if(pokemon_number>4){
		flag=1;
		while(flag==1){
			printf("Enter battle of pokemon number(by number in my pocket): ");	
			scanf("%d",&pokemon_number);	
			if(pokemon_number < 4){
				flag=0;
				break;
			}
		}
	}

	/*Keep Value*/	
	new_x=current_x[pokemon_number];
	new_y=current_y[pokemon_number];
	/*For check*/
	flag=0;
	/*Enter coordinate move battle pokemon */
	/*(y koordinate equal current_y)*/
	printf("Enter x koordinate move must be 1 or 2 block: ");
	scanf("%d",&move_x);
	if(move_x>2 && move_x<=1){
		flag=1;
		while(flag==1){
			printf("Enter x koordinate move must be 1 or 2 block: ");
			scanf("%d",&move_x);
			if(move_x == 1 || move_x == 0){
				flag=0;
				break;
			}
			flag=1;
		}
	}
	/*Update coordinate*/
	new_x += move_x;
	new_y += move_y;
	current_x[pokemon_number]=new_x;
	current_y[pokemon_number]=new_y;
	show_area(Pokemon_name,area,pokemon_staminas_view);
	/*Check range for attack*/
	for(i=0;i<range[pokemon_number];i++){
		current_x_AI[pokemon_number]++;
		if(area[current_x_AI[pokemon_number]][current_y_AI[pokemon_number]] < 9 && area[current_x_AI[pokemon_number]][current_y_AI[pokemon_number]] >= 0){
			
		}
	}

	
	/*AI choose battle pokemons*/
	AI_number=(rand()%4);
	
	/*AI move battle to choose random 1 or 2 blocks*/
	srand(time(NULL));
	move_x_AI=(1+rand()%3);
	move_y_AI=0;
	/*Update coordinate*/
	new_x_AI += move_x_AI;
	new_y_AI += move_y_AI;
	current_x[AI_number]=new_x_AI;
	current_y[AI_number]=new_y_AI;
	show_area(Pokemon_name,area,pokemon_staminas_view);


}

void show_area(char Pokemon_name[P_SIZE][P_LEN],int area[AREA_SIZE][AREA_SIZE],int pokemon_stamina_view[8][8]){
	int i,j;
	int temp;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(area[i][j]<9 || area[i][j]>=0){
				temp=area[i][j];
				switch(area[i][j]){
					case 0:
						printf("|  Cha  ");
						break;
					case 1:
						printf("|  Pik  ");
						break;
					case 2:
						printf("|  Squ  ");
						break;
					case 3:
						printf("|  Bul  ");
						break;
					case 4:
						printf("|  Pid  ");
						break;
					case 5:
						printf("|  Rat  ");
						break;
					case 6:
						printf("|  Mug  ");
						break;
					case 7:
						printf("|  Cate ");
						break;
					case 8:
						printf("|  Zub  ");
						break;
					case 9:
						printf("|  Kra  ");
						break;
				}
			}
			printf("|       ");
		}
		
		printf("\n");
		
		for(j=0;j<8;j++){
			if(pokemon_stamina_view[i][j] != 0){
				printf("|(%d) ",pokemon_stamina_view[i][j]);
			}	
			printf("|       ");
		}
		printf("|\n");
		for(j=0;j<65;j++)
			printf("-");
		printf("\n");
	}	
	printf("\n");
}





			
			
	
