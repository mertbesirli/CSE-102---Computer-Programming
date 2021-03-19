#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20

typedef enum types{noone,car,cap}player_type;
typedef enum typ{start,property,tax,punish}block_type;

typedef struct{
	player_type type;
	int current_block_id;
	int owned_block_ids[12];
	int account;
	int turn_to_wait;
	char *name;
}player;

typedef struct{
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
}block;

void init_the_board(block board[ARRAY_SIZE]);
void show_board(block board[ARRAY_SIZE],player player_one,player player_two);
void gameplay(block board[ARRAY_SIZE],player player_one,player player_two);
void show_my_properties(player player_any);
void show_properties(block board[ARRAY_SIZE]);
void buy_property(block *current_block,player *current_player);
void sell_property(block board[ARRAY_SIZE],player *current_player);

int main(){
	
	block board[ARRAY_SIZE];
	player player_one;
	player player_two;
	int i;	//For loop
	/*İnitial statement*/
	for(i=0;i<11;i++){
		player_one.owned_block_ids[i]=0;
		player_two.owned_block_ids[i]=0;
	}
	/*Fill in the board*/
	init_the_board(board);
	
	/*Gameplay menu*/
	gameplay(board,player_one,player_two);

	return 0;
}

void init_the_board(block board[ARRAY_SIZE]){
	int i;	//For loop
	/*Fill array block_id*/
	for(i=0;i<20;i++)
		board[0].block_id=i;
	/*Fill array blocks names*/
	board[0].name="Start";
	board[1].name="Esenyurt";
	board[2].name="Car Park";
	board[3].name="Tuzla";
	board[4].name="Arnavutkoy";
	board[5].name="Wait 2 Turn";
	board[6].name="Catalca";
	board[7].name="Beykoz";
	board[8].name="Car Fix";
	board[9].name="Maltepe";
	board[10].name="Bills";
	board[11].name="Sisli";
	board[12].name="Oil";
	board[13].name="Atasehir";
	board[14].name="Sariyer";
	board[15].name="Wait 1 Turn";
	board[16].name="Kadiköy";
	board[17].name="Besiktas";
	board[18].name="Vocation";
	board[19].name="Bebek";
	/*Fill array blocks price*/
	board[0].price=0;
	board[1].price=16000;
	board[2].price=0;
	board[3].price=16500;
	board[4].price=17000;
	board[5].price=0;
	board[6].price=20000;
	board[7].price=23000;
	board[8].price=0;
	board[9].price=30000;
	board[10].price=0;
	board[11].price=33000;
	board[12].price=0;
	board[13].price=35000;
	board[14].price=40000;
	board[15].price=0;
	board[16].price=43000;
	board[17].price=60000;
	board[18].price=0;
	board[19].price=70000;
	/*Fill array blocks rent(no house)*/
	board[0].rent=0;
	board[1].rent=800;
	board[2].rent=1500;
	board[3].rent=850;
	board[4].rent=875;
	board[5].rent=2;
	board[6].rent=1000;
	board[7].rent=1100;
	board[8].rent=1750;
	board[9].rent=1350;
	board[10].rent=2000;
	board[11].rent=1500;
	board[12].rent=2250;
	board[13].rent=1600;
	board[14].rent=1750;
	board[15].rent=1;
	board[16].rent=1900;
	board[17].rent=2500;
	board[18].rent=5000;
	board[19].rent=3500;
	/*Fill array block rent(one house)*/
	board[0].rent_1=0;
	board[1].rent_1=4000;
	board[2].rent_1=0;
	board[3].rent_1=4250;
	board[4].rent_1=4500;
	board[5].rent_1=0;
	board[6].rent_1=5000;
	board[7].rent_1=5500;
	board[8].rent_1=0;
	board[9].rent_1=7000;
	board[10].rent_1=0;
	board[11].rent_1=8000;
	board[12].rent_1=0;
	board[13].rent_1=8500;
	board[14].rent_1=9500;
	board[15].rent_1=0;
	board[16].rent_1=11000;
	board[17].rent_1=15000;
	board[18].rent_1=0;
	board[19].rent_1=20000;
	/*Fill array block rent(two house)*/
	board[0].rent_2=0;
	board[1].rent_2=9000;
	board[2].rent_2=0;
	board[3].rent_2=9500;
	board[4].rent_2=10000;
	board[5].rent_2=0;
	board[6].rent_2=12000;
	board[7].rent_2=12500;
	board[8].rent_2=0;
	board[9].rent_2=15000;
	board[10].rent_2=0;
	board[11].rent_2=16000;
	board[12].rent_2=0;
	board[13].rent_2=17000;
	board[14].rent_2=19000;
	board[15].rent_2=0;
	board[16].rent_2=21500;
	board[17].rent_2=28000;
	board[18].rent_2=0;
	board[19].rent_2=35500;
	/*Fill array block rent(three house)*/
	board[0].rent_3=0;
	board[1].rent_3=25000;
	board[2].rent_3=0;
	board[3].rent_3=26000;
	board[4].rent_3=28000;
	board[5].rent_3=0;
	board[6].rent_3=30000;
	board[7].rent_3=33000;
	board[8].rent_3=0;
	board[9].rent_3=40000;
	board[10].rent_3=0;
	board[11].rent_3=42000;
	board[12].rent_3=0;
	board[13].rent_3=45000;
	board[14].rent_3=48000;
	board[15].rent_3=0;
	board[16].rent_3=55000;
	board[17].rent_3=60000;
	board[18].rent_3=0;
	board[19].rent_3=65000;
	/*Fill array house price*/
	board[0].house_price=0;
	board[1].house_price=10000;
	board[2].house_price=0;
	board[3].house_price=12000;
	board[4].house_price=12000;
	board[5].house_price=0;
	board[6].house_price=13000;
	board[7].house_price=13000;
	board[8].house_price=0;
	board[9].house_price=15000;
	board[10].house_price=0;
	board[11].house_price=16000;
	board[12].house_price=0;
	board[13].house_price=17000;
	board[14].house_price=19000;
	board[15].house_price=0;
	board[16].house_price=23000;
	board[17].house_price=30000;
	board[18].house_price=0;
	board[19].house_price=35000;
	/*Fill array block type*/
	board[0].type=start;
	board[1].type=property;
	board[2].type=tax;
	board[3].type=property;
	board[4].type=property;
	board[5].type=punish;
	board[6].type=property;
	board[7].type=property;
	board[8].type=tax;
	board[9].type=property;
	board[10].type=tax;
	board[11].type=property;
	board[12].type=tax;
	board[13].type=property;
	board[14].type=property;
	board[15].type=punish;
	board[16].type=property;
	board[17].type=property;
	board[18].type=tax;
	board[19].type=property;
	/*Block owner*/
	board[0].owner.type=noone;
	board[1].owner.type=noone;
	board[2].owner.type=noone;
	board[3].owner.type=noone;
	board[4].owner.type=noone;
	board[5].owner.type=noone;
	board[6].owner.type=noone;
	board[7].owner.type=noone;
	board[8].owner.type=noone;
	board[9].owner.type=noone;
	board[10].owner.type=noone;
	board[11].owner.type=noone;
	board[12].owner.type=noone;
	board[13].owner.type=noone;
	board[14].owner.type=noone;
	board[15].owner.type=noone;
	board[16].owner.type=noone;
	board[17].owner.type=noone;
	board[18].owner.type=noone;
	board[19].owner.type=noone;
	/*Block house count*/
	board[0].house_count=0;
	board[1].house_count=0;
	board[2].house_count=0;
	board[3].house_count=0;
	board[4].house_count=0;
	board[5].house_count=0;
	board[6].house_count=0;
	board[7].house_count=0;
	board[8].house_count=0;
	board[9].house_count=0;
	board[10].house_count=0;
	board[11].house_count=0;
	board[12].house_count=0;
	board[13].house_count=0;
	board[14].house_count=0;
	board[15].house_count=0;
	board[16].house_count=0;
	board[17].house_count=0;
	board[18].house_count=0;
	board[19].house_count=0;
	
}

void gameplay(block board[ARRAY_SIZE],player player_one,player player_two){

	int choice,
		count=0, //Turn car and count=1 turn cap
		dice,	   //Roll of dice number
		house,	//House number
		answer,
		dice_count=0,	//To throw the dice once
		ws=0,ws2=0,	//Dice situation necessary variable
		option,
		x=0,	//buy 	one more than house check variable
		ch; //choice variable (one more house)
	/*İnitial statement*/	
	player_one.current_block_id=0;
	player_two.current_block_id=0;
	player_one.type=cap;
	player_two.type=car;
	player_one.account=100000;
	player_two.account=100000;
	player_one.turn_to_wait=0;
	player_two.turn_to_wait=0;
	int i;
	for(i=0;i<12;i++){
		player_one.owned_block_ids[i]=0;
		player_two.owned_block_ids[i]=0;
	}
	/*Continue until the money runs out. */
	while(player_one.account > 0 || player_one.account > 0){
		while(count == 0){	//Turn car
			/*Show in board*/
			show_board(board,player_one,player_two);
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
				
				block current_block_one;
				/*To set block owner type */
				/*Checking for buying */
				player temp1;
				temp1.account=player_one.account;
				
				current_block_one=board[player_one.current_block_id];
				current_block_one.block_id=player_one.current_block_id;
				
				
				switch(choice){
					case 1:
						/*To roll the dice once*/
						if(dice_count == 0 && player_one.turn_to_wait == 0 && ws == 0){
							/*Roll dice and add new location*/
							srand(time(NULL));
							dice=1+rand()%6;
							player_one.current_block_id += dice;
							dice_count=1;
							
							/*If the limit passes, check it*/
							if(player_one.current_block_id >= 20){
								player_one.current_block_id-=20;
								/*If money passes again from the beginning, 10000$ added */
								player_one.account += 10000;
								temp1.account=player_one.account; 
							}
							current_block_one=board[player_one.current_block_id];
							current_block_one.block_id=player_one.current_block_id;
							/*Showing now board*/
							show_board(board,player_one,player_two);
							/*Situation of current block tax */
							if(board[player_one.current_block_id].type == tax)
								player_one.account -= board[player_one.current_block_id].rent;
							/*Situation of current block punish */
							if(board[player_one.current_block_id].type == punish){
								player_one.turn_to_wait += board[player_one.current_block_id].rent;
								printf("You shoud wait %d tour\n\n",player_one.turn_to_wait);	
							}
							/*Asking want to buy property*/
							if(board[player_one.current_block_id].type == property && board[player_one.current_block_id].owner.type == noone){
								printf("Do you want to this block enter press Yes (1) :");
								scanf("%d",&option);
								if(option == 1){
									/*Buy property*/
									buy_property(&current_block_one,&player_one);
									/*Board update*/
									board[player_one.current_block_id].house_count += 1;
									/*If buy current property, change property owner type*/
									if(temp1.account != player_one.account)
										board[player_one.current_block_id].owner.type=car;
									/*For player want one more than house */
									while(x == 0){
										printf("Do you want to build one more house?\n");
										printf("If you want press 1!:\n");
										scanf("%d",&ch); 	
										if(ch == 1){	
											/*Does he have enough money to buy a house? No more than 3 home */
											if(player_one.account >= current_block_one.house_price && current_block_one.house_count < 3){
												current_block_one.house_count += 1;
												/*Board update*/
												board[player_one.current_block_id].house_count += 1;
												player_one.account -= current_block_one.house_price;	
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
							if(board[player_one.current_block_id].type == property && board[player_one.current_block_id].owner.type ==cap){
								/*Check have money or not */
								if(player_one.account >= board[player_one.current_block_id].rent)
									player_one.account -= board[player_one.current_block_id].rent;
								else{
									printf("You have to sell one of your properties\n");
									sell_property(board,&player_one);
									player_one.account -= board[player_one.current_block_id].rent;
								}
							}
							/*Check have house build or not , according to this player pay rent house money */
							if(board[player_one.current_block_id].type == property && board[player_one.current_block_id].owner.type ==cap && board[player_one.current_block_id].house_count != 0 ){
								/*Situation of have 3 house*/
								if(board[player_one.current_block_id].house_count == 3){
									if(player_one.account >= board[player_one.current_block_id].rent_3)
										player_one.account -= board[player_one.current_block_id].rent_3;
									else{
										printf("You have to sell one of your properties\n");
										sell_property(board,&player_one);
										player_one.account -= board[player_one.current_block_id].rent_3;
									}
								}
								/*Situation of have 2 house*/
								else if(board[player_one.current_block_id].house_count == 2){
									if(player_one.account >= board[player_one.current_block_id].rent_2)
										player_one.account -= board[player_one.current_block_id].rent_2;
									else{
										printf("You have to sell one of your properties\n");
										sell_property(board,&player_one);
										player_one.account -= board[player_one.current_block_id].rent_2;
									}
								}
								/*Situation of have 1 house*/
								else if(board[player_one.current_block_id].house_count == 1){
									if(player_one.account >= board[player_one.current_block_id].rent_1)
										player_one.account -= board[player_one.current_block_id].rent_1;
									else{
										printf("You have to sell one of your properties\n");
										sell_property(board,&player_one);
										player_one.account -= board[player_one.current_block_id].rent_1;
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
						/*To avoid multiple dice*/
						else
							printf("Just one time roll the dice\n\n");
						/*For turn of other player*/
						printf("Finish your turn...\n\n");
						count=1;
						dice_count=1;		
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
						show_properties(board);
						break;
					case 5:
						/*Buy property*/
						buy_property(&current_block_one,&player_one);
						/*If buy current property , change property owner type*/
						if(temp1.account != player_one.account)
							board[player_one.current_block_id].owner.type=car;
						/*Update house count for board(initial)*/
						board[player_one.current_block_id].house_count=current_block_one.house_count;
						break;
					case 6:
						if(current_block_one.house_count == 3)
								printf("Made home enough , you can't do more\n");
						else{
							if(current_block_one.type == property && player_one.account >= current_block_one.house_price && player_one.current_block_id == current_block_one.block_id){
								printf("Only build one house each tour\n");
								printf("Are you sure build home , enter Yes(Press 1) or No(N): ");
								scanf("%d",&answer);
								if(answer == 1){
									current_block_one.house_count += 1;							
									player_one.account -= current_block_one.house_price;
									board[player_one.current_block_id].house_count += 1;
									printf("The house was built\n\n");
								}
								else{			
									printf("I understand you don't want to build a house\n\n");
									break;
								}
							}
						}		
						break;
					case 7:
						/*For sell block*/
						sell_property(board,&player_one);
						break;		
				}
				if(count == 1)
					break;
			}
		}
		/*Turn of cap(player two)*/
		while(count == 1){
			/*Show in board*/
			show_board(board,player_one,player_two);
			/*Menu*/
			while(1){
				printf("!!CAP TURN(PLAYER TWO)!!\n");
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
				block current_block_two;
				/*To set block owner type */
				/*Checking for buying */
				player temp2;
				temp2.account=player_two.account;
				
				current_block_two=board[player_two.current_block_id];
				current_block_two.block_id=player_two.current_block_id;
				
				switch(choice){
					case 1:
						/*To roll the dice once*/
						if(dice_count == 1 && player_two.turn_to_wait == 0 && ws2 == 0){
							/*Roll dice and add new location*/
							srand(time(NULL));
							dice=1+rand()%6;
							player_two.current_block_id += dice;
							dice_count=0;
							/*If the limit passes, check it*/
							if(player_two.current_block_id >= 20){
								player_two.current_block_id-=20;
								/*If money passes again from the beginning, 10000$ added */
								player_two.account += 10000; 
								temp2.account=player_two.account;
							}
							current_block_two=board[player_two.current_block_id];
							current_block_two.block_id=player_two.current_block_id;
							/*Showing now board*/
							show_board(board,player_one,player_two);
							/*Situation of current block tax */
							if(board[player_two.current_block_id].type == tax)
								player_two.account -= board[player_two.current_block_id].rent;
							/*Situation of current block punish */
							if(board[player_two.current_block_id].type == punish){
								player_two.turn_to_wait += board[player_two.current_block_id].rent;
								printf("You shoud wait %d tour\n\n",player_two.turn_to_wait);	
							}
							/*Asking want to buy property*/
							if(board[player_two.current_block_id].type == property && board[player_two.current_block_id].owner.type == noone){
								printf("Do you want to this block enter press Yes 1: ");
								scanf("%d",&option);
								if(option == 1){
									/*Buy property*/
									buy_property(&current_block_two,&player_two);
									/*Board update*/
									board[player_two.current_block_id].house_count += 1;
									/*If buy current property , change property owner type*/
									if(temp2.account != player_two.account)
										board[player_two.current_block_id].owner.type=cap;
									/*For player want one more than house */
									while(x == 0){
										printf("Do you want to build one more house?\n");
										printf("If you want press 1!:\n");
										scanf("%d",&ch); 	
										if(ch == 1){	
											/*Does he have enough money to buy a house? No more than 3 home */
											if(player_two.account >= current_block_two.house_price && current_block_two.house_count < 3){
												current_block_two.house_count += 1;
												board[player_two.current_block_id].house_count += 1;
												player_two.account -= current_block_two.house_price;	
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
							if(board[player_two.current_block_id].type == property && board[player_two.current_block_id].owner.type ==car){
								/*Check have money or not */
								if(player_two.account >= board[player_two.current_block_id].rent)
									player_two.account -= board[player_two.current_block_id].rent;
								else{
									printf("You have to sell one of your properties\n");
									sell_property(board,&player_two);
									player_two.account -= board[player_two.current_block_id].rent;
									
								}		
							}
							/*Check have house build or not , according to this player pay rent house money */
							if(board[player_two.current_block_id].type == property && board[player_two.current_block_id].owner.type ==car && board[player_two.current_block_id].house_count != 0 ){
								/*Situation of have 3 house*/
								if(board[player_two.current_block_id].house_count == 3){
									if(player_two.account >= board[player_two.current_block_id].rent_3)
										player_two.account -= board[player_two.current_block_id].rent_3;
									else{
										printf("You have to sell one of your properties\n");
										sell_property(board,&player_two);
										player_two.account -= board[player_two.current_block_id].rent_3;
									}
								}
								/*Situation of have 2 house*/
								else if(board[player_two.current_block_id].house_count == 2){
									if(player_two.account >= board[player_two.current_block_id].rent_2)
										player_two.account -= board[player_two.current_block_id].rent_2;
									else{
										printf("You have to sell one of your properties\n");
										sell_property(board,&player_one);
										player_two.account -= board[player_two.current_block_id].rent_2;
									}
								}
								/*Situation of have 1 house*/
								else if(board[player_two.current_block_id].house_count == 1){
									if(player_two.account >= board[player_two.current_block_id].rent_1)
										player_two.account -= board[player_two.current_block_id].rent_1;
									else{
										printf("You have to sell one of your properties\n");
										sell_property(board,&player_two);
										player_two.account -= board[player_two.current_block_id].rent_1;
									}
								}
							}
						}
						/*To wait of the punish*/
						else if(dice_count == 1 && player_two.turn_to_wait != 0){
							ws2=1;
							player_two.turn_to_wait -= 1;
							printf("Remaining tour: %d\n\n",player_two.turn_to_wait);
							if(player_two.turn_to_wait == 0)
								ws2=0;
						}
						/*To avoid multiple dice*/
						else
							printf("Just one time roll the dice\n\n");
						/*For turn of other player*/
						printf("Finish your turn...\n\n");
						count=0;
						dice_count=0;
						break;
					case 2:
						/*Showing current account*/
						printf("%d\n",player_two.account);
						break;
					case 3:
						/*Show own properties */
						show_my_properties(player_two);
						break;
					case 4:
						/*See details of its property*/
						show_properties(board);
						break;
					case 5:
						/*Buy property*/
						buy_property(&current_block_two,&player_two);
						/*If buy current property , change property owner type*/
						if(temp2.account != player_two.account)
							board[player_two.current_block_id].owner.type=cap;
						/*Update house count for board(initial)*/
						board[player_two.current_block_id].house_count=current_block_two.house_count;
						break;
					case 6:
						if(current_block_two.house_count == 3)
								printf("Made home enough , you can't do more\n\n");
						else{
							if(current_block_two.type == property && player_two.account >= current_block_two.house_price && player_two.current_block_id == current_block_two.block_id){
								printf("Only build one house each tour\n");
								printf("Are you sure build home , enter Yes(Press 1) or No(N): ");
								scanf("%d",&answer);
								if(answer == 1){
									current_block_two.house_count +=1;							
									player_two.account -= current_block_two.house_price;
									board[player_two.current_block_id].house_count += 1;
									printf("The house was built\n");
								}
								else{		
									printf("I understand you don't want to build a house\n\n");	
									break;
								}
							}
						}		
						break;
					case 7:
						/*For sell block*/
						sell_property(board,&player_two);
						break;
				}
				if(count == 0)
					break;
			}
		}
		
	}

	if(player_one.account <= 0)
		printf("YOU WIN CAP(PLAYER TWO)\n\n");
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

void show_properties(block board[ARRAY_SIZE]){
	int choice,	//Choice variables for propery
		flag=0;
		
	/*Choose want to porperty see details*/
	while(flag == 0){
		printf("Please select a property to see details: ");
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
		printf("0 -  Exit\n");	
		scanf("%d",&choice);
		/*Check choice range*/
		if(choice == 2 || choice == 5 || choice == 8 || choice == 10 || choice == 12 || choice ==15 ||
		choice == 18 || choice > 19)
			printf("Invalid value, please try again\n\n");
		else{
			int i; //For loop
			switch(choice){
				case 1:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					printf("|       %12s         |\n",board[1].name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",board[1].rent);
					printf("|    Rent 1 H      %6d$   |\n",board[1].rent_1);
					printf("|    Rent 2 H      %6d$   |\n",board[1].rent_2);
					printf("|    Rent 3 H      %6d$   |\n",board[1].rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",board[1].house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");	
					break;
				case 3:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					printf("|       %12s         |\n",board[3].name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",board[3].rent);
					printf("|    Rent 1 H      %6d$   |\n",board[3].rent_1);
					printf("|    Rent 2 H      %6d$   |\n",board[3].rent_2);
					printf("|    Rent 3 H      %6d$   |\n",board[3].rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",board[3].house_price);
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
					printf("|       %12s         |\n",board[4].name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",board[4].rent);
					printf("|    Rent 1 H      %6d$   |\n",board[4].rent_1);
					printf("|    Rent 2 H      %6d$   |\n",board[4].rent_2);
					printf("|    Rent 3 H      %6d$   |\n",board[4].rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",board[4].house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");	
					break;
				case 6:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					printf("|       %12s         |\n",board[6].name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",board[6].rent);
					printf("|    Rent 1 H      %6d$   |\n",board[6].rent_1);
					printf("|    Rent 2 H      %6d$   |\n",board[6].rent_2);
					printf("|    Rent 3 H      %6d$   |\n",board[6].rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",board[6].house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");	
					break;
				case 7:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					printf("|       %12s         |\n",board[7].name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",board[7].rent);
					printf("|    Rent 1 H      %6d$   |\n",board[7].rent_1);
					printf("|    Rent 2 H      %6d$   |\n",board[7].rent_2);
					printf("|    Rent 3 H      %6d$   |\n",board[7].rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",board[7].house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");	
					break;
				case 9:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					printf("|       %12s         |\n",board[9].name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",board[9].rent);
					printf("|    Rent 1 H      %6d$   |\n",board[9].rent_1);
					printf("|    Rent 2 H      %6d$   |\n",board[9].rent_2);
					printf("|    Rent 3 H      %6d$   |\n",board[9].rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",board[9].house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");	
					break;
				case 11:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					printf("|       %12s         |\n",board[11].name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",board[11].rent);
					printf("|    Rent 1 H      %6d$   |\n",board[11].rent_1);
					printf("|    Rent 2 H      %6d$   |\n",board[11].rent_2);
					printf("|    Rent 3 H      %6d$   |\n",board[11].rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",board[11].house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");	
					break;
				case 13:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					printf("|       %12s         |\n",board[13].name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",board[13].rent);
					printf("|    Rent 1 H      %6d$   |\n",board[13].rent_1);
					printf("|    Rent 2 H      %6d$   |\n",board[13].rent_2);
					printf("|    Rent 3 H      %6d$   |\n",board[13].rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",board[13].house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");	
					break;
				case 14:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					printf("|       %12s         |\n",board[14].name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",board[14].rent);
					printf("|    Rent 1 H      %6d$   |\n",board[14].rent_1);
					printf("|    Rent 2 H      %6d$   |\n",board[14].rent_2);
					printf("|    Rent 3 H      %6d$   |\n",board[14].rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",board[14].house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");	
					break;
				case 16:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					printf("|       %12s         |\n",board[16].name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",board[16].rent);
					printf("|    Rent 1 H      %6d$   |\n",board[16].rent_1);
					printf("|    Rent 2 H      %6d$   |\n",board[16].rent_2);
					printf("|    Rent 3 H      %6d$   |\n",board[16].rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",board[16].house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");	
					break;
				case 17:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					printf("|       %12s         |\n",board[17].name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",board[17].rent);
					printf("|    Rent 1 H      %6d$   |\n",board[17].rent_1);
					printf("|    Rent 2 H      %6d$   |\n",board[17].rent_2);
					printf("|    Rent 3 H      %6d$   |\n",board[17].rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",board[17].house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");	
					break;
				case 19:
					/*First line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*Second line*/
					printf("|       %12s         |\n",board[19].name);
					/*Three line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					/*4,5,6,7. line*/
					/*Rent information*/
					printf("|    Rent          %6dŞ   |\n",board[19].rent);
					printf("|    Rent 1 H      %6d$   |\n",board[19].rent_1);
					printf("|    Rent 2 H      %6d$   |\n",board[19].rent_2);
					printf("|    Rent 3 H      %6d$   |\n",board[19].rent_3);
					/*8.line*/
					/*House price information*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n");
					printf("|    House Price   %6d$   |\n",board[19].house_price);
					/*9.line*/
					for(i=0;i<30;i++)
						printf("-");
					printf("\n\n");	
					break;
				case 0:
					flag=1;
					break;
			}
		}
	}
}

void buy_property(block *current_block,player *current_player){
	
	int choice;
	int i;
	i=current_player->current_block_id;
	if(current_player->account >= current_block->price && current_block->owner.type == noone && current_block->type == property){
		/*According to situation buying block and added array */
		if(i < 10)
			current_player->owned_block_ids[i]=current_block->block_id;
		else if(i == 11)
			current_player->owned_block_ids[0]=current_block->block_id;
		else if(i == 13)
			current_player->owned_block_ids[2]=current_block->block_id;
		else if(i == 14)
			current_player->owned_block_ids[5]=current_block->block_id;
		else if(i == 16)
			current_player->owned_block_ids[8]=current_block->block_id;
		else if(i == 17)
			current_player->owned_block_ids[10]=current_block->block_id;
		else if(i == 19)
			current_player->owned_block_ids[11]=current_block->block_id;
		/*Paid for the property*/
		current_player->account -= current_block->price;
		printf("Block is your\n\n");
		printf("Do you want to build one house?\n");
		printf("If you want press 1!:\n");
		scanf("%d",&choice); 	
		if(choice == 1){	
			/*Does he have enough money to buy a house? No more than 3 home */
			if(current_player->account >= current_block->house_price && current_block->house_count < 4){
				current_block->house_count += 1;
				current_player->account -= current_block->house_price;	
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

void show_board(block board[ARRAY_SIZE],player player_one,player player_two){
	int i;
	char a=' ';
	
	
	for(i=0;i<145;i++)
		printf("-");
	printf("\n");
	printf("|");
	
	for(i=0;i<6;i++)
		printf("\t%11s\t|",board[i].name);
	printf("\n");
	printf("|");
	for(i=0;i<6;i++){
		if(board[i].price == 0)
			printf("\t%10c\t|",a);	
		else
			printf("\t%10d$\t|",board[i].price);	
	}
	printf("\n");
	printf("|");
	for(i=0;i<6;i++){
		if(player_one.current_block_id == i && player_two.current_block_id == i)
			printf("\tcar\tcap\t|");
		else if(player_one.current_block_id == i)
			printf("\t\tcar\t|");
		else if(player_two.current_block_id == i)
			printf("\t\tcap\t|");
		else
			printf("\t%10c\t|",a);	
	}
	printf("\n");
	for(i=0;i<145;i++)
		printf("-");
	printf("\n");
	
	printf("|\t%11s\t|",board[19].name);
	
	for(i=0;i<95;i++)
		printf(" ");
	
	printf("|\t%11s\t|",board[6].name);
	
	printf("\n");
	
	if(board[19].price == 0)
			printf("|\t%10c\t|",a);
	else
		printf("|\t%10d$\t|",board[19].price);
		
	for(i=0;i<95;i++)
		printf(" ");
	if(board[6].price == 0)
		printf("|\t%10c\t|",a);
	else
		printf("|\t%10d$\t|",board[6].price);
	printf("\n");
	printf("|");
	if(player_one.current_block_id == 19 && player_two.current_block_id == 19)
		printf("\tcar\tcap\t|");
	else if(player_one.current_block_id == 19)
		printf("\t\tcar\t|");
	else if(player_two.current_block_id == 19)
		printf("\t\tcap\t|");
	else
		printf("\t%10c\t|",a);
	for(i=0;i<95;i++)
		printf(" ");
	printf("|");
	if(player_one.current_block_id == 6 && player_two.current_block_id == 6)
		printf("\tcar\tcap\t|");
	else if(player_one.current_block_id == 6)
		printf("\t\tcar\t|");
	else if(player_two.current_block_id == 6)
		printf("\t\tcap\t|");
	else
		printf("\t%10c\t|",a);	
	
	printf("\n");
	for(i=0;i<25;i++)
		printf("-");
	for(i=0;i<95;i++)
		printf(" ");
	for(i=0;i<25;i++)
		printf("-");
	printf("\n");
	
	printf("|\t%11s\t|",board[18].name);
	
	for(i=0;i<95;i++)
		printf(" ");
		
	printf("|\t%11s\t|",board[7].name);
	printf("\n");
	
	if(board[18].price == 0)
		printf("|\t%10c\t|",a);
	else
		printf("|\t%10d$\t|",board[18].price);
	for(i=0;i<95;i++)
		printf(" ");
	if(board[7].price == 0)
		printf("\t%10c\t|",a);
	else
		printf("|\t%10d$\t|",board[7].price);
	
	printf("\n");
	printf("|");
	if(player_one.current_block_id == 18 && player_two.current_block_id == 18)
		printf("\tcar\tcap\t|");
	else if(player_one.current_block_id == 18)
		printf("\t\tcar\t|");
	else if(player_two.current_block_id == 18)
		printf("\t\tcap\t|");
	else
		printf("\t%10c\t|",a);
	for(i=0;i<95;i++)
		printf(" ");
	printf("|");
	if(player_one.current_block_id == 7 && player_two.current_block_id == 7)
		printf("\tcar\tcap\t|");
	else if(player_one.current_block_id == 7)
		printf("\t\tcar\t|");
	else if(player_two.current_block_id == 7)
		printf("\t\tcap\t|");
	else
		printf("\t%10c\t|",a);	
	
	printf("\n");
	for(i=0;i<25;i++)
		printf("-");
	for(i=0;i<95;i++)
		printf(" ");
	for(i=0;i<25;i++)
		printf("-");
	printf("\n");
	
	printf("|\t%11s\t|",board[17].name);	
	for(i=0;i<95;i++)
		printf(" ");
	printf("|\t%11s\t|",board[8].name);
	
	printf("\n");
	
	if(board[17].price == 0)
		printf("\t%10c\t|",a);
	else
		printf("|\t%10d$\t|",board[17].price);	
	for(i=0;i<95;i++)
		printf(" ");
	if(board[8].price == 0)
		printf("|\t%10c\t|",a);
	else
		printf("|\t%10d$\t|",board[8].price);
	
	printf("\n");
	printf("|");
	if(player_one.current_block_id == 17 && player_two.current_block_id == 17)
		printf("\tcar\tcap\t|");
	else if(player_one.current_block_id == 17)
		printf("\t\tcar\t|");
	else if(player_two.current_block_id == 17)
		printf("\t\tcap\t|");
	else
		printf("\t%10c\t|",a);
	for(i=0;i<95;i++)
		printf(" ");
	printf("|");
	if(player_one.current_block_id == 8 && player_two.current_block_id == 8)
		printf("\tcar\tcap\t|");
	else if(player_one.current_block_id == 8)
		printf("\t\tcar\t|");
	else if(player_two.current_block_id == 8)
		printf("\t\tcap\t|");
	else
		printf("\t%10c\t|",a);	
	
	printf("\n");
	for(i=0;i<25;i++)
		printf("-");
	for(i=0;i<95;i++)
		printf(" ");
	for(i=0;i<25;i++)
		printf("-");
	printf("\n");
	
	printf("|\t%11s\t|",board[16].name);
	for(i=0;i<95;i++)
		printf(" ");		
	printf("|\t%11s\t|",board[9].name);
	
	printf("\n");
	if(board[16].price == 0)
		printf("\t%10c\t|",a);
	else
		printf("|\t%10d$\t|",board[16].price);
	for(i=0;i<95;i++)
		printf(" ");
	if(board[9].price == 0)
		printf("\t%10c\t|",a);
	else
		printf("|\t%10d$\t|",board[9].price);
	
	printf("\n");
	printf("|");
	if(player_one.current_block_id == 16 && player_two.current_block_id == 16)
		printf("\tcar\tcap\t|");
	else if(player_one.current_block_id == 16)
		printf("\t\tcar\t|");
	else if(player_two.current_block_id == 16)
		printf("\t\tcap\t|");
	else
		printf("\t%10c\t|",a);
	for(i=0;i<95;i++)
		printf(" ");
	printf("|");
	if(player_one.current_block_id == 9 && player_two.current_block_id == 9)
		printf("\tcar\tcap\t|");
	else if(player_one.current_block_id == 9)
		printf("\t\tcar\t|");
	else if(player_two.current_block_id == 9)
		printf("\t\tcap\t|");
	else
		printf("\t%10c\t|",a);	
	
	printf("\n");
	
	for(i=0;i<145;i++)
		printf("-");
	printf("\n");
	printf("|");
	for(i=15;i>=10;i--)
		printf("\t%11s\t|",board[i].name);
	printf("\n");
	printf("|");
	for(i=15;i>=10;i--){
		if(board[i].price == 0)
			printf("\t%10c\t|",a);
		else
			printf("\t%10d$\t|",board[i].price);	
	}
	printf("\n");
	
	printf("|");
	for(i=15;i>=10;i--){
		if(player_one.current_block_id == i && player_two.current_block_id == i)
			printf("\tcar\tcap\t|");
		else if(player_one.current_block_id == i)
			printf("\t\tcar\t|");
		else if(player_two.current_block_id == i)
			printf("\t\tcap\t|");
		else
			printf("\t%10c\t|",a);	
	}
	printf("\n");
	for(i=0;i<145;i++)
		printf("-");
	printf("\n");
	
}

void sell_property(block board[ARRAY_SIZE],player *current_player){

	int id,temp=0,i;
	int choice,count=0;
	int j=0,res=0;
	/*Check player have property or not*/
/*	for(i=0;i<12;i++){
		if(current_player->owned_block_ids[i] == temp)
			j+=1;		
	}
	/*Situation of not have property*/
/*	if(j == 12){
		count=1;
		printf("You have no property\n\n");
	}*/
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
		board[temp].owner.type=noone;
		current_player->account += (board[id].price/2);
		if(board[temp].house_count != 0){
			current_player->account += ((board[temp].house_price*board[temp].house_count)/2);
			board[temp].house_count=0;	
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



