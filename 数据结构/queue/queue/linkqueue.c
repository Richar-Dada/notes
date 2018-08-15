#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linklist.h"
#include "linkqueue.h"

typedef struct _tag_LinkQueueNode{
	LinkListNode node;
	void* item;
}TLinkQueueNode;

typedef void LinkQueue;

LinkQueue* LinkQueue_Create(){
	return LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue* queue){
	LinkQueue_Clear(queue);
	LinkList_Destory(queue);
}

void LinkQueue_Clear(LinkQueue* queue){
	while (LinkQueue_Length(queue) > 0)
	{
		LinkQueue_Retrieve(queue);
	}
	LinkList_Clear(queue);
	return ;
}

int LinkQueue_Append(LinkQueue* queue, void* item){
	int ret = 0;
	TLinkQueueNode* tmp = NULL;
	tmp = (TLinkQueueNode*)malloc(sizeof(TLinkQueueNode));
	if(tmp == NULL){
		ret = -1;
		printf("LinkQueue_Append malloc err %d\n", ret);
		return ret;
	}
	memset(tmp, 0, sizeof(TLinkQueueNode));
	tmp->item = item;
	ret = LinkList_Insert(queue, (LinkListNode*)tmp, LinkList_Length(queue));
	if(ret != 0){
		printf("LinkQueue_Append LinkList_Insert err %d\n", ret);
		return ret;
	}
	return ret;
}

void* LinkQueue_Retrieve(LinkQueue* queue){
	void* ret = 0;
	TLinkQueueNode* tmp = NULL;

	tmp = (TLinkQueueNode*)LinkList_Delete(queue, 0);
	if(tmp == NULL){
		printf("LinkQueue_Retrieve err \n");
		return NULL;
	}

	ret = tmp->item;

	if(tmp != NULL){
		free(tmp);
	}
	return ret;
}

void* LinkQueue_Header(LinkQueue* queue){
	void* ret = 0;
	TLinkQueueNode* tmp = NULL;
	tmp = (TLinkQueueNode*)LinkList_Get(queue, 0);
	if(tmp == NULL){
		printf("LinkQueue_Header err \n");
		return NULL;
	}

	ret = tmp->item;
	return ret;
}

int LinkQueue_Length(LinkQueue* queue){
	return LinkList_Length(queue);
}