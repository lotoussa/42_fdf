/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_number.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:11 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:35:01 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*pf_inside_number(char *str)
{
	if (str[0] == '-')
		str = ft_strjoin("-0", str + 1);
	else if (str[0] == '+')
		str = ft_strjoin("+0", str + 1);
	else if (str[0] == ' ')
		str = ft_strjoin(" 0", str + 1);
	else
		str = ft_strjoin("0", str);
	return (str);
}

static char		*pf_number_prec(char *str, t_flags *flags)
{
	char *tmp;

	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
		(flags->size)++;
	while ((int)ft_strlen(str) < flags->size && str)
	{
		tmp = str;
		str = pf_inside_number(str);
		free(tmp);
	}
	return (str);
}

void			pf_star_width(char **str, t_flags **flags, va_list ap)
{
	char	*tmp;

	if ((*flags)->star == 1)
	{
		(*flags)->star = va_arg(ap, int);
		tmp = *str;
		*str = ft_strdup(pf_litoa_base((long)(*flags)->star, "0123456789"));
		(*flags)->star = ft_atoi(tmp);
		free(tmp);
		if ((*flags)->star < 0)
		{
			(*flags)->star *= -1;
			(*flags)->less = 1;
		}
		if ((*flags)->width != 1)
			(*flags)->width = ((*flags)->star < (*flags)->width
					? (*flags)->width : 0);
		else
			(*flags)->width = (*flags)->star;
	}
}

static char		*pf_number_width(char *str, t_flags *flags, va_list ap)
{
	char	*tmp;

	pf_star_width(&str, &flags, ap);
	if (flags->less == 1 && flags->hashtag == 1)
		str = pf_hashtag(flags->ptype, str);
	while ((int)ft_strlen(str) < flags->width && str)
	{
		tmp = str;
		if (flags->less == 1)
			str = ft_strjoin(str, " ");
		else
		{
			if (flags->zero == 1 && flags->prec == 0)
				str = pf_inside_number(str);
			else
				str = ft_strjoin(" ", str);
		}
		free(tmp);
	}
	return (str);
}

char			*pf_number(char *str, t_flags *flags, va_list ap)
{
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = str;
	if (flags->more == 1 && *str != '-')
	{
		str = ft_strjoin("+", str);
		free(tmp);
	}
	else if (flags->space == 1 && *str != '-')
	{
		str = ft_strjoin(" ", str);
		free(tmp);
	}
	if (flags->prec == 1)
		str = pf_number_prec(str, flags);
	flags->width = (flags->width == -1 ? 1 : flags->width);
	str = pf_number_width(str, flags, ap);
	return (str);
}
