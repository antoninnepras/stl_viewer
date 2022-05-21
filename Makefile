CC 		= gcc
CFLAGS	= -Wall -g
LSFLAGS = -lGL -lglut -lm
TARGET 	= main

CFILES  = $(wildcard src/*.c)
OBJECTS = $(patsubst %.c,%.o,$(CFILES))
HEADERS = $(wildcard src/*.h)

CFILES += main.c 

all: $(TARGET)

objects: $(OBJECTS)


$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LSFLAGS) $(OBJECTS) -o $(TARGET)


$(OBJECTS): $(CFILES) $(HEADERS)
	$(CC) $(CFLAGS) $(LSFLAGS) $(patsubst %.o,%.c,$@) -c
	@if [ "$@" != "$(TARGET).o" ]; then\
		mv -f $(patsubst src/%,%,$@) $@;\
	fi


clean:
	rm -rf *.o $(TARGET)
	rm -rf src/*o 


run:
	./$(TARGET)

val:
	valgrind ./$(TARGET)
