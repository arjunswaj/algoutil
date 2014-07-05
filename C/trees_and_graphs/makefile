4_1_1: ./tree.o ./4_1_1_check_balanced.o
	gcc -o 4_1_1_check_balanced 4_1_1_check_balanced.o ./tree.o	
4_1_2: ./tree.o ./4_1_2_check_balanced.o
	gcc -o 4_1_2_check_balanced 4_1_2_check_balanced.o ./tree.o
4_2: ./tree.o ./4_2_find_path.o
	gcc -o 4_2_find_path 4_2_find_path.o ./tree.o
4_bst: ./tree.o ./4_bst.o
	gcc -o 4_bst 4_bst.o ./tree.o

4_1_1_check_balanced.o: ./4_1_1_check_balanced.c
	gcc -g -c ./4_1_1_check_balanced.c -o 4_1_1_check_balanced.o
4_1_2_check_balanced.o: ./4_1_2_check_balanced.c
	gcc -g -c ./4_1_2_check_balanced.c -o 4_1_2_check_balanced.o
4_2_find_path.o: ./4_2_find_path.c
	gcc -g -c ./4_2_find_path.c -o 4_2_find_path.o
4_bst.o: ./4_bst.c
	gcc -g -c ./4_bst.c -o 4_bst.o

tree.o:./tree.c
	gcc -g -c ./tree.c -o ./tree.o
clean:
	rm *.o 4_1_1_check_balanced 4_1_2_check_balanced 4_2_find_path
