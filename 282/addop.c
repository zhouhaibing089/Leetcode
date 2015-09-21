#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void print_list(list l) {
    node* n = l->head;
    while(n != NULL) {
        printf("%s ", n->value);
        n = n->next;
    }
    printf("\n");
}

char** convert(list l, int size) {
    char** result = (char**)malloc(size * sizeof(char*));
    int i = 0;
    node* n = l->head;
    while (n != NULL) {
        result[i++] = n->value;
        n = n->next;
    }
    return result;
}

char* create_string(char sign, char c, char* cat) {
    int size = 1;
    if (sign != 0) {
        size += 1;
    }
    if (cat != NULL) {
        size += strlen(cat);
    }
    char* str = (char*)malloc((size + 1) * sizeof(char));
    if (sign != 0) {
        str[0] = sign;
        str[1] = c;
        if (cat != NULL) {
            strncpy(str + 2, cat, strlen(cat));
        }
    } else {
        str[0] = c;
        if (cat != NULL) {
            strncpy(str + 1, cat, strlen(cat));
        }
    }
    str[size] = 0;
    return str;
}

bool safe(int i, int j) {
    return (INT_MAX - i * 10) >= j;
}

/*
 * with one more argument
 */
char** addOperators2(int head, char* num, int target, int* returnSize, bool reverse, int lhs, int rhs) {
    // printf("head=%d [%s] = %d\n", head, num, target);
    int size = 0;
    int count = 0;
    char** result;
    int digit = num[0] - '0';
    list l = create_list();
    // #0: base cases
    if (num[1] == 0) {
        // can we add it?
        if ((head + digit) == target) {
            printf("Yes: head=%d + [%s] = %d\n", head, num, target);
            ++count;
            append(l, create_string(reverse ? '-' : '+', num[0], NULL));
        }
        if ((head - digit) == target) {
            printf("Yes: head=%d - [%s] = %d\n", head, num, target);
            ++count;
            append(l, create_string(reverse ? '+' : '-', num[0], NULL));
        }
        if ((head * digit) == target) {
            printf("Yes: head=%d * [%s] = %d\n", head, num, target);
            ++count;
            append(l, create_string('*', num[0], NULL));
        }
        if((lhs == -1 && rhs == -1) && head != 0 && (safe(head, digit)) && head != 0 && (head * 10 + digit) == target) {
            printf("Yes: head=%d[%s] = %d\n", head, num, target);
            ++count;
            append(l, create_string(0, num[0], NULL));
        } else if ((lhs != -1 && rhs != -1 && rhs != 0) && (lhs * (rhs * 10 + digit) == target)) {
            printf("Yes: head=%d[%s] = %d\n", head, num, target);
            ++count;
            append(l, create_string(0, num[0], NULL));
        }
        *returnSize = count;
        return convert(l, count);
    }
    // #1: head + [(num target) - head]
    // printf("Try: head=%d + [%s] = %d\n", head, num, target);
    result = addOperators2(num[0] - '0', num + 1, target - head, &size, reverse, -1, -1);
    count += size;
    if (size > 0) {
        for (int i = 0; i < size; ++i) {
            append(l, create_string(reverse ? '-' : '+', num[0], result[i]));
            free(result[i]);
        }
        free(result);
    }
    // #2: head - [head - (num target)]
    // printf("Try: head=%d - [%s] = %d\n", head, num, target);
    result = addOperators2(num[0] - '0', num + 1, head - target, &size, !reverse, -1, -1);
    count += size;
    if (size > 0) {
        for (int i = 0; i < size; ++i) {
            append(l, create_string(reverse ? '+' : '-', num[0], result[i]));
            free(result[i]);
        }
        free(result);
    }
    // #3: head => head * num[0], num => num + 1
    // printf("Try: head=%d * [%s] = %d\n", head, num, target);
    result = addOperators2(head * (num[0] - '0'), num + 1, target, &size, reverse, head, num[0] - '0');
    count += size;
    if (size > 0) {
        for (int i = 0; i < size; ++i) {
            append(l, create_string('*', num[0], result[i]));
            free(result[i]);
        }
        free(result);
    }
    // #4: head => head * 10 + num[0], num => num + 1
    // printf("Try: head=%d[%s] = %d\n", head, num, target);
    if (lhs == -1 && rhs == -1 && head != 0) {
        result = addOperators2(head * 10 + (num[0] - '0'), num + 1, target, &size, reverse, -1, -1);
        count += size;
        if (size > 0) {
            for (int i = 0; i < size; ++i) {
                append(l, create_string(0, num[0], result[i]));
                free(result[i]);
            }
            free(result);
        }
    } else if (rhs != 0 && lhs != -1) {
        rhs = rhs * 10 + num[0] - '0';
        result = addOperators2(lhs * rhs, num + 1, target, &size, reverse, lhs, rhs);
        count += size;
        if (size > 0) {
            for (int i = 0; i < size; ++i) {
                append(l, create_string(0, num[0], result[i]));
                free(result[i]);
            }
            free(result);
        }
    } else {
        // lhs != -1 && rhs == 0
    }

    // #5: retrieve result
    *returnSize = count;
    return convert(l, count);
}


char** addOperators(char* num, int target, int* returnSize) {
    if (num == NULL || num[0] == 0) {
        *returnSize = 0;
        return NULL;
    }
    if (num[1] == 0) {
        if (num[0] == (target + '0')) {
            *returnSize = 1;
            char** result = (char**)malloc(sizeof(char*));
            result[0] = num;
            return result;
        } else {
            *returnSize = 0;
            return NULL;
        }
    }
    char** result = addOperators2(num[0] - '0', num + 1, target, returnSize, false, -1, -1);
    int size = *returnSize;
    if (size == 0) {
        return NULL;
    } else {
        for (int i = 0; i < size; ++i) {
            char* str = result[i];
            result[i] = create_string(0, num[0], str);
            free(str);
        }
        return result;
    }
}

int main() {
    char* s = (char*)malloc(11 * sizeof(char));
    s[0] = '2';
    s[1] = '1';
    s[2] = '4';
    s[3] = '7';
    s[4] = '4';
    s[5] = '8';
    s[6] = '3';
    s[7] = '6';
    s[8] = '4';
    s[9] = '8';
    s[10] = 0;
    // s[0] = '3';
    // s[1] = '4';
    // s[2] = '5';
    // s[3] = '6';
    // s[4] = '2';
    // s[5] = '3';
    // s[6] = '7';
    // s[7] = '4';
    // s[8] = '9';
    // s[9] = '0';
    // s[10] = 0;
    int target = -2147483648;
    int size;
    char** result = addOperators(s, target, &size);
    for (int i = 0; i < size; ++i) {
        printf("%s\n", result[i]);
    }
    return 0;
}
