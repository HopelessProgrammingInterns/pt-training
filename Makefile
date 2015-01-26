CFLAGS=-g
OUTDIR=bin

SRC = $(shell find . -iname "*.c")
OBJ = $(SRC:%.c=%.o)

$(OUTDIR)/%:
	@mkdir -p $(OUTDIR)
	$(CC) $(LOADLIBES) $(LDFLAGS) $^ -o $@

$(OUTDIR)/lists-test: lists/vector.o lists/list.o lists/test.o

clean:
	$(RM) $(OBJ)
	$(RM) -r $(OUTDIR)

