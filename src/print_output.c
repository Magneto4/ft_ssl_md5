#include "print_output.h"

void print_suffix(t_input input, t_flags flags) {
		switch (input.type) {
		case STRING:
			if (flags.r)
				ft_printf("\"%s\"", input.str);
			else
				ft_printf("MD5 (\"%s\") = ", input.str);
			break;
		case FILE_INPUT:
			if (flags.r)
				ft_printf("%s", input.file_name);
			else
				ft_printf("MD5 (%s) = ", input.file_name);
			break;
		case STDIN:
			if (flags.p)
				ft_printf("(\"%s\")= ", input.str);
			else
				ft_printf("(STDIN)= ");
		default:
			break;
	}
}

void	print_result(char *res, t_flags flags, t_input input) {
	if ((!flags.r || input.type == STDIN) && !flags.q) {
		print_suffix(input, flags);
	}

	ft_printf("%s", res);

	if ((flags.r && input.type != STDIN) && !flags.q) {
		ft_printf(" ");
		print_suffix(input, flags);
	}

	ft_printf("\n");

}
