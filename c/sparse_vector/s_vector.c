#include "s_vector.h"
#include "stdlib.h"

void s_vector_init(struct s_vector* vec, size_t capacity) {
	vec->capacity = capacity;
	vec->size = 0;
	vec->dense = (size_t *) malloc(sizeof(size_t)*capacity);
	vec->sparse = (size_t *) malloc(sizeof(size_t)*capacity);
	vec->data = (double *) malloc(sizeof(double)*capacity);
}

void s_vector_uninit(struct s_vector* vec) {
	free(vec->dense);
	free(vec->sparse); 
	free(vec->data);
}

struct s_vector* s_vector_alloc(size_t capacity) {
	struct s_vector* vec;
	vec  = (struct s_vector*) malloc(sizeof(struct s_vector));
	s_vector_init(vec, capacity);
	return vec;
}

void s_vector_free(struct s_vector* vec) {
	s_vector_uninit(vec);
	free(vec);
}

void s_vector_clear(struct s_vector* vec) {
	vec->size = 0;
}

int s_vector_has(struct s_vector* vec, size_t i) {	
	size_t pos;
	pos = vec->sparse[i];
	return pos < vec->size && vec->dense[pos] == i;
}

void s_vector_set(struct s_vector* vec, size_t i, double d) {
	if( !s_vector_has(vec, i) ) {
		vec->dense[vec->size] = i;
		vec->sparse[i] = vec->size;
		++vec->size;
	}
	vec->data[i] = d;
}

int s_vector_get(struct s_vector* vec, size_t i, double * d) {	
	(*d) = vec->data[i];
	return s_vector_has(vec, i);
}

struct s_vector_iterator s_vector_begin(struct s_vector* vec) {
	struct s_vector_iterator it;
	it.dense_pos = 0;
	return it;
}

struct s_vector_iterator s_vector_end(struct s_vector* vec) {
	struct s_vector_iterator it;
	it.dense_pos = vec->size;
	return it;
}

double s_vector_iterator_value(struct s_vector* vec, struct s_vector_iterator* it) {
	return vec->data[vec->dense[it->dense_pos]];
}

struct s_vector_iterator s_vector_iterator_next(struct s_vector* vec, struct s_vector_iterator* it) {
	struct s_vector_iterator it_new;
	it_new.dense_pos = it->dense_pos + 1;
	return it_new;
}

int s_vector_iterator_eqaul(struct s_vector_iterator* it_left, struct s_vector_iterator* it_right) {
	return it_left->dense_pos == it_right->dense_pos;
}