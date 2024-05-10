/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:54:41 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/09 19:46:25 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "libft/libft.h" //you need this to use external functions!
# include <stdarg.h>

typedef struct s_arg
{
	int		flag[2];
	int		width;
	int		precision;
	char	specifier;
}	t_arg;

/* ft_print.c */
int		ft_printf(const char *format, ...);

/* ft_helpers.c */
int		ft_putchar_n(char c);
char	*ft_tolower_all(char *str);

/* ft_csp.c */
int		c_process(int nb);
int		s_process(char *str);
int		p_process(void *ptr);

/* ft_base.c */
char	*base_start(unsigned long long ptr, int base);
char	*base_change(unsigned long long ptr_alt, int base, char *str, int digits);

#endif