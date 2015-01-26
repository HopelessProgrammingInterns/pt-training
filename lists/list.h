#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct list {
	struct list *next;
	struct list *prev;
	int data;
} list_t;

list_t *
list_prepend (list_t *list, int data) __attribute__((warn_unused_result));

list_t *
list_append(list_t *list, int data) __attribute__((warn_unused_result));

list_t *
list_insert(list_t *list, int data, int index) __attribute__((warn_unused_result));

list_t *
list_reverse(list_t *list) __attribute__((warn_unused_result));

list_t *
list_concat(list_t *first, list_t *second) __attribute__((warn_unused_result));

unsigned int
list_length(list_t *list);

int
list_get(list_t *list, int index);

list_t *
list_remove(list_t *list, int index) __attribute__((warn_unused_result));

void
list_foreach(list_t *list, void (*callback)(int data, int index));

#endif // LIST_H
