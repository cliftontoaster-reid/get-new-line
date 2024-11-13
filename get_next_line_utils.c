/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:40:41 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/12 17:07:18 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, char c)
{
	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}

int	ft_memset(char *str, char c, size_t n)
{
	if (str == NULL)
		return (-1);
	while (n > 0)
	{
		*str = c;
		str++;
		n--;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_memcpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL || n == 0)
		return (dest);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*str;
	int		l1;
	int		l2;

	if (s2 == NULL)
		return (s1);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (n > l2)
		n = l2;
	str = malloc(sizeof(char) * (l1 + n + 1));
	if (str == NULL)
		return (free(s1), NULL);
	if (s1)
		ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, n);
	str[l1 + n] = '\0';
	free(s1);
	return (str);
}
