#include <stdio.h>
#include <malloc.h>
#include "circlelist.h"

typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode *slider;
	int length;
}TCircleList;

CircleList* CircleList_Create(){
	TCircleList *ret = (TCircleList*)malloc(sizeof(TCircleList));
	if(ret == NULL){
		return NULL;
	}
	ret->length = 0;
	ret->header.next = NULL;
	ret->slider = NULL;
	return ret;
}

void List_Destroy(CircleList* list){
	if(list == NULL){
		return ;
	}
	free(list);
}

void CircleList_Clear(CircleList* list){
	TCircleList* sList = (TCircleList*)list;
	if(sList == NULL){
		return ;
	}
	sList->length = 0;
	sList->header.next = NULL;
	sList->slider = NULL;
}

int CircleList_Length(CircleList* list){
	TCircleList* sList = (TCircleList*)list;
	int ret = -1;
	if(list == NULL){
		return ret;
	}
	ret = sList->length;
	return ret;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos){
	int ret = 0, i = 0;
	TCircleList* sList = (TCircleList *)list;
	
	if(list == NULL || node == NULL || pos < 0){
		return -1;
	}
	{
		CircleListNode *current = (CircleListNode*)sList;
		for(i=0;(i<pos)&&(current->next != NULL); i++){
			current = current->next;
		}

		node->next = current->next;
		current->next = node;

		if(sList->length == 0){
			sList->slider = node;
		}

		sList->length ++;

		if(current == (CircleListNode*)sList){
			CircleListNode* last = CircleList_Get(sList, sList->length - 1);
			last->next = current->next;
		}
	}
	return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos){
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;
	if(list == NULL){
		return NULL;
	}
	{
		CircleListNode* current = (CircleListNode*) sList;
		for(i=0;i<pos;i++){
			current = current->next;
		}
		ret = current->next;
	}
	return ret;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos) // O(n)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if( (sList != NULL) && (pos >= 0) && (sList->length > 0) )
	{
		CircleListNode* current = (CircleListNode*)sList;
		CircleListNode* last = NULL;

		for(i=0; i<pos; i++)
		{
			current = current->next;
		}

		//��ɾ����һ��Ԫ�أ�ͷ��㣩
		if( current == (CircleListNode*)sList )
		{
			last = (CircleListNode*)CircleList_Get(sList, sList->length - 1);
		}

		//��Ҫɾ����Ԫ��
		ret = current->next;
		current->next = ret->next;

		sList->length--;

		//�ж������Ƿ�Ϊ��
		if( last != NULL )
		{
			sList->header.next = ret->next;
			last->next = ret->next;
		}

		//��ɾ����Ԫ��Ϊ�α���ָ��Ԫ��
		if( sList->slider == ret )
		{
			sList->slider = ret->next;
		}

		//��ɾ��Ԫ�غ�������Ϊ0
		if( sList->length == 0 )
		{
			sList->header.next = NULL;
			sList->slider = NULL;
		}
	}

	return ret;
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node) // O(n)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if( sList != NULL )
	{
		CircleListNode* current = (CircleListNode*)sList;
		
		//����node��ѭ�������е�λ��i
		for(i=0; i<sList->length; i++)
		{
			if( current->next == node )
			{
				ret = current->next;
				break;
			}

			current = current->next;
		}
		
		//���ret�ҵ�������iȥɾ��	
		if( ret != NULL )
		{
			CircleList_Delete(sList, i);
		}
	}

	return ret;
}

CircleListNode* CircleList_Reset(CircleList* list) // O(1)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if( sList != NULL )
	{
		sList->slider = sList->header.next;
		ret = sList->slider;
	}

	return ret;
}

CircleListNode* CircleList_Current(CircleList* list) // O(1)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if( sList != NULL )
	{
		ret = sList->slider;
	}

	return ret;
}

//�ѵ�ǰλ�÷��أ������α�����
CircleListNode* CircleList_Next(CircleList* list) // O(1)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if( (sList != NULL) && (sList->slider != NULL) )
	{
		ret = sList->slider;
		sList->slider = ret->next;
	}

	return ret;
}