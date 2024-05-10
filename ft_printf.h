/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:54:41 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/10 18:23:04 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h" //you need this to use external functions!
#include <stdarg.h> //review header format

/* ft_print.c */
int		ft_printf(const char *format, ...);

/* ft_helpers.c */
int		ft_putchar_n(char c);
char	*ft_tolower_all(char *str);
char	*ft_toupper_all(char *str);

/* ft_csp.c */
int		c_process(int nb);
int		s_process(char *str);
int		p_process(void *ptr);

/* ft_diux.c */
int		d_i_process(int nb);
int		u_process(unsigned int nb);
int		x_process(unsigned int nb);
int		bigx_process(unsigned int nb);
/* ft_base.c */
char	*base_start(unsigned long long ptr, int base);
char	*base_change(unsigned long long ptr_alt, int base, char *str, int digits);

#endif