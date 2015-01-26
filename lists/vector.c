#include "vector.h"

#include <stdlib.h>

vector_t *
vector_new()
{
	return NULL;
}

void
vector_free(vector_t *vec)
{
}

void
vector_prepend(vector_t *vec, int data)
{
}

void
vector_append(vector_t *vec, int data)
{
}

void
vector_insert(vector_t *vec, int data, int index)
{
}

void
vector_reverse(vector_t *vec)
{
}

void
vector_concat(vector_t *first, vector_t *second)
{
}

unsigned int
vector_length(vector_t *vec)
{
	return 0;
}

int
vector_get(vector_t *vec, int index)
{
	return 0;
}

void
vector_remove(vector_t *vec, int index)
{
}

void
vector_foreach(vector_t *vec, void (*callback)(int data, int index))
{
}

