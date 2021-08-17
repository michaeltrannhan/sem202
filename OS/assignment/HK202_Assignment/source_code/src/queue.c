#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void push(struct queue_t * q, int idx){
	for( int i = idx+1 ; i< q->size - 1; i++){
		q->proc[i-1] = q->proc[i];
	}
}


void swap(struct pcb_t  * a, struct pcb_t * b) {
  struct pcb_t  temp  = *b;
  *b = *a;  
  *a = temp;
}

void heapify(struct queue_t * q, int sizee, int i) {
  if (sizee == 1) {
    //printf("Single element in the heap");
  } else {
    // Find the largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < sizee 
    		&& q->proc[l]->priority < q->proc[largest]->priority)
      largest = l;
    if (r < sizee && q->proc[r]->priority < q->proc[largest]->priority)
      largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(q->proc[i], q->proc[largest]);
      heapify(q, sizee, largest);
    }
  }
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */

	if(q->size > MAX_QUEUE_SIZE) 
		return;
	q->proc[q->size]= proc;
	q->size +=1;
 	for(int i = q->size / 2 - 1; i >= 0; i--){
 		heapify(q,q->size, i);
 	}
 // 	if (q->size == MAX_QUEUE_SIZE) return;
	// q->proc[q->size++] = proc;
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size == 0) return NULL;
	q->size--;
	swap(q->proc[0], q->proc[q->size]);
	for(int i = q->size / 2 - 1; i >= 0; i--){
		heapify(q,q->size, i);
 	}
	struct pcb_t *item = q->proc[q->size];
	return item;
	// if (q->size == 0) return NULL;
	// int i = 0, j;
	// for (j = 1; j < q->size; j++) {
	// 	if (q->proc[j]->priority < q->proc[i]->priority) {
	// 		i = j;
	// 	}
	// }
	// struct pcb_t * res = q->proc[i];
	// for (j = i+1; j < q->size; j++) {
	// 	q->proc[j-1] = q->proc[j];
	// }
	// q->size--;

	// return res;
}


