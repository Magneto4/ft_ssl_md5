#ifndef MAIN_H
# define MAIN_H


# include <md5.h>
# include <ft_printf.h>
# include <fcntl.h>
# include <sha_256.h>

# define COMMANDS 2

typedef struct s_flags {
  unsigned int p;
  unsigned int q;
  unsigned int r;
  unsigned int s;
} t_flags;

typedef enum input_type {
  STRING,
  FILE_INPUT,
  STDIN,
  NULL_INPUT,
  INVALID_INPUT
} t_input_type;

typedef struct s_input {
  char *str;
  char *file_name;
  t_input_type type;
} t_input;

# include <print_output.h>


#endif