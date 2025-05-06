//
// Created by intak on 19.04.2025.
//

#ifndef INC_7_FUNCTIONS_H
#define INC_7_FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include <time.h>
#include <Windows.h>
//#include <string.h>
//#include <ctype.h>

#include "BinaryTree.h"


void setNumber(int* number);
Node* createNode(int value);
Node* createRandomBinaryTree();
Node* generateRandomTree(int n);
void visualizeRecursive(Node* node, const char* prefix, int isLeft, int isLast);
void visualizeTree(Node* root);
int findNodeAndParent(Node* root, int target, Node** result, Node** parent);
Node* findReplacement(Node* root);
Node* deleteNode(Node* tree, int value);
Node* deleteNodeInTree(Node* tree);
int isST(Node* node, long min, long max);
int isSearchTree(Node* tree);
void freeTree(Node* root);
#endif //INC_7_FUNCTIONS_H
