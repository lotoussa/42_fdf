/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_string_width.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:12 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:07 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*pf_string_width(char *str, t_flags *flags)
{
	char	*tmp;

	if (flags->width == -1)
		return (str);
	while ((int)ft_strlen(str) < flags->width)
	{
		tmp = str;
		if (flags->less == 1)
			str = ft_strjoin(str, " ");
		else
			str = ft_strjoin((flags->zero == 1 ? "0" : " "), str);
		free(tmp);
	}
	return (str);
}
