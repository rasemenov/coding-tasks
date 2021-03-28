#include "square_root.h"


static uint16_t babylonian_root(uint16_t radicand) {
    uint16_t approx_root = 500;
    float error = 100.0;
    while (error > 1e-5) {
        approx_root = 0.5 * (approx_root + (radicand / approx_root));
        error = (radicand - approx_root * approx_root) / (2.0 * approx_root);
        if (error < 0) {
            error *= -1;
        }
    }
    return approx_root;
}

uint16_t square_root(uint16_t radicand) {
    uint16_t res = babylonian_root(radicand);
    return res;
}
