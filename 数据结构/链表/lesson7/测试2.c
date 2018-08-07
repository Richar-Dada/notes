#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linklist.h"

typedef struct _TT
{
	LinkListNode *node;
	int age;
}TT;

int main03(){
	int ret = 0;
	int i = 0;
	LinkList *tl = NULL;

	TT t1,t2,t3,t4,t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;

	tl = (LinkList *)LinkList_Create(10);
	if(tl == NULL){
		printf("LinkList init err");
		return 0;
	}

	ret = LinkList_Insert(tl, (LinkListNode*) &t1, 0);
	ret = LinkList_Insert(tl, (LinkListNode*) &t2, 0);
	ret = LinkList_Insert(tl, (LinkListNode*) &t3, 0);
	ret = LinkList_Insert(tl, (LinkListNode*) &t4, 0);
	ret = LinkList_Insert(tl, (LinkListNode*) &t5, 0);

	for(i = 0; i < LinkList_Length(tl); i++){
		TT *tmp = NULL;
		tmp = (TT *)LinkList_Get(tl, i);
		printf("tmp->age:%d \n", tmp->age);
	}

	while (LinkList_Length(tl) > 0)
	{
		LinkList_Delete(tl, 0);
	}

	system("pause");
}