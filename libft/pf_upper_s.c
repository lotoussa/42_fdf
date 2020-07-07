/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_upper_s.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:13 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:08 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_upper_s(va_list ap, t_flags *flags)
{
	char		*str;
	char		*tmp;
	char		*new;
	wchar_t		*wstr;
	int			i;

	wstr = va_arg(ap, int*);
	if (!wstr)
		return (ft_strdup("(null)"));
	if (!(str = ft_memalloc(1)))
		return (NULL);
	i = -1;
	while (wstr[++i])
	{
		tmp = str;
		if (!(new = pf_unicode(wstr[i])))
			return (NULL);
		if (!(str = ft_strjoin(str, new)))
			return (NULL);
		free(tmp);
		free(new);
	}
	str = pf_string_prec(str, flags);
	str = pf_string_width(str, flags);
	return (str);
}
