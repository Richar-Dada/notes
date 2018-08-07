#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linklist.h"

typedef struct _tag_linklist
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkList_Create(int capacity){
	TLinkList *tl = NULL;
	tl = (TLinkList*)malloc(sizeof(TLinkList));
	if (tl == NULL) {
		printf("Linklist malloc err:");
		return NULL;
	}
	memset(tl, 0, sizeof(TLinkList));
	tl->header.next = NULL;
	tl->length = 0;
	return tl;
}

void LinkList_Destory(LinkList* list){
	TLinkList *tl = NULL;
	tl = (TLinkList*) list;
	if (tl == NULL) {
		printf("LinkList destory err");
		return ;
	}
	free(tl);
	return ;
}

void LinkList_Clear(LinkList* list){
	TLinkList *tl = NULL;
	tl = (TLinkList*) list;
	if (tl == NULL) {
		printf("LinkList Clear err");
		return ;
	}
	tl->header.next = NULL;
	tl->length = 0;
	return ;
}

int LinkList_Length(LinkList* list){
	TLinkList *tl = NULL;
	tl = (TLinkList*) list;
	if (tl == NULL) {
		printf("LinkList Clear err");
		return ;
	}
	return tl->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos){
	int i = 0;
	TLinkList *tl = NULL;
	LinkListNode *current = NULL;
	tl = (TLinkList*) list;
	if (tl == NULL) {
		printf("LinkList Clear err");
		return ;
	}
	current = &(tl->header);

	for(i=0;i<pos;i++){
		current = current->next;
	}

	node->next = current->next;
	current->next = node;
	tl->length ++;
	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos){
	int i = 0;
	TLinkList *tl = NULL;
	LinkListNode *current = NULL;
	tl = (TLinkList*) list;
	if (tl == NULL) {
		printf("LinkList Get err");
		return ;
	}
	current = &(tl->header);

	for(i=0;i<pos;i++){
		current = current->next;
	}
	return current->next;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos){
	int i = 0;
	TLinkList *tl = NULL;
	LinkListNode *current = NULL;
	LinkListNode *ret = NULL;
	tl = (TLinkList*) list;
	if (tl == NULL) {
		printf("LinkList Get err");
		return ;
	}
	current = &(tl->header);

	for(i=0;i<pos;i++){
		current = current->next;
	}

	ret = current->next;
	current->next = ret->next;
	tl->length --;
	return ret;
}