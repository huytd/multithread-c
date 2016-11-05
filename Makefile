all: clean
	gcc thread.c -o thread -lpthread
	gcc raw.c -o raw

clean:
	rm -rf raw thread
