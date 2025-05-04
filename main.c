//
// Created by ivashneu andrei on 19.04.2025.
//

//9. Написать функцию, которая определяет, является ли бинарное дерево деревом
//поиска.

#include "functions.h"

int main(void) {
    printf("enter value for first MAIN node\n");
    int x;
    setNumber(&x);
    BinaryTree *tree = createBinaryTree(x);
    // МЕНЮШКА
    printf(
            "1 - add object in tree\n"
            "2 - delete some object in tree\n"
            "3 - find out, it is binary search tree or not\n"
            "4 - show binary tree\n"
            "5 - exit program\n"
    );
    while(1)
    {
        printf("what would you like to do\n");
        int ch = getch();
        switch(ch)
        {
            case '1':
                pushNodeInTree(tree);
                break;
            case '2':
                deleteNodeInTree(tree);
                break;
            case '3':
                isSearchTree(tree) == 1 ? printf("YES\n") : printf("NO\n");
                break;
            case '4':
                printf("here is your binary tree(values)\n");
                showTreeValues(tree, 0);
                break;
            case '5':
                return 0;
            default:
                printf("There is no this case, try again\n");
                continue;
        }
    }
}
