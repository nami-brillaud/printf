/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:54:43 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/10 17:51:59 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar_n(const char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_tolower_all(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return(str);
}

// int	num_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (c == '\0')
// 		return (-1);
// 	while (*(s + i) && *(s + i) != c)
// 		i++;
// 	if (*(s + i) == c)
// 		return (i);
// 	return (-1);
// }
