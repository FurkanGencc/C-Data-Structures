#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} node;

struct Node* bagli_liste_olustur(int data){
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

void yazdir(struct Node* n){
    node* temp = n;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n----------------------------\n");
}

void basa_eleman_ekle(struct Node** bagli_liste,int data){
    node* yeni = bagli_liste_olustur(data);
    yeni->next = *bagli_liste;
    *bagli_liste = yeni;
}

void sona_eleman_ekle(struct Node** bagli_liste,int data){
    if(*bagli_liste == NULL){
        *bagli_liste = bagli_liste_olustur(data);
        return;
    }
    node* temp = *bagli_liste;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = bagli_liste_olustur(data);
}

void araya_ekle(struct Node** bagli_liste,int x,int data){
    if(*bagli_liste == NULL) return;

    node* temp = *bagli_liste;
    while(temp->next != NULL && temp->next->data != x){
        temp = temp->next;
    }
    if(temp->next == NULL) return;

    node* eklenen = bagli_liste_olustur(data);
    eklenen->next = temp->next;
    temp->next = eklenen;
}

void arama(struct Node* bagli_liste,int aranan){
    node* temp = bagli_liste;
    while(temp != NULL){
        if(temp->data == aranan){
            printf("%d bulundu\n", aranan);
            return;
        }
        temp = temp->next;
    }
    printf("%d bulunamadi\n", aranan);
}

void sondan_sil(struct Node** bagli_liste){
    if(*bagli_liste == NULL) return;

    node* temp = *bagli_liste;
    if(temp->next == NULL){
        free(temp);
        *bagli_liste = NULL;
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void bastan_sil(struct Node** bagli_liste){
    if(*bagli_liste == NULL) return;
    node* temp = *bagli_liste;
    *bagli_liste = temp->next;
    free(temp);
}

void aradan_sil(struct Node** bagli_liste, int silinecek){
    if(*bagli_liste == NULL) return;

    node* temp = *bagli_liste;
    if(temp->data == silinecek){
        *bagli_liste = temp->next;
        free(temp);
        return;
    }
    while(temp->next != NULL && temp->next->data != silinecek){
        temp = temp->next;
    }
    if(temp->next == NULL) return;

    node* silinen = temp->next;
    temp->next = silinen->next;
    free(silinen);
}

int main(){
    node* root = bagli_liste_olustur(10);
    basa_eleman_ekle(&root, 20);
    sona_eleman_ekle(&root, 30);
    yazdir(root);

    araya_ekle(&root, 30, 5);
    yazdir(root);

    arama(root, 20);
    arama(root, 33);

    sondan_sil(&root);
    yazdir(root);

    bastan_sil(&root);
    yazdir(root);

    aradan_sil(&root, 5);
    yazdir(root);

    return 0;
}

