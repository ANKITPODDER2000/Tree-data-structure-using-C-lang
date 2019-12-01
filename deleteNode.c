#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tree{
    int value;
    struct tree *left, *right;
} BT;

//Function Prototype
BT* create(int );
void insert(BT **, int);
void inOrder(BT *);
BT* inOrderNode(BT *);
BT* delete (BT *, int);

BT *root = NULL;

int main()
{
    int op, val;
    system("cls");
    while (1)
    {
        printf("\nEnter 1 -> Insert a Node \nEnter 2 -> Delete a Node\nEnter 3->InOrder Traversal\nEnter 4->Exit\nEnter the Operation  : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the value to Insert : ");
            scanf("%d", &val);
            insert(&root, val);
            break;
        case 2:
            printf("\nEnter any key to delete : ");
            scanf("%d", &val);
            root = delete (root, val);
            break;
        case 3:
            printf("\nInOrder of the tree is : ");
            inOrder(root);
            break;
        case 4:
            printf("\nEnd of Program.");
            exit(0);
        }
        printf("\nEnter any key to continue : ");
        getch();
        system("cls");
    }
}
//Insert a New node in BST
void insert(BT **root, int val)
{

    if (*root == NULL)
    {
        *root = create(val);
        return;
    }
    else if ((*root)->value > val)
        insert(&((*root)->left), val);
    else
        insert(&((*root)->right), val);
}
//Create a node with specific value
BT *create(int val)
{
    BT *new_node = (BT *)malloc(sizeof(BT));
    new_node->value = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
//Traverse the Tree in InOrder Pattern
void inOrder(BT *root){
    if (root!=NULL){
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}
//Find the InOrder Element of the Deleted element 
BT* inOrderNode(BT *root){
    if(root==NULL)
        return NULL;
    while(root->left != NULL)
        root = root->left;
    return root;
}

BT* delete(BT *root,int val){
    BT *temp;
    if(root==NULL)
        return NULL;
    if(root->value > val)
        root->left = delete (root->left, val);
    else if (root->value < val)
        root->right = delete (root->right, val);
    else{
        //Delete a node if it has no child or One child
        if (root->left == NULL || root->right == NULL)
        {
            if(root->right){
                temp = root->right;
                free(root);
                return temp;
            }
            else if(root->left){
                temp = root->left;
                free(root);
                return temp;
            }
            return NULL;
        }
        temp = inOrderNode(root->right);
        temp->left = root->left;
        root = temp;
        root->right = delete (root->right, temp->value);
    }
}