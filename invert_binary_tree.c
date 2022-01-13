#include <stdio.h>
#include <stdlib.h>

/**
 * Binary tree data structure
 */
struct Node {
    struct Node *left;
    int value;
    struct Node *right;
};

/**
 * Creates new binary tree node
 *
 * @param int value
 * @return Node*
 */
struct Node* new(int value)
{
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Inverts binary tree
 *
 * @param Node *node
 * @return void
 */
void invert(struct Node *node)
{
    if (node->left)
        invert(node->left);
    if (node->right)
        invert(node->right);

    struct Node *help = node->left;
    node->left = node->right;
    node->right = help;
}

/**
 * Generates indentation
 *
 * @param int size
 * @return void
 */
void tab(int size)
{
    for (int iterator = 0; iterator < size * 4; iterator++)
        putchar(' ');
}

/**
 * Uses simple visualizer similar to php print_r that shows tree content
 *
 * @param Node *node
 * @param int level
 * @return void
 */
void visualize(struct Node *node, int level)
{
    tab(level);
    printf("\033[3%im[\n", level);
    if (node->left)
        visualize(node->left, level+1);
    else
    {
        tab(level);
        tab(1);
        printf("NULL,\n");
    }
    
    tab(level);
    tab(1);
    printf("%i,\n", node->value);
    
    if (node->right)
        visualize(node->right, level+1);
    else
    {
        tab(level);
        tab(1);
        printf("NULL,\n");
    }
    tab(level);
    printf("],\033[3%im\n", level-1);
}

int main()
{
    struct Node *node = new(5);
    node->left = new(10);
    node->left->left = new(4);
    node->left->right = new(6);
    node->right = new(3);
    /*
    
        5
       / \
      10  3
     / \
    4   6

    */
    visualize(node, 1);
    invert(node);
    printf("\nINVERTED\n");
    visualize(node, 1);
}
