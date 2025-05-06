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

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){exit(1);}
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* createRandomBinaryTree()
{
    Node *tree;
    printf("enter how many nodes will be in your binary tree\n");
    int N;
    setNumber(&N);
    tree = generateRandomTree(N);
}
Node* generateRandomTree(int n)
{
    if(n <= 0) {return NULL;}


    srand(time(NULL));

    Node *tree = createNode(rand() % 10);
    n--;

    if(n == 0){return tree;}

    // массив доступных узлов
    Node** available = (Node**)malloc(n * sizeof(Node*));
    int availSize = 0;

    available[availSize++] = tree;

    for (int i = 0; i < n; i++) {
        int parentIdx = rand() % availSize;
        Node* parent = available[parentIdx];

        int canLeft = !parent->left;
        int canRight = !parent->right;

        if(canLeft + canRight == 0){continue;}

        char dir;
        if(canLeft && canRight) {
            dir = rand() % 2 ? 'L' : 'R';
        }
        else{
            dir = canLeft ? 'L' : 'R';
        }

        Node* newNode = createNode(rand() % 100);

        if(dir == 'L') {
            parent->left = newNode;
        }
        else{
            parent->right = newNode;
        }

        if(parent->left && parent->right) {
            available[parentIdx] = available[--availSize];
        }
        available[availSize++] = newNode;
    }
    free(available);
    return tree;
}

void visualizeRecursive(Node* node, const char* prefix, int isLeft, int isLast)
{
    if (node == NULL) return;

    // выводим текущий узел
    printf("%s", prefix);
    printf(isLast ? "└── " : "├── ");
    printf("%d\n", node->value);

    // формируем новый префикс
    char newPrefix[256];
    snprintf(newPrefix, sizeof(newPrefix), "%s%s    ",
             prefix, (isLast ? " " : "│   "));

    if(node->left){
        visualizeRecursive(node->left, newPrefix, 1, !node->right);
    }
    if(node->right){
        visualizeRecursive(node->right, newPrefix, 0, 1);
    }
}

void visualizeTree(Node* root)
{
    if (root == NULL) {
        printf("BINARY TREE IS EMPTYYYYYYYYYY!\n");
        return;
    }

    printf("%d\n", root->value);

    char prefix[256] = "";
    if (root->right) {
        visualizeRecursive(root->left, prefix, 1, !root->right);
        visualizeRecursive(root->right, prefix, 0, 1);
    }
    else if (root->left) {
        visualizeRecursive(root->left, prefix, 1, 1);
    }
}

int findNodeAndParent(Node* root, int target, Node** result, Node** parent) {
    if (root == NULL) return 0;

    if (root->value == target) {
        *result = root;
        return 1;
    }

    if (findNodeAndParent(root->left, target, result, parent)) {
        if (*parent == NULL) *parent = root;
        return 1;
    }

    if (findNodeAndParent(root->right, target, result, parent)) {
        if (*parent == NULL) *parent = root;
        return 1;
    }

    return 0;
}

// Функция для поиска замены
Node* findReplacement(Node* root) {
    if (root == NULL) return NULL;

    if (root->right)
        return findReplacement(root->right);
    else if (root->left)
        return findReplacement(root->left);
    else
        return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) {return NULL;}

    Node* toDelete = NULL;
    Node* parent = NULL;

    // Поиск удаляемого узла и его родителя
    if(root->value == value){
        toDelete = root;
    }
    else{
        findNodeAndParent(root, value, &toDelete, &parent);
    }

    if(toDelete == NULL){
        printf("Node %d not found!\n", value);
        return root;
    }

    Node* replacement = findReplacement(toDelete);
    if (replacement == toDelete) replacement = NULL;

    // Если есть замена - копируем значение
    if (replacement) {
        int newValue = replacement->value;
        root = deleteNode(root, replacement->value);
        toDelete->value = newValue;
        return root;
    }

    // Нет замены - удаляем узел
    if (parent) {
        if (parent->left == toDelete)
            parent->left = NULL;
        else
            parent->right = NULL;
    } else {
        root = NULL;
    }

    free(toDelete);
    return root;
}

Node* deleteNodeInTree(Node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return NULL;
    }

    visualizeTree(root);
    printf("Enter value to delete: ");
    int val;
    setNumber(&val);

    Node* newRoot = deleteNode(root, val);
    return newRoot;
}

int isST(Node* node, long min, long max) {
    if (node == NULL) return 1;

    if (node->value <= min || node->value >= max)
        return 0;

    return isST(node->left, min, node->value) &&
           isST(node->right, node->value, max);
}

int isSearchTree(Node* root) {
    return isST(root, LONG_MIN, LONG_MAX);
}
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
