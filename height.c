#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct tree{
    int value;
    struct tree *left, *right;
} BT;

BT *create(int);
void insert(BT **, int);
int printHeight(BT *);

BT *root = NULL;
int main()
{
    int op,val;
    while(1){
        printf("\nInsert a Node \nEnter 2 -> Height\nEnter 3->Exit\nEnter the Operation  : ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("\nEnter the value to Insert : ");
                scanf("%d", &val);
                insert(&root,val);
                break;
            case 2:
                printf("Height of the tree is : %d",printHeight(root));
                break;
            case 3:
                printf("\nEnd of Program.");
                exit(0);
        }
        printf("\nEnter any key to continue : ");
        getch();
        system("cls");
    }
}

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

BT *create(int val)
{
    BT *new_node = (BT *)malloc(sizeof(BT));
    new_node->value = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int printHeight(BT *root){
    BT *stack[20];
    int height = 0,top=-1,i;
    if (root == NULL)
        return height;
    stack[++top] = root;
    while(1){
        if(top==-1)
            return height;
        height++;
        i = top;
        while(i>-1){
            root = stack[top--];
            if(root->left)
                stack[++top] = root->left;
            if(root->right)
                stack[++top] = root->right;
            i--;
        }
    }
}