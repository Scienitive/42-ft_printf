/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:25:47 by alyasar           #+#    #+#             */
/*   Updated: 2022/02/04 12:26:42 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	c_flag(va_list args, int *rtrn)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	(*rtrn)++;
}

void	s_flag(va_list args, int *rtrn)
{
	size_t		i;
	const char	*str;

	i = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		write(1, &(str[i]), 1);
		(*rtrn)++;
		i++;
	}
}

void	d_flag(va_list args, int *rtrn)
{
	int	d;

	d = va_arg(args, int);
	ft_putnbr_fd(d, 1, rtrn);
}

int	ft_printf(const char *input, ...)
{
	size_t	i;
	va_list	args;
	int		rtrn;

	rtrn = 0;
	va_start(args, input);
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] != '%')
		{
			write(1, &(input[i]), 1);
			rtrn++;
		}
		else
		{
			flag_redirect(input, args, i, &rtrn);
			i++;
		}
		i++;
	}
	va_end(args);
	return (rtrn);
}
/*
#include <stdio.h>

int main()
{
	ft_printf(" NULL %s NULL ", NULL);
	ft_printf("\n");
	printf(" NULL %s NULL ", NULL);
	printf("\n");
}
*/
