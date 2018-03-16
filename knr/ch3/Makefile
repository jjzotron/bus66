CLFAGS=-Weverything -Werror -pedantic -fno-strict-aliasing -Wstrict-overflow
SOURCES=$(wildcard *.c)
OBJECTS=$(patsubst %.c, %, $(SOURCES))

all: $(OBJECTS)

%:%.c
	cc $< $(CLFAGS) -o $@.out

clean:
	rm *.out
