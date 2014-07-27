#ifndef DIM_ARRAY_H
#define DIM_ARRAY_H

typedef struct dim_array dim_array_t;

unsigned int dimensions(dim_array_t*);

unsigned int* lengths(dim_array_t*);

dim_array_t* alloc_dim_array(unsigned int, size_t*);

void free_dim_array(dim_array_t*);

void* get(dim_array_t*, unsigned int*);

void set(dim_array_t*, unsigned int*, void*);

#endif
