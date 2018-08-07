#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "seqlist.h"

/*
typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int * node;
}TSeqlist;

SeqList* SeqList_Create(int capacity){
	int ret = 0;
	TSeqlist *tmp = NULL;

	tmp = (TSeqlist *)malloc(sizeof(TSeqlist));
	if(tmp == NULL){
		ret = -1;
		printf("func SeqList_Create() err:%d \n", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqlist));

	tmp->node = (unsigned int *)malloc(sizeof(unsigned int *) * capacity);
	if(tmp->node == NULL){
		ret = -2;
		printf("func SeqList_Create err: malloc err %d \n", ret);
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;
	return tmp;
}

void SeqList_Destory(SeqList* list){
	TSeqlist *tlist = NULL;
	if(list == NULL){
		return;
	}
	tlist = (TSeqlist *)list;
	if(tlist->node != NULL){
		free(tlist->node);
	}
	free(tlist);
	return ;
}

void SeqList_Clear(SeqList* list){
	TSeqlist *tlist = NULL;
	if(list == NULL){
		return ;
	}
	tlist = (TSeqlist *)list;
	tlist->length = 0;
	return ;
}

int SeqList_Length(SeqList* list){
	TSeqlist *tlist = NULL;
	if(list == NULL){
		return -1;
	}
	tlist = (TSeqlist *)list;
	return tlist->length;
}

int SeqList_Capacity(SeqList* list){
	TSeqlist *tlist = NULL;
	if(list == NULL){
		return -1;
	}
	tlist = (TSeqlist *)list;
	return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos){
	int i = 0, ret = 0;
	TSeqlist *tlist = NULL;

	if(list == NULL || node == NULL || pos < 0){
		ret = -1;
		printf("fun SeqList_Insert() err:%d \n", ret);
		return ret;
	}

	tlist = (TSeqlist*)list;

	if(tlist->length >= tlist->capacity){
		ret = -2;
		printf("fun SeqList_Insert() (this->length >= tlist->capacity) err:%d \n", ret);
		return ret;
	}

	if(pos >= tlist->length){
		pos = tlist->length;
	}

	for(i=tlist->length; i > pos; i--){
		tlist->node[i] = tlist->node[i-1];
	}

	tlist->node[i] = (unsigned int) node;
	tlist->length ++;
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos){
	int i=0;
	SeqListNode *ret = 0;
	TSeqlist *tlist = NULL;

	if(list == NULL || pos < 0){
		printf("fun SeqList_Get() err:%d \n", ret);
		return NULL;
	}
	tlist = (TSeqlist *)list;

	ret = (void *)tlist->node[pos];
	return ret;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos){
	int i = 0;
	SeqListNode *ret = 0;
	TSeqlist *tlist = NULL;

	if(list == NULL || pos < 0){
		printf("fun SeqList_Delete() err:%d \n", ret);
		return NULL;
	}
	tlist = (TSeqlist *)list;

	ret = (SeqListNode *)tlist->node[pos];
	
	for(i = pos + 1; i < tlist->length; i++){
		tlist->node[i-1] = tlist->node[i];
	}
	tlist->length --;
	return ret;
}
*/

typedef struct _tag_sqlList
{
	int length;
	unsigned int * node;
	int capacity;
}TsqlList;


SeqList* SeqList_Create(int capacity){
	int ret = 0;
	TsqlList *list = NULL;
	list = (TsqlList *)malloc(sizeof(TsqlList));
	

	if(list == NULL){
		ret = -1;
		printf("TsqlList malloc err: %d", ret);
		return NULL;
	}
	memset(list, 0, sizeof(TsqlList));

	list->node = (unsigned int *)malloc(sizeof(unsigned int *) * capacity);

	if(list->node == NULL){
		ret = -2;
		printf("list->node malloc err: %d", ret);
		return NULL;
	}

	list->length = 0;
	list->capacity = capacity;
	return list;
}

void SeqList_Destory(SeqList* list){
	int ret = 0;
	TsqlList *tlist = NULL;
	tlist = (TsqlList *) list;
	if(tlist == NULL){
		ret = -1;
		printf("seqList destory err: %d", ret);
		return;
	}
	free(tlist);
	return;
}

void SeqList_Clear(SeqList* list){
	int ret = 0;
	TsqlList *tlist = NULL;
	tlist = (TsqlList *) list;
	if(tlist){
		ret = -1;
		printf("seqList destory err: %d", ret);
		return;
	}
	tlist->length = 0;
	free(tlist->node);
	return ;
}

int SeqList_Length(SeqList* list){
	int ret = 0;
	TsqlList *tlist = NULL;
	if(list == NULL){
		ret = -1;
		printf("seqList Length err: %d", ret);
		return ret;
	}
	tlist = (TsqlList *) list;

	return tlist->length;
}

int SeqList_Capacity(SeqList* list){
	int ret = 0;
	TsqlList *tlist = NULL;
	tlist = (TsqlList *) list;
	if(tlist == NULL){
		ret = -1;
		printf("seqList capacity err: %d", ret);
		return ret;
	}
	return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos){
	int ret = 0;
	int i = 0;
	TsqlList *tlist = NULL;
	if(list == NULL){
		ret = -1;
		printf("seqList Insert err: %d", ret);
		return ret;
	}

	tlist = (TsqlList *) list;

	
	for(i=tlist->length; i > pos; i--){
		tlist->node[i] = tlist->node[i-1];
	}
	tlist->node[i] = (unsigned int) node;
	tlist->length ++;
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos){
	int ret = 0;
	TsqlList *tlist = NULL;
	SeqListNode *n = NULL;
	if(list == NULL){
		ret = -1;
		printf("seqList Get err: %d", ret);
		return NULL;
	}
	tlist = (TsqlList *) list;

	n = (void *)tlist->node[pos];
	return n;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos){
	int ret = 0;
	int i = 0;
	TsqlList *tlist = NULL;
	SeqListNode *n = NULL;

	tlist = (TsqlList *) list;
	if(tlist == NULL){
		ret = -1;
		printf("seqList Delete err: %d", ret);
	}
	n = (SeqListNode*) tlist->node[pos];

	for(i = pos + 1; i<tlist->length; i++){
		tlist->node[i-1] = tlist->node[i];
	}
	tlist->length --;
	return n;
}