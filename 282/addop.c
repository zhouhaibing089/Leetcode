#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node*    prev;
    struct node*    next;
    char*           value;
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
    node* n = l->head;
    while(n != NULL) {
        node* next = n->next;
        free(n);
        n = next;
    }
    free(l);
}

// add element
void append(list l, char* value) {
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

/*
 * with one more argument
 */
char** addOperators(int head, char* num, int target, int* returnSize) {

}


char** addOperators(char* num, int target, int* returnSize) {
    printf("%s %d\n", num, target);
    list l = create_list();
    // #1: single character
    if (num[1] == 0) {
        printf("Come to end: %s\n", num);
        // #1.1: exactly the same
        if (num[0] == (target + '0')) {
            *returnSize = 1;
            char* str = (char*)malloc(2 * sizeof(char));
            str[0] = num[0];
            str[1] = 0;
            char** result = (char**)malloc(sizeof(char*));
            result[0] = str;
            return result;
        }
        // #1.2: different
        else {
            *returnSize = 0;
            return NULL;
        }
    }
    int retSize = 0;
    int count = 0;
    int a = num[0] - '0';
    int b = num[1] - '0';
    int c = a * b;
    printf("Try to add '+': %s\n", num);
    // #2: let's add a '+'
    char** subresult = addOperators(num + 1, target - a, &retSize);
    count += retSize;
    // #2.1: copy all the result
    if (retSize != 0) {
        for (int i = 0; i < retSize; ++i) {
            int len = 3 + strlen(subresult[i]);
            char* str = (char*)malloc(len * sizeof(char));
            str[0] = num[0];
            str[1] = '+';
            strncpy(str + 2, subresult[i], len - 2);
            printf("#2 Got %s\n", str);
            free(subresult[i]);
            append(l, str);
        }
        free(subresult);
    }
    printf("Try to add '-': %s\n", num);
    // #3: let's add a '-'
    subresult = addOperators(num + 1, a - target, &retSize);
    count += retSize;
    // #3.1: copy all the result
    if (retSize != 0) {
        for (int i = 0; i < retSize; ++i) {
            int len = 3 + strlen(subresult[i]);
            char* str = (char*)malloc(len * sizeof(char));
            str[0] = num[0];
            str[1] = '-';
            strncpy(str + 2, subresult[i], len - 2);
            printf("#3 Got %s\n", str);
            free(subresult[i]);
            append(l, str);
        }
        free(subresult);
    }
    printf("Try to add '*': %s\n", num);
    // #4: let's add a '*'
    num[1] = c + '0';
    subresult = addOperators(num + 1, target, &retSize);
    count += retSize;
    // #4.1: copy all the result
    if (retSize != 0) {
        for (int i = 0; i < retSize; ++i) {
            int len = 3 + strlen(subresult[i]);
            char* str = (char*)malloc(len * sizeof(char));
            str[0] = num[0];
            str[1] = '*';
            strncpy(str + 2, subresult[i], len - 2);
            str[2] = b + '0';
            printf("#4 Got %s\n", str);
            free(subresult[i]);
            append(l, str);
        }
        free(subresult);
    }
    num[1] = b + '0';
    // #5: try to leave a blank here
    if (a != 0 && a <= 9) {
        num[1] = a * 10 + b + '0';
        subresult = addOperators(num + 1, target, &retSize);
        count += retSize;
        // #5.1: copy all the result
        if (retSize != 0) {
            for (int i = 0; i < retSize; ++i) {
                int len = 2 + strlen(subresult[i]);
                char* str = (char*)malloc(len * sizeof(char));
                str[0] = num[0];
                strncpy(str + 1, subresult[i], len - 1);
                str[1] = b + '0';
                printf("#4 Got %s\n", str);
                free(subresult[i]);
                append(l, str);
            }
            free(subresult);
        }
        num[1] = b + '0';
    }
    *returnSize = count;
    if (count == 0) {
        return NULL;
    }
    char** result = (char**)malloc(count * sizeof(char*));
    count = 0;
    node* n = l->head;
    while(n != NULL) {
        result[count++] = n->value;
        n = n->next;
    }
    free_list(l);
    return result;
}

int main() {
    char* s = (char*)malloc(10 * sizeof(char));
    s[0] = '1';
    s[1] = '2';
    s[2] = '3';
    s[3] = '4';
    s[4] = '5';
    s[5] = '6';
    s[6] = '7';
    s[7] = '8';
    s[8] = '9';
    s[9] = 0;
    int target = 45;
    int size;
    char** result = addOperators(s, target, &size);
    for (int i = 0; i < size; ++i) {
        // printf("%s\n", result[i]);
    }
    return 0;
}
