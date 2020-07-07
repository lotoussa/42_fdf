/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_special.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:12 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:07 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void			pf_durty_c(char *str, t_flags *flags, int *len)
{
	flags->width = (flags->width == -1 ? 0 : flags->width);
	if (str[0] == 0)
	{
		if (flags->less == 0)
		{
			while (flags->width > 1)
			{
				ft_putchar(flags->zero ? '0' : ' ');
				(flags->width)--;
				(*len)++;
			}
			ft_putchar('\0');
		}
		else
		{
			ft_putchar('\0');
			while (flags->width > 1)
			{
				ft_putchar(flags->zero ? '0' : ' ');
				(flags->width)--;
				(*len)++;
			}
		}
		(*len)++;
	}
}

char			*pf_special(const char *format, int *i, va_list ap, int *len)
{
	t_flags		flags;
	char		*str;

	if (!(format[I]))
		return (ft_strdup(""));
	I++;
	pf_flags(format, i, &flags);
	if (!(pf_multi(format, i, &flags)))
		return (NULL);
	pf_modif(format, i, &flags);
	if (!(str = pf_type(format, i, &flags, ap)))
		return (NULL);
	if (flags.ptype == c)
		pf_durty_c(str, &flags, len);
	return (str);
}
