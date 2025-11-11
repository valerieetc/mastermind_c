all: my_mastermind

my_mastermind: my_mastermind.o functions.o
	gcc -Wall -Wextra -Werror -o my_mastermind my_mastermind.o functions.o

functions.o: functions.c
	gcc -Wall -Wextra -Werror -c functions.c

my_mastermind.o: my_mastermind.c
	gcc -Wall -Wextra -Werror -c my_mastermind.c

clean:
	rm -f *.o

fclean: clean
	rm -f my_mastermind

re: fclean all
