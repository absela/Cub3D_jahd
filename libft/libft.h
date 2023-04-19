/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:28:58 by abelahce          #+#    #+#             */
/*   Updated: 2023/04/02 05:10:54 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen(const char *str);
int		ft_toupper(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_memset(void *s1, int s2, size_t n);
void	ft_bzero(void *s1, size_t n);
void	*ft_memcpy(void	*s1, const void	*s2, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char	*s1, const char	*s2, size_t n);
size_t	ft_strlcat(char	*s1, const char	*s2, size_t n);
char	*ft_strrchr(const char *s1, int n);
char	*ft_strchr(const char *s1, int n);
void	*ft_memchr(const void *s1, int c, size_t n);
int		ft_memcmp(const void	*s1, const void *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);

#endif