/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_o.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:12 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:07 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*pf_hashtag_octal(char *s)
{
	int		i;

	i = 0;
	if (('0' < s[0] && s[0] <= '9') || s[0] == '\0')
		s = ft_strjoin("0", s);
	else
	{
		if (!(s = ft_strdup(s)))
			return (NULL);
		while (!('0' <= s[i + 1] && s[i + 1] <= '9'))
			i++;
		s[i] = '0';
	}
	return (s);
}

static void		pf_modif_flags(t_flags **flags)
{
	(*flags)->more = 0;
	(*flags)->ptype = o;
	(*flags)->space = 0;
}

static int		pf_cast_o(t_flags *flags, long n, char **str)
{
	if (flags->modif == 0)
		n = (unsigned int)n;
	else if (flags->modif == h)
		n = (unsigned short)n;
	else if (flags->modif == hh)
		n = (unsigned char)n;
	if (!(*str = pf_litoa_base(n, "01234567")))
		return (0);
	return (1);
}

char			*pf_o(va_list ap, t_flags *flags)
{
	long	n;
	char	*s;

	pf_modif_flags(&flags);
	n = (flags->modif == j ? va_arg(ap, uintmax_t) : va_arg(ap, unsigned long));
	if (n == 0 && flags->prec == 1 && (flags->size == 0 || flags->size == -1))
	{
		s = ft_strdup("");
		flags->width = (flags->width == -1 ? 0 : flags->width);
	}
	else
		pf_cast_o(flags, n, &s);
	if (!(s = pf_number(s, flags, ap)))
		return (NULL);
	if (s[0] == '0' && flags->hashtag == 1)
		return (s);
	s = (flags->hashtag == 1 ? pf_hashtag_octal(s) : s);
	return (s);
}
