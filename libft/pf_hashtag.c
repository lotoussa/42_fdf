/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_hashtag.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:11 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:24:06 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*pf_hashtag(t_ptype ptype, char *str)
{
	if (ptype == x)
		return (pf_hashtag_hex(str));
	else if (ptype == X)
		return (pf_hashtag_upper_hex(str));
	else if (ptype == o)
		return (pf_hashtag_octal(str));
	return (str);
}
