#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdint.h>

#define EXIT_OK (0)
#define EXIT_FAILURE (-1)

typedef int buffer_value_t;
typedef struct {
    size_t capacity;
    size_t length;
    size_t read_head;
    size_t write_head;
    buffer_value_t *ring;
} circular_buffer_t;

/* Error in any of this functions sets errno value.*/
circular_buffer_t* new_circular_buffer(size_t capacity);
int16_t read(circular_buffer_t *buffer, buffer_value_t *value);
int16_t write(circular_buffer_t *buffer, buffer_value_t value);
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);
int16_t delete_buffer(circular_buffer_t *buffer);
int16_t clear_buffer(circular_buffer_t *buffer);

#endif
