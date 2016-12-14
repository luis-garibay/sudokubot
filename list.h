#ifndef __LIST__
#define __LIST__

#include "boolean.h"

typedef struct _Node* NodePtr;
typedef struct _Node {
	int value;
	NodePtr next;
} Node;

typedef struct _List {
	Node *head;
	int elemcount;
} List;

List *createList();
Boolean isEmptyList(List *list);
void listInsert(List *list, int value);
void listRemoveValue(List *list, int value);
int listRemoveIndex(List *list, int index);
Boolean isValueInList(List *list, int value);
int listIndex2Value(List *list, int index);
int listHeadValue(List *list);
int listTailValue(List *list);
void deleteList(List *list);

#endif
