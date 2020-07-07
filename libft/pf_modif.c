/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_modif.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:11 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:06 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	pf_modif(const char *f, int *i, t_flags *flags)
{
	flags->modif = 0;
	if (f[I] == 'h')
		flags->modif = (f[I + 1] == 'h' ? hh : h);
	else if (f[I] == 'l')
		flags->modif = (f[I + 1] == 'l' ? ll : l);
	else if (f[I] == 'j')
		flags->modif = j;
	else if (f[I] == 'z')
		flags->modif = z;
	I += (flags->modif != 0 ? 2 : 0);
	if (flags->modif == l || flags->modif == h ||
			flags->modif == j || flags->modif == z)
		I--;
}
