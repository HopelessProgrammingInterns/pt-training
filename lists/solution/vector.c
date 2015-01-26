#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 32

static void
vector_allocate(vector_t *vec)
{
	vec->data = realloc(vec->data, vec->capacity * sizeof(int));
}

static void
vector_ensure(vector_t *vec)
{
	if (vec->length > vec->capacity) {
		vec->capacity *= 2;
		vector_allocate(vec);
	} else if (vec->length < vec->capacity / 4) {
		vec->capacity /= 2;
		vector_allocate(vec);
	}
}

vector_t *
vector_new()
{
	vector_t *vec;

	vec = malloc(sizeof(vector_t));
	vec->capacity = INITIAL_SIZE;
	vec->length = 0;
	vector_allocate(vec);

	return vec;
}

void
vector_free(vector_t *vec)
{
	free(vec);
}

void
vector_prepend(vector_t *vec, int data)
{
	unsigned int len = vec->length;

	vec->length++;
	vector_ensure(vec);

	memmove(vec->data + 1, vec->data, len * sizeof(int));
	vec->data[0] = data;
}

void
vector_append(vector_t *vec, int data)
{
	unsigned int len = vec->length;

	vec->length++;
	vector_ensure(vec);

	vec->data[len] = data;
}

void
vector_insert(vector_t *vec, int data, int index)
{
	unsigned int len = vec->length;
	vec->length++;
	vector_ensure(vec);

	memmove(vec->data + index + 1, vec->data + index, (len - index) * sizeof(int));
	vec->data[index] = data;
}

void
vector_reverse(vector_t *vec)
{
	int tmp, i, len;

	len = vec->length / 2;

	for (i = 0; i < len; i++) {
		tmp = vec->data[i];
		vec->data[i] = vec->data[vec->length - i - 1];
		vec->data[vec->length - i - 1] = tmp;
	}
}

void
vector_concat(vector_t *first, vector_t *second)
{
	unsigned int first_len = first->length;

	first->length += second->length;
	vector_ensure(first);

	memcpy(first->data + first_len, second->data, second->length * sizeof(int));
}

unsigned int
vector_length(vector_t *vec)
{
	return vec->length;
}

int
vector_get(vector_t *vec, int index)
{
	return vec->data[index];
}

void
vector_remove(vector_t *vec, int index)
{
	vec->length--;
	vector_ensure(vec);

	memmove(vec->data + index, vec->data + index + 1, (vec->length - index) * sizeof(int));
}

void
vector_foreach(vector_t *vec, void (*callback)(int data, int index))
{
	int i;

	for (i = 0; i < vec->length; i++) {
		callback(vec->data[i], i);
	}
}

