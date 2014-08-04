linked_list: ./linked_list.o ./number_op.o
	gcc -o linked_list number_op.o linked_list.o
lld:  ./linked_list.o ./linked_list_driver.o
	gcc -o lld linked_list_driver.o linked_list.o

number_op.o: ./number_op.c
	gcc -g -c ./number_op.c
linked_list.o:./linked_list.c
	gcc -g -c ./linked_list.c -o linked_list.o

linked_list_driver.o:./linked_list_driver.c
	gcc -g -c ./linked_list_driver.c -o linked_list_driver.o
clean:
	rm *.o linked_list
