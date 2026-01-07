#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} node;

node* dugum_olustur(int data){
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void yazdir(node* n){
    node* temp = n;
    if (temp == NULL) {
        printf("bos\n");
        return;
    }
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void basa_ekle(node** bagli_liste, int data){
    node* yeni = dugum_olustur(data);
    if (*bagli_liste == NULL) {
        *bagli_liste = yeni;
        return;
    }
    yeni->next = *bagli_liste;
    (*bagli_liste)->prev = yeni;
    *bagli_liste = yeni;
}

void sona_ekle(node** bagli_liste, int data){
    node* yeni = dugum_olustur(data);
    if (*bagli_liste == NULL) {
        *bagli_liste = yeni;
        return;
    }
    node* temp = *bagli_liste;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = yeni;
    yeni->prev = temp;
}

void araya_ekle(node** bagli_liste, int kimin_onune, int data){
    if (*bagli_liste == NULL) return;

    node* temp = *bagli_liste;
    while (temp != NULL && temp->data != kimin_onune) {
        temp = temp->next;
    }
    if (temp == NULL) return;

    node* yeni = dugum_olustur(data);

    if (temp->prev == NULL) {
        yeni->next = temp;
        temp->prev = yeni;
        *bagli_liste = yeni;
        return;
    }

    node* onceki = temp->prev;
    onceki->next = yeni;
    yeni->prev = onceki;
    yeni->next = temp;
    temp->prev = yeni;
}

void bastan_sil(node** bagli_liste){
    if (*bagli_liste == NULL) return;

    node* temp = *bagli_liste;
    if (temp->next == NULL) {
        free(temp);
        *bagli_liste = NULL;
        return;
    }

    *bagli_liste = temp->next;
    (*bagli_liste)->prev = NULL;
    free(temp);
}

void sondan_sil(node** bagli_liste){
    if (*bagli_liste == NULL) return;

    node* temp = *bagli_liste;
    if (temp->next == NULL) {
        free(temp);
        *bagli_liste = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

void aradan_sil(node** bagli_liste, int silinecek){
    if (*bagli_liste == NULL) return;

    node* temp = *bagli_liste;
    while (temp != NULL && temp->data != silinecek) {
        temp = temp->next;
    }
    if (temp == NULL) return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *bagli_liste = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

int main(){
    node* root = dugum_olustur(11);
    basa_ekle(&root, 10);
    sona_ekle(&root, 12);
    yazdir(root);

    printf("-----------------------\n");

    araya_ekle(&root, 12, 8);
    araya_ekle(&root, 10, 9);
    yazdir(root);

    return 0;
}

