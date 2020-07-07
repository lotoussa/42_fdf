/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_p.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:12 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:07 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*pf_join(char *str, t_flags *flags)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = str;
	if (flags->less == 1)
	{
		str = ft_strjoin("0x", str);
		free(tmp);
	}
	else
	{
		while (str[i] == ' ')
			i++;
		str = ft_strjoin("0x", &str[i]);
		free(tmp);
		while (i--)
		{
			tmp = str;
			str = ft_strjoin(" ", str);
			free(tmp);
		}
	}
	return (str);
}

char		*pf_p(va_list ap, t_flags *flags)
{
	long	n;
	char	*s;

	flags->more = 0;
	flags->ptype = x;
	flags->width -= 2;
	flags->space = 0;
	n = va_arg(ap, unsigned long);
	if (n == 0 && flags->prec == 1 && (flags->size == 0 || flags->size == -1))
	{
		s = ft_strdup("");
		flags->width = (flags->width == -1 ? 0 : flags->width);
	}
	else
		s = pf_litoa_base(n, "0123456789abcdef");
	if (!(s = pf_number(s, flags, ap)))
		return (NULL);
	s = pf_join(s, flags);
	return (s);
}
