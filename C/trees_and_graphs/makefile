4_1_1: ./tree.o ./4_1_1_check_balanced.o
	gcc -o 4_1_1_check_balanced 4_1_1_check_balanced.o ./tree.o	
4_1_2: ./tree.o ./4_1_2_check_balanced.o
	gcc -o 4_1_2_check_balanced 4_1_2_check_balanced.o ./tree.o
4_2: ./tree.o ./4_2_find_path.o
	gcc -o 4_2_find_path 4_2_find_path.o ./tree.o
4_bst: ./tree.o ./4_bst.o
	gcc -o 4_bst 4_bst.o ./tree.o
4_3_minimal_bst: ./tree.o ./4_3_minimal_bst.o
	gcc -o 4_3_minimal_bst 4_3_minimal_bst.o ./tree.o
4_7_lca: ./tree.o ./4_7_lca.o
	gcc -o 4_7_lca 4_7_lca.o ./tree.o
4_root_to_key: ./tree.o ./4_root_to_key.o
	gcc -o 4_root_to_key 4_root_to_key.o ./tree.o
4_tree_to_dll: ./tree.o ./4_tree_to_dll.o
	gcc -o 4_tree_to_dll 4_tree_to_dll.o ./tree.o
4_reverse_nodes: ./tree.o ./4_reverse_nodes.o
	gcc -o 4_reverse_nodes 4_reverse_nodes.o ./tree.o

4_1_1_check_balanced.o: ./4_1_1_check_balanced.c
	gcc -g -c ./4_1_1_check_balanced.c -o 4_1_1_check_balanced.o
4_1_2_check_balanced.o: ./4_1_2_check_balanced.c
	gcc -g -c ./4_1_2_check_balanced.c -o 4_1_2_check_balanced.o
4_2_find_path.o: ./4_2_find_path.c
	gcc -g -c ./4_2_find_path.c -o 4_2_find_path.o
4_bst.o: ./4_bst.c
	gcc -g -c ./4_bst.c -o 4_bst.o
4_3_minimal_bst.o: ./4_3_minimal_bst.c
	gcc -g -c ./4_3_minimal_bst.c -o 4_3_minimal_bst.o
4_7_lca.o: ./4_7_lca.c
	gcc -g -c ./4_7_lca.c -o 4_7_lca.o
4_root_to_key.o: ./4_root_to_key.c
	gcc -g -c ./4_root_to_key.c -o 4_root_to_key.o
4_tree_to_dll.o: ./4_tree_to_dll.c
	gcc -g -c ./4_tree_to_dll.c -o 4_tree_to_dll.o
4_reverse_nodes.o: ./4_reverse_nodes.c
	gcc -g -c ./4_reverse_nodes.c -o 4_reverse_nodes.o
	
tree.o:./tree.c
	gcc -g -c ./tree.c -o ./tree.o
clean:
	rm *.o 4_1_1_check_balanced 4_1_2_check_balanced 4_2_find_path 4_bst 4_3_minimal_bst 4_7_lca 4_root_to_key
