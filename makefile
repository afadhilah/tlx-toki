CC = gcc
CFLAGS = -Wall
TARGET = program
SRCS = src/main.c src/KompetitifDasar/01/A.c src/KompetitifDasar/01/P1.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
