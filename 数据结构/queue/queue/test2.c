#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linkqueue.h"

int main(){
	int i = 0;
	int a[10];
	LinkQueue* queue = NULL;
	queue = LinkQueue_Create();
	if(queue == NULL){
		return ;
	}

	for(i = 0; i < 5; i ++){
		a[i] = i + 1;
		LinkQueue_Append(queue, &a[i]);
	}

	printf("len: %d \n", LinkQueue_Length(queue));
	printf("header: %d \n", *((int *)LinkQueue_Header(queue)));

	while(LinkQueue_Length(queue) > 0){
		int tmp = *((int *)LinkQueue_Retrieve(queue));
		printf("linkqueue-tmp: %d \n", tmp);
	}

	printf("hello...\n");
	system("pause");
}