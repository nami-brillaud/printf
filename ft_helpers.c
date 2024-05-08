/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:54:43 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/08 18:34:00 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	num_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (-1);
	while (*(s + i) && *(s + i) != c)
		i++;
	if (*(s + i) == c)
		return (i);
	return (-1);
}
