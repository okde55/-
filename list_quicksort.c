/* ID 2013104293	- REPLACE WITH YOUR ID
 * NAME Jeong Min Jae	- REPLACE WITH YOUR NAME */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/////////////////////////////////////////////
struct DNODE {
  int val;
  struct DNODE *prev, *next;
};

/////////////////////////////////////////////
void freelist(struct DNODE *head)
{
  struct DNODE *next;
  while ( head ) {
    next = head->next;
    free(head);
    head = next;
  }
}

/////////////////////////////////////////////
void printlist(struct DNODE *head)
{
  while ( head ) {
    fprintf(stdout, "%d ", head->val);
    head = head->next;
  }
}

/////////////////////////////////////////////
// List QUICK SORT
// You may define other functions if necessary

void swap (struct DNODE *a, struct DNODE *b){ //a should be on the leftside of b
	struct DNODE *temp=a->next;
	struct DNODE *temp2=a->prev;

	if((a->prev != NULL)&&(b->next != NULL)){
		if(a->next == b){
			a->prev->next = b;
			b->next->prev = a;
		}else{
			a->prev->next = b;
			a->next->prev = b;
			b->prev->next = a;
			b->next->prev = a;
		}
	}else if((a->prev == NULL)&&(b->next != NULL)){
		if(a->next == b){
			a->next->prev = a->prev;
			b->next->prev = a;

		}else{
			a->next->prev = b;
			b->prev->next = a;
			b->next->prev = a;
		}
	}else if((a->prev != NULL)&&(b->next == NULL)){
		if(a->next == b){
			a->prev->next = b;
			a->next->prev = a->prev;

			//b->prev->next = a;
		}else{
			a->prev->next = b;
			a->next->prev = b;
			b->prev->next = a;
		}
	}else if((a->prev == NULL)&&(b->next == NULL)){
		if(a->next == b){
			a->next->prev = temp2;
		}else{
			a->next->prev = b;
			b->prev->next = a;
		}
	}else{
		printf("ERRROOOOOOOOOO3");
	}

	if(a->next == b){
		if(b->next == NULL){
			a->prev = b;
			a->next = b->next;
			b->next = a;

		}else{
			a->next = b->next;
			a->prev = b;
			b->next = a;
			b->prev = temp2;
		}
	}else{
		a->next = b->next;
		a->prev = b->prev;
		b->next = temp;
		b->prev = temp2;
	}
}


struct DNODE *mergerpl(
	struct DNODE *left, 
	struct DNODE *lefttail,
	struct DNODE *right,
	struct DNODE *righttail)
{

	while(left->next){
		left = left->next;
	}
	left->next = right;
	right->prev = left;
	lefttail = righttail;
	while(left->prev){
		left = left->prev;
	}
	while(lefttail->next){
		lefttail = lefttail->next;
	}
	//while(lefttail->next){
	//	lefttail = lefttail->next;
	//}

	return left;
}
struct DNODE *quicksort_list(struct DNODE *head, struct DNODE *tail)
{
	struct DNODE *pivot, *left, *right, *lefttail, *righttail;

	pivot = head;
	left = pivot->next;
	right = tail;
	while(left->val != 348989){ // exception ! : if left == right, it means that pivot is the biggest number of the list.
		
int a=0,b = 0;
		while( (pivot->val) > (left->val) && (left!=right) ){ //search the left that is bigger than pivot.

			left = left->next;
		}

//printf("pivot%d : right%d rp%d\n",pivot->val, right->val, right->prev->val);

		while( (pivot->val) < (right->val) && (right->prev != pivot)){ //sarch the right that is smaller than pivot

			right = right->prev;
			if( (left) == (right) ) {
				break;
			}
		}


		if( (left != right) && (left->prev != right->next) &&(left->prev != right)){
			swap(left, right);
			struct DNODE *tempnode = right; //convert the pointing right and left nodes 
			right = left;
			left = tempnode;
			if(left == tail){
				tail = right;
			}
		}

		if (((left->val) > (right->val)) || (left == right)){
			break;
		}else{
		}
	}


	if( (left!=right) && (left->val) > (right->val) ){ // ordinary case
		swap(pivot, right);
		left = right;
		lefttail = pivot; 
		right = pivot->next;
		righttail = tail;
		head = left;

	}else if((left==right) && (left==tail)){
		if(pivot->val > left->val){
			if(pivot->next == left){
				swap(pivot, right);
				left = right;
				lefttail = right;
				right = pivot;
				righttail = pivot;
				head = left;
			}else{
				swap(pivot, right);
				left = right;
				lefttail = pivot->prev;
				right = pivot;
				righttail = pivot;
				head = left;
			}
		}else if(pivot->val == left->val){
			left = pivot;
			lefttail = right->prev;
			righttail;
			righttail = right;
		}else{
			left = pivot;
			lefttail = pivot;
			right =  right;
			righttail = right;
			head = left;
		}
	}else if((left==right) && (left==head)){ //this must be errored
		lefttail = left;
		right = left->next;
		righttail = tail->prev;
	}else if((left==right) && (left->val) > (pivot->val)){ //i don't know what it is
		left = pivot;
		lefttail = right->prev;
		right = right;
		righttail = tail;
	}else if((left==right) && (left->val) < (pivot->val)){

	}else{ //if left == right but left!=head or tail
		float k = right->val - left->val;
		int kk;
		if (right == left) kk = 1;
		else kk =0;
		//exit(0);
		left = pivot;
		lefttail = right;
		right = right->next;
		righttail = tail;
	}
	lefttail->next = NULL;
	right->prev = NULL;
		//printlist22(left, lefttail, right, righttail);
	if(!(left->prev == NULL && left->next == NULL))
		left = quicksort_list(left,lefttail);
	if(!(right->prev == NULL && right->next == NULL)){		
		right = quicksort_list(right,righttail);
	}
	while(lefttail->next){
		lefttail = lefttail->next;
	}
	int p = 0;
	head = mergerpl(left, lefttail, right, righttail);
	tail = left->next;
	while(tail->next && p != 1000){
		p ++;
		tail = tail->next;
	}
	return head;

	//return head;

}


/////////////////////////////////////////////

int main()
{

  int i, N;
  int val;
  struct DNODE *head, *tail, *cur;

  fprintf(stderr, "How many numbers? \n");
  fscanf(stdin, "%d", &N);

  head = tail = NULL;
  for (i=0; i<N; i++) {
    if ( fscanf(stdin, "%d", &val) != 1 ) {
      fprintf(stderr, "cannot read integer from standard input.\n");
      freelist(head);
      exit(0);
    }
    else {
      cur = (struct DNODE*) malloc(sizeof(struct DNODE));
      cur->val = val;
      cur->next = NULL;
      if ( !head ) {
		cur->prev = NULL;
		head = tail = cur;
      }
      else {
		tail->next = cur; 
		cur->prev = tail;
		tail = cur;
      }
    }
  }
  head = quicksort_list(head, tail);
  
  printlist(head);

  // free memory
  freelist(head);

  return 0;
}
