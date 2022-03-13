gcc:
	gcc -g -Wall -o main *.c
run:
	./main
gdb:
	gdb ./main
clean:
	rm main