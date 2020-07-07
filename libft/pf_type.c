/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_type.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:12 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:07 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		pf_init(char *(*p[15]) (va_list ap, t_flags *flags))
{
	p[0] = &pf_s;
	p[1] = &pf_upper_s;
	p[2] = &pf_p;
	p[3] = &pf_d;
	p[4] = &pf_upper_d;
	p[5] = &pf_i;
	p[6] = &pf_o;
	p[7] = &pf_upper_o;
	p[8] = &pf_u;
	p[9] = &pf_upper_u;
	p[10] = &pf_x;
	p[11] = &pf_upper_x;
	p[12] = &pf_c;
	p[13] = &pf_upper_c;
	p[14] = &pf_percent;
}

static int		pf_check_another_type(const char *f, int **i)
{
	int		j;
	char	*type;

	j = 0;
	type = "sSpdDioOuUxXcC%";
	while (type[j])
	{
		if ((type[j] == f[*I + 1] || type[j] == f[*I + 2]) && f[*I] != '%')
		{
			*I += (type[j] == f[*I + 1] ? 1 : 2);
			return (1);
		}
		j++;
	}
	return (0);
}

static void		pf_print_invalid(const char *f, int *i, t_flags *flags)
{
	if (f[I - 1] == '+')
		flags->more = 1;
	else if (f[I - 1] == '#')
		flags->hashtag = 1;
}

char			*pf_type(const char *f, int *i, t_flags *flags, va_list ap)
{
	int		j;
	char	*type;
	char	*(*p[15]) (va_list ap, t_flags *flags);

	pf_init(p);
	j = 0;
	type = "sSpdDioOuUxXcC%";
	pf_print_invalid(f, i, flags);
	while (type[j])
	{
		if (type[j] == f[I])
		{
			I++;
			return ((p[j](ap, flags)));
		}
		j++;
	}
	if (!flags->zero && flags->width == -1 && !flags->prec)
		return (ft_strdup(""));
	if (pf_check_another_type(f, &i))
		return (pf_type(f, i, flags, ap));
	if (flags->less == 1)
		I++;
	return (pf_invalid_type(flags, f[I - 1]));
}
