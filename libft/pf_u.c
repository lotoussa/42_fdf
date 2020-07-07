/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_u.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:13 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:08 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_u(va_list ap, t_flags *flags)
{
	long	n;
	char	*str;

	flags->more = 0;
	flags->space = 0;
	flags->ptype = u;
	n = va_arg(ap, long);
	if (n == 0 && flags->prec == 1 && (flags->size == 0 || flags->size == -1))
	{
		str = ft_strdup("");
		flags->width = (flags->width == -1 ? 0 : flags->width);
	}
	else
	{
		if (flags->modif == 0)
			n = (unsigned int)n;
		else if (flags->modif == hh)
			n = (unsigned char)n;
		if (!(str = pf_luitoa_base(n, "0123456789")))
			return (NULL);
	}
	if (!(str = pf_number(str, flags, ap)))
		return (NULL);
	return (str);
}
