/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:46:15 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/05/05 18:38:10 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*temp;

	i = 0;
	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
	{
		temp = malloc(1);
		if (temp == NULL)
			return (NULL);
		temp[0] = '\0';
		return (temp);
	}
	if (len > str_len - start)
		len = str_len - start;
	temp = malloc(len + 1);
	if (temp == NULL)
		return (NULL);
	while (i < len)
		temp[i++] = s[start++];
	temp[i] = '\0';
	return (temp);
}
