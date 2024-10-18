#ifndef UTILS_H
# define UTILS_H

#include <ft_printf.h>

char  **split_into_sized_blocks(char *str, unsigned int block_size);

void print_bits(char *str, unsigned int block_size);

unsigned int *split_into_words(char *str);

void print_int_bits(size_t n);

unsigned int modular_addition(unsigned int a, unsigned int b);

unsigned int left_rotate(unsigned int n, unsigned int s);

unsigned int right_rotate(unsigned int n, unsigned int s);

unsigned int endian_encode(unsigned int n);

unsigned int endian_decode(unsigned int n);

char *hex_to_string(unsigned int n);

char **blocks_with_padding(char *str);

unsigned int modular_additions(unsigned int *a, unsigned int size);

#endif