main : main.o modify_config.o
	gcc -o main main.o modify_config.o
main.o : main.c modify_config.h
	gcc -c main.c
modify_config.o : modify_config.c modify_config.h
	gcc -c modify_config.c
clean:
	-rm *.o
	-rm ./tmp/*
