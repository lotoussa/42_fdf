/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:03 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:23:03 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dest;
	unsigned char			ch;
	const unsigned char		*source;

	dest = dst;
	source = src;
	ch = c;
	while (n--)
	{
		*dest = *source;
		dest++;
		if (*source == ch)
			return (dest);
		source++;
	}
	return (NULL);
}
