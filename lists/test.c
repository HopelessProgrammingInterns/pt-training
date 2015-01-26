#include <stdio.h>
#include <assert.h>

#define USE_VECTOR 1

#if USE_VECTOR
	#include "vector.h"
	#define LIST_TYPE vector_t
	#define TEST_OP(op, obj) vector_## op
	#define TEST_VAL(op) vector_## op
#else
	#include "list.h"
	#define LIST_TYPE list_t
	#define TEST_OP(op, obj) obj = list_## op
	#define TEST_VAL(op) list_## op
#endif


void print_data(int data, int index)
{
	printf("%i -> %i\n", index, data);
}

void print_list(LIST_TYPE *list)
{
	printf(">>>> List contents:\n");
	TEST_VAL(foreach)(list, &print_data);
	printf("\n");
}

int main(int argc, char **argv)
{
	puts("Constructing list objects ...");
	LIST_TYPE *list = NULL, *other_list = NULL;
#if USE_VECTOR
	list = vector_new();
	other_list = vector_new();
#endif

	puts("Testing length ...");
	assert(TEST_VAL(length)(list) == 0);

	puts("Testing prepend with empty list ...");
	TEST_OP(prepend, list)(list, 5);
	assert(TEST_VAL(length)(list) == 1);
	puts("Testing get ...");
	assert(TEST_VAL(get)(list, 0) == 5);

	puts("Testing prepend ...");
	TEST_OP(prepend, list)(list, 6);
	assert(TEST_VAL(length)(list) == 2);
	assert(TEST_VAL(get)(list, 0) == 6);
	assert(TEST_VAL(get)(list, 1) == 5);

	puts("Testing insert ...");
	TEST_OP(insert, list)(list, 7, 1);
	assert(TEST_VAL(length)(list) == 3);
	assert(TEST_VAL(get)(list, 0) == 6);
	assert(TEST_VAL(get)(list, 1) == 7);
	assert(TEST_VAL(get)(list, 2) == 5);

	puts("Testing append ...");
	TEST_OP(append, list)(list, 8);
	assert(TEST_VAL(length)(list) == 4);
	assert(TEST_VAL(get)(list, 0) == 6);
	assert(TEST_VAL(get)(list, 1) == 7);
	assert(TEST_VAL(get)(list, 2) == 5);
	assert(TEST_VAL(get)(list, 3) == 8);

	puts("Testing remove ...");
	TEST_OP(remove, list)(list, 2);
	assert(TEST_VAL(length)(list) == 3);
	assert(TEST_VAL(get)(list, 0) == 6);
	assert(TEST_VAL(get)(list, 1) == 7);
	assert(TEST_VAL(get)(list, 2) == 8);

	puts("Testing reverse ...");
	TEST_OP(reverse, list)(list);
	assert(TEST_VAL(get)(list, 0) == 8);
	assert(TEST_VAL(get)(list, 1) == 7);
	assert(TEST_VAL(get)(list, 2) == 6);

	puts("Testing remove at 0 ...");
	TEST_OP(remove, list)(list, 0);
	assert(TEST_VAL(length)(list) == 2);
	assert(TEST_VAL(get)(list, 0) == 7);
	assert(TEST_VAL(get)(list, 1) == 6);

	puts("Testing append on empty list ...");
	TEST_OP(append, other_list)(other_list, 1);
	assert(TEST_VAL(length)(other_list) == 1);
	assert(TEST_VAL(get)(other_list, 0) == 1);

	puts("Testing removing to empty list ...");
	TEST_OP(remove, other_list)(other_list, 0);
	assert(TEST_VAL(length)(other_list) == 0);

	puts("Testing insert to empty list ...");
	TEST_OP(insert, other_list)(other_list, 1, 0);
	assert(TEST_VAL(length)(other_list) == 1);
	assert(TEST_VAL(get)(other_list, 0) == 1);

	puts("Testing append ...");
	TEST_OP(append, other_list)(other_list, 2);
	assert(TEST_VAL(length)(other_list) == 2);
	assert(TEST_VAL(get)(other_list, 0) == 1);
	assert(TEST_VAL(get)(other_list, 1) == 2);

	puts("Testing concat ...");
	TEST_OP(concat, list)(list, other_list);
	assert(TEST_VAL(length)(list) == 4);
	assert(TEST_VAL(get)(list, 0) == 7);
	assert(TEST_VAL(get)(list, 1) == 6);
	assert(TEST_VAL(get)(list, 2) == 1);
	assert(TEST_VAL(get)(list, 3) == 2);

	printf("All tests passed successfully!\n");

#if USE_VECTOR
	vector_free(list);
	vector_free(other_list);
#endif
}
