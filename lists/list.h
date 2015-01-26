#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/**
 * the main list struct. each node contains a pointer to the next element in the
 * list and one to the previous element in the list, as well as the data.
 */
typedef struct list {
	struct list *next;
	struct list *prev;
	int data;
} list_t;

/**
 * insert the given data at the start of the list and return the start of the list
 */
list_t *
list_prepend (list_t *list, int data) __attribute__((warn_unused_result));

/**
 * append the given data to the end of the list and return the start of the list
 */
list_t *
list_append(list_t *list, int data) __attribute__((warn_unused_result));

/**
 * insert the given data at `index` in the list and return the start of the list
 */
list_t *
list_insert(list_t *list, int data, int index) __attribute__((warn_unused_result));

/**
 * reverse all elements of the list and return the new start of the list
 */
list_t *
list_reverse(list_t *list) __attribute__((warn_unused_result));

/**
 * add all elements of the second list to the first list without making a copy
 * and return the start of the list
 */
list_t *
list_concat(list_t *first, list_t *second) __attribute__((warn_unused_result));

/**
 * return the length of the list
 */
unsigned int
list_length(list_t *list);

/**
 * return the data at `index`
 */
int
list_get(list_t *list, int index);

/**
 * remove the node at `index` and return the start of the list
 */
list_t *
list_remove(list_t *list, int index) __attribute__((warn_unused_result));

/**
 * execute the given `callback` on each data item in the list, also passing
 * the index of the item in the list to the callback.
 */
void
list_foreach(list_t *list, void (*callback)(int data, int index));

#endif // LIST_H
