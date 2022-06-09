/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:31:04 by alyasar           #+#    #+#             */
/*   Updated: 2022/02/04 12:32:12 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	flag_redirect(const char *input, va_list args, int i, int *rtrn)
{
	if (input[i + 1] == 'c')
		c_flag(args, rtrn);
	else if (input[i + 1] == 's')
		s_flag(args, rtrn);
	else if (input[i + 1] == 'd' || input[i + 1] == 'i')
		d_flag(args, rtrn);
	else if (input[i + 1] == 'p')
		p_flag(args, rtrn);
	else if (input[i + 1] == 'x')
		x_flag(args, 0, rtrn);
	else if (input[i + 1] == 'X')
		x_flag(args, 1, rtrn);
	else if (input[i + 1] == 'u')
		u_flag(args, rtrn);
	else if (input[i + 1] == '%')
	{
		write(1, "%", 1);
		(*rtrn)++;
	}
}

void	ft_unsigned_putnbr_fd(unsigned int n, int fd, int *rtrn)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd, rtrn);
	else
	{
		ft_unsigned_putnbr_fd(n / 10, fd, rtrn);
		ft_unsigned_putnbr_fd(n % 10, fd, rtrn);
	}
}

void	ft_putchar_fd(char c, int fd, int *rtrn)
{
	write(fd, &c, 1);
	(*rtrn)++;
}

void	ft_putnbr_fd(int n, int fd, int *rtrn)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd, rtrn);
		ft_putchar_fd('2', fd, rtrn);
		ft_putnbr_fd(147483648, fd, rtrn);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd, rtrn);
		ft_putnbr_fd(-n, fd, rtrn);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd, rtrn);
	else
	{
		ft_putnbr_fd(n / 10, fd, rtrn);
		ft_putnbr_fd(n % 10, fd, rtrn);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
