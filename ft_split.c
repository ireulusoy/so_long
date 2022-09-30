/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irulusoy <irulusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:40:42 by irulusoy          #+#    #+#             */
/*   Updated: 2022/09/29 23:23:45 by irulusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

char	*ft_strdup(const char *str);

size_t	ft_word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	**ft_free_ptr(char **s, int i)
{
	while (--i >= 0 && s[i])
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
	return (NULL);
}

const char	*nexts(char const *s, char c)
{
	while (*s && *s != c)
		++s;
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	new_len;

	if (!s || (unsigned int)ft_strlen((char *)s) < start || len > 2147483647)
		return (ft_strdup(""));
	new_len = ft_strlen((char *)s + start);
	if (new_len < len)
		len = new_len;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, (char *)s + start, len + 1);
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	char			**buf;
	char			*from;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	buf = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!buf)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			s = nexts(s, c);
			buf[i++] = ft_substr(from, 0, (s - from));
			if (!buf)
				return (ft_free_ptr (buf, i));
		}
		else
			++s;
	}
	buf[i] = NULL;
	return (buf);
}
