/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:54:08 by magneto           #+#    #+#             */
/*   Updated: 2022/06/01 14:53:47 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
# define CONVERSIONS "cspdiuxX%"
# include <stdint.h>

int		ft_printf(const char *str, ...);

int		print_c_1(char *str, int i, va_list args);

int		print_c_2(int c, int min, int left_justify);

int		print_s_1(char *str, int i, va_list args);

int		print_s_2(char *s, int min, int precision, char *str);

int		print_p_1(char *str, int i, va_list args);

int		print_p_2(void *ptr, int min, int left_justify);

int		print_d_i_1(char *str, int i, va_list args);

int		ft_strchrn(const char *s, int c, int n);

int		print_hexa_lower(unsigned int n);

int		print_hexa_upper(unsigned int n);

int		hexa_length(long int n);

int		nbr_len(int n);

int		nbr_len_unsigned(unsigned int n);

void	ft_putnbr_absolute(long int nb);

int		print_u_1(char *str, int i, va_list args);

int		print_x_1(char *str, int i, va_list args);

int		print_upperx_1(char *str, int i, va_list args);

int		hexa_length(long int n);

void	ft_putnbr_unsigned(long unsigned int nb);

int		print_hexa_lower_long(unsigned long long int nbr);

int		zero(char *str);

int		get_precision(char *str);

#endif