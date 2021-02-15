/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 22:31:07 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/04/11 00:13:25 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			g_writecount = 0;

t_dispatch	g_cstable[] =
{
	{'c', &convert_c},
	{'s', &convert_s},
	{'p', &convert_p},
	{'d', &convert_d},
	{'i', &convert_d},
	{'o', &convert_o},
	{'u', &convert_u},
	{'x', &convert_x},
	{'X', &convert_xx},
	{'f', &convert_f}
};
