#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linkstack.h"

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

int match(char c, char code){
	int ret = 0;
	switch (c)
	{
	case '<':
		ret = (code == '>');
		break;
	case '[':
		ret = (code == ']');
		break;
	case '(':
		ret = (code == ')');
		break;
	case '{':
		ret = (code == '}');
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

void analyse(char *code){
	LinkStack* ls = NULL;
	int i = 0, ret = 1;
	ls = LinkStack_Create();

	while(code[i] != '\0'){
		if(isLeft(code[i]) == 1){
			LinkStack_Push(ls, &code[i]);
		} else if(isRight(code[i]) == 1){
			char* c = (char*)LinkStack_Pop(ls);
			if((c == NULL) || !match(*c, code[i])){
				printf("%c does not match!\n", code[i]);
				ret = 0;
				break;
			}
		}
		i++;
	}

	if((LinkStack_Size(ls) == 0) && (code[i] == '\0')){
		printf("success!");
	}
}

int main02(){
	char *code = "{c('aa'}";
	analyse(code);
	system("pause");
	return 0;
}