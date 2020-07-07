/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:10 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:23:10 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = i;
	k = 0;
	if (!(char)needle[0])
		return ((char*)haystack);
	while (haystack[i])
	{
		j = i;
		while (needle[k] == haystack[j])
		{
			j++;
			k++;
			if (!needle[k])
				return ((char*)&haystack[i]);
		}
		k = 0;
		i++;
	}
	return (0);
}
