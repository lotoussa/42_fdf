/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:12 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:07 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*pf_strsub(char *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (s)
	{
		if (!(tab = (char *)malloc(sizeof(*tab) * (len) + 1)))
			return (NULL);
		while (s[start] && i < len)
		{
			tab[i] = s[start++];
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	free(s);
	return (NULL);
}
