#include<stdlib.h>
#include<stdio.h>

typedef struct LListNode {
	struct LListNode *next;
	int value;
} LListNode;

typedef struct LList {
	LListNode *first;
	LListNode *last;
} LList;

// create a new LList
LList *llist_new() {
	LList *l = malloc(sizeof(LList));
	l->first = NULL;
	l->last = NULL;
	return l;
}

// create a new LList node.
// NOTE: this does not insert it into the LList anywhere
LListNode *llist_node_new(int v) {
	LListNode *n = malloc(sizeof(LListNode));
	n->next = NULL;
	n->value = v;
	return n;
}

// delete a LList node
void llist_node_delete(LListNode *n) {
	free(n);
}

// add a value at the end of a LList
void llist_append(LList *l, int v) {
	LListNode *n = llist_node_new(v);
	if(l->last) {
		l->last->next = n;
		l->last = n;
	} else { // no items in list
		l->first = n;
		l->last = n;	
	}
}

// remove a value from a LList
void llist_remove(LList *l, int index) {
	LListNode *before = NULL;
	LListNode *n = l->first;

	// traverse list until we find the Nth node (at index).
	for(int i = 0; i < index; i++) {
		before = n;
		n = n->next;
	}

	// make sure first pointer is valid, if N is first.
	if(l->first == n) {
		l->first = n->next;
	}

	// make sure last pointer is valid, if N is last.
	if(l->last == n) {
		l->last = before;
	}

	// pull N out of the list. Make sure the node before N points to the
	// node after N.
	if(before != NULL) {
		before->next = n->next;
	}
	llist_node_delete(n);
}

// delete the entire LList
void llist_delete(LList *l) {
	while(l->first) {
		llist_remove(l, 0);
	}
	free(l);
}

// get a value from the LList
int llist_get(LList *l, int index) {
	LListNode *n = l->first;
	for(int i = 0; i < index; i++) {
		n = n->next;
	}
	return n->value;
}

// get the length of a LList
int llist_length(LList *l) {
	int len = 0;
	LListNode *n = l->first;
	while(n != NULL) {
		n = n->next;
		len++;
	}
	return len;
}

int main(int argc, char **argv) {
	LList *l = llist_new();
	llist_append(l, 1);
	llist_append(l, 5);
	llist_append(l, 10);
	llist_remove(l, 1);
	llist_append(l, 15);

	for(int i = 0; i < llist_length(l); i++) {
		printf("%d\n", llist_get(l, i));
	}

	llist_delete(l);
	return 0;
}
