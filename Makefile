CC = gcc
CFLAGS = -g -Wall

OBJS = main.o scan.o data.o tree.o expr.o interp.o gen.o cg.o

scanner: $(OBJS)
	$(CC) $(CFLAGS) -o scanner $(OBJS)

%.o: %.c def.h decl.h data.h
	$(CC) $(CFLAGS) -c $<

test:
	for f in test/test1/*; do \
		echo "Running $$f"; \
		./scanner $$f; \
	done

clean:
	rm -f scanner *.o

.PHONY: test clean