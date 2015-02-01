#include <stdio.h>
#include <stdlib.h>
#include "s_vector.h"

void assert_equal_sizet(size_t left, size_t right, const char* msg) {
	if(left != right) {
		printf("ERROR: %s\n", msg);
		exit (EXIT_FAILURE);
	}
}

void assert_equal_double(double left, double right, const char* msg) {
	if(left != right) {
		printf("ERROR: %s\n", msg);
		exit (EXIT_FAILURE);
	}
}

int main( int argc, const char* argv[] ) {
	const size_t SIZE = 1024;
	double value;
	struct s_vector vec;
	struct s_vector_iterator it;
	struct s_vector_iterator it_end;

	printf("begin test\n");
	s_vector_init(&vec, SIZE);

	assert_equal_sizet(vec.capacity, SIZE, "capacity wrong");
	assert_equal_sizet(vec.size, 0, "size wrong");

	s_vector_set(&vec, 5, 5.0);
	s_vector_set(&vec, 50, 50.0);

	assert_equal_sizet(vec.size, 2, "size wrong");

	it = s_vector_begin(&vec);
	it_end = s_vector_end(&vec);

	value = 0.0;
	while(!s_vector_iterator_eqaul(&it, &it_end)) {
		value += s_vector_iterator_value(&vec, &it);
		it = s_vector_iterator_next(&vec, &it);
	}
	assert_equal_double(value, 55.0, "test sum incorrect");

	s_vector_uninit(&vec);
	printf("end test\n");	
}