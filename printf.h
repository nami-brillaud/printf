/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:54:41 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/08 18:33:30 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <unistd.h>
# include <stdarg.h>

typedef struct s_arg
{
	int		flag[2];
	int		width;
	int		precision;
	char	specifier;
}	t_arg;

#endif