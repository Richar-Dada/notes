#ifndef __MY_SEQLIST_H__
#define __MY_SEQLIST_H__

typedef void LinkList;
typedef struct _tag_LinkListNode{
	struct _tag_LinkListNode* next;
}LinkListNode;

LinkList* LinkList_Create();

void LinkList_Destory(LinkList* list);

void LinkList_Clear(LinkList* list);

int LinkList_Length(LinkList* list);

int LinkList_Capacity(LinkList* list);

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* LinkList_Get(LinkList* list, int pos);

LinkListNode* LinkList_Delete(LinkList* list, int pos);

#endif