#include <algorithm_runner.h>

char *algorithm_runner(int encode, char *input, void (*algorithm)(unsigned int *, unsigned int *), unsigned int vector_size, unsigned int *initialisation_vectors) {
  char **blocks = blocks_with_padding(input);
  if (!blocks) {
    return NULL;
  }
  unsigned int result[vector_size];

  for (unsigned int i = 0; i < vector_size; i++) {
    result[i] = initialisation_vectors[i];
  }

  for (unsigned int i = 0; blocks[i]; i++) {
    for (unsigned int i = 0; i < vector_size; i++) {
      initialisation_vectors[i] = result[i];
    }
    unsigned int *words = split_into_words(blocks[i]);
    if (!words) {
      for (unsigned int k = 0; blocks[k]; k++) {
        free(blocks[k]);
      }
      free (blocks);
      return NULL;
    }

    free(blocks[i]);

    if (encode) {
      if (!blocks[i + 1]) {
        for (unsigned int i = 0; i < 14; i++) {
          words[i] = endian_encode(words[i]);
        }
      } else {
        for (unsigned int i = 0; i < 16; i++) {
          words[i] = endian_encode(words[i]);
        }
      }
        unsigned int tmp = words[15];
        words[15] = words[14];
        words[14] = tmp;
    }

    //do the whole algorithm
    algorithm(words, initialisation_vectors);

    free (words);

    for (unsigned int i = 0; i < vector_size; i++) {
      result[i] = modular_addition(result[i], initialisation_vectors[i]);
    }
  }
  free(blocks);

  char *res = malloc(sizeof(char) * (vector_size * 8 + 1));
  if (!res) {
    return NULL;
  }

  for (unsigned int i = 0; i < vector_size; i++) {
    char *part_result;
    if (encode) {
      part_result = hex_to_string(endian_encode(result[i]));
    } else {
      part_result = hex_to_string(result[i]);
    }
    if (!part_result) {
      free(res);
      return NULL;
    }
    ft_strlcpy(res + i * 8, part_result, 9);
    free(part_result);
  }

  return res;
}