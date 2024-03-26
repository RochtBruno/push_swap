/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:25:15 by bruno             #+#    #+#             */
/*   Updated: 2024/03/25 19:48:34 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_get_words(char *str, char sep)
{
	size_t	count_word;

	if (!str)
		return (0);
	count_word = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str)
		{
			count_word++;
			while (*str && *str != sep)
				str++;
		}
	}
	return (count_word);
}

static	char	*ft_get_string(char const *s, size_t *start, char sep)
{
	size_t	index;
	size_t	start_s;
	size_t	total_len;

	index = 0;
	start_s = *start;
	while (s[start_s + index] && s[start_s + index] != sep)
		index++;
	total_len = (start_s + index) - start_s;
	*start += index;
	return (ft_substr(s, start_s, total_len));
}

static	char	**ft_free_all(char **ptr, int i_word)
{
	while (i_word >= 0)
		free(ptr[i_word--]);
	free(ptr);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	size_t	i_word;
	size_t	index;
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (ft_get_words((char *)s, c) + 1));
	if (!ptr)
		return (NULL);
	i_word = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index])
		{
			ptr[i_word] = ft_get_string(s, &index, c);
			if (ptr[i_word] == NULL)
				return (ft_free_all(ptr, (int)--i_word));
			i_word++;
		}
	}
	ptr[i_word] = NULL;
	return (ptr);
}
