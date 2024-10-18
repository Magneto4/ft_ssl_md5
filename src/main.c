#include <main.h>

unsigned int ft_strcmp(char *s1, char *s2) {
  while (*s1 && *s2 && *s1 == *s2) {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}

char *read_fd(unsigned int fd) {
	char buffer[1024];
	char *res = malloc(sizeof(char));
	if (!res) {
		ft_printf("ft_ssl: Error: Could not allocate memory.\n");
		exit(1);
	}
	res[0] = '\0';
	int i = 0;
	char ch;
	while(read(fd, &ch, 1) > 0)
	{
		buffer[i] = ch;
		i++;
		buffer[i] = '\0';
		if (i == 1023) {
			char *tmp = res;
			res = ft_strjoin(res, buffer);
			free(tmp);
			if (!res) {
				ft_printf("ft_ssl: Error: Could not allocate memory.\n");
				exit(1);
			}
			i = 0;
		}
	}
	char *tmp = res;
	res = ft_strjoin(res, buffer);
	free(tmp);
	return res;
}


char *read_file(char *file_name) {
	int fd = open(file_name, O_RDONLY);
	if (fd == -1) {
		ft_printf("ft_ssl: %s: No such file or directory\n", file_name);
		return NULL;
	};
	char *res = read_fd(fd);
	if (res) {
		ft_printf("ft_ssl: Error: Could not allocate memory.\n");
		exit(1);
	}
	close(fd);
	return res;
}

void	parse_args(unsigned int argc, char **argv, t_flags flags, char *(*command)(char *)) {
	t_input input;
	input.type = NULL_INPUT;
	int found_s = 0;
	int found_arg = 0;

	if (flags.p) {
		input.type = STDIN;
		input.str = read_fd(0);
		char *res = command(input.str);
		free(input.str);
		if (!res) {
			ft_printf("ft_ssl: Error: Could not allocate memory.\n");
			exit(1);
		}
		print_result(res, flags, input);
		free(res);
	}

  for (unsigned int j = 2; j < argc; j++) {
		if (!found_s && ft_strcmp(argv[j], "-s") == 0) {
			found_s = 1;
			input.type = STRING;
			input.str = argv[j + 1];
			j++;
		}
		else if (ft_strcmp(argv[j], "-s") && argv[j][0] == '-') {
			continue;
		} else {
			input.type = FILE_INPUT;
			input.file_name = argv[j];
			input.str = read_file(argv[j]);
			if (!input.str) {
				input.type = INVALID_INPUT;
			}
		}

		found_arg = 1;

		if (input.type == INVALID_INPUT) {
			continue;
		}

		char *res = command(input.str);
		if (!res) {
			ft_printf("ft_ssl: Error: Could not allocate memory.\n");
			exit(1);
		}
		print_result(res, flags, input);
		free(res);
  }
	input.type = NULL_INPUT;

	if (!found_arg && !flags.p) {
		input.type = STDIN;
		input.str = read_fd(0);
		char *res = command(input.str);
		free(input.str);
		if (!res) {
			ft_printf("ft_ssl: Error: Could not allocate memory.\n");
			exit(1);
		}
		print_result(res, flags, input);
		free(res);
	}
}

t_flags parse_flags(unsigned int argc, char **argv) {
	t_flags flags = {0, 0, 0, 0};

	for (unsigned int i = 2; i < argc; i++) {
		if (argv[i][0] == '-') {
			for (unsigned int j = 1; argv[i][j]; j++) {
				switch (argv[i][j]) {
					case 'p':
						flags.p = 1;
						break;
					case 'q':
						flags.q = 1;
						break;
					case 'r':
						flags.r = 1;
						break;
					case 's':
						break;
					default:
						ft_printf("ft_ssl: Error: '%c' is an invalid flag.\nFlags:\n-p -q -r -s\n", argv[i][j]);
						exit(1);
				}
			}
		}
	}

	return flags;
}

int main (int argc, char **argv) {
  if (argc == 1) {
    ft_printf("usage: ft_ssl command [flags] [file/string]\n");
    return 1;
  }

	t_flags flags = parse_flags(argc, argv);
	(void)flags;

	char *commands[COMMANDS] = {"md5", "sha256"};
  char *(*command_functions[COMMANDS])(char *) = {&md5, &sha_256};

	int found = 0;

	for (unsigned int i = 0; i < COMMANDS; i++) {
    if (ft_strcmp(argv[1], commands[i]) == 0) {
			char *(*command_function)(char *) = command_functions[i];
			parse_args(argc, argv, flags, command_function);
			found = 1;
			break;
    }
  }

  if (!found) {
    ft_printf("ft_ssl: Error: '%s' is an invalid command.\nCommands:\nmd5\nsha256\nFlags:\n-p -q -r -s\n", argv[1]);
    return 1;
  }
  
  return 0;
}