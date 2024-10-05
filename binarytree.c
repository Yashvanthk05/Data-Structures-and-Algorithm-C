#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* insert(struct node *root,int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL){
        return newnode;
    }

    struct node** queue=(struct node**)malloc(100*sizeof(struct node));
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct node *temp=queue[front++];
        if(temp->left==NULL){
            temp->left=newnode;
            return root;
        }else{
            queue[rear++]=temp->left;
        }
        if(temp->right==NULL){
            temp->right=newnode;
            return root;
        }else{
            queue[rear++]=temp->right;
        }
    }
    return root;
}

void reverseLevelOrderTraversal(struct node *root){
    if(root==NULL){
        return;
    }
    struct node **queue=(struct node**)malloc(100*sizeof(struct node));
    int front=0,rear=0;
    queue[rear++]=root;
    struct node **stack=(struct node**)malloc(100*sizeof(struct node));
    int top=-1;
    while(front<rear){
        struct node* temp=queue[front++];
        stack[++top]=temp;
        if(temp->left!=NULL){
            queue[rear++]=temp->left;
        }
        if(temp->right!=NULL){
            queue[rear++]=temp->right;
        }
    }
    while(top>=0){
        printf("%d ",stack[top--]->data);
    }
}

void levelOrderTraversal(struct node *root){
    if(root==NULL){
        return;
    }
    struct node** queue=(struct node**)malloc(100*sizeof(struct node));
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct node* temp=queue[front++];
        printf("%d ",temp->data);
        if(temp->left!=NULL){
            queue[rear++]=temp->left;
        }
        if(temp->right!=NULL){
            queue[rear++]=temp->right;
        }
    }
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        preorder(root->left);
        preorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    struct node *root=NULL;
    int num;
    while(n--){
        scanf("%d",&num);
        root=insert(root,num);
    }
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\nReverse Level Order Traversal: ");
    reverseLevelOrderTraversal(root);
    return 0;
}
