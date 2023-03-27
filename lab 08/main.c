/*
 -------------------------------------------------------
 main.c
 Linked version of the BST ADT.
 -------------------------------------------------------
 Author:       Heider Ali/David Brown
 ID:           XXXXXXXXX
 Email:        heali@wlu.ca/dbrown@wlu.ca
 Modified Version:      2023-03-10
 -------------------------------------------------------
 */


#include <stdio.h>
#include <stdlib.h>

#include "avl_linked_simple.h"

#define SEP "-------------------------------\n"
#define SIZE 15

static void test_avl_linked() {
	printf("::::: Test avl_linked :::::\n");
	printf("===========================\n\n");
	printf(SEP);
	printf(":::> Inserting\n\n");
	int found = 0;
	int n     = SIZE;
	avl *tree = avl_initialize();

	for (int i = 1; i <= n; i++) {
		printf("Insert: [%d]\n", i);

		avl_insert(tree, i);

		printf("Valid : [%d]\n", avl_valid(tree));
		avl_preorder(tree);
	}

	printf("\n");
	printf(SEP);
	printf("Max:\n\n");
	printf("%d\n", avl_max(tree));

	printf(SEP);
	printf("Retrieve:\n\n");
	int value;

	for (int i = 1; i <= n; i++) {
		found = avl_retrieve(tree, i, &value);
		printf("Retrieve: %d - %d, %d\n", i, found, value);
	}
	found = avl_retrieve(tree, 99, &value);
	printf("Retrieve: %d - %d, %d\n", 99, found, value);

	printf(SEP);
	printf("Removing\n");

	for (int i = 1; i <= n; i++) {
		printf("Remove: %d\n", i);
		found = avl_remove(tree, i, &value);
		printf("Valid: %d\n", avl_valid(tree));
		avl_preorder(tree);
		printf("\n");
	}
	printf(SEP);
	avl_destroy(&tree);
	printf("tree: %p\n", tree);
	printf(SEP);
	printf("Done\n");
}

/**
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);
	test_avl_linked();
}
