/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_x.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:13 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:18 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*pf_hashtag_hex(char *s)
{
	int		i;

	i = 0;
	if (ft_strchr("123456789abcdef", s[0]) || !s[0] ||
			!ft_strchr("0123456789abcdef ", s[1]))
		s = ft_strjoin("0x", s);
	else if (ft_strchr("123456789abcdef", s[1]) ||
			!ft_strchr("0123456789abcdef ", s[2]))
		s = (!ft_strcmp("0", s) ? ft_strjoin("0x", s)
				: ft_strjoin("0x", s + 1));
	else
	{
		if (!(s = ft_strdup(s)))
			return (NULL);
		while (s[i] && s[i] == '0')
			i++;
		if (i == (int)ft_strlen(s))
			return (s = ft_strjoin("0x", s));
		i = 0;
		while (!ft_strchr("0123456789abcdef", s[i + 2]))
			i++;
		s[i] = '0';
		s[i + 1] = 'x';
	}
	return (s);
}

static void		pf_modif_flags(t_flags **flags)
{
	(*flags)->more = 0;
	(*flags)->ptype = x;
	(*flags)->space = 0;
}

static char		*pf_hashtag_prec_hex(char **str, t_flags *flags, long n)
{
	if (flags->hashtag == 1 && flags->prec == 1 && flags->size && n != 0)
		*str = ft_strjoin("00", *str);
	return (*str);
}

char			*pf_x(va_list ap, t_flags *flags)
{
	long	n;
	char	*s;

	pf_modif_flags(&flags);
	n = (flags->modif == h ? (unsigned short)va_arg(ap, unsigned int)
			: va_arg(ap, unsigned long));
	if (n == 0 && flags->prec == 1 && (flags->size == 0 || flags->size == -1))
	{
		s = ft_strdup("");
		flags->width = (flags->width == -1 ? 0 : flags->width);
	}
	else
	{
		if (flags->modif == 0)
			n = (unsigned int)n;
		else if (flags->modif == j)
			n = (uintmax_t)n;
		else if (flags->modif == hh)
			n = (unsigned char)n;
		s = pf_litoa_base(n, "0123456789abcdef");
	}
	if (!(s = pf_number(s, flags, ap)))
		return (NULL);
	pf_hashtag_prec_hex(&s, flags, n);
	return (flags->hashtag == 1 && n && !flags->less ? pf_hashtag_hex(s) : s);
}
