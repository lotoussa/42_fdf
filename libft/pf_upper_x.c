/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_upper_x.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:13 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:08 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*pf_hashtag_upper_hex(char *s)
{
	int		i;

	i = 0;
	if (('0' < s[0] && s[0] <= '9') || ('A' <= s[0] && s[0] <= 'F') || !s[0])
		s = ft_strjoin("0X", s);
	else if (('0' < s[1] && s[1] <= '9') || ('A' <= s[1] && s[1] <= 'F'))
		s = ft_strjoin("0X", s + 1);
	else
	{
		if (!(s = ft_strdup(s)))
			return (NULL);
		while (!(('0' <= s[i + 2] && s[i + 2] <= '9') ||
					('A' <= s[i + 2] && s[i + 2] <= 'F')))
			i++;
		s[i] = '0';
		s[i + 1] = 'X';
	}
	return (s);
}

static void		pf_modif_flags(t_flags **flags)
{
	(*flags)->more = 0;
	(*flags)->ptype = X;
	(*flags)->space = 0;
}

char			*pf_upper_x(va_list ap, t_flags *flags)
{
	long	n;
	char	*s;
	char	*tmp;

	pf_modif_flags(&flags);
	if (flags->modif == j)
		n = va_arg(ap, uintmax_t);
	else
		n = (flags->modif == h ? (unsigned short)va_arg(ap, unsigned int)
				: va_arg(ap, unsigned long));
	if (n == 0 && flags->prec == 1 && (flags->size == 0 || flags->size == -1))
		return (ft_strdup(""));
	if (flags->modif == 0)
		n = (unsigned int)n;
	else if (flags->modif == hh)
		n = (unsigned char)n;
	if (!(s = pf_number(pf_litoa_base(n, "0123456789ABCDEF"), flags, ap)))
		return (NULL);
	if (flags->hashtag == 1 && n != 0 && flags->less == 0)
	{
		tmp = s;
		s = pf_hashtag_upper_hex(s);
		free(tmp);
	}
	return (s);
}
