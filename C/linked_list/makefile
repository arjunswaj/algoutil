linked_list: ./linked_list.o ./number_op.o
	gcc -o linked_list number_op.o linked_list.o
number_op.o: ./number_op.c
	gcc -g -c ./number_op.c
linked_list.o:./linked_list.c
	gcc -g -c ./linked_list.c -o linked_list.o
clean:
	rm *.o linked_list
