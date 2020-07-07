/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:04 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 15:25:08 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_standard(const char *format, int *i)
{
	int		j;
	char	*str;

	j = I;
	while (format[I] != '%' && format[I])
		I++;
	if (!(str = pf_strsub((char*)format, j, I - j)))
		return (NULL);
	return (str);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			len;
	char		*save;

	i = 0;
	va_start(ap, format);
	len = 0;
	while (format[i])
	{
		if (!(save = ft_standard(format, &i)))
			return (-1);
		ft_putstr(save);
		len += ft_strlen(save);
		free(save);
		if (!(save = pf_special(format, &i, ap, &len)))
			return (-1);
		ft_putstr(save);
		len += ft_strlen(save);
		free(save);
	}
	va_end(ap);
	return (len);
}
