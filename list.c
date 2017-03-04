#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "mem_wrap.h"

List *createList() {
	List *list = (List*) wMalloc(sizeof(List));

	list->head = NULL;
	list->elemcount = 0;

	return list;
}

Boolean isEmptyList(List *list) {
	if (list->elemcount == 0)
		return TRUE;
	else
		return FALSE;
}

void listInsert(List *list, int value) {
	Node *cur, *newNode;

	if (isValueInList(list, value) == TRUE)
		return;

	newNode = (Node*) wMalloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;

	list->elemcount++; // increment count

	if (list->head == NULL) {
		list->head = newNode;
		return;
	}

	cur = list->head;

	while (cur->next != NULL)
		cur = cur->next;

	cur->next = newNode;
}

void listRemoveValue(List *list, int value) {
	Node *cur = list->head, *prev = NULL;

	if (isEmptyList(list) == TRUE)
		return;

	if (isValueInList(list, value) == FALSE)
		return;

	if (list->head->value == value) {
		cur = list->head;
		list->head = list->head->next;
		wFree(cur);
		list->elemcount--;
		return;
	}

	while (cur != NULL) {
		if (cur->value == value) {
			prev->next = cur->next;
			wFree(cur);
			list->elemcount--;
			return;
		}

		prev = cur;
		cur = cur->next;
	}
}

int listRemoveIndex(List *list, int index) { // TODO
	return -1;
}

Boolean isValueInList(List *list, int value) {
	Node *cur = list->head;

	while (cur != NULL) {
		if (cur->value == value)
			return TRUE;

		cur = cur->next;
	}

	return FALSE;
}

int listIndex2Value(List *list, int index) { // TODO
	return -1;
}

int listHeadValue(List *list) {
	if (list->head == NULL)
		return -1;

	return list->head->value;
}

int listTailValue(List *list) { // TODO
	return -1;
}

void deleteListHelper(Node *n) {
	if (n == NULL)
		return;

	deleteListHelper(n->next);

	wFree(n);
}

void deleteList(List *list) {
	if (list == NULL)
		return;

	deleteListHelper(list->head);

	wFree(list);
}

void printList(List *list) {
	Node *cur = list->head;

	if (cur != NULL)
		printf("%d", cur->value);

	while (cur != NULL) {
		printf(",%d", cur->value);
	}
}
