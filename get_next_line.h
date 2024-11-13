/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:35:59 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/12 17:04:46 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 621
# endif

char	*get_next_line(int fd);
char	*ft_strchr(char *str, char c);
char	*ft_strnjoin(char *s1, char *s2, int n);
int		ft_memset(char *str, char c, size_t n);
int		ft_strlen(char *str);
char	*ft_memcpy(char *dest, char *src, size_t n);

#endif