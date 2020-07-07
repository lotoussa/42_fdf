/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:06 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:23:06 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i] && i < size)
		i++;
	k = i + ft_strlen(src);
	if (i != size)
	{
		while (i < size - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (k);
}
