//
// Created by intak on 19.04.2025.
//

#include "functions.h"

void setNumber(int* number)
{
    int inputValid;
    do{
        *number = 0;
        int digit;
        inputValid = 1;
        int isNegative = 1, isEmpty = 1;

        while ((digit = getchar()) != '\n' && digit != ' ') {
            if(digit == '-' && *number == 0) {
                isNegative = -1;
            }
            else if (digit < '0' || digit > '9') {
                printf("Incorrect input. Only digits are allowed.\n");
                inputValid = 0;
                while ((digit = getchar()) != '\n' && digit != ' ');
                break;
            }
            else {
                if (*number > (INT_MAX - (digit - '0')) / 10) {
                    printf("Number is too large. Maximum value is %d.\n", INT_MAX);
                    inputValid = 0;
                    while ((digit = getchar()) != '\n' && digit != ' ');
                    break;
                }
                isEmpty = 0;
                *number = *number * 10 + (digit - '0');
            }
        }

        if (isEmpty){
            printf("Empty enter\n");
            inputValid = 0;
        }

        if (!inputValid)
            *number = 0;

        if (digit != '\n'){
            printf("You need to write only one number\n");
            inputValid = 0;
            while ((digit = getchar()) != '\n');
        }
        *number *=isNegative;
    }while(inputValid == 0);
}

BinaryTree* createBinaryTree(int value) {
    BinaryTree *tree = (BinaryTree *) malloc(sizeof(BinaryTree));
    if (tree == NULL) {
        printf("malloc failed\n");
        return NULL;
    }
    tree->value = value;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}
void showBinaryTree(BinaryTree* tree, int space, int* size)
{
    if (tree == NULL){return;}

    space += 5;
    showBinaryTree(tree->right, space, size);
    (*size)++;
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");

    printf("%d\n", *size);

    showBinaryTree(tree->left, space, size);
}
void showTreeValues(BinaryTree* tree, int space)
{
    if (tree == NULL){return;}

    space += 5;
    showTreeValues(tree->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");

    printf("%d\n", tree->value);

    showTreeValues(tree->left, space);
}
void pushNodeInTree(BinaryTree* tree)
{
    int currNum = 0;
    printf("here is your binary tree(nums)\n");
    showBinaryTree(tree, 0, &currNum);
    printf("Enter value for the new node\n");
    int data;
    setNumber(&data);
    printf("Choose node where you will add new node\n");
    int num;
    setNumber(&num);
    printf("Choose side(LEFT = 1, RIGHT = 2)");
    int side;
    setNumber(&side);

    currNum = 0;
    pushInTree(tree, num, &currNum, data, side);
}
void pushInTree(BinaryTree* tree, int num, int* currNum, int data, int side)
{
    if(tree == NULL){return;}

    pushInTree(tree->right, num, currNum, data, side);
    (*currNum)++;
    if(num == *currNum){
        if(side == 1){
            tree->left = createBinaryTree(data);
        }
        if(side == 2){
            tree->right = createBinaryTree(data);
        }
        return;
    }
        pushInTree(tree->left, num, currNum, data, side);
}
void deleteNodeInTree(BinaryTree* tree)
{
    int currNum = 0;
    showBinaryTree(tree, 0, &currNum);
    printf("Choose node that you will delete\n");
    int num;
    setNumber(&num);
    currNum = 0;
    deleteInTree(tree, num, &currNum);
}
void deleteInTree(BinaryTree* tree, int num, int* currNum)
{
    if(tree == NULL){return;}

    deleteInTree(tree->right, num, currNum);
    (*currNum)++;
    if(num == *currNum){
        free(tree->left);
        free(tree->right);
        tree = NULL;
        return;
    }
    deleteInTree(tree->left, num, currNum);
}
int isSearchTree(BinaryTree* tree)
{
    if(tree == NULL){return 1;}
    if(tree->left != NULL &&
    (tree->left->value > tree->value || tree->right->value < tree->value)){
        return 0;
    }
    return isSearchTree(tree->left) & isSearchTree(tree->right);
}