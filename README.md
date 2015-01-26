PT Training Playground!
=======================

Come closer and check out all the nice playgrounds for your training pleasure found in those nifty sub directories. Each even contains its own README telling you more about it!

## On Contributing

For your own training area, place a new subfolder in the project, which ideally contains a `README.md` detailling the task and a `solutions` directory containing the solutions to the task. Lastly, just add
```
$(OUTDIR)/your-folder-test: your-folder/source.c your-folder/source2.c your-folder/test.c
```
 to the `Makefile` below the other entries of that schema (Do include the `-test`, otherwise we hit weirdnesses with make). A `test.c` file, checking whether the task has successfully been solved, is greatly appreciated as well.
