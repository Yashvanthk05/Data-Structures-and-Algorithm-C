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
    if(root->left==NULL){
        root->left=newnode;
    }else if(root->right==NULL){
        root->right=newnode;
    }else{
        if(insert(root->left,data)==NULL){
            insert(root->right,data);
        }
    }
    return root;
}

int height(struct node *root){
    if(root==NULL){
        return 0;
    }else{
        int lh=height(root->left);
        int rh=height(root->right);
        return (lh>rh)?lh+1:rh+1;
    }
}

void levelOrderPrint(struct node *root,int level){
    if (root == NULL) return;
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        levelOrderPrint(root->left, level - 1);
        levelOrderPrint(root->right, level - 1);
    }
}

void levelOrderTraversal(struct node *root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        levelOrderPrint(root,i);
    }
}



int main(){
    int n;
    scanf("%d",&n);
    int num;
    struct node *root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        root=insert(root,num);
    }
    levelOrderTraversal(root);
    return 0;
}
