#include "list_ops.h"

#include <string.h>


list_t *new_list(size_t length, list_element_t elements[]) {
    list_t *list = malloc(LIST_SIZE);
    if (!list) {
        return NULL;
    }
    list->length = length;
    list->elements = calloc(length, ELEMENT_SIZE);
    if (elements) {
        if (!list->elements) {
            delete_list(list);
            return NULL;
        }
        for (int indx = 0; indx < (int)length; indx++) {
            list->elements[indx] = elements[indx];
        }
    }
    return list;
}


list_t *append_list(list_t *list1, list_t *list2) {
    if (!list1 || !list2) {
        return NULL;
    }
    list_t *res = NULL;
    size_t len = list1->length + list2->length;
    if (len == 0) {
        res = new_list(0, NULL);
    } else if (list1->length == 0) {
        res = new_list(len, list2->elements);
    } else if (list2->length == 0) {
        res = new_list(len, list1->elements);
    } else {
        list_element_t *array = calloc(len, ELEMENT_SIZE);
        memcpy(array, list1->elements, list1->length * ELEMENT_SIZE);
        memcpy(array + list1->length, list2->elements,
               list2->length * ELEMENT_SIZE);
        res = new_list(len, array);
        free(array);
    }
    return res;
}


void delete_list(list_t *list) {
    if (!list) {
        return;
    }
    if (list->elements) {
        free(list->elements);
    }
    free(list);
}


list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
    if (!list) {
        return NULL;
    }
    list_element_t *tmp_buf = calloc(list->length, ELEMENT_SIZE);
    int indx_tmp = 0;
    for (int indx_orig = 0; indx_orig < (int)list->length; indx_orig++) {
        if (filter(list->elements[indx_orig])) {
            tmp_buf[indx_tmp++] = list->elements[indx_orig];
        }
    }
    list_t *res = new_list(indx_tmp, tmp_buf);
    return res;
}


size_t length_list(list_t *list) {
    if (list) {
        return list->length;
    }
    return 0;
}


list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
    if (!list || !map) {
        return NULL;
    }
    list_t *res = new_list(list->length, list->elements);
    for (int indx = 0; indx < (int)list->length; indx++) {
        res->elements[indx] = map(list->elements[indx]); 
    }
    return res;
}


list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
    if (!list || !foldl || !list->length) {
        return initial;
    }
    for (int indx = 0; indx < (int)list->length; indx++) {
        initial = foldl(initial, list->elements[indx]);
    }
    return initial;
}


list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
    if (!list || !foldr || !list->length) {
        return initial;
    }
    for (int indx = list->length - 1; indx >= 0; indx--) {
        initial = foldr(list->elements[indx], initial);
    }
    return initial;
}


list_t *reverse_list(list_t *list) {
    if (!list) {
        NULL;
    }
    list_t *res = new_list(list->length, NULL);
    for (int indx = 0; indx < (int)list->length; indx++) {
        res->elements[indx] = list->elements[list->length - indx - 1];
    }
    return res;
}
