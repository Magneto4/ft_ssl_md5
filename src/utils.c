#include <utils.h>

char  **split_into_sized_blocks(char *str, unsigned int block_size) {
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;

    unsigned int len = ft_strlen(str);
    char **blocks = malloc(sizeof(char *) * (len / block_size + 1));
    if (!blocks) {
      return NULL;
    }

    for (i = 0; i < len; i += block_size) {
      blocks[j] = malloc(sizeof(char) * block_size);
      if (!blocks[j]) {
        for (unsigned int k = 0; k < j; k++) {
          free(blocks[k]);
        }
        free(blocks);
        return NULL;
      }
      ft_bzero(blocks[j], block_size);
      for (k = 0; k < block_size; k++) {
        if (i + k < len) {
          blocks[j][k] = str[i + k];
        } else {
          blocks[j][k] = 0;
        }
      }
      j++;
    }
    blocks[j] = 0;
    return blocks;
}

unsigned int *split_into_words(char *str) {
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;

    unsigned int len = 16 * 4;
    unsigned int *words = malloc(sizeof(unsigned int) * (16));
    if (!words) {
      return NULL;
    }

    for (i = 0; i < len; i += 4) {
        words[j] = 0;
        for (k = 0; k < 4; k++) {
          words[j] |= (str[i + k] & 0xff) << (8 * (3 - k));
        }
        j++;
    }
    for (i = j; i < 16; i++) {
        words[i] = 0;
    }
    words[j] = 0;
    return words;
}

unsigned int left_rotate(unsigned int n, unsigned int s) {
  return (n << s) | (n >> (32 - s));
}

unsigned int right_rotate(unsigned int n, unsigned int s) {
  return (n >> s) | (n << (32 - s));
}

char **blocks_with_padding(char *str) {
  size_t block_size = 512 / 8;
  char **blocks = split_into_sized_blocks(str, block_size);

  if (!blocks) {
    return NULL;
  }

  size_t len = 0;

  while (blocks[len]) {
      len++;
  }

  unsigned int block_to_add = len - 1;

  if (ft_strlen(blocks[len - 1]) >= block_size - 8) {
    len++;
    char **tmp_blocks = malloc(sizeof(char *) * (len + 1));
    if (!tmp_blocks) {
      return NULL;
    }
    for (size_t i = 0; i < len - 1; i++) {
      tmp_blocks[i] = blocks[i];
    }
    free(blocks);
    blocks = tmp_blocks;
    blocks[len - 1] = malloc(sizeof(char) * block_size);
    if (!blocks[len - 1]) {
      for (size_t i = 0; i < len - 1; i++) {
        free(blocks[i]);
      }
      free(blocks);
      return NULL;
    }
    ft_bzero(blocks[len - 1], block_size);
    blocks[len] = 0;
  }

  // adding the 10000000 to the end of the block with padding
  blocks[block_to_add][ft_strlen(blocks[block_to_add])] = 0b10000000;

  //TODO handle integer overflow
  // adding the length of the original message to the last 8 bytes of the last block
  size_t original_len = ft_strlen(str) * 8;

  for (size_t i = 0; i < 8; i++) {
    blocks[len - 1][block_size - 1 - i] = (original_len >> (i * 8)) & 0xff;
  }

  return blocks;
}

void print_bits(char *str, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        if (i && i % 8 == 0)
          ft_printf("\n");
        for (unsigned int j = 0; j < 8; j++) {
            ft_printf("%i", (str[i] >> (7 - j)) & 1);
        }
        ft_printf(" ");
    }
    ft_printf("\n");
}

void print_int_bits(size_t n) {
    for (unsigned int i = 0; i < 32; i++) {
        if (i && i % 8 == 0)
          ft_printf(" ");
        ft_printf("%i", (n >> (31 - i)) & 1);
    }
    ft_printf("\n");
}

unsigned int modular_addition(unsigned int a, unsigned int b) {
  long int result = (long int)a + (long int)b;
  result = result % (0x100000000);
  return (unsigned int)result;
}

unsigned int endian_encode(unsigned int n) {
  return ((n & 0xff) << 24) | ((n & 0xff00) << 8) | ((n & 0xff0000) >> 8) | ((n & 0xff000000) >> 24);
}

unsigned int endian_decode(unsigned int n) {
  return ((n & 0xff) << 24) | ((n & 0xff00) << 8) | ((n & 0xff0000) >> 8) | ((n & 0xff000000) >> 24);
}

char *hex_to_string(unsigned int n) {
  char *str = malloc(sizeof(char) * 8);
  if (!str) {
    return NULL;
  }

  for (unsigned int i = 0; i < 8; i++) {
    str[7 - i] = "0123456789abcdef"[(n >> (i * 4)) & 0xf];
  }

  return str;
}

unsigned int modular_additions(unsigned int *a, unsigned int size) {
  unsigned int result = 0;
  for (unsigned int i = 0; i < size; i++) {
    result = modular_addition(result, a[i]);
  }
  return result;
}