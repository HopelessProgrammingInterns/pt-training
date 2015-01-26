Lists
=====

This is the training area for lists. In lists.c, you may implement a [doubly-linked list](http://www.wikiwand.com/en/Doubly_linked_list) based on the interface defined in `list.h`.

There's also an interface for a C++ STL-vector type list, which uses an array that is resized as needed instead of linking to the next element every time. To test your implementation, open `test.c` and change `USE_VECTOR` at the very top to:
```
#define USE_VECTOR 1
```

The test suite won't guarantee that you have a perfectly working implementation, but it will test quite a few cases.

Building
========

After having configured whether you want to test vectors or lists in test.c, run `make bin/lists-test` in the project's main directory. Then run `./bin/lists-test`. If a test fails, it will show you a failed assertion and which test exactly failed, including the line in test.c, so you may check it out a little closer.

More Debugging
==============

There's also a `print_list` method in test.c, which you may insert at any point in test.c to see more details, e.g.
```
  [...]
  print_list(other_list);
  [...]
```

I can't get it to work D:
=========================

We have solutions in the `solution/` and a helpful channel on slack.
