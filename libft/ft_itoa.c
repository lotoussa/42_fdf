/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:02 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:23:02 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static long	ft_intlen(long n)
{
	int		i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	j;

	j = n;
	i = ft_intlen(j);
	if (!j)
		return (str = ft_strdup("0"));
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (j < 0)
	{
		j = -j;
		str[0] = '-';
	}
	while (j > 0)
	{
		str[i] = j % 10 + '0';
		j = j / 10;
		i--;
	}
	return (str);
}
