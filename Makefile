all: clean
	gcc thread.c -o thread
	gcc raw.c -o raw

clean:
	rm -rf raw thread
