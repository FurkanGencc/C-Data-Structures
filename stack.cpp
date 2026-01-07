#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} node;

node* top = NULL;

//  Ekleme
void push(int veri) {
    node* eklenecek = (node*)malloc(sizeof(node));
    eklenecek->data = veri;
    eklenecek->next = top; 
    top = eklenecek;
}

// Çýkarma
void pop() {
    if (top == NULL) {
        printf("Stack boþ\n");
        return;
    }
    node* temp = top;
    top = top->next;
    free(temp);
}

// Uazdýrma
void yazdir() {
    node* n = top;
    while (n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("NULL\n");
}

//  Tepe elemanýný gösterme
int peek() {
    if (top == NULL) {
        printf("Stack boþ\n");
        return -1; 
    }
    return top->data;
}


int main() {
    push(10);
    push(20);
    push(30);

    printf("Stack durumu:\n");
    yazdir();              // 30 -> 20 -> 10 -> NULL

    printf("Tepe eleman: %d\n", peek());

    pop();
    printf("Pop sonrasý stack:\n");
    yazdir();              // 20 -> 10 -> NULL

    return 0;
}

