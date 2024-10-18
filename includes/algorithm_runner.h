#ifndef ALGORITHM_RUNNER_H
# define ALGORITHM_RUNNER_H

#include <utils.h>

char *algorithm_runner(int endian_encode, char *input, void (*algorithm)(unsigned int *, unsigned int *), unsigned int vector_size, unsigned int *initialisation_vectors);

#endif