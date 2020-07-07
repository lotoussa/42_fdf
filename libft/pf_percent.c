/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_percent.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:12 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:07 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_percent(va_list ap, t_flags *flags)
{
	char	*str;
	char	*tmp;

	(void)ap;
	str = ft_strdup("%");
	while ((int)ft_strlen(str) < flags->width && str)
	{
		tmp = str;
		if (flags->less == 1 && flags->zero == 1)
			str = ft_strjoin(str, " ");
		else if (flags->less == 1 && flags->zero == 0)
			str = ft_strjoin(str, " ");
		else
			str = ft_strjoin(flags->zero ? "0" : " ", str);
		free(tmp);
	}
	return (str);
}
