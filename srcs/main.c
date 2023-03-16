/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:53:13 by acostin           #+#    #+#             */
/*   Updated: 2023/03/16 08:43:39 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	main(int argc, char **argv)
{
	t_pall	all;

	if (parsing_main(&all, argc, argv) == 1)
		return (1);
	exec_main(&all);
	return (0);
}
