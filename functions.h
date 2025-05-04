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
void pushInTree(BinaryTree* tree, int num, int* currNum, int data, int side);
void pushNodeInTree(BinaryTree* tree);
void deleteInTree(BinaryTree* tree, int num, int* currNum);
void deleteNodeInTree(BinaryTree* tree);
void showTreeValues(BinaryTree* tree, int space);
int isSearchTree(BinaryTree* tree);
#endif //INC_7_FUNCTIONS_H
