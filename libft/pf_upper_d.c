/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_upper_d.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:13 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:08 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_upper_d(va_list ap, t_flags *flags)
{
	long	n;
	char	*str;

	n = va_arg(ap, long);
	if (flags->modif == j)
		n = (int)n;
	else if (flags->modif == h && n != 65535)
		n = (short)n;
	else if (flags->modif == hh && n != 65535)
		n = (signed char)n;
	if (!(str = pf_litoa_base(n, "0123456789")))
		return (NULL);
	if (!(str = pf_number(str, flags, ap)))
		return (NULL);
	return (str);
}
