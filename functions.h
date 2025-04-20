//
// Created by intak on 19.04.2025.
//

#ifndef INC_7_FUNCTIONS_H
#define INC_7_FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <limits.h>
//#include <string.h>
//#include <ctype.h>

#include "BinaryTree.h"


void setNumber(int* number);
BinaryTree* createBinaryTree(int value);
void showBinaryTree(BinaryTree* tree, int space, int* size);
void push(BinaryTree* tree, int num, int* currNum, int data, int side);
void pushNode(BinaryTree* tree);
void delete(BinaryTree* tree, int num, int* currNum);
void deleteNode(BinaryTree* tree);
void showTreeValues(BinaryTree* tree, int space);
int isSearchTree(BinaryTree* tree);
#endif //INC_7_FUNCTIONS_H
