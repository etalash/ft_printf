/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:08:46 by stalash           #+#    #+#             */
/*   Updated: 2024/03/27 15:08:46 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h> //NULL, malloc, free
# include <stdio.h> //testing
# include <stdarg.h> //varidic stuff
# include <unistd.h> //write

//**********prototype****************

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char const *s);
int		ft_putnbr(long long nb, int base, int upercase);
int		print_pointer(void *ptr);
// int print_digit_a(unsigned long nb, int base, int uppercase);
char	*ft_strchr(const char *s, int c);
int		ft_putnbr_1(long long nb);

#endif
