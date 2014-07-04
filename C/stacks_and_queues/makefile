linked_list: ./linked_list.o ./3_6_sort_stack.o
	gcc -o 3_6_sort_stack 3_6_sort_stack.o ../linked_list/linked_list.o
3_6_sort_stack.o: ./3_6_sort_stack.c
	gcc -g -c ./3_6_sort_stack.c
linked_list.o:../linked_list/linked_list.c
	gcc -g -c ../linked_list/linked_list.c -o ../linked_list/linked_list.o
clean:
	rm *.o 3_6_sort_stack
