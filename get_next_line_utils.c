/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:19:00 by mlima-si          #+#    #+#             */
/*   Updated: 2025/05/02 18:40:32 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s); //procurar a primeira ocorrencia de um char em uma string
char	*ft_strdup(const char *str); //duplicar uma string
size_t	ft_strlen(const char *str); //retorna o tamanho da string
char	*ft_substr(char const *s, unsigned int start, size_t len); //criar uma copia da string a partir do star e com "len" tamanho
char	*ft_strjoin(char const *s1, char const *s2); //juntar duas strings
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strcat(char *dest, char *src);

int	ft_strchr(const char *s)
{
	int	i;

	i = 0;
	//printf("looking for n_line\n");
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
	{
		//printf("found n_line, breaking loop\n");
		return (i);
	}
	//printf("n achou n_line\n");
	return (0);
}
int ft_find(const char s)
{
	
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*new_str;

	i = 0;
	new_str = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!new_str)
		return (0);
	while (i < ft_strlen(str))
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);

}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	subs = malloc((len + 1) * sizeof(char));
	if (subs)
	{
		ft_strlcpy(subs, s + start, len + 1);
		return (subs);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str)
	{
		i = 0;
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			str[i] = s2[j];
			i++;
			j++;
		}
		str[i] = 0;
		return (str);
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (src_size);
}

char	*ft_strcat(char *dest, char *src)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	//printf("entered cat\n");
	while (dest[c1] != '\0')
		c1++;
	while (src[c2] != '\0')
	{
		dest[c1] = src[c2];
		c1++;
		c2++;
	}
	dest[c1] = '\0';
	//printf("ok concat\n");
	return (dest);
}