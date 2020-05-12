#include <stdio.h>
#include <stdlib.h>


struct buffer {
    int number;
    struct buffer *next;
};

void put(struct buffer **head, int number) {
    struct buffer *tmp, *current = *head;
    tmp = (struct buffer *)malloc(sizeof(struct buffer));
    if (!tmp) {
        return;
    }
    tmp->number = number;
    tmp->next = NULL;
    if (current) {
        while (current->next) {
            current = current->next;
        }
        current->next = tmp;
    } else {
        *head = tmp;
    }
}


void popleft(struct buffer **head) {
    struct buffer *new_head;
    if (!(*head)) {
        return;
    }
    new_head = (*head)->next;
    free(*head);
    *head = new_head;
}


void print_list(struct buffer *list) {
    struct buffer *tmp = list;
    int i = 0;
    while (tmp) {
        printf("%d - %d\n", i++, tmp->number);
        tmp = tmp->next;
    }
}


void duplicateZeros(int *arr, int arrSize){
    int indx;
    struct buffer *buf_head;
    buf_head = NULL;
    for (indx = 0; indx < arrSize; indx++) {
        print_list(buf_head);
        if (!arr[indx]) {
            put(&buf_head, 0);
        }
        if (buf_head) {
            put(&buf_head, arr[indx]);
            if (buf_head) {
                arr[indx] = buf_head->number;
            }
            popleft(&buf_head);
        }
    }
    while (buf_head) {
        popleft(&buf_head);
    }
}


int main(void) {
    int i, sz, arr[] = {1, 0, 2, 0, 3};
    sz = sizeof(arr) / sizeof(int);
    duplicateZeros(arr, sz);
    for (i; i < sz; i++) {
        printf("%d %d\n", i, arr[i]);
    }
    return 0;
}
