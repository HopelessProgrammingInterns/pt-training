#ifndef VECTOR_H
#define VECTOR_H

/**
 * the main list struct. it contains the data array and keeps track of the length,
 * that is the number of actually filled places in the array and the total size of
 * the array, that is the number of elements it can currently hold. As you run out of
 * space, you may need to get more by calling `realloc`.
 */
typedef struct {
	int *data;
	unsigned int capacity;
	unsigned int length;
} vector_t;

/**
 * allocates a new object of `vector_t` on the heap and returns a pointer to it
 */
vector_t *
vector_new();

/**
 * frees a previously allocated `vector_t` object again
 */
void
vector_free(vector_t *vec);

/**
 * prepend the given data to the very start of the list
 */
void
vector_prepend(vector_t *vec, int data);

/**
 * append the given data to the very end of the list
 */
void
vector_append(vector_t *vec, int data);

/**
 * insert the given data in the array at `index`
 */
void
vector_insert(vector_t *vec, int data, int index);

/**
 * reverse the order of all elements in the array
 */
void
vector_reverse(vector_t *vec);

/**
 * copy all elements from second after the end of first
 */
void
vector_concat(vector_t *first, vector_t *second);

/**
 * return the length of the vector
 */
unsigned int
vector_length(vector_t *vec);

/**
 * return the item in the vector at `index`
 */
int
vector_get(vector_t *vec, int index);

/**
 * remove the item in vector at `ìndex`
 */
void
vector_remove(vector_t *vec, int index);

/**
 * execute the given `callback` on each data item in the list, also passing
 * the index of the item in the list to the callback.
 */
void
vector_foreach(vector_t *vec, void (*callback)(int data, int index));

#endif // VECTOR_H
