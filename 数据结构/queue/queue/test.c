#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "seqqueue.h"

int main01(){
	int i = 0;
	int a[10];
	SeqQueue* queue = NULL;
	queue = SeqQueue_Create(10);
	if(queue == NULL){
		return ;
	}

	for(i = 0; i < 5; i ++){
		a[i] = i + 1;
		SeqQueue_Append(queue, &a[i]);
	}

	printf("len: %d \n", SeqQueue_Length(queue));
	printf("header: %d \n", *((int *)SeqQueue_Header(queue)));

	while(SeqQueue_Length(queue) > 0){
		int tmp = *((int *)SeqQueue_Retrieve(queue));
		printf("tmp: %d", tmp);
	}

	printf("hello...\n");
	system("pause");
	return 0;
}