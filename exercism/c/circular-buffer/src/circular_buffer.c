#include "circular_buffer.h"

#include <errno.h>
#include <stdlib.h>


static buffer_value_t* allocate_ring(size_t capacity) {
    return (buffer_value_t *)malloc(capacity * sizeof(buffer_value_t));
}


circular_buffer_t* new_circular_buffer(size_t capacity) {
    circular_buffer_t *buffer = NULL;
    buffer = malloc(sizeof(circular_buffer_t));
    if (!buffer) {
        return buffer;
    }
    buffer->capacity = capacity;
    buffer->length = 0;
    buffer->write_head = 0;
    buffer->read_head = 0;
    buffer->ring = NULL;
    return buffer;
}


int16_t read(circular_buffer_t *buffer, buffer_value_t *value) {
    if (!buffer || !buffer->ring || !buffer->length) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    *value = buffer->ring[buffer->read_head++];
    buffer->length--;
    buffer->read_head %= buffer->capacity;
    return EXIT_OK;
}


int16_t write(circular_buffer_t *buffer, buffer_value_t value) {
    if (!buffer || buffer->length == buffer->capacity) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }
    if (!buffer->ring) {
        buffer->ring = allocate_ring(buffer->capacity);
        if (!buffer->ring) {
            return EXIT_FAILURE;
        }
    }
    buffer->ring[buffer->write_head++] = value;
    buffer->length++;
    buffer->write_head %= buffer->capacity;
    return EXIT_OK;
}


int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
    if (buffer->length < buffer->capacity) {
        return write(buffer, value);
    }
    buffer->ring[buffer->write_head++] = value;
    buffer->write_head %= buffer->capacity;
    buffer->read_head++;
    buffer->read_head %= buffer->capacity;
    return EXIT_OK;
}


int16_t delete_buffer(circular_buffer_t *buffer) {
    if (!buffer) {
        return EXIT_FAILURE;
    }
    clear_buffer(buffer);
    if (buffer->ring) {
        free(buffer->ring);
    }
    buffer->ring = NULL;
    free(buffer);
    return EXIT_OK;
}


int16_t clear_buffer(circular_buffer_t *buffer) {
    if (!buffer) {
        return EXIT_FAILURE;
    }
    buffer->length = 0;
    buffer->write_head = 0;
    buffer->read_head = 0;
    return EXIT_OK;
}
