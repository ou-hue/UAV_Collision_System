CC = gcc
CFLAGS = -Wall -Wextra -O2 -lm
TARGET = collision_system

all: $(TARGET)

$(TARGET): main.o collision_system.o
	$(CC) -o $(TARGET) main.o collision_system.o -lm

main.o: main.c collision_system.h
	$(CC) -c main.c $(CFLAGS)

collision_system.o: collision_system.c collision_system.h
	$(CC) -c collision_system.c $(CFLAGS)

clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)
