/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_c.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:10 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:01 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_c(va_list ap, t_flags *flags)
{
	char	*str;
	char	*tmp;
	int		i;

	flags->ptype = c;
	if (flags->modif == l)
		return (pf_upper_c(ap, flags));
	str = ft_memalloc(2);
	i = va_arg(ap, int);
	*str = (unsigned char)i;
	while (flags->width > (int)ft_strlen(str) && str && i)
	{
		tmp = str;
		if (flags->zero)
			str = ft_strjoin("0", str);
		else if (!flags->less)
			str = ft_strjoin(" ", str);
		else
			str = ft_strjoin(str, " ");
		free(tmp);
	}
	return (str);
}
