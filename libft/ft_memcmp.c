/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:35:33 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/04/29 11:35:36 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s3;
	const unsigned char	*s4;

	i = 0;
	s3 = (const unsigned char *) s1;
	s4 = (const unsigned char *) s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s3[i] != s4[i])
			return ((unsigned char)s3[i] - (unsigned char)s4[i]);
		i++;
	}
	return (0);
}
