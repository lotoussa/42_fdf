/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:10 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:23:10 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_check_blank(char const *s)
{
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && *s != '\n')
			return (0);
		s++;
	}
	return (1);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		st;
	int		len;
	char	*tab;

	i = 0;
	j = 0;
	st = 0;
	if (s)
	{
		if (ft_check_blank(s))
			return (ft_strdup(""));
		while (s[st] && (s[st] == ' ' || s[st] == '\t' || s[st] == '\n'))
			st++;
		while (s[i + 1])
			i++;
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i--)
			j++;
		len = ft_strlen(s) - j - st;
		tab = ft_strsub(s, st, len);
		return (tab);
	}
	return (NULL);
}
