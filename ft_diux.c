/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:20:46 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/10 17:50:51 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
	if (nb >= 10)
		digits += u_process(nb / 10); //counting the digits 100 -> 10 (2))
	ft_putchar_fd((ul % 10) + '0', 1); //print rightmost digit one by one (as printing doesn't care about size.)
	return (digits);
}