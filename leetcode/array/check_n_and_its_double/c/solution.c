struct values {
    int value;
    UT_hash_handle hh;
};

void add_value(struct values **dict, int value) {
    struct values *s;
    s = (struct values *)malloc(sizeof(struct values));
    s->value = value;
    HASH_ADD_INT(*dict, value, s);
}

struct values *get_value(struct values **dict, int value) {
    struct values *s;
    HASH_FIND_INT(*dict, &value, s);
    return s;
}

bool checkIfExist(int* arr, int arrSize){
    bool res = false;
    int indx, item, sign = 1;
    struct values *s = NULL, *dict = NULL;
    if (!arr || !arrSize) {
        return false;
    }
    for (indx = 0; indx < arrSize; indx++) {
        item = arr[indx];
        s = get_value(&dict, 2 * item);
        if (!s) {
            sign = (item < 0) ? -1 : 1;
            if (!((item * sign) % 2)) {
                s = get_value(&dict, item / 2);
            }
        }
        if (s) {
            res = true;
            break;
        } else {
            add_value(&dict, item);
        }
    }
    while (--indx >= 0) {
        HASH_FIND_INT(dict, &arr[indx], s);
        if (s) {
            HASH_DEL(dict, s);
            free(s);
        }
    }
    return res;
}
