/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:55:20 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/08 18:33:08 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	initialize_set(t_arg *set, int n)
{
	set->flag[0] = 0;
	set->flag[1] = 0;
	set->width = -1; //idk why
	set->precision = -1; //idk why
	set->specifier = -1; //character so ok to put number
	
}

void	arg_processor(const char **start, const char **format, int *n, va_list *ap) //is it void
{
	int		num;
	t_arg	set;

	(*format)++;
	initialize_set(&set, *n); //you'll need n at some point later
	while ((num = num_strchr("0-", **format)) >= 0)//count_strchr returns an int indicating 
	//le combientieme among the string  matched
	{
		set.flag[num] = 1; //if there is the flag, set to 1
		(*format)++; //update each character here to run it thru num_strchr
	}
	set.width = ft_str_to_num(the 10 in your string above);
	if (**format == '.')
	{
		(*format++); //skip the dot
		set.precision = ft_str_to_num(the 5 in your string above);
	}
	set.specifier = num_strchr("cspdiuxX%", **format);
	//add code to update n
	}

void	comment_printer(const char **start, const char **format, int *n)
{
	while (**format != '%' && **format)
		(*format)++;
	write(1, *start, *format - *start);
	*n += *format - *start;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		n;
	const char *start;
	
	n = 0;
	va_start(ap, format);
	if (!format)
		n = -1;
	while (n >= 0 && *format)
	{
		start = format;
		if (*start != '%')
			comment_printer(&start, &format, &n);
		else
			arg_processor(&start, &format, &n, &ap);
	}
	va_end(ap);
	return (n);
}