#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linkstack.h"

void output(char c){
	if(c != '\0'){
		printf("%c", c);
	}
}

int isNumber(char c){
	int ret = 0;
	switch (c)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

/*
int isLeft(char s){
	int ret = 0;
	
	switch (s)
	{
	case '<':
	case '(':
	case '[':
	case '{':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

int isRight(char s){
	int ret = 0;

	switch (s)
	{
	case '>':
	case ')':
	case ']':
	case '}':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}
*/

int isOperator(char c){
	int ret = 0;
	switch (c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

int priority(char c){
	int ret = 0;
	switch (c)
	{
	case '+':
	case '-':
		ret = 1;
		break;
	case '*':
	case '/':
		ret = 2;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

void transform(const char* exp){
	int i = 0;
	LinkStack* stack = LinkStack_Create();

	while(exp[i] != '\0'){
		if(isNumber(exp[i])){
			output(exp[i]);
		} else if(isOperator(exp[i])){
			while(priority(exp[i]) <= priority((char)(int)LinkStack_Top(stack))){
				output((char)(int)LinkStack_Pop(stack));
			}
			LinkStack_Push(stack, (void*)(int)exp[i]);
		} else if(isLeft(exp[i])){
			LinkStack_Push(stack, (void*)(int)exp[i]);
		} else if(isRight(exp[i])){
			while(!isLeft((char)(int)LinkStack_Top(stack))){
				output((char)(int)LinkStack_Pop(stack));
			}
			LinkStack_Pop(stack);
		} else {
			printf("Invalid expression");
			break;
		}
		i++;
	}

	while((LinkStack_Size(stack) > 0) && (exp[i] == '\0')){
		output((char)(int)LinkStack_Pop(stack));
	}

	LinkStack_Destroy(stack);
}

int main(){
	transform("8+(3-1)*5");

	printf("\n");
	system("pause");
	return 0;
}