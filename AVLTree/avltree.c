#include<stdio.h>
#include<stdlib.h>
typedef struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
}node;
node *root = NULL;
int findHeight(node *temp)
{
    int height = -1;
    if(temp != NULL){
        int leftHeight = findHeight(temp->left);
        int rightHeight = findHeight(temp->right);
        int max = (leftHeight>rightHeight)?leftHeight:rightHeight;
        height = 1+max;
    }
    return height;
}

int getDiff(node *temp)
{
    int leftHeight = findHeight(temp->left);
    int rightHeight = findHeight(temp->right);
    int balanceFactor = leftHeight - rightHeight;
    return balanceFactor;
}

node *leftRotation(node *parent)
{
    node *temp1,*temp2;
    temp1 = parent->right;
    temp2 = temp1->left;
    parent->right = temp2;
    temp1->left = parent;
    return temp1;
}
node *rightRotation(node *parent)
{
    node *temp1,*temp2;
    temp1 = parent->left;
    temp2 = temp1->right;
    temp1->right = parent;
    parent->left = temp2;
    return temp1;
}
node *rightLeftRotation(node *parent)
{
    node *node1;
    node1 = parent->right;
    parent->right = rightRotation(node1);
    return leftRotation(parent);
}
node *leftRightRotation(node *parent)
{
    node *node1;
    node1 = parent->left;
    parent->left = leftRotation(node1);
    return rightRotation(parent);
}


node *balancing(node *n)
{
    int bf = getDiff(n);
    if(bf>1){
        if(getDiff(n->left>0))
           n = rightRotation(n);
        else
        {
            n = leftRightRotation(n);
        }
        
    }
    else if(bf < -1){
        if(getDiff(n->right) < 0)
            n = leftRotation(n);
        else
            n = rightLeftRotation(n);
    }
    return n;
}

node *insert(node *root,int val)
{
    if(root == NULL){
        root = (node*)malloc(sizeof(node));
        root->data = val;
        root->left = root->right = NULL;
        return root;  
    }
    else if(val < root->data){
        root->left = insert(root->left, val);
        root = balancing(root);
    }
    else if(val > root->data){
        root->right = insert(root->right, val);
        root = balancing(root);
    }
    return root;
    
}

void inorder(node *root)
{
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(node *root)
{
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void main()
{
	
    int ch,val;
    while(1){
        printf("1-Insert\t2-Display\nEnter Choice ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&val);
                root = insert(root,val);
                break;

            case 2:
                if(root == NULL)
                    printf("Tree is not created\n");
                else{
                    printf("Preorder Sequence: ");
                    preorder(root);
                    printf("\nInorder Sequence: ");
                    inorder(root);
                    printf("\nPostorder Sequence: ");
                    postorder(root);
                    
                }
                break;
            default:
                exit(0);
        }
        
    }
}



