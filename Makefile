
all: myshell

myshell: myshell.o utility.o
		gcc  myshell.c utility.c -o myshell

myshell.o: myshell.c
		   gcc -c myshell.c
utility.o: utility.c
		   gcc -c utility.c

clean:
		rm -rf *o myshell
