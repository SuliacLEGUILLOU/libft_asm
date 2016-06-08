/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 14:53:57 by sle-guil          #+#    #+#             */
/*   Updated: 2015/06/11 17:39:09 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include <string.h>

void	ft_bzero(void *p, size_t len);
void	ft_cat(int fd);

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);							// Bonus

void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memset(void *dst, int c, size_t len);

char	ft_tolower(int c);
char	ft_toupper(int c);

int		ft_puts(char *s);
int		ft_putstr(char *s);							// Bonus
int		ft_putstr_fd(char *s, int fd);				// Bonus

char	*ft_strcat(char *s1, const char *s2);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dst, const char *src);		// Bonus
int		ft_strcmp(const char *s1, const char *s2);	// Bonus

#endif
