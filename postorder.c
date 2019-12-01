#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tree{
    int value;
    struct tree *left, *right;
} BT;

BT *create(int);
void insert(BT **, int);
void postorder(BT *);
void print(void);

BT *root = NULL,
   *stack1[10], *stack2[20];
int top1 = -1, top2 = -1;

int main()
{
    int op, val;
    char a;
    while (1)
    {
        printf("\nEnter 1->Insert\nEnter 2->POST Traversal\nEnter 3->Exit\nEnetr the Operation : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the value : ");
            scanf("%d", &val);
            insert(&root, val);
            break;
        case 2:
            postorder(root);
            printf("\nPostorder of the tree is : ");
            print();
            break;
        case 3:
            printf("\nEnd of Program.");
            exit(0);
        }
        printf("\nEnter any key to Continue : ");
        a = getch();
        system("cls");
    }
    return 0;
}
BT *create(int val)
{
    BT *new_node = (BT *)malloc(sizeof(BT));
    new_node->value = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void insert(BT **ptr, int val)
{
    if (*ptr == NULL)
        *ptr = create(val);
    else if ((*ptr)->value > val)
        insert(&((*ptr)->left), val);
    else
        insert(&((*ptr)->right), val);
}
void postorder(BT *root){
    stack1[++top1] = root;
    while(top1!=-1){
        root = stack1[top1];
        stack2[++top2] = stack1[top1--];
        if (root->left!=NULL)
            stack1[++top1] = root->left;
        if (root->right!=NULL)
            stack1[++top1] = root->right;
    }
}
void print(void){
    int i;
    for (i = top2; i >= 0;i--)
        printf("%d ", stack2[i]->value);
}