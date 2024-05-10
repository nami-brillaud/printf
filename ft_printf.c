/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:55:20 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/10 17:54:56 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//printf("Hello %d", 5)
int	specifier_check(const char format, va_list ap) //looks at one character at the time
{
	int		n_add;

	n_add = 0;
	if (format == 'c')
		n_add += c_process(va_arg(ap, int));
	else if (format == 's')
		n_add += s_process(va_arg(ap, char *));
	else if (format == 'p')
		n_add += p_process(va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		n_add += d_i_process(va_arg(ap, int));
	else if (format == 'u')
		n_add += u_process(va_arg(ap, unsigned int));
	// else if (format == 'x')
	// 	n_add += x_process(&ap);
	// else if (format == 'X')
	// 	n_add += bigx_process(&ap);
	// else
	// 	n_add += percen_addt_process(&ap);
	return (n_add);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		n;

	n = 0;
	va_start(ap, format);
	if (!format)
		n = -1;
	while (*format)
	{
		if (*format != '%')
			n += ft_putchar_n(*format);
		else
			n += specifier_check(*(++format), ap); //you encounter the %, then advance of one step
		format++;
	}
	va_end(ap);
	return (n);
}

int	main(void)
{
	void *p = NULL;
	char c = 'i';
	char s[] = "haha";
	int d = INT_MIN;
	unsigned int u = -20;
	ft_printf("Hello c %c\n s %s\n p %p\n d %d\n u %u\n", c, s, p, d, u);
	system("leaks a.out");
	return (0);
}

// void	initialize_set(t_arg *set, int n)
// {
// 	set->flag[0] = 0;
// 	set->flag[1] = 0;
// 	set->width = -1; //idk why
// 	set->precision = -1; //idk why
// 	set->specifier = -1; //character so ok to put number
// 
// }
// 
// void	arg_processor(const char **start, const char **format, int *n, va_list *ap) //is it void
// {
// 	int		num;
// 	t_arg	set;
// 
// 	(*format)++;
// 	initialize_set(&set, *n); //you'll need n at some point later
// 	while ((num = num_strchr("0-", **format)) >= 0)//count_strchr returns an int indicating 
// 	//le combientieme among the string  matched
// 	{
// 		set.flag[num] = 1; //if there is the flag, set to 1
// 		(*format)++; //update each character here to run it thru num_strchr
// 	}
// 	set.width = ft_str_to_num(the 10 in your string above);
// 	if (**format == '.')
// 	{
// 		(*format++); //skip the dot
// 		set.precision = ft_str_to_num(the 5 in your string above);
// 	}
// 	set.specifier = num_strchr("cspdiuxX%", **format);
// 	//add code to update n
// 	}
// 
// void	comment_printer(const char **start, const char **format, int *n)
// {
// 	while (**format != '%' && **format)
// 		(*format)++;
// 	write(1, *start, *format - *start);
// 	*n += *format - *start;
// }
// 
// int	ft_printf(const char *format, ...)
// {
// 	va_list	ap;
// 	int		n;
// 	const char *start;
// 
// 	n = 0;
// 	va_start(ap, format);
// 	if (!format)
// 		n = -1;
// 	while (n >= 0 && *format)
// 	{
// 		start = format;
// 		if (*start != '%')
// 			comment_printer(&start, &format, &n);
// 		else
// 			arg_processor(&start, &format, &n, &ap);
// 	}
// 	va_end(ap);
// 	return (n);
// }