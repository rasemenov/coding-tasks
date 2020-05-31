#define BAIL_OUT res = false; \
                 break;

bool validMountainArray(int *A, int ASize){
    if (!A || ASize < 3) {
        return false;
    }
    int indx, current, next;
    bool raised = false, felt = false, res = true;
    for (indx = 0; indx < ASize - 1; indx++) {
        current = A[indx];
        next = A[indx + 1];
        if (current == next) {
            BAIL_OUT
        }
        if (current > next) {
            if (!raised) {
                BAIL_OUT
            }
            if (!felt) {
                felt = true;
            }
        } else {
            if (!raised) {
                raised = true;
            }
            if (felt) {
                BAIL_OUT
            }
        }
    }
    if (!raised || !felt) {
        res = false;
    }
    return res;
}
