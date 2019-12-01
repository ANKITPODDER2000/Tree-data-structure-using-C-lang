#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *left;
    struct node *right;

};

void preOrder( struct node *root) {

	if( root == NULL )
      return;
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);

}

/* you only have to complete the function given below.
node is defined as

struct node {

    int data;
    struct node *left;
    struct node *right;

};

*/

struct node* create(int val)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert( struct node* root, int data ) {
    struct node* temp = root;
    if (root == NULL)
        return create(data);
    while(1){
        if(root->data > data){
            if(root->left==NULL){
                root->left = create(data);
                return temp;
            }
            root = root->left;
        }
        else{
            if(root->right == NULL){
                root->right = create(data);
                return temp;
            }
            root = root->right;
        }
    }
}


int main() {

    struct node* root = NULL;

    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }

	preOrder(root);
    return 0;
}
