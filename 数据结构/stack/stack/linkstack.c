#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linklist.h"
#include "linkstack.h"

typedef struct _tag_LinkStackNode{
	LinkListNode node;
	void* item;
}TLinkStackNode;

LinkStack* LinkStack_Create(){
	return LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack){
	LinkStack_Clear(stack);
	LinkList_Destory(stack);
}

void LinkStack_Clear(LinkStack* stack){
	if(stack == NULL){
		return ;
	}
	while(LinkStack_Size(stack) > 0){
		LinkStack_Pop(stack);
	}
	return ;
}

int LinkStack_Push(LinkStack* stack, void* item){
	TLinkStackNode* tmp = NULL;
	int ret = 0;

	tmp = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if(tmp == NULL){
		return -1;
	}
	memset(tmp, 0, sizeof(TLinkStackNode));
	tmp->item = item;

	ret = LinkList_Insert(stack, (LinkListNode*)tmp, 0);

	if(ret != 0){
		printf("func LinkList_Insert() err:%d \n", ret);
		if(tmp != NULL){
			free(tmp);
		}
		return ret;
	}
}

void* LinkStack_Pop(LinkStack* stack){
	void *item = NULL;
	TLinkStackNode *tmp = NULL;
	tmp = (TLinkStackNode*)LinkList_Delete(stack, 0);
	if(tmp == NULL){
		return NULL;
	}
	item = tmp->item;
	free(tmp);
	return item;
}

void* LinkStack_Top(LinkStack* stack){
	TLinkStackNode *tmp = NULL;
	tmp = (TLinkStackNode*)LinkList_Get(stack, 0);
	if(tmp == NULL){
		return NULL;
	}
	return tmp->item;
}

int LinkStack_Size(LinkStack* stack){
	return LinkList_Length(stack);
}

/*
typedef struct _tag_LinkStackNode
{
	LinkListNode node;
	void* item;
}TLinkStackNode;


LinkStack* LinkStack_Create(){
	return LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack){
	LinkStack_Clear(stack);
	LinkList_Destory(stack);
}

void LinkStack_Clear(LinkStack* stack){
	if(stack == NULL){
		return ;
	}

	while (LinkStack_Size(stack) > 0)
	{
		LinkStack_Pop(stack);
	}
	return ;
}

int LinkStack_Push(LinkStack* stack, void* item){
	TLinkStackNode* tmp = NULL;
	int ret = 0;
	tmp = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if(tmp == NULL){
		printf("LinkStack_Push err");
	}
	memset(tmp, 0, sizeof(TLinkStackNode));
	tmp->item = item;
	ret = LinkList_Insert(stack, (LinkListNode*)tmp, 0);
	if(ret != 0){
		printf("LinkStack_Push LinkList_Insert err");
		return ret;
	}
	return ret;
}

void* LinkStack_Pop(LinkStack* stack){
	TLinkStackNode* tmp = NULL;
	void * item = NULL;
	tmp = (TLinkStackNode*)LinkList_Delete(stack, 0);
	if(tmp == NULL){
		printf("LinkStack_Pop err");
		return NULL;
	}
	item = tmp->item;
	free(tmp);
	return item;
}

void* LinkStack_Top(LinkStack* stack){
	TLinkStackNode* tmp = NULL;
	void * item = NULL;
	tmp = (TLinkStackNode*)LinkList_Get(stack, 0);
	if(tmp == NULL){
		printf("LinkStack_Top err");
		return NULL;
	}
	item = tmp->item;
	return item;
}

int LinkStack_Size(LinkStack* stack){
	return LinkList_Length(stack);
}
*/