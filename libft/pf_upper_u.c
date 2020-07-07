/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_upper_u.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:13 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:08 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_upper_u(va_list ap, t_flags *flags)
{
	long	n;
	char	*str;

	flags->more = 0;
	n = va_arg(ap, unsigned long);
	if (!(str = pf_luitoa_base(n, "0123456789")))
		return (NULL);
	if (!(str = pf_number(str, flags, ap)))
		return (NULL);
	return (str);
}
