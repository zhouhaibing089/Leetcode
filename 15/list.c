#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    struct node*    prev;
    struct node*    next;
    int             value;
} node;

typedef struct meta {
    node*   head;
    node*   last;
} meta;

typedef meta* list;

// create list
list create_list() {
    list l = (meta*)malloc(sizeof(meta));
    l->head = NULL;
    l->last = NULL;
    return l;
}

// free it
void free_list(list l) {
    node* n = l->last;
    while(n != NULL) {
        n = n->prev;
        free(n->next);
    }
    free(l);
}

// add element
void append(list l, int value) {
    node* n = (node*)malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    if (l->last == NULL) {
        n->prev = NULL;
        l->last = n;
        l->head = n;
    } else {
        n->prev = l->last;
        l->last->next = n;
        l->last = n;
    }
}

void print(list l) {
    node* n = l->head;
    while(n != NULL) {
        printf("%d ", n->value);
        n = n->next;
    }
    printf("\n");
}

int main() {
    list l = create_list();
    append(l, 5);
    append(l, 3);
    append(l, 4);
    append(l, 1);
    append(l, 2);
    print(l);
    free(l);
    return 0;
}
