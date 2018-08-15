#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "seqlist.h"
#include "seqqueue.h"

SeqQueue* SeqQueue_Create(int capacity){
	return SeqList_Create(capacity);
}

void SeqQueue_Destroy(SeqQueue* queue){
	SeqList_Destory(queue);
	return ;
}

void SeqQueue_Clear(SeqQueue* queue){
	SeqList_Clear(queue);
	return;
}

int SeqQueue_Append(SeqQueue* queue, void* item){
	SeqList* tmp = NULL;
	tmp = (SeqList*)queue;
	return SeqList_Insert(tmp, item, SeqList_Length(tmp));
}

void* SeqQueue_Retrieve(SeqQueue* queue){
	return SeqList_Delete(queue, 0);
}

void* SeqQueue_Header(SeqQueue* queue){
	return SeqList_Get(queue, 0);
}

int SeqQueue_Length(SeqQueue* queue){
	return SeqList_Length(queue);
}

int SeqQueue_Capacity(SeqQueue* queue){
	return SeqList_Capacity(queue);
}