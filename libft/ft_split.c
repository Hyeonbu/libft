/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 05:04:54 by chanjeon          #+#    #+#             */
/*   Updated: 2022/01/30 05:30:37 by chanjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_malloc(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

size_t	strs_index(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			cnt++;
		}
		else
		{
			while (s[i] == c && s[i])
				i++;
		}
	}
	return (cnt);
}

void	split_index(char **strs, char const *s, char c, size_t cnt)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = 0;
	i = -1;
	while (++i < cnt && s[len])
	{
		while (s[len] == c && s[len])
			len++;
		j = len;
		while (s[len] != c && s[len])
			len++;
		strs[i] = ft_substr(s, j, len - j);
		if (!strs[i])
			free_malloc(strs);
	}
	strs[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	cnt;

	if (!s)
		return (NULL);
	cnt = strs_index(s, c);
	strs = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!strs)
		return (NULL);
	split_index(strs, s, c, cnt);
	return (strs);
}
