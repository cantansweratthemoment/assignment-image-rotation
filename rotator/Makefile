CFLAGS=--std=c18 -Wall -pedantic -Isrc/ -ggdb -Wextra -Werror -DDEBUG
CC=gcc

all: rotate-image

bmp-worker.o: bmp-worker.c
	$(CC) -c $(CFLAGS) $< -o $@

image.o: image.c
	$(CC) -c $(CFLAGS) $< -o $@

logger.o: logger.c
	$(CC) -c $(CFLAGS) $< -o $@

main.o: main.c
	$(CC) -c $(CFLAGS) $< -o $@

file-worker.o: file-worker.c
	$(CC) -c $(CFLAGS) $< -o $@

header.o: header.c
	$(CC) -c $(CFLAGS) $< -o $@

rotate-image: main.o logger.o bmp-worker.o image.c file-worker.o header.o
	$(CC) -o rotate-image $^

clean:
	rm -f main.o logger.o bmp-worker.o image.c file-worker.o header.o rotate-image
