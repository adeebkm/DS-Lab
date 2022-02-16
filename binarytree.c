#include <stdio.h>
#include <stdlib.h>

typedef struct BT
{
    struct BT *right;
    int data;
    struct BT *left;
} BT;

int count = 0;

BT *inorder(BT *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}

BT *preorder(BT *root)
{
    if (root == NULL)
        return;
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

BT *postorder(BT *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

BT *createnode(int value)
{
    BT *newnode = (BT *)malloc(sizeof(BT));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    count++;
    return newnode;
}

void display(BT *root, int i)
{
    int j;
    if (root == NULL)
        return;
    display(root->right, i + 1);
    for (j = 1; j <= i; j++)
        printf("\t");
    printf("%d (%d:%d)\n", root->data, i, j);
    display(root->left, i + 1);
}

BT *createtree()
{
    int chk, value;
    printf("would you like to add a node:1)yes  2)no\n");
    scanf("%d", &chk);
    if (chk == 2)
        return NULL;
    printf("enter value of node\n");
    scanf("%d", &value);

    BT *ptr = createnode(value);
    printf("enter left node\n");
    ptr->left = createtree(ptr->left);

    printf("enter right node\n");
    ptr->right = createtree(ptr->right);
    return ptr;
}

void main()
{
    BT *root = NULL;
    int choice;
    while (1)
    {
        printf("\n Binary tree operations");
        printf("\n1)create");
        printf("\n2)inorder");
        printf("\n3)preorder");
        printf("\n4)postorder");
        printf("\n5)display");
        printf("\n6)exit");
        printf("enter chouice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = createtree();
            break;
        case 2:
            printf("\n inorder traversal \n");
            inorder(root);
            break;
        case 3:
            printf("\n preorder traversal \n");
            preorder(root);
            break;
        case 5:
            display(root, 1);
            break;
        default:
            printf("\ninvalid option");
            break;
        }
    }
}
