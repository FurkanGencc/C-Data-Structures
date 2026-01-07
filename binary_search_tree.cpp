#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* right;
    struct node* left;
} node;

node* root = NULL;

node* dugum_olustur(int data){
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

node* ekle(node* n, int data){
    if(n == NULL){
        return dugum_olustur(data);
    }
    if(data < n->data){
        n->left = ekle(n->left, data);
    }
    else if(data > n->data){
        n->right = ekle(n->right, data);
    }
    return n;
}

void arama(node* root, int data){
    if(root == NULL){
        printf("aranan deger bulunamadi\n");
        return;
    }
    if(root->data == data){
        printf("aranan deger bulundu %d\n", data);
        return;
    }
    if(data < root->data)
        arama(root->left, data);
    else
        arama(root->right, data);
}

node* minBul(node* root){
    if(root == NULL) return NULL;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

node* maxBul(node* root){
    if(root == NULL) return NULL;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

void maxyazdir(node* root){
    if(root == NULL) return;
    while(root->right != NULL){
        root = root->right;
    }
    printf("Maximum deger: %d\n", root->data);
}

int simetri(node* a, node* b){
    if(a == NULL && b == NULL) return 1;
    if(a == NULL || b == NULL) return 0;
    return simetri(a->left, b->right) && simetri(a->right, b->left);
}

int simetrikmi(node* root){
    if(root == NULL) return 1;
    return simetri(root->left, root->right);
}

int main(){
    root = ekle(root, 10);
    root = ekle(root, 5);
    root = ekle(root, 12);
    root = ekle(root, 13);
    root = ekle(root, 14);
    root = ekle(root, 11);
    root = ekle(root, 4);
    root = ekle(root, 3);
    root = ekle(root, 7);

    arama(root, 9);
    inorder(root);
    printf("\n");

    node* min = minBul(root);
    node* max = maxBul(root);
    if(min) printf("Minimum deger: %d\n", min->data);
    if(max) printf("Maximum deger: %d\n", max->data);

    printf("Simetrik mi: %d\n", simetrikmi(root));

    return 0;
}

