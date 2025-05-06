/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:34:39 by mlima-si          #+#    #+#             */
/*   Updated: 2025/05/06 17:26:10 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS
# define GET_NEXT_LINE_BONUS

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line_bonus(int fd);
size_t	ft_strlen(char *str);
int		ft_strchr(char *str);
void	*ft_memmov(char *stach);
char	*ft_strjoin(char *line, char *stach);
char	release(char *line, char *stach);

#endif