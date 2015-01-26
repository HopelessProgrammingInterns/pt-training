#include "list.h"

list_t *
list_prepend(list_t *list, int data)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	new->prev = NULL;
	new->next = list;
	new->data = data;

	if (list)
		list->prev = new;

	return new;
}

list_t *
list_append(list_t *list, int data)
{
	list_t *it, *new;

	new = malloc(sizeof(list_t));
	new->data = data;
	new->next = NULL;

	if (!list) {
		new->prev = NULL;
		return new;
	}

	for (it = list; it->next; it = it->next)
		;

	new->prev = it;
	it->next = new;

	return list;
}

list_t *
list_insert(list_t *list, int data, int index)
{
	list_t *new, *it;

	new = malloc(sizeof(list_t));
	new->data = data;

	for (it = list; index > 0; it = it->next) {
		index--;
	}

	if (it)
		new->prev = it->prev;
	else
		list = new;

	new->next = it;

	if (it && it->prev)
		it->prev->next = new;
	else
		list = new;

	if (it)
		it->prev = new;

	return list;
}

unsigned int
list_length(list_t *list)
{
	unsigned int len = 0;

	for (; list; list = list->next) {
		len++;
	}

	return len;
}

list_t *
list_reverse(list_t *list)
{
	list_t *tmp;

	while (list) {
		tmp = list->prev;
		list->prev = list->next;
		list->next = tmp;
		list = list->prev;
	}

	// that's now reversed and "sort of actually" tmp->next
	return tmp->prev;
}

int
list_get(list_t *list, int index)
{
	for (; index > 0; list = list->next) {
		index--;
	}

	return list->data;
}

list_t *
list_remove(list_t *list, int index)
{
	list_t *it;

	for (it = list; index > 0; it = it->next) {
		index--;
	}

	if (it->prev)
		it->prev->next = it->next;
	else
		list = it->next;

	if (it->next)
		it->next->prev = it->prev;

	free(it);

	return list;
}

static list_t *
list_last(list_t *list)
{
	if (list) {
		while (list->next)
			list = list->next;
	}

	return list;
}

list_t *
list_concat(list_t *first, list_t *second)
{
	list_t *first_end;

	first_end = list_last(first);
	first_end->next = second;
	second->prev = first_end;

	return first;
}

void
list_foreach(list_t *list, void (callback)(int data, int index))
{
	int i = 0;
	for (; list; list = list->next) {
		callback(list->data, i++);
	}
}
