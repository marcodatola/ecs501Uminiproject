CC=gcc
OBJECTS=structs.o queueListLib.o headsListLib.o rulesFromFile.o router.o
DEPS=structs.h queueListLib.h headsListLib.h rulesFromFile.h router.h

all: main.c $(OBJECTS)
	$(CC) -g -o ecs501u main.c $(OBJECTS)
#look for all relevant .c files in directory for the .o
%.o: %.c $(DEPS)
	$(CC) -c $<
