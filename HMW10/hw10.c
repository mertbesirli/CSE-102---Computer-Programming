#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

typedef struct node_t{
	int x;
	int x_q;
	struct node_t *next;
}node;

typedef struct stack_t{
	node *top;
}stack;

typedef struct queue_t{
	node *front;
	node *rear;
}queue;

typedef struct bst_t{
	int y;
	struct bst_t *left;
	struct bst_t *right;
}bst;


void fill_structures(stack **stack_,queue **queue_,bst **bst_,int data[SIZE]);
bst *add_bst(bst *root,int number);
void ordered_print(stack *stack_,queue *queue_,bst *bst_);
void printing_bst(bst *bst_);
void search(stack *stack_,queue *queue_,bst *bst_,int val_to_search);
void special_traverse(stack *stack_,queue *queue_,bst *bst_);
void traverse_bst(bst *bst_);
int max_value(bst *b);
bst *delete(bst *b,int value);
bst *find_min(bst *root);
int min_value(bst *b);


int main(){
	int data[SIZE]={5,2,7,8,11,3,21,7,6,15,19,35,24,1,8,12,17,8,23,4};
	bst *bst_;
	queue *queue_;
	stack *stack_;
	
	fill_structures(&stack_,&queue_,&bst_,data);
	
	ordered_print(stack_,queue_,bst_);
	
	search(stack_,queue_,bst_,5);
	
	special_traverse(stack_,queue_,bst_);
	
	free(queue_);
	free(stack_);
	free(bst_);
	
	return 0;



}

void fill_structures(stack **stack_,queue **queue_,bst **bst_,int data[SIZE]){
	int i;
	/*For total time*/
	double spent_time=0.0;
	/*For stack*/
	(*stack_)=(stack*)malloc(sizeof(stack));
	(*stack_)->top=NULL;
	
	/*Stack filled and measured time*/
	for(i=0;i<SIZE;i++){
		clock_t begin=clock();
		node *tmp;
		tmp=(node*)malloc(sizeof(node));
		tmp->x=data[i];
		tmp->next=(*stack_)->top;
		(*stack_)->top=tmp;
		clock_t end=clock();
		spent_time += (double)(end-begin);
	}
	/*Printing total time*/
	printf("Stack fill struct time: %.4f\n",((spent_time/CLOCKS_PER_SEC)*1000)); 
	spent_time=0.0;
	
	/*For queue*/
	(*queue_)=(queue*)malloc(sizeof(node));
	(*queue_)->front=NULL;
	(*queue_)->rear=NULL;
	
	/*Queue filled and measured time*/
	for(i=0;i<SIZE;i++){
		clock_t begin=clock();
		node *temp;
		temp=(node*)malloc(sizeof(node));
		temp->x_q=data[i];
		temp->next=NULL;
		if((*queue_)->rear != NULL){
			(*queue_)->rear->next=temp;
			(*queue_)->rear=temp;
		}
		else{
			(*queue_)->rear=temp;
			(*queue_)->front=temp;
		
		}
		clock_t end=clock();
		spent_time += (double)(end-begin);
	}
	/*Printing total time*/
	printf("Queue fill struct time: %.4f\n",((spent_time/CLOCKS_PER_SEC)*1000));
	
	/*For bst*/
	*bst_=NULL;
	bst *root=(*bst_);
	spent_time=0.0;
	/*Bst filled and measured time*/
	for(i=0;i<SIZE;i++){
		clock_t begin=clock();
		root=add_bst(root,data[i]);
		clock_t end=clock();
		spent_time += (double)(end-begin);
	}
	printf("Bst fill struct time: %.4f\n\n",((spent_time/CLOCKS_PER_SEC)*1000));
	*(bst_)=root;	
}
bst *add_bst(bst *root,int number){
	//Null condition
	if(root == NULL){
		bst *iter=(bst*)malloc(sizeof(bst));
		iter->right=NULL;
		iter->left=NULL;
		iter->y=number;
		return iter;
	}
	/*Right condition*/
	if(root->y < number){
		root->right=add_bst(root->right,number);
		return root;
	}
	/*Left condition*/
	else{
		root->left=add_bst(root->left,number);
		return root;
	}

}

void ordered_print(stack *stack_,queue *queue_,bst *bst_){
	int arr[SIZE],arr_q[SIZE];
	int i=0,j,temp;
	double spent_time=0.0;
	/*For stack printing*/
	node *tmp;
	tmp=stack_->top;
	
	while(tmp != NULL){
		arr[i]=tmp->x;
		tmp=tmp->next;
		i++;
	}
	for(i=0;i<SIZE;i++){
		clock_t begin=clock();
		for(j=(i+1);j<SIZE;j++){
			if(arr[i] < arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}	
			
		}
		clock_t end=clock();
		spent_time += (double)(end-begin);
	}
	printf("Stack elements descending order: ");
	printf("\n");
	
	for(i=0;i<SIZE;i++)
		printf("%d ",arr[i]);
	printf("\n");
	i=0;
	printf("Stack printing total time: %.4f\n\n",((spent_time/CLOCKS_PER_SEC)*1000));
	/*Value resting*/
	spent_time=0.0;
	/*For queue printing*/
	node *q;
	q=queue_->front;
	while(q != NULL){
		arr_q[i]=q->x_q;
		q=q->next;
		i++;
	}
	for(i=0;i<SIZE;i++){
		clock_t begin=clock();
		for(j=(i+1);j<SIZE;j++){
			if(arr_q[i] < arr_q[j]){
				temp=arr_q[i];
				arr_q[i]=arr_q[j];
				arr_q[j]=temp;		
			}
		}
		clock_t end=clock();
		spent_time += (double)(end-begin);
	}
	printf("Queue elements descending order: ");
	printf("\n");
	for(i=0;i<SIZE;i++)
		printf("%d ",arr_q[i]);
	printf("\n");
	
	/*Printing total time*/
	printf("Queue printing total time: %.4f\n\n",((spent_time/CLOCKS_PER_SEC)*1000));
	spent_time=0.0;
	/*For bst printing with helper function*/
	printf("Bst elements descending order: ");
	printf("\n");
	
	clock_t begin=clock();
	printing_bst(bst_);
	printf("\n");
	clock_t end=clock();
	spent_time += (double)(end-begin);
	
	/*Printing total time*/
	printf("Bst printing total time: %.4f\n\n",((spent_time/CLOCKS_PER_SEC)*1000));
	

}

void printing_bst(bst *bst_){
	if(bst_ == NULL)
		return;
	else{
		printing_bst(bst_->right);
		printf("%d ",bst_->y);
		printing_bst(bst_->left);
	}
}

void search(stack *stack_,queue *queue_,bst *bst_,int val_to_search){
	double spent_time=0.0;
	int count=1;
	/*For stack search*/
	node *tmp;
	tmp=stack_->top;
	
	while(tmp != NULL){
		clock_t begin=clock();
		if(tmp->x == val_to_search){
			printf("%d result founded on %d.step\n",val_to_search,count);
			break;
		}
		else
			tmp=tmp->next;
		count++;
		clock_t end=clock();
		spent_time += (double)(end-begin);
	}	
	printf("Stack searching total time: %.4f\n",((spent_time/CLOCKS_PER_SEC)*1000));
	spent_time=0.0;
	count=1;
	/*For queue*/
	node *q;
	q=queue_->front;
	
	while(q != NULL){
		clock_t begin=clock();
		if(q->x_q == val_to_search){
			printf("%d result founded on %d.step\n",val_to_search,count);
			break;
		}
		else
			q=q->next;
		count++;
		clock_t end=clock();
		spent_time += (double)(end-begin);
	}
	/*Printing queue total time*/
	printf("Queue searching total time: %.4f\n",((spent_time/CLOCKS_PER_SEC)*1000));
	spent_time=0.0;
	count=1;
	/*For bst*/
	bst *t;
	t=bst_;
	
	while(t != NULL){
		clock_t begin=clock();
		if(val_to_search > t->y)
			t=t->right;
		else if(val_to_search < t->y)
			t=t->left;
		else{
			printf("%d result founded on %d.step\n",val_to_search,count);
			break;
		}
		count++;
		clock_t end=clock();
		spent_time += (double)(end-begin);
	}
	/*Printing bst total time*/
	printf("Bst searching total time: %.4f\n\n",((spent_time/CLOCKS_PER_SEC)*1000));
}

void special_traverse(stack *stack_,queue *queue_,bst *bst_){
	double spent_time=0.0;
	int 	j,i,
		max,min;
	int count=0;
	/*For stack*/
	node *iter=stack_->top;
	printf("Stack special traverse : \n");
	while(iter != NULL){
		count++;
		iter=iter->next;
	}
	iter=stack_->top;
	/*Data size even number*/
	if(count % 2 == 0){
		while(iter != NULL){
			/*Time begin*/
			clock_t begin=clock();
			max=iter->x;
			j=0;
			/*Find maximum elements*/
			while(iter != NULL){
				if(max < iter->x)
					max=iter->x;
				iter=iter->next;
			}
			iter=stack_->top;
		
			/*Go to printing element*/
			while(iter != NULL){
				if(iter->x == max)
					break;
				j++;
				iter=iter->next;
			}
			/*Printing element*/
			printf("%d ",iter->x);
			/*Deletion stack node*/
			/*Condition if first stack elements*/
			if(iter->x == stack_->top->x){
				node *tmp2;
				tmp2=stack_->top;
				stack_->top=stack_->top->next;
				free(tmp2);
			}
			/*The other conditions*/
			else{
				iter=stack_->top;
				for(i=0;i<(j-1);i++)
					iter=iter->next;
				node *temp;
				temp=iter->next;
				iter->next=iter->next->next;	
				free(temp);
			}
		
			j=0;
			iter=stack_->top;
		
			min=iter->x;
			/*Find minimum element*/
			while(iter != NULL){
				if(min > iter->x)
					min=iter->x;
				iter=iter->next;
			}
		
			iter=stack_->top;
			/*Go to printing element*/
			while(iter != NULL){
				if(iter->x == min)
					break;
				j++;
				iter=iter->next;
			}
			printf("%d ",iter->x);
			/*Deletion stack node*/
			/*Condition if first stack elements*/
			if(iter->x == stack_->top->x){
				node *tmp;
				tmp=stack_->top;
				stack_->top=stack_->top->next;
				free(tmp);
			}
			/*The other conditions*/
			else{
				iter=stack_->top;
				for(i=0;i<(j-1);i++)
					iter=iter->next;
				node *temp2;
				temp2=iter->next;
				iter->next=iter->next->next;
				free(temp2);
			}	
		
			iter=stack_->top;
			/*Time end and calculate*/
			clock_t end=clock();
			spent_time += (double)(end-begin);
		}
		printf("\n");
		printf("Stack traverse total time: %.4f\n\n",((spent_time/CLOCKS_PER_SEC)*1000));
	}
	/*Data size odd number*/
	else{
		while(iter->next != NULL){
			/*Time begin*/
			clock_t begin=clock();
			max=iter->x;
			j=0;
			/*Find maximum elements*/
			while(iter != NULL){
				if(max < iter->x)
					max=iter->x;
				iter=iter->next;
			}
			iter=stack_->top;
		
			/*Go to printing element*/
			while(iter != NULL){
				if(iter->x == max)
					break;
				j++;
				iter=iter->next;
			}
			/*Printing element*/
			printf("%d ",iter->x);
			/*Deletion stack node*/
			/*Condition if first stack elements*/
			if(iter->x == stack_->top->x){
				node *tmp2;
				tmp2=stack_->top;
				stack_->top=stack_->top->next;
				free(tmp2);
			}
			/*The other conditions*/
			else{
				iter=stack_->top;
				for(i=0;i<(j-1);i++)
					iter=iter->next;
				node *temp;
				temp=iter->next;
				iter->next=iter->next->next;	
				free(temp);
			}
		
			j=0;
			iter=stack_->top;
		
			min=iter->x;
			/*Find minimum element*/
			while(iter != NULL){
				if(min > iter->x)
					min=iter->x;
				iter=iter->next;
			}
		
			iter=stack_->top;
			/*Go to printing element*/
			while(iter != NULL){
				if(iter->x == min)
					break;
				j++;
				iter=iter->next;
			}
			printf("%d ",iter->x);
			/*Deletion stack node*/
			/*Condition if first stack elements*/
			if(iter->x == stack_->top->x){
				node *tmp;
				tmp=stack_->top;
				stack_->top=stack_->top->next;
				free(tmp);
			}
			/*The other conditions*/
			else{
				iter=stack_->top;
				for(i=0;i<(j-1);i++)
					iter=iter->next;
				node *temp2;
				temp2=iter->next;
				iter->next=iter->next->next;
				free(temp2);
			}	
		
			iter=stack_->top;
			/*Time end and calculate*/
			clock_t end=clock();
			spent_time += (double)(end-begin);
		}
		printf("%d ",iter->x);
		printf("\n");
		printf("Stack traverse total time: %.4f\n\n",((spent_time/CLOCKS_PER_SEC)*1000));
	
	}
		
	
	
	/*For queue*/
	spent_time=0.0;
	count=0;
	iter=queue_->front;
	printf("Queue special traverse : \n");
	while(iter != NULL){
		count++;
		iter=iter->next;
	}
	
	iter=queue_->front;
	/*Data size even number*/
	if(count % 2 == 0){
		while(iter != NULL){
			/*Time begin*/
			clock_t begin=clock();
			max=iter->x_q;
			j=0;
			/*Find maximum elements*/
			while(iter != NULL){
				if(max < iter->x_q)
					max=iter->x_q;
				iter=iter->next;
			}
			iter=queue_->front;
		
			/*Go to printing element*/
			while(iter != NULL){
				if(iter->x_q == max)
					break;
				j++;
				iter=iter->next;
			}
			/*Printing element*/
			printf("%d ",iter->x_q);
			/*Deletion stack node*/
			/*Condition if first stack elements*/
			if(iter->x_q == queue_->front->x_q){
				node *tmp2;
				tmp2=queue_->front;
				queue_->front=queue_->front->next;
				free(tmp2);
			}
			/*The other conditions*/
			else{
				iter=queue_->front;
				for(i=0;i<(j-1);i++)
					iter=iter->next;
				node *temp;
				temp=iter->next;
				iter->next=iter->next->next;	
				free(temp);
			}
		
			j=0;
			iter=queue_->front;
		
			min=iter->x_q;
			/*Find minimum element*/
			while(iter != NULL){
				if(min > iter->x_q)
					min=iter->x_q;
				iter=iter->next;
			}
		
			iter=queue_->front;
			/*Go to printing element*/
			while(iter != NULL){
				if(iter->x_q == min)
					break;
				j++;
				iter=iter->next;
			}
			printf("%d ",iter->x_q);
			/*Deletion stack node*/
			/*Condition if first stack elements*/
			if(iter->x_q == queue_->front->x_q){
				node *tmp;
				tmp=queue_->front;
				queue_->front=queue_->front->next;
				free(tmp);
			}
			/*The other conditions*/
			else{
				iter=queue_->front;
				for(i=0;i<(j-1);i++)
					iter=iter->next;
				node *temp2;
				temp2=iter->next;
				iter->next=iter->next->next;
				free(temp2);
			}	
		
			iter=queue_->front;
			/*Time end and calculate*/
			clock_t end=clock();
			spent_time += (double)(end-begin);
		}
	
		printf("\n");
	
		printf("Queue traverse total time: %.4f\n",((spent_time/CLOCKS_PER_SEC)*1000));
	}
	/*Data size odd number*/
	else{
		while(iter->next != NULL){
			/*Time begin*/
			clock_t begin=clock();
			max=iter->x_q;
			j=0;
			/*Find maximum elements*/
			while(iter != NULL){
				if(max < iter->x_q)
					max=iter->x_q;
				iter=iter->next;
			}
			iter=queue_->front;
		
			/*Go to printing element*/
			while(iter != NULL){
				if(iter->x_q == max)
					break;
				j++;
				iter=iter->next;
			}
			/*Printing element*/
			printf("%d ",iter->x_q);
			/*Deletion stack node*/
			/*Condition if first stack elements*/
			if(iter->x_q == queue_->front->x_q){
				node *tmp2;
				tmp2=queue_->front;
				queue_->front=queue_->front->next;
				free(tmp2);
			}
			/*The other conditions*/
			else{
				iter=queue_->front;
				for(i=0;i<(j-1);i++)
					iter=iter->next;
				node *temp;
				temp=iter->next;
				iter->next=iter->next->next;	
				free(temp);
			}
		
			j=0;
			iter=queue_->front;
		
			min=iter->x_q;
			/*Find minimum element*/
			while(iter != NULL){
				if(min > iter->x_q)
					min=iter->x_q;
				iter=iter->next;
			}
		
			iter=queue_->front;
			/*Go to printing element*/
			while(iter != NULL){
				if(iter->x_q == min)
					break;
				j++;
				iter=iter->next;
			}
			printf("%d ",iter->x_q);
			/*Deletion stack node*/
			/*Condition if first stack elements*/
			if(iter->x_q == queue_->front->x_q){
				node *tmp;
				tmp=queue_->front;
				queue_->front=queue_->front->next;
				free(tmp);
			}
			/*The other conditions*/
			else{
				iter=queue_->front;
				for(i=0;i<(j-1);i++)
					iter=iter->next;
				node *temp2;
				temp2=iter->next;
				iter->next=iter->next->next;
				free(temp2);
			}	
		
			iter=queue_->front;
			/*Time end and calculate*/
			clock_t end=clock();
			spent_time += (double)(end-begin);
		}
		printf("%d ",iter->x_q);
		printf("\n");
	
		printf("Queue traverse total time: %.4f\n",((spent_time/CLOCKS_PER_SEC)*1000));
	}
	
	
	/*For bst*/
	spent_time=0.0;
	bst *b=bst_;
	printf("\nBst special traverse: \n");
	
	while(bst_ != NULL){
		clock_t begin=clock();
		/*Condition of data size odd number*/
		if(count == 1){
			printf("%d ",bst_->y);
			clock_t end=clock();
			spent_time += (double)(end-begin);
			break;
		}
		//Find max
		max=max_value(bst_);
		//Print max
		printf("%d ",max);
		count--;
		//Delete max element
		bst_=delete(bst_,max);
		//Find min
		min=min_value(bst_);
		//Print min
		printf("%d ",min);
		count--;
		//Delete min element
		bst_=delete(bst_,min);
		/*Time end and calculate*/
		clock_t end=clock();
		spent_time += (double)(end-begin);
	}
	printf("\n");

	printf("Bst traverse total time: %.4f\n",((spent_time/CLOCKS_PER_SEC)*1000));
	
}

int max_value(bst *b){
	while(b->right != NULL)
		b=b->right;	
	return (b->y);	
}

bst *delete(bst *b,int value){
	if(b == NULL)
		return NULL;
	/*For max*/
	if(value > b->y)
		b->right=delete(b->right,value);
	/*For min*/
	else if(value < b->y)
		b->left=delete(b->left,value);
	else{
		//Having no left and right child
		if(b->left == NULL && b->right == NULL){
			free(b);
			return NULL;	
		}
		//Having one left or one right child
		else if(b->right == NULL || b->left == NULL){
			bst *tmp;
			if(b->left == NULL)
				tmp=b->right;
			else
				tmp=b->left;
			free(b);
			return tmp;
		}
		//Having both of them
		else{
			bst *temp=find_min(b->right);
			b->y=temp->y;
			b->right=delete(b->right,temp->y);
		}
	}
	return b;
}

bst *find_min(bst *root){
	if(root == NULL)
		return NULL;
	else if(root->left != NULL)
		return find_min(root->left);
	return root;

}

int min_value(bst *b){
	while(b->left != NULL)
		b=b->left;
	return (b->y);

}

