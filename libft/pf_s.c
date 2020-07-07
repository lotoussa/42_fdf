/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_s.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:12 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:07 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*pf_zero_str(char *str, t_flags *flags)
{
	if (!(str = ft_strdup("")))
		return (NULL);
	str = pf_string_prec(str, flags);
	str = pf_string_width(str, flags);
	return (str);
}

char			*pf_s(va_list ap, t_flags *flags)
{
	char	*str;

	if (flags->modif == l)
		return (pf_upper_s(ap, flags));
	str = va_arg(ap, char*);
	if (!str && flags->prec == 1)
		return (pf_zero_str(str, flags));
	if (!str)
		return (ft_strdup("(null)"));
	if (!(str = ft_strdup(str)))
		return (NULL);
	str = pf_string_prec(str, flags);
	str = pf_string_width(str, flags);
	return (str);
}
