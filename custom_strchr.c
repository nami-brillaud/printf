/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_strchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:54:43 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/08 17:35:34 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_strchr(const char *s, int c)
{
	int	i;
	if (c == '\0') //if nothing is specified i.e. reach null, return -1 so arg processor skips flags
		return (-1);
	while (*(s + i) && *(s + i) != c)
		i++;
	if (*(s + i) == c)
		return (i);
	return (-1);//when you reach null ie when everything is scanned, return -1 too
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}