/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:06 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:23:06 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;

	if (!(s1 && s2))
		return (NULL);
	tab = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (tab)
		ft_strcat(ft_strcpy(tab, s1), s2);
	return (tab);
}
