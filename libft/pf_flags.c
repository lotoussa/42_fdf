/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_flags.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:11 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:06 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	pf_init_flags_ntr(t_flags *flags)
{
	flags->hashtag = 0;
	flags->less = 0;
	flags->more = 0;
	flags->space = 0;
	flags->zero = 0;
}

void		pf_flags(const char *f, int *i, t_flags *flags)
{
	pf_init_flags_ntr(flags);
	while (f[I] == '#' || f[I] == '-' || f[I] == '+' ||
			f[I] == ' ' || f[I] == '0')
	{
		if (f[I] == '#')
			flags->hashtag = 1;
		else if (f[I] == '-')
			flags->less = 1;
		else if (f[I] == '+')
			flags->more = 1;
		else if (f[I] == ' ')
			flags->space = 1;
		else if (f[I] == '0')
			flags->zero = 1;
		I++;
	}
}
