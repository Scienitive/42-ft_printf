/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:27:23 by alyasar           #+#    #+#             */
/*   Updated: 2022/02/04 12:30:22 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	extra_fnc(size_t *i, int _0x, char *str)
{
	if (_0x)
	{
		str[(*i)++] = 'x';
		str[(*i)++] = '0';
	}
}

char	*convert_base_to_16(unsigned long long dec, int _0x, int big)
{
	size_t				i;
	char				*str;
	unsigned long long	remainder;

	i = 0;
	str = malloc(100 * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (dec == 0)
		str[i++] = '0';
	while (dec != 0)
	{
		remainder = dec % 16;
		if (remainder < 10)
			str[i++] = '0' + remainder;
		else
			str[i++] = (87 - (big * 32)) + remainder;
		dec /= 16;
	}
	extra_fnc(&i, _0x, str);
	str[i] = '\0';
	return (str);
}

void	u_flag(va_list args, int *rtrn)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);
	ft_unsigned_putnbr_fd(u, 1, rtrn);
}

void	x_flag(va_list args, int big, int *rtrn)
{
	int				i;
	unsigned int	x;
	char			*str;

	x = va_arg(args, unsigned int);
	str = convert_base_to_16(x, 0, big);
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		write(1, &(str[i]), 1);
		(*rtrn)++;
		i--;
	}
	free(str);
}

void	p_flag(va_list args, int *rtrn)
{
	int					i;
	unsigned long long	p;
	char				*str;

	p = va_arg(args, unsigned long long);
	str = convert_base_to_16(p, 1, 0);
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		write(1, &(str[i]), 1);
		(*rtrn)++;
		i--;
	}
	free(str);
}
