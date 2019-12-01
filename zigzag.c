#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tree
{
    int value;
    struct tree *left, *right;
} BT;

BT *create(int);
void insert(BT **, int);
void printzigzag(BT *);

BT *root = NULL;
int main()
{
    int op, val;
    system("cls");
    while (1)
    {
        printf("\nInsert a Node \nEnter 2 -> Print ZigZag\nEnter 3->Exit\nEnter the Operation  : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the value to Insert : ");
            scanf("%d", &val);
            insert(&root, val);
            break;
        case 2:
            printf("\nZigzag poattern of the tree is : ");
            printzigzag(root);
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

void printzigzag(BT *root){
    BT *stack1[20], *stack2[20],*temp;
    int top1, top2;
    top1 = top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1){
        while (top1 != -1){
            temp = stack1[top1--];
            printf("%d ", temp->value);
            if(temp->left)
                stack2[++top2] = temp->left;
            if(temp->right)
                stack2[++top2] = temp->right;
        }
        while(top2!=-1){
            temp = stack2[top2--];
            printf("%d ", temp->value);
            if (temp->right)
                stack1[++top1] = temp->right;
            if (temp->left)
                stack1[++top1] = temp->left;
        }
    }
}