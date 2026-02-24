/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:37:57 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/04/30 12:37:59 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*ft_get_word(const char *s, char c, int *index)
{
	int		start;
	int		word_len;
	char	*word;
	int		i;

	start = *index;
	while (s[start] == c && s[start] != '\0')
		start++;
	word_len = 0;
	while (s[start + word_len] != '\0' && s[start + word_len] != c)
		word_len++;
	word = malloc(sizeof(char) * (word_len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	*index = start + word_len;
	return (word);
}

static void	ft_free_all(char **result, int filled)
{
	while (--filled >= 0)
		free(result[filled]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		result[j] = ft_get_word(s, c, &i);
		if (result[j] == NULL)
		{
			ft_free_all(result, j);
			return (NULL);
		}
		j++;
	}
	result[j] = NULL;
	return (result);
}
