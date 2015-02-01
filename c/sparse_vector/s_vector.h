#ifndef __SPARSE_MATRIX__
#define __SPARSE_MATRIX__

#include "stddef.h"

struct s_vector {
	size_t capacity;
	size_t size;
	size_t *dense;
	size_t *sparse;
	double *data;
};

struct s_vector_iterator {
	size_t dense_pos;
};

void s_vector_init(struct s_vector* vec, size_t capacity);
void s_vector_uninit(struct s_vector* vec);

struct s_vector* s_vector_alloc(size_t capacity);
void s_vector_free(struct s_vector* vec);

void s_vector_clear(struct s_vector* vec);
int s_vector_has(struct s_vector* vec, size_t i);
void s_vector_set(struct s_vector* vec, size_t i, double d);
int s_vector_get(struct s_vector* vec, size_t i, double * d);

struct s_vector_iterator s_vector_begin(struct s_vector* vec);
struct s_vector_iterator s_vector_end(struct s_vector* vec);

double s_vector_iterator_value(struct s_vector* vec, struct s_vector_iterator* it);
struct s_vector_iterator s_vector_iterator_next(struct s_vector* vec, struct s_vector_iterator* it);
int s_vector_iterator_eqaul(struct s_vector_iterator* it_left, struct s_vector_iterator* it_right);

#endif