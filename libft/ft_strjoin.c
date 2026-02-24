/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:43:19 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/04/29 11:43:20 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		d;
	char	*str;

	i = 0;
	d = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[d] != '\0')
	{
		str[i] = s2[d];
		d++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
