/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:53:57 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/10 16:12:21 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*base_change(unsigned long long ptr_alt, int base, char *str, int digits)
{
	while (ptr_alt != 0)
	{
		if ((ptr_alt % 16) < 10)
			str[digits - 1] = (ptr_alt % base) + 48; //-1 for the null. DECIMAL
		else //e.g. 16
			str[digits - 1] = (ptr_alt % base) + 55; //why 55??. HEXADECIMAL
		ptr_alt = ptr_alt / base; //go to next digit
		digits--;
	}
	return (str); //completed string
}

char	*base_start(unsigned long long ptr, int base)//is ul sufficient?
{
	unsigned long long ptr_alt;
	char		*str;
	int			digits;

	digits = 0;
	ptr_alt = ptr;
	if (ptr == 0) //because it's an unsigned long
		return(ft_strdup("0"));
	while (ptr != 0) //dividing
	{
		ptr = ptr / base;
		digits++; //counting number of digits to allocate
	}
	str = ft_calloc(digits + 1, sizeof(char)); //1 for the null. where is the free?
	if (!str)
		return (0); //0 because we are returning int!
	str = base_change(ptr_alt, base, str, digits);
	return (str);
}