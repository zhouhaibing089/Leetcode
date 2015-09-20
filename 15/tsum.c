#include <stdio.h>
#include <stdlib.h>

int** threeSum(int* nums, int numsSize, int* returnSize);

int compare(const void* p1, const void* p2);

typedef struct node {
    struct node*    prev;
    struct node*    next;
    int*            value;
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
void append(list l, int* value) {
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

int main() {
    int a[27] = {-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
    int returnSize = 0;
    int** result = threeSum(a, 27, &returnSize);
    printf("Size: %d\n", returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("(%d %d %d)\n", result[i][0], result[i][1], result[i][2]);
    }
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int count = 0;
    list l = create_list();
    // #1 sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    // #2 loop over the array
    for (int i = 0; i < (numsSize - 2); ++i) {
        for (int j = i + 1; j < (numsSize - 1); ++j) {
            int twoSum = nums[i] + nums[j];
            printf("Two Sum: i = %d, j = %d, sum = %d\n", i, j, twoSum);
            // #3.1: absolutely we will not find the third number
            if ((twoSum + nums[j]) > 0) {
                break;
            }
            // #3.2: binary search the third number
            int toFind = 0 - twoSum;
            void* p = bsearch(&toFind, nums + j + 1, numsSize - j - 1,
                sizeof(int), compare);
            // #3.2.1: not found
            if (p != NULL) {
                int* tuple = (int*)malloc(3 * sizeof(int));
                tuple[0] = nums[i];
                tuple[1] = nums[j];
                tuple[2] = *(int*)p;
                append(l, tuple);
                ++count;
            }
            // find the next j
            int k = j + 1;
            for (; k < (numsSize - 1); ++k) {
                if (nums[k] != nums[j]) {
                    j = k - 1;
                    break;
                }
            }
            printf("Next j = %d, k = %d\n", j, k);
            if ((j + 1) != k) {
                break;
            } else {
                continue;
            }
        }
        // find the next i
        int k = i + 1;
        for (; k < (numsSize - 2); ++k) {
            if (nums[k] != nums[i]) {
                i = k - 1;
                break;
            }
        }
        printf("Next i = %d, k = %d\n", i, k);
        if ((i + 1) != k) {
            break;
        }
    }
    *returnSize = count;
    int** result = (int**)malloc(count*sizeof(int*));
    count = 0;
    node* n = l->head;
    while(n != NULL) {
        result[count++] = n->value;
        n = n->next;
    }
    free_list(l);
    return result;
}

int compare(const void* p1, const void* p2) {
    return (*(int*)p1) - (*(int*)p2);
}
