#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18
#define GRID_SIZE 15

int get_line_size(char *line);
void copy_string(char *source, char *destination);
void remove_newline(char *line);
void print_dictionary(char *dict[]);
void print_coord(int coord[DICT_SIZE][4]);
void print_grid(char table[GRID_SIZE][GRID_SIZE]);
void words_placing(char grid[GRID_SIZE][GRID_SIZE],int coord[DICT_SIZE][4],char *dict[DICT_SIZE]);
void print_grid_new(char table[GRID_SIZE][GRID_SIZE]);
void check_south(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]);
void check_north(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]);
void check_east(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]);
void check_west(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]);
void check_south_east(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]);
void check_north_west(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]);
void check_south_west(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]);
void check_north_east(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]);


int main(){
	char *dict[DICT_SIZE];
    	int coord[DICT_SIZE][4];    
    	char line[LINE_LEN];
	FILE *fp = fopen("word_hunter.dat", "r");
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);
	//print_dictionary(dict);
	//print_coord(coord);
	int s_x,s_y; 	//Enter coordinates from user
	char s_word[20];	//Enter words for search grid
	char grid[GRID_SIZE][GRID_SIZE];	//Grid table
	char grid_cp[GRID_SIZE][GRID_SIZE];	//Grid temp table
	int len=0,	//Enter word length
		i=0,
		count=0,
		j,
		flag=0,	
		m=1,	//While loop variable
		index=0;	//For program finish
	/*Print grid */
	print_grid(grid);	
	printf("\n");
	/*Words placing according to coordinates*/
	words_placing(grid,coord,dict);

	/*Print placing words grid*/
	print_grid_new(grid);

	/*Check program win , if user exit enter 1
	First enter word and x , y coordinates.
	Then check 8 direction , according to situation
	finish or continue */ 
	while(m != 0){
		i=0;
		flag=0;
		len=0;
		char s_word[20]={0};
		/*Enter words for search*/
		printf("Enter words(For exit enter '1' please): ");
		scanf("%s",s_word);
		
		/*Situation exit*/
		if(s_word[0] == '1'){
			printf("Exiting..\n");
			m=1;
			return 0;
		}

		/*Enter x and y coordinates*/
		printf("Enter x and y coordinates respectively , don't important begin or finish place: ");
		scanf("%d%d",&s_x,&s_y);
	
		
		/*Range limit settings*/
		if(s_x > 14 & s_x < 0){
			printf("Wrong place\n");
			break;
		}
		if(s_y > 14 & s_y < 0){
			printf("Wrong place\n");
			break;
		}
		/*Find word length*/ 
		while(s_word[i] != '\0'){
			len++;
			i++;
		}	
		/*It's necessary */
		i=0;
		while(flag == 0){
			/*Check south*/
			check_south(grid,len,&flag,s_x,s_y,s_word);
			if(flag != 0){
				print_grid_new(grid);
				index++;
				break;
			}
			/*Check north*/
			check_north(grid,len,&flag,s_x,s_y,s_word);
			if(flag != 0){
				print_grid_new(grid);
				index++;
				break;
			}
			/*Check east*/
			check_east(grid,len,&flag,s_x,s_y,s_word);
			if(flag != 0){
				print_grid_new(grid);
				index++;
				break;
			}
			/*Check west*/
			check_west(grid,len,&flag,s_x,s_y,s_word);
			if(flag != 0){
				print_grid_new(grid);
				index++;
				break;
			}
			/*Check south east*/
			check_south_east(grid,len,&flag,s_x,s_y,s_word);
			if(flag != 0){
				print_grid_new(grid);
				index++;
				break;
			}
			/*Check north west*/
			check_north_west(grid,len,&flag,s_x,s_y,s_word);
			if(flag != 0){
				print_grid_new(grid);
				index++;
				break;
			}
			/*Check south west*/
			check_south_west(grid,len,&flag,s_x,s_y,s_word);
			if(flag != 0){
				print_grid_new(grid);
				index++;
				break;
			}	
			/*Check north east*/
			check_north_east(grid,len,&flag,s_x,s_y,s_word);
			if(flag != 0){
				print_grid_new(grid);
				index++;
				break;
			}
			flag=1;
		}
		/*Program end condition*/
		if(index == 15){
			m=0;
			printf("Congratulations game finish. You win !\n");
			break;
		}	
		
	}
	return 0;
}

int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n') {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}
void print_grid(char table[GRID_SIZE][GRID_SIZE]){
	int i,j;	//For loop
	//srand(time(NULL));	//For each random character
	/*Print grid*/
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			table[i][j]='a'+(rand()%26);
		}
	}
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			printf("%c ",table[i][j]);
		}
		printf("\n");
	}	

}
void words_placing(char grid[GRID_SIZE][GRID_SIZE],int coord[DICT_SIZE][4],char *dict[DICT_SIZE]){
	int i=0,j=0,k=0,m;
	int x1=0,y1=0,x2=0,y2=0;
	int temp=0;
	/*Words placing according to coordinates*/
	while(k<15){	
		x1=coord[i][j++];
		y1=coord[i][j++];
		x2=coord[i][j++];
		y2=coord[i][j++];
		i+=1;
		j=0;
		if(y1 == y2){
			temp=x2-x1;
			for(m=0;m<(temp+1);m++){
				grid[x1][y1]=dict[k][m];
				x1+=1;	
			}
			k+=1;
		}
		else if(x1 == x2){				
			temp=y2-y1;
			for(m=0;m<(temp+1);m++){
				grid[x1][y1]=dict[k][m];
				y1+=1;	
				
			}
			k+=1;
		}
		else if(x1 != x2 & y1 != y2){
			temp=x2-x1;
			for(m=0;m<(temp+1);m++){
				grid[x1][y1]=dict[k][m];
				x1+=1;
				y1+=1;
			}
			k+=1;	
		}
	}	

}
void print_grid_new(char table[GRID_SIZE][GRID_SIZE]){
	int i,j;
	/*Print grid*/
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			printf("%c ",table[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
}

void check_south(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]){
	int count=0,i=0;
	/*Check between grid and word character */
	while(count != (len+1)){
		if(grid_cp[s_x][s_y] == s_word[i] || grid_cp[s_x][s_y] == (s_word[i]-32)){
			s_x++;
			count++;
			i++;
			if(count == len){
				while(len != 0){
					grid_cp[s_x-(1)][s_y]=(s_word[i-(1)]-32);
					s_x--;
					i--;
					len--;
				}
				*flag=1;
				break;
			}
		}
		else{
			*flag=0;
			break;
		}
	}

}

void check_north(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]){
	int count=0,i=0;
	/*Check between grid and word character */
	while(count != (len+1)){
		if(grid_cp[s_x][s_y] == s_word[i+(len-1)] || grid_cp[s_x][s_y] == (s_word[i+(len-1)]-32)){
			s_x--;
			count++;
			i--;
			if(count == len){
				i=i+len;
				while(len != 0){
					grid_cp[s_x+1][s_y]=(s_word[i]-32);
					s_x++;
					i++;
					len--;
				}
				*flag=1;
				break;	
			}
		}
		else{
			*flag=0;
			break;
		}	
	}
}

void check_east(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]){
	int count=0,i=0;
	/*Check between grid and word character */
	while(count != (len+1)){
		if(grid_cp[s_x][s_y] == s_word[i] || grid_cp[s_x][s_y] == (s_word[i]-32)){
			s_y++;
			count++;
			i++;
			if(count == len){
				while(len != 0){
					grid_cp[s_x][s_y-1]=(s_word[i-(1)]-32);
					s_y--;
					i--;
					len--;
				}
				*flag=1;
				break;
			}
		}
		else{
			*flag=0;
			break;		
		}

	}

}

void check_west(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]){
	int count=0,i=0;
	/*Check between grid and word character */
	while(count != (len+1)){
		if(grid_cp[s_x][s_y] == s_word[i+(len-1)] || grid_cp[s_x][s_y] == (s_word[i+(len-1)]-32)){
			s_y--;
			count++;
			i--;
			if(count == len){
				i=i+len;
				while(len != 0){
					grid_cp[s_x][s_y+1]=(s_word[i]-32);
					s_y++;
					i++;
					len--;
				}
				*flag=1;
				break;	
			}
		}
		else{
			*flag=0;
			break;
		}	
	}

}

void check_south_east(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]){
	int count=0,i=0;
	/*Check between grid and word character */
	while(count != (len+1)){
		if(grid_cp[s_x][s_y] == s_word[i] || grid_cp[s_x][s_y] == (s_word[i]-32)){
			s_x++;
			s_y++;
			count++;
			i++;
			if(count == len){
				while(len != 0){
					grid_cp[s_x-1][s_y-1]=(s_word[i-(1)]-32);
					s_x--;
					s_y--;
					i--;
					len--;
				}
				*flag=1;
				break;
			}
		}
		else{
			*flag=0;
			break;
		}
	}
}

void check_north_west(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]){
	int count=0,i=0;
	/*Check between grid and word character */
	while(count != (len+1)){
		if(grid_cp[s_x][s_y] == s_word[i+(len-1)] || grid_cp[s_x][s_y] == (s_word[i+(len-1)]-32)){
			s_x--;
			s_y--;
			count++;
			i--;
			if(count == len){
				i=i+len;
				while(len != 0){
					grid_cp[s_x+1][s_y+1]=(s_word[i]-32);
					s_x++;
					s_y++;
					i++;
					len--;
				}
				*flag=1;
				break;	
			}
		}
		else{
			*flag=0;
			break;
		}	
	}
}

void check_south_west(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]){
	int count=0,i=0;
	/*Check between grid and word character */
	while(count != (len+1)){
		if(grid_cp[s_x][s_y] == s_word[i] || grid_cp[s_x][s_y] == (s_word[i]-32)){
			s_x++;
			s_y--;
			count++;
			i++;
			if(count == len){
				while(len != 0){
					grid_cp[s_x-1][s_y+1]=(s_word[i-(1)]-32);
					s_x--;
					s_y++;
					i--;
					len--;
				}
				*flag=1;
				break;
			}
		}
		else{
			*flag=0;
			break;
		}
	}
}

void check_north_east(char grid_cp[GRID_SIZE][GRID_SIZE],int len,int *flag,int s_x,int s_y,char s_word[20]){
	int count=0,i=0;
	/*Check between grid and word character */
	while(count != (len+1)){
		if(grid_cp[s_x][s_y] == s_word[i+(len-1)] || grid_cp[s_x][s_y] == (s_word[i+(len-1)]-32)){
			s_x--;
			s_y++;
			count++;
			i--;
			if(count == len){
				i=i+len;
				while(len != 0){
					grid_cp[s_x+1][s_y-1]=(s_word[i]-32);
					s_x++;
					s_y--;
					i++;
					len--;
				}
				*flag=1;
				break;	
			}
		}
		else{
			*flag=0;
			break;
		}	
	}

}

