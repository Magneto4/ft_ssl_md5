#include <md5.h>

unsigned int k_constants[64] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501, 
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8, 
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, 
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1, 
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};


unsigned int f_operator(unsigned int x, unsigned int y, unsigned int z) {
  return ((x) & (y)) | ((~x) & (z));
}

unsigned int g_operator(unsigned int x, unsigned int y, unsigned int z) {
  return (((x) & (z)) | ((y) & (~z)));
}

unsigned int h_operator(unsigned int x, unsigned int y, unsigned int z) {
  return ((x) ^ (y) ^ (z));
}

unsigned int i_operator(unsigned int x, unsigned int y, unsigned int z) {
  return ((y) ^ ((x) | (~z)));
}

void run_round(unsigned int *initialisation_vectors, unsigned int *words, unsigned int round) {
  unsigned int  (*functions[4])(unsigned int, unsigned int, unsigned int) = {&f_operator, &g_operator, &h_operator, &i_operator};

  unsigned int bitshift_value[4][4] = {
    {7, 12, 17, 22},
    {5, 9, 14, 20},
    {4, 11, 16, 23},
    {6, 10, 15, 21}
  };

  unsigned int result;

  for (unsigned int i = 0; i < 16; i++) {
    unsigned int input_i;
    switch (round) {
      case 0:
        input_i = i;
        break;
      case 1:
        input_i = (5*i + 1) % 16;
        break;
      case 2:
        input_i = (3*i + 5) % 16;
        break;
      case 3:
        input_i = (7*i) % 16;
        break;
    }
    result = modular_additions((unsigned int[4]){
        functions[round](initialisation_vectors[1], initialisation_vectors[2], initialisation_vectors[3]),
        initialisation_vectors[0],
        words[input_i],
        k_constants[round * 16 + i],
      }, 4);
    result = left_rotate(result, bitshift_value[round][i % 4]);
    result = modular_addition(result, initialisation_vectors[1]);

    initialisation_vectors[0] = initialisation_vectors[3];
    initialisation_vectors[3] = initialisation_vectors[2];
    initialisation_vectors[2] = initialisation_vectors[1];
    initialisation_vectors[1] = result;
  }
}

void md5_algorithm(unsigned int *words, unsigned int *initialisation_vectors) {
  for (unsigned int i = 0; i < 4; i++) {
    run_round(initialisation_vectors, words, i);
  }
}

char *md5(char *input) {
  return algorithm_runner(1, input, &md5_algorithm, 4, (unsigned int[4]){0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476});
}