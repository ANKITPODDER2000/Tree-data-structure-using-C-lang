#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int value;
    struct tree *left, *right;
} BT;


BT* create(int);
void insert(BT **, int);
void inOrder(BT *);

BT *root = NULL , *stack[30];
int top = -1;

int main()
{
    int op,val;
    while(1){
        printf("\nEnter 1 -> Insert\nENter 2->PreOrdre \nEnetr 3->Exit \nEnter the Operation : ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("\nEnter the value to insert : ");
                scanf("%d", &val);
                insert(&root, val);
                break;
            case 2:
                printf("\nInorder Traversal of Tree is : ");
                inOrder(root);
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

void insert(BT **root, int val){
    if(*root == NULL){
        *root = create(val);
        return;
    }
    else if((*root)->value > val)
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
void inOrder(BT *root){
    BT *temp;
    if (root==NULL)
        return;
    while(1){
        while(root!=NULL){
            stack[++top] = root;
            root = root->left;
        }
        if (top == -1)
            return;
        temp = stack[top--];
        printf("%d ", temp->value);
        root = temp->right;
    }
}