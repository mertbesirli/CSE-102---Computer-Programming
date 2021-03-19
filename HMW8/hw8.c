#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef enum types{noone,car,cap}player_type;
typedef enum typ{start,property,tax,punish,fortune}block_type;

typedef struct m{
	int card_no;
	char *name;
	struct m *next_f;
}fortune_card;

typedef struct{
	player_type type;
	int current_block_id;
	int owned_block_ids[12];
	int account;
	int turn_to_wait;
	char *name;
}player;

typedef struct n{
	int block_id;
	char *name;
	int price;
	int rent;
	int rent_1;
	int rent_2;
	int rent_3;
	int house_price;
	int house_count;
	player owner;
	block_type type;
	struct n *next;
}block;



void init_the_board(block *iter);
void init_the_fortune(fortune_card *fiter);
void show_board(block *iter,player player_one,player player_two);
void gameplay(block *iter,fortune_card *fiter,player player_one,player player_two);
void show_my_properties(player player_any);
void show_properties(block *iter);
void buy_property(block *iter,player *current_player);
void sell_property(block *iter,player *current_player);

int main(){
	int i;	//For loop	
		
	block *root=(block*)malloc(sizeof(block));
	block *iter;
	root->next=NULL;
	iter=root;
	
	fortune_card *ftr=(fortune_card*)malloc(sizeof(fortune_card));
	fortune_card *fiter;
	ftr->next_f=NULL;
	fiter=ftr;
	
	
	
	player player_one;
	player player_two;
		
	/*Fill in the board*/
	init_the_board(iter);	
	/*Fill in the fortune*/
	init_the_fortune(fiter);
	/*Gameplay menu*/
	gameplay(iter,fiter,player_one,player_two);

	return 0;
}

void init_the_board(block *iter){
	int i;	//For loop
	
	block *temp;
	
	temp=iter;
	/*Fill board with linked list for block_id*/
	temp->block_id=0;
	for(i=1;i<24;i++){
		temp->next=(block*)malloc(sizeof(block));
		temp=temp->next;
		temp->block_id=i;
		temp->next=NULL;
	}
	
	temp=iter;
	
	/*Fill board with linked list for block names*/
	temp->name="Start";
	temp->next->name="Esenyurt";
	temp->next->next->name="Car Park";
	temp=temp->next->next;
	temp->next->name="Fortune Card";
	temp->next->next->name="Tuzla";
	temp=temp->next->next;
	temp->next->name="Arnavutkoy";
	temp->next->next->name="Wait 2 Turn";	
	temp=temp->next->next;
	temp->next->name="Catalca";
	temp->next->next->name="Beykoz";
	temp=temp->next->next;
	temp->next->name="Fortune Card";
	temp->next->next->name="Car Fix";
	temp=temp->next->next;
	temp->next->name="Maltepe";
	temp->next->next->name="Bills";
	temp=temp->next->next;
	temp->next->name="Sisli";
	temp->next->next->name="Oil";
	temp=temp->next->next;
	temp->next->name="Fortune Card";
	temp->next->next->name="Atasehir";
	temp=temp->next->next;
	temp->next->name="Sariyer";
	temp->next->next->name="Wait 1 Turn";
	temp=temp->next->next;
	temp->next->name="Kadiköy";
	temp->next->next->name="Besiktas";
	temp=temp->next->next;
	temp->next->name="Fortune Card";
	temp->next->next->name="Vocation";
	temp=temp->next->next;
	temp->next->name="Bebek";
	
	temp=iter;
	
	/*Fill board with linked list for block price*/
	temp->price=0;
	temp->next->price=16000;
	temp->next->next->price=0;
	temp=temp->next->next;
	temp->next->price=0;
	temp->next->next->price=16500;
	temp=temp->next->next;
	temp->next->price=17000;
	temp->next->next->price=0;
	temp=temp->next->next;
	temp->next->price=20000;
	temp->next->next->price=23000;
	temp=temp->next->next;
	temp->next->price=0;
	temp->next->next->price=0;
	temp=temp->next->next;
	temp->next->price=30000;
	temp->next->next->price=0;
	temp=temp->next->next;
	temp->next->price=33000;
	temp->next->next->price=0;
	temp=temp->next->next;
	temp->next->price=0;
	temp->next->next->price=35000;
	temp=temp->next->next;
	temp->next->price=40000;
	temp->next->next->price=0;
	temp=temp->next->next;
	temp->next->price=43000;
	temp->next->next->price=60000;
	temp=temp->next->next;
	temp->next->price=0;
	temp->next->next->price=0;
	temp=temp->next->next;
	temp->next->price=70000;
	
	temp=iter;
	
	/*Fill board with linked list for rent(no house)*/
	temp->rent=0;
	temp->next->rent=800;
	temp->next->next->rent=1500;
	temp=temp->next->next;
	temp->next->rent=0;
	temp->next->next->rent=850;
	temp=temp->next->next;
	temp->next->rent=875;
	temp->next->next->rent=2;
	temp=temp->next->next;
	temp->next->rent=1000;
	temp->next->next->rent=1100;
	temp=temp->next->next;
	temp->next->rent=0;
	temp->next->next->rent=1750;
	temp=temp->next->next;
	temp->next->rent=1350;
	temp->next->next->rent=2000;
	temp=temp->next->next;
	temp->next->rent=1500;
	temp->next->next->rent=2250;
	temp=temp->next->next;
	temp->next->rent=0;
	temp->next->next->rent=1600;
	temp=temp->next->next;
	temp->next->rent=1750;
	temp->next->next->rent=1;
	temp=temp->next->next;
	temp->next->rent=1900;
	temp->next->next->rent=2500;
	temp=temp->next->next;
	temp->next->rent=0;
	temp->next->next->rent=5000;
	temp=temp->next->next;
	temp->next->rent=3500;
	
	temp=iter;
	
	/*Fill board with linked list for rent(one house)*/
	temp->rent_1=0;
	temp->next->rent_1=4000;
	temp->next->next->rent_1=0;
	temp=temp->next->next;
	temp->next->rent_1=0;
	temp->next->next->rent_1=4250;
	temp=temp->next->next;
	temp->next->rent_1=4500;
	temp->next->next->rent_1=0;
	temp=temp->next->next;
	temp->next->rent_1=5000;
	temp->next->next->rent_1=5500;
	temp=temp->next->next;
	temp->next->rent_1=0;
	temp->next->next->rent_1=0;
	temp=temp->next->next;
	temp->next->rent_1=7000;
	temp->next->next->rent_1=0;
	temp=temp->next->next;
	temp->next->rent_1=8000;
	temp->next->next->rent_1=0;
	temp=temp->next->next;
	temp->next->rent_1=0;
	temp->next->next->rent_1=8500;
	temp=temp->next->next;
	temp->next->rent_1=9500;
	temp->next->next->rent_1=0;
	temp=temp->next->next;
	temp->next->rent_1=11000;
	temp->next->next->rent_1=15000;
	temp=temp->next->next;
	temp->next->rent_1=0;
	temp->next->next->rent_1=0;
	temp=temp->next->next;
	temp->next->rent_1=20000;
	
	temp=iter;
	
	
	/*Fill board with linked list for rent(two house)*/
	temp->rent_2=0;
	temp->next->rent_2=9000;
	temp->next->next->rent_2=0;
	temp=temp->next->next;
	temp->next->rent_2=0;
	temp->next->next->rent_2=9500;
	temp=temp->next->next;
	temp->next->rent_2=10000;
	temp->next->next->rent_2=0;
	temp=temp->next->next;
	temp->next->rent_2=12000;
	temp->next->next->rent_2=12500;
	temp=temp->next->next;
	temp->next->rent_2=0;
	temp->next->next->rent_2=0;
	temp=temp->next->next;
	temp->next->rent_2=15000;
	temp->next->next->rent_2=0;
	temp=temp->next->next;
	temp->next->rent_2=16000;
	temp->next->next->rent_2=0;
	temp=temp->next->next;
	temp->next->rent_2=0;
	temp->next->next->rent_2=17000;
	temp=temp->next->next;
	temp->next->rent_2=19000;
	temp->next->next->rent_2=0;
	temp=temp->next->next;
	temp->next->rent_2=21500;
	temp->next->next->rent_2=28000;
	temp=temp->next->next;
	temp->next->rent_2=0;
	temp->next->next->rent_2=0;
	temp=temp->next->next;
	temp->next->rent_2=35500;
	
	temp=iter;
	
	/*Fill board with linked list for rent(three house)*/
	temp->rent_3=0;
	temp->next->rent_3=25000;
	temp->next->next->rent_3=0;
	temp=temp->next->next;
	temp->next->rent_3=0;
	temp->next->next->rent_3=26000;
	temp=temp->next->next;
	temp->next->rent_3=28000;
	temp->next->next->rent_3=0;
	temp=temp->next->next;
	temp->next->rent_3=30000;
	temp->next->next->rent_3=33000;
	temp=temp->next->next;
	temp->next->rent_3=0;
	temp->next->next->rent_3=0;
	temp=temp->next->next;
	temp->next->rent_3=40000;
	temp->next->next->rent_3=0;
	temp=temp->next->next;
	temp->next->rent_3=42000;
	temp->next->next->rent_3=0;
	temp=temp->next->next;
	temp->next->rent_3=0;
	temp->next->next->rent_3=45000;
	temp=temp->next->next;
	temp->next->rent_3=48000;
	temp->next->next->rent_3=0;
	temp=temp->next->next;
	temp->next->rent_3=55000;
	temp->next->next->rent_3=60000;
	temp=temp->next->next;
	temp->next->rent_3=0;
	temp->next->next->rent_3=0;
	temp=temp->next->next;
	temp->next->rent_3=65000;
	
	temp=iter;
	
	/*Fill board with linked list for house price*/
	temp->house_price=0;
	temp->next->house_price=10000;
	temp->next->next->house_price=0;
	temp=temp->next->next;
	temp->next->house_price=0;
	temp->next->next->house_price=12000;
	temp=temp->next->next;
	temp->next->house_price=12000;
	temp->next->next->house_price=0;
	temp=temp->next->next;
	temp->next->house_price=13000;
	temp->next->next->house_price=13000;
	temp=temp->next->next;
	temp->next->house_price=0;
	temp->next->next->house_price=0;
	temp=temp->next->next;
	temp->next->house_price=15000;
	temp->next->next->house_price=0;
	temp=temp->next->next;
	temp->next->house_price=16000;
	temp->next->next->house_price=0;
	temp=temp->next->next;
	temp->next->house_price=0;
	temp->next->next->house_price=17000;
	temp=temp->next->next;
	temp->next->house_price=19000;
	temp->next->next->house_price=0;
	temp=temp->next->next;
	temp->next->house_price=23000;
	temp->next->next->house_price=30000;
	temp=temp->next->next;
	temp->next->house_price=0;
	temp->next->next->house_price=0;
	temp=temp->next->next;
	temp->next->house_price=35000;
	
	temp=iter;
	
	/*Fill board with linked list for block type*/
	temp->type=start;
	temp->next->type=property;
	temp->next->next->type=tax;
	temp=temp->next->next;
	temp->next->type=fortune;
	temp->next->next->type=property;
	temp=temp->next->next;
	temp->next->type=property;
	temp->next->next->type=punish;
	temp=temp->next->next;
	temp->next->type=property;
	temp->next->next->type=property;
	temp=temp->next->next;
	temp->next->type=fortune;
	temp->next->next->type=tax;
	temp=temp->next->next;
	temp->next->type=property;
	temp->next->next->type=tax;
	temp=temp->next->next;
	temp->next->type=property;
	temp->next->next->type=tax;
	temp=temp->next->next;
	temp->next->type=fortune;
	temp->next->next->type=property;
	temp=temp->next->next;
	temp->next->type=property;
	temp->next->next->type=punish;
	temp=temp->next->next;
	temp->next->type=property;
	temp->next->next->type=property;
	temp=temp->next->next;
	temp->next->type=fortune;
	temp->next->next->type=tax;
	temp=temp->next->next;
	temp->next->type=property;
	
	temp=iter;
	
	/*Fill board with linked list for house count*/
	temp->house_count=0;
	temp->next->house_count=0;
	temp->next->next->house_count=0;
	temp=temp->next->next;
	temp->next->house_count=0;
	temp->next->next->house_count=0;
	temp=temp->next->next;
	temp->next->house_count=0;
	temp->next->next->house_count=0;
	temp=temp->next->next;
	temp->next->house_count=0;
	temp->next->next->house_count=0;
	temp=temp->next->next;
	temp->next->house_count=0;
	temp->next->next->house_count=0;
	temp=temp->next->next;
	temp->next->house_count=0;
	temp->next->next->house_count=0;
	temp=temp->next->next;
	temp->next->house_count=0;
	temp->next->next->house_count=0;
	temp=temp->next->next;
	temp->next->house_count=0;
	temp->next->next->house_count=0;
	temp=temp->next->next;
	temp->next->house_count=0;
	temp->next->next->house_count=0;
	temp=temp->next->next;
	temp->next->house_count=0;
	temp->next->next->house_count=0;
	temp=temp->next->next;
	temp->next->house_count=0;
	temp->next->next->house_count=0;
	temp=temp->next->next;
	temp->next->house_count=0;
	
	temp=iter;
	/*Block owner*/
	temp->owner.type=noone;
	temp->next->owner.type=noone;
	temp->next->next->owner.type=noone;
	temp=temp->next->next;
	temp->next->owner.type=noone;
	temp->next->next->owner.type=noone;
	temp=temp->next->next;
	temp->next->owner.type=noone;
	temp->next->next->owner.type=noone;
	temp=temp->next->next;
	temp->next->owner.type=noone;
	temp->next->next->owner.type=noone;
	temp=temp->next->next;
	temp->next->owner.type=noone;
	temp->next->next->owner.type=noone;
	temp=temp->next->next;
	temp->next->owner.type=noone;
	temp->next->next->owner.type=noone;
	temp=temp->next->next;
	temp->next->owner.type=noone;
	temp->next->next->owner.type=noone;
	temp=temp->next->next;
	temp->next->owner.type=noone;
	temp->next->next->owner.type=noone;
	temp=temp->next->next;
	temp->next->owner.type=noone;
	temp->next->next->owner.type=noone;
	temp=temp->next->next;
	temp->next->owner.type=noone;
	temp->next->next->owner.type=noone;
	temp=temp->next->next;
	temp->next->owner.type=noone;
	temp->next->next->owner.type=noone;
	temp=temp->next->next;
	temp->next->owner.type=noone;
	
	temp=iter;
	
}
void init_the_fortune(fortune_card *fiter){
	fortune_card *ftemp;
	ftemp=fiter;
	int i;	//For loop
	
	ftemp->card_no=1;
	for(i=1;i<5;i++){
		ftemp->next_f=(fortune_card*)malloc(sizeof(fortune_card));
		ftemp=ftemp->next_f;
		ftemp->card_no=(i+1);
		ftemp->next_f=NULL;
	}
	ftemp=fiter;
	
	ftemp->name="Free House";
	ftemp->next_f->name="Time Travel";
	ftemp->next_f->next_f->name="Garnishment";
	ftemp=ftemp->next_f->next_f;
	ftemp->next_f->name="Generosity";
	ftemp->next_f->next_f->name="Treasure Hunter";
	
	ftemp=fiter;
	
}

void show_board(block *iter,player player_one,player player_two){
	int i;
	char a=' ';
	block *ptr;
	ptr=iter;
	/*1.Chapter*/
	for(i=0;i<113;i++)
		printf("-");
	printf("\n");
	printf("|");
	/*1.Line*/
	for(i=0;i<7;i++){
		printf("%13s\t|",ptr->name);
		ptr=ptr->next;
	}
	printf("\n");
	/*2.line*/
	printf("|");
	ptr=iter;
	
	for(i=0;i<7;i++){
		if(ptr->price == 0){
			printf("%13c\t|",a);
			ptr=ptr->next;	
		}	
		else{
			printf("%12d$\t|",ptr->price);
			ptr=ptr->next;	
		}	
	}
	printf("\n");
	/*3.line*/
	printf("|");
	for(i=0;i<7;i++){
		if(player_one.current_block_id == i && player_two.current_block_id == i)
			printf("\tcar cap\t|");
		else if(player_one.current_block_id == i)
			printf("\t car\t|");
		else if(player_two.current_block_id == i)
			printf("\t cap\t|");
		else
			printf("%13c\t|",a);	
	}
	printf("\n");
	/*4.line*/
	for(i=0;i<113;i++)
		printf("-");
	printf("\n");
	/*2.chapter*/
	ptr=iter;
	
	for(i=0;i<23;i++)
		ptr=ptr->next;
	
	/*1.line*/
	printf("|%13s\t|",ptr->name);
	ptr=iter;
	
	for(i=0;i<79;i++)
		printf(" ");
	for(i=0;i<7;i++)
		ptr=ptr->next;
	
	printf("|%13s\t|",ptr->name);
	printf("\n");
	/*2.line*/
	ptr=iter;
	for(i=0;i<23;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("|%13c\t|",a);	
	else
		printf("|%12d$\t|",ptr->price);
		
	for(i=0;i<79;i++)
		printf(" ");
	ptr=iter;
	for(i=0;i<7;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("|%13c\t|",a);	
	else
		printf("|%12d$\t|",ptr->price);
		
	printf("\n");
	/*3.line*/
	printf("|");
	if(player_one.current_block_id == 23 && player_two.current_block_id == 23)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 23)
		printf("\t car\t|");
	else if(player_two.current_block_id == 23)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);
	/*Gap between them*/	
	for(i=0;i<79;i++)
		printf(" ");
	printf("|");	
	/*3.line*/
	if(player_one.current_block_id == 7 && player_two.current_block_id == 7)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 7)
		printf("\t car\t|");
	else if(player_two.current_block_id == 7)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);	
	printf("\n");
	
	for(i=0;i<17;i++)
		printf("-");
	for(i=0;i<79;i++)
		printf(" ");
	for(i=0;i<17;i++)
		printf("-");
	printf("\n");
	
	//3.chapter
	ptr=iter;
	for(i=0;i<22;i++)
		ptr=ptr->next;
	//1.line
	printf("|%13s\t|",ptr->name);
	ptr=iter;
	for(i=0;i<79;i++)
		printf(" ");
	for(i=0;i<8;i++)
		ptr=ptr->next;
	printf("|%13s\t|",ptr->name);
	printf("\n");
	//2.line
	ptr=iter;
	for(i=0;i<22;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("|%13c\t|",a);	
	else
		printf("|%12d$\t|",ptr->price);
		
	for(i=0;i<79;i++)
		printf(" ");
	ptr=iter;
	for(i=0;i<8;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("|%13c\t|",a);	
	else
		printf("|%12d$\t|",ptr->price);
		
	printf("\n");
	//3.line
	printf("|");
	if(player_one.current_block_id == 22 && player_two.current_block_id == 22)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 22)
		printf("\t car\t|");
	else if(player_two.current_block_id == 22)
		printf("\t cap\t|");
	else
		printf("%12c\t|",a);	
	/*Gap between them*/
	for(i=0;i<79;i++)
		printf(" ");
	printf("|");	
	//3.line
	if(player_one.current_block_id == 8 && player_two.current_block_id == 8)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 8)
		printf("\t car\t|");
	else if(player_two.current_block_id == 8)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);	
	printf("\n");
	
	for(i=0;i<17;i++)
		printf("-");
	for(i=0;i<79;i++)
		printf(" ");
	for(i=0;i<17;i++)
		printf("-");
	printf("\n");
	//4.chapter
	ptr=iter;
	for(i=0;i<21;i++)
		ptr=ptr->next;
	printf("|%13s\t|",ptr->name);
	ptr=iter;
	for(i=0;i<79;i++)
		printf(" ");
	for(i=0;i<9;i++)
		ptr=ptr->next;
	printf("|%13s\t|",ptr->name);
	printf("\n");
	
	ptr=iter;
	for(i=0;i<21;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("|%13c\t|",a);	
	else
		printf("|%12d$\t|",ptr->price);
	/*Gap between them*/	
	for(i=0;i<79;i++)
		printf(" ");
	ptr=iter;
	for(i=0;i<9;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("|%13c\t|",a);	
	else
		printf("|%12d$\t|",ptr->price);
		
	printf("\n");
	
	printf("|");
	if(player_one.current_block_id == 21 && player_two.current_block_id == 21)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 21)
		printf("\t car\t|");
	else if(player_two.current_block_id == 21)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);	
	for(i=0;i<79;i++)
		printf(" ");
	printf("|");	
	if(player_one.current_block_id == 9 && player_two.current_block_id == 9)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 9)
		printf("\t car\t|");
	else if(player_two.current_block_id == 9)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);	
	printf("\n");
	
	for(i=0;i<17;i++)
		printf("-");
	for(i=0;i<79;i++)
		printf(" ");
	for(i=0;i<17;i++)
		printf("-");
	printf("\n");
	//5.chapter
	ptr=iter;
	for(i=0;i<20;i++)
		ptr=ptr->next;
	printf("|%13s\t|",ptr->name);
	ptr=iter;
	for(i=0;i<79;i++)
		printf(" ");
	for(i=0;i<10;i++)
		ptr=ptr->next;
	printf("|%13s\t|",ptr->name);
	printf("\n");
	ptr=iter;
	for(i=0;i<20;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("|%13c\t|",a);	
	else
		printf("|%12d$\t|",ptr->price);
		
	for(i=0;i<79;i++)
		printf(" ");
	ptr=iter;
	for(i=0;i<10;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("|%13c\t|",a);	
	else
		printf("|%12d$\t|",ptr->price);
		
	printf("\n");
	printf("|");
	if(player_one.current_block_id == 20 && player_two.current_block_id == 20)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 20)
		printf("\t car\t|");
	else if(player_two.current_block_id == 20)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);	
	for(i=0;i<79;i++)
		printf(" ");
	printf("|");	
	if(player_one.current_block_id == 10 && player_two.current_block_id == 10)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 10)
		printf("\t car\t|");
	else if(player_two.current_block_id == 10)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);	
	printf("\n");
	
	for(i=0;i<17;i++)
		printf("-");
	for(i=0;i<79;i++)
		printf(" ");
	for(i=0;i<17;i++)
		printf("-");
	printf("\n");
	//6.chapter
	ptr=iter;
	for(i=0;i<19;i++)
		ptr=ptr->next;
	printf("|%13s\t|",ptr->name);
	ptr=iter;
	for(i=0;i<79;i++)
		printf(" ");
	for(i=0;i<11;i++)
		ptr=ptr->next;
	printf("|%13s\t|",ptr->name);
	printf("\n");
	ptr=iter;
	for(i=0;i<19;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("|%13c\t|",a);	
	else
		printf("|%12d$\t|",ptr->price);
		
	for(i=0;i<79;i++)
		printf(" ");
	ptr=iter;
	for(i=0;i<11;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("|%13c\t|",a);	
	else
		printf("|%12d$\t|",ptr->price);
		
	printf("\n");
	printf("|");
	if(player_one.current_block_id == 19 && player_two.current_block_id == 19)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 19)
		printf("\t car\t|");
	else if(player_two.current_block_id == 19)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);	
	for(i=0;i<79;i++)
		printf(" ");
	printf("|");	
	if(player_one.current_block_id == 11 && player_two.current_block_id == 11)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 11)
		printf("\t car\t|");
	else if(player_two.current_block_id == 11)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);	
	printf("\n");
	
	ptr=iter;
	//7.chapter
	for(i=0;i<113;i++)
		printf("-");
	printf("\n");
	for(i=0;i<18;i++)
		ptr=ptr->next;
	printf("|%13s\t|",ptr->name);
	ptr=iter;
	for(i=0;i<17;i++)
		ptr=ptr->next;
	printf("%13s\t|",ptr->name);
	ptr=iter;
	for(i=0;i<16;i++)
		ptr=ptr->next;
	printf("%13s\t|",ptr->name);
	ptr=iter;
	for(i=0;i<15;i++)
		ptr=ptr->next;
	printf("%13s\t|",ptr->name);
	ptr=iter;
	for(i=0;i<14;i++)
		ptr=ptr->next;
	printf("%13s\t|",ptr->name);
	ptr=iter;
	for(i=0;i<13;i++)
		ptr=ptr->next;
	printf("%13s\t|",ptr->name);
	ptr=iter;
	for(i=0;i<12;i++)
		ptr=ptr->next;
	printf("%13s\t|",ptr->name);
	printf("\n");
	ptr=iter;
	for(i=0;i<18;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("|%13c\t|",a);	
	else
		printf("|%12d$\t|",ptr->price);
	ptr=iter;
	for(i=0;i<17;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("%13c\t|",a);	
	else
		printf("%12d$\t|",ptr->price);
	ptr=iter;
	for(i=0;i<16;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("%13c\t|",a);	
	else
		printf("%12d$\t|",ptr->price);
	ptr=iter;
	for(i=0;i<15;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("%13c\t|",a);	
	else
		printf("%12d$\t|",ptr->price);
	ptr=iter;
	for(i=0;i<14;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("%13c\t|",a);	
	else
		printf("%12d$\t|",ptr->price);
	ptr=iter;
	for(i=0;i<13;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("%13c\t|",a);	
	else
		printf("%12d$\t|",ptr->price);
	ptr=iter;
	for(i=0;i<12;i++)
		ptr=ptr->next;
	if(ptr->price == 0)
			printf("%13c\t|",a);	
	else
		printf("%12d$\t|",ptr->price);
	printf("\n");
	printf("|");
	if(player_one.current_block_id == 18 && player_two.current_block_id == 18)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 18)
		printf("\t car\t|");
	else if(player_two.current_block_id == 18)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);
	if(player_one.current_block_id == 17 && player_two.current_block_id == 17)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 17)
		printf("\t car\t|");
	else if(player_two.current_block_id == 17)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);	
	if(player_one.current_block_id == 16 && player_two.current_block_id == 16)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 16)
		printf("\t car\t|");
	else if(player_two.current_block_id == 16)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);
	if(player_one.current_block_id == 15  && player_two.current_block_id == 15)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 15)
		printf("\t car\t|");
	else if(player_two.current_block_id == 15)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);	
	if(player_one.current_block_id == 14  && player_two.current_block_id == 14)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 14)
		printf("\t car\t|");
	else if(player_two.current_block_id == 14)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);
	if(player_one.current_block_id == 13  && player_two.current_block_id == 13)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 13)
		printf("\t car\t|");
	else if(player_two.current_block_id == 13)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);
	if(player_one.current_block_id == 12  && player_two.current_block_id == 12)
			printf("\tcar cap\t|");
	else if(player_one.current_block_id == 12)
		printf("\t car\t|");
	else if(player_two.current_block_id == 12)
		printf("\t cap\t|");
	else
		printf("%13c\t|",a);
	printf("\n");		
	for(i=0;i<113;i++)
		printf("-");
	printf("\n");
		
}

void gameplay(block *iter,fortune_card *fiter,player player_one,player player_two){
	int count=0,	//Turn car and count=1 turn cap
		choice,
		dice,dice2,
		option,
		ch,
		house_c,  //House count for owned block
		x=0,
		k=0,
		card,	//Choose fortune card
		answer,
		times=0,
		n=0,
		res=0, //Block add number
		i,	//For loop
		dice_count=0,	//To throw the dice once
		ws=0,ws2=0;	//Dice situation necessary variable
	/*İnitial statement*/	
	player_one.current_block_id=0;
	player_two.current_block_id=0;
	player_one.type=car;
	player_two.type=cap;	//computer type cap
	player_one.account=100000;
	player_two.account=100000;
	player_one.turn_to_wait=0;
	player_two.turn_to_wait=0;
	/*Block node for return starting point*/
	block *temp;
	temp=iter;
	/*Same thing for fortune card*/
	fortune_card *f;
	f=fiter;
				
	/*Initial statement*/
	for(i=0;i<12;i++){
		player_one.owned_block_ids[i]=0;
		player_two.owned_block_ids[i]=0;
	}
	
	/*Continue until the money runs out. */
	while(player_one.account > 0 || player_one.account > 0){
		while(count == 0){	//Turn car
			/*Show in board*/
			show_board(iter,player_one,player_two);
			while(1){
				/*Menu*/
				printf("!!CAR TURN(PLAYER ONE)!!\n");
				printf("1 - Roll the dice\n");
				printf("2 - Show my account\n");
				printf("3 - Show my properties\n");
				printf("4 - Show property deeds\n");
				printf("5 - Buy property\n");
				printf("6 - Buy house\n");
				printf("7 - Sell property\n");
				printf("Please select an option to continue: ");
				scanf("%d",&choice);
				
				/*Check choice*/
				if(choice < 1 || choice > 7){
					printf("This invalid choice\n\n");
					break;
				}
				
				/*To set block owner type */
				/*Checking for buying */
				player temp1;
				temp1.account=player_one.account;
				
				
				
				switch(choice){
					case 1:
						dice_count=0;
						/*To roll the dice once*/
						if(dice_count == 0 && player_one.turn_to_wait == 0 && ws == 0){
							/*Roll dice and add new location*/
							srand(time(NULL));
							dice=1+rand()%6;
							player_one.current_block_id += dice;
							dice_count=1;
							n=0;
							/*If the limit passes, check it*/
							if(player_one.current_block_id >= 24){
								player_one.current_block_id-=24;
								/*If money passes again from the beginning, 10000$ added */
								player_one.account += 10000;
								temp1.account=player_one.account; 
							}
							for(i=0;i<player_one.current_block_id;i++)
								temp=temp->next;
							show_board(iter,player_one,player_two);
							printf("\n");
							
							/*Situation of current block tax */
							if(temp->type == tax){
								if(player_one.account >= temp->rent)
									player_one.account -= temp->rent;
								else{
									printf("You have to sell one of your properties\n");
									while(player_one.account < temp->rent)
										sell_property(iter,&player_one);
									player_one.account -= temp->rent;
								}
							}
							/*Situation of current block punish */
							if(temp->type == punish){
								player_one.turn_to_wait += temp->rent;
								printf("You shoud wait %d tour\n\n",player_one.turn_to_wait);	
							}
							/*Situation of current block fortune card*/
							if(temp->type == fortune){
								srand(time(NULL));
								card=1+rand()%5;
								for(i=0;i<card;i++)
									f=f->next_f;
								printf("\nSelecting card No: %d Name: %s\n\n",f->card_no,f->name);
								/*Card 1 situation*/
								if(card == 1){
									show_my_properties(player_one);
									/*Check player have property or not*/
									for(i=0;i<12;i++){
										if(player_one.owned_block_ids[i] == 0)
											house_c+=1;		
									}
									/*Situation of not have property*/
									if(house_c == 12){
										printf("You have no property\n\n");
										n=1;
									}
									while(n == 0){	
										printf("Which property you build house: ");
										scanf("%d",&choice);
										for(i=0;i<12;i++){
											if(player_one.owned_block_ids[i] == choice){
												if(temp->house_count == 3){
													printf("Made home enough , you can't do more\n");
													printf("Choose other property for build house\n\n");
												}
												else{
													temp->house_count += 1;
													n=1;
													break;
												}
											}
										}
									}
								}
								/*Card 2 situation*/
								else if(card == 2){
									srand(time(NULL));
									dice=1+rand()%6;
									if(dice >=1 && dice <=3){
										player_one.current_block_id += 2;
										/*If the limit passes, check it*/
										if(player_one.current_block_id >= 24){
											player_one.current_block_id-=24;
											/*If money passes again from the beginning, 10000$ added */
											player_one.account += 10000;
											temp1.account=player_one.account; 
										}
									}
									else{
										player_one.current_block_id -= 2;
										/*If the limit passes, check it*/
										if(player_one.current_block_id >= 24){
											player_one.current_block_id-=24;
											/*If money passes again from the beginning, 10000$ added */
											player_one.account += 10000;
											temp1.account=player_one.account; 
										}
									}
								}
								/*Card 3 situation*/
								else if(card == 3){
									if(player_one.account >= 5000)
										player_one.account -= 5000;
									else{
										printf("You have to sell one of your properties\n");
										while(player_one.account < 5000)
											sell_property(iter,&player_one);
										player_one.account -= 5000;
									}
									
								}
								/*Card 4 situation*/
								else if(card == 4){
									if(player_one.account >= 10000){
										player_one.account -= 10000;
										player_two.account += 10000;
									}
									else{
										printf("You have to sell one of your properties\n");
										while(player_one.account < 10000)
											sell_property(iter,&player_one);
										player_one.account -= 10000;
									}
								}
								/*Card 5 situation*/
								else if(card == 5)
									player_one.account += 20000;
							}
							house_c=0;
							n=0;
							/*Asking want to buy property*/
							if(temp->type == property && temp->owner.type == noone){	
								printf("Do you want to this block enter press Yes (1) :");
								scanf("%d",&option);
								if(option == 1){
									/*Buy property*/
									buy_property(temp,&player_one);
									/*Board update*/
									temp->house_count += 1;
									/*If buy current property, change property owner type*/
									if(temp1.account != player_one.account)
										temp->owner.type=car;
									/*For player want one more than house */
									while(x == 0){
										printf("Do you want to build one more house?\n");
										printf("If you want press 1!:\n");
										scanf("%d",&ch); 
										if(ch == 1){	
											/*Does he have enough money to buy a house? No more than 3 home */
											if(player_one.account >= temp->house_price && temp->house_count < 3){
												temp->house_count += 1;
												player_one.account -= temp->house_price;	
											}
											else{
												printf("You have not money or build no more than 3 home\n\n");
												x=1;
												break;
											}
										}
										else{
											printf("I understand you can't build house\n\n");
											x=1;
											break;
										}
									}	
									x=0;
								}
							}
							/*Situation of current block someone's property */
							if(temp->type == property && temp->owner.type == cap){
								/*Check have money or not */
								if(player_one.account >= temp->rent)
									player_one.account -= temp->rent;
								else{
									printf("You have to sell one of your properties\n");
									while(player_one.account < temp->rent)
										sell_property(iter,&player_one);
									player_one.account -= temp->rent;
								}
							}
							/*Check have house build or not , according to this player pay rent house money */
							if(temp->type == property && temp->owner.type ==cap && temp->house_count != 0 ){
								/*Situation of have 3 house*/
								if(temp->house_count == 3){
									if(player_one.account >= temp->rent_3)
										player_one.account -= temp->rent_3;
									else{
										printf("You have to sell one of your properties\n");
										while(player_one.account < temp->rent_3)
											sell_property(iter,&player_one);
										player_one.account -= temp->rent_3;
									}
								}
								/*Situation of have 2 house*/
								else if(temp->house_count == 2){
									if(player_one.account >= temp->rent_2)
										player_one.account -= temp->rent_2;
									else{
										printf("You have to sell one of your properties\n");
										while(player_one.account < temp->rent_2)
											sell_property(iter,&player_one);
										player_one.account -= temp->rent_2;
									}
								}
								/*Situation of have 1 house*/
								else if(temp->house_count == 1){
									if(player_one.account >= temp->rent_1)
										player_one.account -= temp->rent_1;
									else{
										printf("You have to sell one of your properties\n");
										while(player_one.account < temp->rent_1)
											sell_property(iter,&player_one);
										player_one.account -= temp->rent_1;
									}
								}		
							}
						
						}
						/*To wait of the punish*/
						else if(dice_count == 0 && player_one.turn_to_wait != 0){
							ws=1;
							player_one.turn_to_wait -= 1;
							printf("Remaining tour: %d\n\n",player_one.turn_to_wait);
							if(player_one.turn_to_wait == 0)
								ws=0;
						}
						/*For turn of other player*/
						printf("Finish your turn...\n\n");
						count=1;
						dice_count=1; 
						temp=iter;
						break;
					case 2:
						/*Showing current account*/
						printf("%d\n",player_one.account);
						break;
					case 3:
						/*Show own properties */
						show_my_properties(player_one);
						break;
					case 4:
						/*See details of its property*/
						show_properties(iter);
						break;
					case 5:
						for(i=0;i<player_one.current_block_id;i++)
							temp=temp->next;
						/*Buy property*/
						buy_property(temp,&player_one);
						if(temp1.account != player_one.account)
							temp->owner.type=car;
						temp=iter;
						break;
					case 6:
						for(i=0;i<player_one.current_block_id;i++)
							temp=temp->next;
						/*Not buy three or more than house*/
						if(temp->house_count == 3)
								printf("Made home enough , you can't do more\n");
						else{
							if(temp->type == property && player_one.account >= temp->house_price && player_one.current_block_id == temp->block_id){
								printf("Only build one house each tour\n");
								printf("Are you sure build home , enter Yes(Press 1) or No(N): ");
								scanf("%d",&answer);
								if(answer == 1){
									temp->house_count += 1;							
									player_one.account -= temp->house_price;
									printf("The house was built\n\n");
								}
								else{			
									printf("I understand you don't want to build a house\n\n");
									temp=iter;
									break;
								}
							}
						}
						temp=iter;
						break;
					case 7:
						sell_property(iter,&player_one);
						break;
				}
				/*For turn the other player*/
				if(count == 1)
					break;
			}
		}
		while(count == 1){	//Turn cap (computer)
			while(1){
				player temp2;
				temp2.account=player_two.account;
				/*Non-waiting condition*/
				if(dice_count == 1 && player_two.turn_to_wait == 0 && ws2 == 0){
					temp=iter;
					for(i=0;i<player_two.current_block_id;i++)
						temp=temp->next;
					/*Buying noone block situation*/
					if(temp->type == property && temp->owner.type == noone){	
						temp=iter;
						res += temp->price;
						/*Total of all of blocks*/
						for(i=0;i<22;i++){
							temp=temp->next;
							res += temp->price;
						}
						temp=iter;
						for(i=0;i<player_two.current_block_id;i++)
							temp=temp->next;
						/*Computer block buying condition check*/		
						if(temp->price < res){
							i=player_two.current_block_id;	
							if(i < 10)
								player_two.owned_block_ids[i]=temp->block_id;
							else if(i == 11)
								player_two.owned_block_ids[0]=temp->block_id;
							else if(i == 13)
								player_two.owned_block_ids[2]=temp->block_id;
							else if(i == 14)
								player_two.owned_block_ids[5]=temp->block_id;
							else if(i == 16)
								player_two.owned_block_ids[8]=temp->block_id;
							else if(i == 17)
								player_two.owned_block_ids[10]=temp->block_id;
							else if(i == 19)
								player_two.owned_block_ids[11]=temp->block_id;
							player_two.account -= temp->price;
							temp->owner.type=car;
						}
						/*Probability if lower than the total*/
						else{
							//Roll the dice
							srand(time(NULL));
							dice=1+rand()%6;
							/*Between 1-3 dice*/
							if(dice >= 1 && dice <= 3){
								i=player_two.current_block_id;	
								if(i < 10)
									player_two.owned_block_ids[i]=temp->block_id;
								else if(i == 11)
									player_two.owned_block_ids[0]=temp->block_id;
								else if(i == 13)
									player_two.owned_block_ids[2]=temp->block_id;
								else if(i == 14)
									player_two.owned_block_ids[5]=temp->block_id;
								else if(i == 16)
									player_two.owned_block_ids[8]=temp->block_id;
								else if(i == 17)
									player_two.owned_block_ids[10]=temp->block_id;
								else if(i == 19)
									player_two.owned_block_ids[11]=temp->block_id;
								player_two.account -= temp->price;
								temp->owner.type=car;
							}
							/*Between 4-6 dice*/
							else{
								count=0;
								dice_count=0;
								temp=iter;
								break;
							}
						}	
					
					}
					
					//If comes to own property
					if(temp->owner.type == cap){
						for(i=0;i<12;i++){
							if(player_two.owned_block_ids[i] != 0 || player_two.owned_block_ids[i] != 2 || player_two.owned_block_ids[i] != 3 || player_two.owned_block_ids[i] != 6 || player_two.owned_block_ids[i] != 9 || player_two.owned_block_ids[i] != 10 || player_two.owned_block_ids[i] != 12 || player_two.owned_block_ids[i] != 14 || player_two.owned_block_ids[i] != 15 || player_two.owned_block_ids[i] != 18 || player_two.owned_block_ids[i] != 21 || player_two.owned_block_ids[i] != 22)
								k+=1;
						}
						if(k >= 4){
							srand(time(NULL));
							dice=1+rand()%6;
							/*Condition of build house*/
							if(dice >= 1 && dice <= 3){
								if(temp->house_count == 3)
									printf("Made home enough , you can't do more\n");
								else{
									if(temp->type==property && player_one.account>=temp->house_price && player_one.current_block_id==temp->block_id){
										temp->house_count += 1;							
										player_one.account -= temp->house_price;
									}
								}
								temp=iter;
							}
							/*Not condition*/
							else{
								count=0;
								dice_count=0;
								temp=iter;
								break;
							}
						}
						
						
					}
					temp=iter;
					/*Roll dice and add new location*/
					srand(time(NULL));
					dice2=1+rand()%6;
					printf("Computer rolled the dice: %d\n\n",dice2);
					player_two.current_block_id += dice2;
					dice_count=0;
					/*Show in board*/
					show_board(iter,player_one,player_two);
					printf("\n");
					/*If the limit passes, check it*/
					if(player_two.current_block_id >= 24){
						player_two.current_block_id-=24;
						/*If money passes again from the beginning, 10000$ added */
						player_two.account += 10000; 
						temp2.account=player_two.account;
					}
					temp=iter;
					for(i=0;i<player_two.current_block_id;i++)
						temp=temp->next;
					/*Block is not cap*/
					if(temp->type == property && temp->owner.type == car){
						if(player_two.account >= temp->rent)
							player_two.account -= temp->rent;
						else{
							while(player_two.account < temp->rent){
								int max=player_two.owned_block_ids[0];
								for(i=1;i<12;i++){
									if(player_two.owned_block_ids[i] > max)
										max=player_two.owned_block_ids[i];
								}
								temp=iter;
								if(max == 0){
									printf("No property for selling\n\n");
									player_two.account -= temp->rent;
									break;
								}
								else{
									for(i=0;i<max;i++)
										temp=temp->next;
									player_two.owned_block_ids[max]=0;
									temp->owner.type=noone;
									player_two.account += (temp->price/2);	
									if(temp->house_count != 0){
										player_two.account += ((temp->house_price*temp->house_count)/2);
										temp->house_count=0;	
									}
									temp=iter;
									for(i=0;i<player_two.current_block_id;i++)
										temp=temp->next;
								}	
							}
							player_two.account -= temp->rent;
						
						}
					
					
					}
					temp=iter;
					for(i=0;i<player_two.current_block_id;i++)
						temp=temp->next;
					/*Situation of current block tax */
					if(temp->type == tax){
						if(player_two.account >= temp->rent)
							player_two.account -= temp->rent;
						else{
							while(player_two.account < temp->rent){
								int max=player_two.owned_block_ids[0];
								for(i=1;i<12;i++){
									if(player_two.owned_block_ids[i] > max)
										max=player_two.owned_block_ids[i];
								}
								temp=iter;
								if(max == 0){
									printf("No property for selling\n\n");
									player_two.account -= temp->rent;
									break;
								}
								else{
									for(i=0;i<max;i++)
										temp=temp->next;
									player_two.owned_block_ids[max]=0;
									temp->owner.type=noone;
									player_two.account += (temp->price/2);
									if(temp->house_count != 0){
										player_two.account += ((temp->house_price*temp->house_count)/2);
										temp->house_count=0;	
									}
									temp=iter;
									for(i=0;i<player_two.current_block_id;i++)
										temp=temp->next;	
								}	
							}
							player_two.account -= temp->rent;
						}
						
					}
					temp=iter;
					for(i=0;i<player_two.current_block_id;i++)
						temp=temp->next;
					
					
					/*Situation of current block fortune card*/
					if(temp->type == fortune){
						/*Roll the dice*/
						srand(time(NULL));
						card=1+rand()%5;
						f=fiter;
						for(i=0;i<card;i++)
							f=f->next_f;
						printf("\nSelecting card No: %d Name: %s\n\n",f->card_no,f->name);
						//Card 1 situation
						if(card == 1){
							for(i=0;i<12;i++){
								if(player_two.owned_block_ids[i] == 0)
									house_c+=1;
							}
							/*Situation of not have property*/
							if(house_c == 12){
								printf("You have no property\n\n");
								n=1;	
							}
							while(n == 0){	
								choice=1+rand()%24;
								for(i=0;i<12;i++){
									if(player_one.owned_block_ids[i] == choice){
										if(temp->house_count != 3){
											temp->house_count += 1;
											n=1;
											break;
										}
									}
								}	
							}	
						}
						//Card 2 situation
						else if(card == 2){
							srand(time(NULL));
							dice=1+rand()%6;
							if(dice >=1 && dice <=3){
								player_two.current_block_id += 2;
								/*If the limit passes, check it*/
								if(player_two.current_block_id >= 24){
									player_two.current_block_id-=24;
									/*If money passes again from the beginning, 10000$ added */
									player_two.account += 10000;
									temp2.account=player_one.account; 
								}
							}
							else{
								player_two.current_block_id -= 2;
								/*If the limit passes, check it*/
								if(player_two.current_block_id >= 24){
									player_two.current_block_id-=24;
								/*If money passes again from the beginning, 10000$ added */
									player_two.account += 10000;
									temp2.account=player_two.account; 
								}
							}
					
						}
						//Card 3 situation
						else if(card == 3){
							if(player_two.account >= 5000)
								player_two.account -= 5000;
							else{
								while(player_two.account < 5000){
									int max=player_two.owned_block_ids[0];
									for(i=1;i<12;i++){
										if(player_two.owned_block_ids[i] > max)
											max=player_two.owned_block_ids[i];
									}
									temp=iter;
									if(max == 0){
										printf("No property for selling\n\n");
										player_two.account -= 5000;
										break;
									}
									else{
										for(i=0;i<max;i++)
											temp=temp->next;
										player_two.owned_block_ids[max]=0;
										temp->owner.type=noone;
										player_two.account += (temp->price/2);
										if(temp->house_count != 0){
											player_two.account += ((temp->house_price*temp->house_count)/2);
											temp->house_count=0;	
										}
										temp=iter;
										for(i=0;i<player_two.current_block_id;i++)
											temp=temp->next;
									}	
								}
								player_two.account -= 5000;
							}
						
						}
						//Card 4 situation
						else if(card == 4){
							if(player_two.account >= 10000){
								player_two.account -= 10000;
								player_one.account += 10000;
							}
							else{
								while(player_two.account < 10000){
									int max=player_two.owned_block_ids[0];
									for(i=1;i<12;i++){
										if(player_two.owned_block_ids[i] > max)
											max=player_two.owned_block_ids[i];
									}
									temp=iter;
									if(max == 0){
										printf("No property for selling\n\n");
										player_two.account -= 10000;
										player_one.account += 10000;
										break;
									}
									else{
										for(i=0;i<max;i++)
											temp=temp->next;
										player_two.owned_block_ids[max]=0;
										temp->owner.type=noone;
										player_two.account += (temp->price/2);
										if(temp->house_count != 0){
											player_two.account += ((temp->house_price*temp->house_count)/2);
											temp->house_count=0;	
										}
										temp=iter;
										for(i=0;i<player_two.current_block_id;i++)
											temp=temp->next;
									}	
								}
								player_two.account -= 10000;
								player_one.account += 10000;
							}
						
						
						}
						//Card 5 situation
						else if(card == 5)
							player_two.account += 20000;		
					}					
					temp=iter;
					for(i=0;i<player_two.current_block_id;i++)
						temp=temp->next;
					/*Situation of current block punish */
					if(temp->type == punish){
						player_two.turn_to_wait += temp->rent;
						printf("You shoud wait %d tour\n\n",player_two.turn_to_wait);	
					}
										
				}
				/*If punish block, wait turn*/
				else if(dice_count == 1 && player_two.turn_to_wait != 0 ){
					ws2=1;
					player_two.turn_to_wait -= 1;
					printf("Remaining tour: %d\n\n",player_two.turn_to_wait);
					if(player_two.turn_to_wait == 0)
						ws2=0;
				}
				count=0;
				dice_count=0;
				temp=iter;
				break;	
			
			}
			if(count == 0)
				break;
		}
		
		
	}
	
	if(player_one.account <= 0)
		printf("YOU WIN CAP(PLAYER TWO(COMPUTER))\n\n");
	else if(player_two.account <= 0)
		printf("YOU WIN CAR(PLAYER ONE)\n\n");	
	
}

void show_my_properties(player player_any){
	for(int i=0;i<(sizeof(player_any.owned_block_ids)/sizeof(int));i++){
		switch(player_any.owned_block_ids[i]){
			case 1:
				printf("1 -   Esenyurt\n");
				break;
			case 3:
				printf("3 -   Tuzla\n");
				break;
			case 4:
				printf("4 -   Arnavutkoy\n");
				break;
			case 6:
				printf("6 -   Catalca\n");
				break;
			case 7:
				printf("7 -   Beykoz\n");
				break;
			case 9:
				printf("9 -   Maltepe\n");
				break;
			case 11:
				printf("11 -  Sisli\n");
				break;
			case 13:
				printf("13 -  Atasehir\n");
				break;
			case 14:
				printf("14 -  Sariyer\n");
				break;		
			case 16:
				printf("16 -  Kadikoy\n");
				break;
			case 17:
				printf("17 -  Besiktas\n");
				break;
			case 19:
				printf("19 -  Bebek\n");
				break;
		}	
	}	
}

void show_properties(block *iter){
	int choice,
		flag=0;
	block *temp;
	temp=iter;
	
	while(flag == 0){
		printf("Please select a property to see details: ");
		printf("\n");
		printf("1 -   Esenyurt\n");
		printf("4 -   Tuzla\n");
		printf("5 -   Arnavutkoy\n");
		printf("7 -   Catalca\n");
		printf("8 -   Beykoz\n");
		printf("11 -   Maltepe\n");
		printf("13 -  Sisli\n");
		printf("16 -  Atasehir\n");
		printf("17 -  Sariyer\n");
		printf("19 -  Kadikoy\n");
		printf("20 -  Besiktas\n");
		printf("23 -  Bebek\n");
		printf("0 -  Exit\n");	
		scanf("%d",&choice);
		if(choice < 0 || choice == 2 || choice == 3 || choice == 6 || choice == 9 || choice == 10 || choice == 12 || choice ==14 || choice == 15 || choice == 18 || choice == 21 || choice == 22)
			printf("Invalid value, please try again\n\n");
		else{
			int i; //For loop
			switch(choice){
				case 1:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|       %12s         |\n",temp->next->name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",temp->next->rent);
					printf("|    Rent 1 H      %6d$   |\n",temp->next->rent_1);
					printf("|    Rent 2 H      %6d$   |\n",temp->next->rent_2);
					printf("|    Rent 3 H      %6d$   |\n",temp->next->rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",temp->next->house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");	
					break;
				case 4:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					for(i=0;i<4;i++)
						temp=temp->next;
					printf("|       %12s         |\n",temp->name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",temp->rent);
					printf("|    Rent 1 H      %6d$   |\n",temp->rent_1);
					printf("|    Rent 2 H      %6d$   |\n",temp->rent_2);
					printf("|    Rent 3 H      %6d$   |\n",temp->rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",temp->house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");
					temp=iter;
					break;
				case 5:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					for(i=0;i<5;i++)
						temp=temp->next;
					printf("|       %12s         |\n",temp->name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",temp->rent);
					printf("|    Rent 1 H      %6d$   |\n",temp->rent_1);
					printf("|    Rent 2 H      %6d$   |\n",temp->rent_2);
					printf("|    Rent 3 H      %6d$   |\n",temp->rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",temp->house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");
					temp=iter;
					break;
				case 7:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					for(i=0;i<7;i++)
						temp=temp->next;
					printf("|       %12s         |\n",temp->name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",temp->rent);
					printf("|    Rent 1 H      %6d$   |\n",temp->rent_1);
					printf("|    Rent 2 H      %6d$   |\n",temp->rent_2);
					printf("|    Rent 3 H      %6d$   |\n",temp->rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",temp->house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");
					temp=iter;
					break;
				case 8:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					for(i=0;i<8;i++)
						temp=temp->next;
					printf("|       %12s         |\n",temp->name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",temp->rent);
					printf("|    Rent 1 H      %6d$   |\n",temp->rent_1);
					printf("|    Rent 2 H      %6d$   |\n",temp->rent_2);
					printf("|    Rent 3 H      %6d$   |\n",temp->rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",temp->house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");
					temp=iter;
					break;
				case 11:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					for(i=0;i<11;i++)
						temp=temp->next;
					printf("|       %12s         |\n",temp->name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",temp->rent);
					printf("|    Rent 1 H      %6d$   |\n",temp->rent_1);
					printf("|    Rent 2 H      %6d$   |\n",temp->rent_2);
					printf("|    Rent 3 H      %6d$   |\n",temp->rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",temp->house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");
					temp=iter;
					break;
				case 13:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					for(i=0;i<13;i++)
						temp=temp->next;
					printf("|       %12s         |\n",temp->name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",temp->rent);
					printf("|    Rent 1 H      %6d$   |\n",temp->rent_1);
					printf("|    Rent 2 H      %6d$   |\n",temp->rent_2);
					printf("|    Rent 3 H      %6d$   |\n",temp->rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",temp->house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");
					temp=iter;
					break;
				case 16:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					for(i=0;i<16;i++)
						temp=temp->next;
					printf("|       %12s         |\n",temp->name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",temp->rent);
					printf("|    Rent 1 H      %6d$   |\n",temp->rent_1);
					printf("|    Rent 2 H      %6d$   |\n",temp->rent_2);
					printf("|    Rent 3 H      %6d$   |\n",temp->rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",temp->house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");
					temp=iter;
					break;
				case 17:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					for(i=0;i<17;i++)
						temp=temp->next;
					printf("|       %12s         |\n",temp->name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",temp->rent);
					printf("|    Rent 1 H      %6d$   |\n",temp->rent_1);
					printf("|    Rent 2 H      %6d$   |\n",temp->rent_2);
					printf("|    Rent 3 H      %6d$   |\n",temp->rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",temp->house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");
					temp=iter;
					break;
				case 19:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					for(i=0;i<19;i++)
						temp=temp->next;
					printf("|       %12s         |\n",temp->name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",temp->rent);
					printf("|    Rent 1 H      %6d$   |\n",temp->rent_1);
					printf("|    Rent 2 H      %6d$   |\n",temp->rent_2);
					printf("|    Rent 3 H      %6d$   |\n",temp->rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",temp->house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");
					temp=iter;
					break;
				case 20:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					for(i=0;i<20;i++)
						temp=temp->next;
					printf("|       %12s         |\n",temp->name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",temp->rent);
					printf("|    Rent 1 H      %6d$   |\n",temp->rent_1);
					printf("|    Rent 2 H      %6d$   |\n",temp->rent_2);
					printf("|    Rent 3 H      %6d$   |\n",temp->rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",temp->house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");
					temp=iter;
					break;
				case 23:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					for(i=0;i<23;i++)
						temp=temp->next;
					printf("|       %12s         |\n",temp->name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",temp->rent);
					printf("|    Rent 1 H      %6d$   |\n",temp->rent_1);
					printf("|    Rent 2 H      %6d$   |\n",temp->rent_2);
					printf("|    Rent 3 H      %6d$   |\n",temp->rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",temp->house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");
					temp=iter;
					break;
				 case 0:
				 	flag=1;
				 	break;
			}
		}
	}
}

void buy_property(block *temp,player *current_player){
	int choice;
	int i;
	i=current_player->current_block_id;
	block *r;
	r=temp;
	
	if(current_player->account >= r->price && r->owner.type == noone && r->type == property){
		/*According to situation buying block and added array */
		if(i < 10)
			current_player->owned_block_ids[i]=r->block_id;
		else if(i == 11)
			current_player->owned_block_ids[0]=r->block_id;
		else if(i == 13)
			current_player->owned_block_ids[2]=r->block_id;
		else if(i == 14)
			current_player->owned_block_ids[5]=r->block_id;
		else if(i == 16)
			current_player->owned_block_ids[8]=r->block_id;
		else if(i == 17)
			current_player->owned_block_ids[10]=r->block_id;
		else if(i == 19)
			current_player->owned_block_ids[11]=r->block_id;
		/*Paid for the property*/
		current_player->account -= r->price;
		printf("Block is your\n\n");
		printf("Do you want to build one house?\n");
		printf("If you want press 1!:\n");
		scanf("%d",&choice); 	
		if(choice == 1){	
			/*Does he have enough money to buy a house? No more than 3 home */
			if(current_player->account >= r->house_price && r->house_count < 4){
				r->house_count += 1;
				current_player->account -= r->house_price;	
			}
			else
				printf("You have not money or build no more than 3 home\n\n");
		}
		else
			printf("I understand you can't build house\n\n");
	}
	/*Not type property*/
	else
		printf("You do not have the right conditions to buy a home\n\n");


}

void sell_property(block *iter,player *current_player){
	int id,temp=0,i;
	int choice,count=0;
	int j=0,res=0;
	block *r;
	r=iter;
	while(count == 0){
		j=0;
		res=0;
		temp=0;
		/*Check player have property or not*/
		for(i=0;i<12;i++){
			if(current_player->owned_block_ids[i] == 0)
				j+=1;		
		}
		/*Situation of not have property*/
		if(j == 12){
			count=1;
			printf("You have no property\n\n");
			break;
		}	
		printf("Block id you want to sell? : ");
		printf("\n");
		printf("1 -   Esenyurt\n");
		printf("3 -   Tuzla\n");
		printf("4 -   Arnavutkoy\n");
		printf("6 -   Catalca\n");
		printf("7 -   Beykoz\n");
		printf("9 -   Maltepe\n");
		printf("11 -  Sisli\n");
		printf("13 -  Atasehir\n");
		printf("14 -  Sariyer\n");
		printf("16 -  Kadikoy\n");
		printf("17 -  Besiktas\n");
		printf("19 -  Bebek\n");
		scanf("%d",&id);
		/*Non-id*/
		if(id <= 0 || id > 19 ){
			printf("This is invalid id\n\n");
			break;
		}
		
		for(i=0;i<12;i++){
			if(current_player->owned_block_ids[i] == id)
				temp=i;	
		}
		/*Selling property presently noone */
		/*Paying money to player*/
		current_player->owned_block_ids[temp]=0;
		for(i=0;i<temp;i++)
			r=r->next;
		r->owner.type=noone;
		r=iter;
		for(i=0;i<id;i++)
			r=r->next;
		current_player->account += (r->price/2);
		r=iter;
		for(i=0;i<temp;i++)
			r=r->next;
		if(r->house_count != 0){
			current_player->account += ((r->house_price*r->house_count)/2);
			r->house_count=0;	
		}
		/*Check user have property */
		j=0;
		for(i=0;i<12;i++){
			if(current_player->owned_block_ids[i] == res)
				j+=1;		
		}
		if(j == 12){
			count=1;
			printf("You have no property\n");
			printf("You cannot make another sell.\n");
			printf("Exit this option...\n\n");
			break;
		}
		/*For sell another block */
		else{
			printf("Want to sell another property?\n ");
			printf("If want to sell enter 1: ");
			scanf("%d",&choice);
			if(choice != 1){
				printf("Exit this option...\n\n");
				count=1;
				break;
			}
		}
	}		
}


