/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:32:43 by alyasar           #+#    #+#             */
/*   Updated: 2022/02/04 12:35:13 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	c_flag(va_list args, int *rtrn);
void	s_flag(va_list args, int *rtrn);
void	d_flag(va_list args, int *rtrn);
void	p_flag(va_list args, int *rtrn);
void	x_flag(va_list args, int big, int *rtrn);
void	u_flag(va_list args, int *rtrn);
void	flag_redirect(const char *input, va_list args, int i, int *rtrn);
int		ft_printf(const char *input, ...);
char	*convert_base_to_16(unsigned long long dec, int _0x, int big);
void	ft_unsigned_putnbr_fd(unsigned int n, int fd, int *rtrn);
void	ft_putchar_fd(char c, int fd, int *rtrn);
void	ft_putnbr_fd(int n, int fd, int *rtrn);
size_t	ft_strlen(const char *s);

#endif
