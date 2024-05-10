/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:20:46 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/10 18:44:35 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int d_i_process(int nb)
{	
	char	*str;
	int		digits;

	str = ft_itoa(nb);
	digits = ft_strlen(str);
	write(1, str, digits);
	free (str);
	return (digits);
}

int	u_process(unsigned int nb)
{
	unsigned long	ul;
	int				digits;

	ul = (unsigned long)nb;//this wraps negative values automatically !!
	digits = 1;
	if (nb >= 10) //probably not nb
		digits += u_process(nb / 10); //counting the digits 100 -> 10 (2))
	ft_putchar_fd((ul % 10) + '0', 1); //print rightmost digit one by one (as printing doesn't care about size.)
	return (digits);
}

int	x_process(unsigned int nb)
{
	char	*str;
	int		len;

	str = ft_tolower_all(base_start((unsigned long long)nb, 16)); //???? the cast
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	bigx_process(unsigned int nb)
{
	char	*str;
	int		len;

	str = ft_toupper_all(base_start((unsigned long long)nb, 16)); //???? the cast
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}


