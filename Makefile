all:
	gcc -lm main.c list.c prng.c -o test

clean:
	rm -vrf ./~*