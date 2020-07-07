/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_upper_c.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:13 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:08 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_upper_c(va_list ap, t_flags *flags)
{
	int		i;

	(void)flags;
	i = va_arg(ap, int);
	flags->ptype = c;
	return (pf_unicode(i));
}
