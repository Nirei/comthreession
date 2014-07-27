#include "dim_array.h"
#include <stdlib.h>
#include <strings.h>

struct dim_array {
	unsigned int dimensions;
	unsigned int* lengths;
	void* elements;
};

unsigned int dimensions(dim_array_t* array)
{
	return array.dimensions;
}

unsigned int* lengths(dim_array_t* array)
{
	unsigned int* lengths;
	
	lengths = malloc(sizeof(unsigned int)*);
	memcpy(lengths, array.lengths, array.dimensions);
	
	return lengths;
}

dim_array_t* alloc_dim_array(unsigned int dims, size_t* lengths)
{
	int i, mult=1;
	dim_array_t* array;

	if(dims < 1 || !lengths) return NULL;

	for(i=0; i<dims; i++) mult *= lengths[i];
	if(!(array = malloc(sizeof(dim_array_t)))) return NULL;
	array.dimensions = dims;

	if(!(array.length = malloc(sizeof(unsigned int)*dims))) {
		free(array);
		return NULL;
	}

	memcpy(array.lenghts, lengths, dims);

	if(!(array.elements = malloc(sizeof(void*)*mult))) {
		free(array.lengths);
		free(array);
		return NULL;
	}

	return array;
}

void free_dim_array(dim_array_t* array)
{
	free(array.elements);
	free(array.lengths);
	free(array);
}

unsigned int index(dim_array_t* array, unsigned int* indexes)
{
	int i, index=0, factor=1;

	for(i=array.dimensions-1; i>=0; i--) {
		index += indexes[i]*factor;
		factor *= array.lengths[i];
	}
	
	return index;
}

void* get(dim_array_t* array, unsigned int* indexes)
{
	return array.elements[index(array, indexes)];

}

void set(dim_array_t* array, unsigned int* indexes, void* value)
{
	array.elements[index(array, indexes)] = value;
}
