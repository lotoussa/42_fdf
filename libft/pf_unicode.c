/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_unicode.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:13 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:08 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*pf_simple_char(int i)
{
	char	*str;

	if (!(str = ft_memalloc(2)))
		return (NULL);
	i = i & 0b01111111;
	*str = i;
	return (str);
}

static char		*pf_double_char(int i)
{
	int		p[2];
	char	*str;

	p[0] = i & 0b111111;
	p[0] = p[0] + 0b10000000;
	p[1] = i & 0b11111000000;
	p[1] = p[1] >> 6;
	p[1] = p[1] + 0b11000000;
	if (!(str = ft_memalloc(3)))
		return (NULL);
	str[0] = p[1];
	str[1] = p[0];
	return (str);
}

static char		*pf_triple_char(int i)
{
	int		p[3];
	char	*str;

	p[0] = (i & 0b111111) + 0b10000000;
	p[1] = ((i & 0b111111000000) >> 6) + 0b10000000;
	p[2] = ((i & 0b1111000000000000) >> 12) + 0b11100000;
	if (!(str = ft_memalloc(4)))
		return (NULL);
	str[0] = p[2];
	str[1] = p[1];
	str[2] = p[0];
	return (str);
}

static char		*pf_quad_char(int i)
{
	int		p[4];
	char	*str;

	p[0] = (i & 0b111111) + 0b10000000;
	p[1] = ((i & 0b111111000000) >> 6) + 0b10000000;
	p[2] = ((i & 0b111111000000000000) >> 12) + 0b10000000;
	p[3] = ((i & 0b111000000000000000000) >> 18) + 0b11110000;
	if (!(str = ft_memalloc(sizeof(char) * 5)))
		return (NULL);
	str[0] = p[3];
	str[1] = p[2];
	str[2] = p[1];
	str[3] = p[0];
	return (str);
}

char			*pf_unicode(int i)
{
	int		len;
	int		j;

	j = i;
	len = 0;
	while (j > 0)
	{
		j = j >> 1;
		len++;
	}
	if (len <= 7)
		return (pf_simple_char(i));
	else if (len <= 11)
		return (pf_double_char(i));
	else if (len <= 16)
		return (pf_triple_char(i));
	else
		return (pf_quad_char(i));
}
