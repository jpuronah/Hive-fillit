/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:10:11 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/28 17:39:02 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

static void	ft_usage(void)
{
	ft_putendl("usage: ./fillit source_file");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	char	*pieces;
	char	**tetri_list;

	pieces = NULL;
	tetri_list = NULL;
	if (argc == 2)
	{
		pieces = ft_reader(argv[1]);
		if (!pieces)
			ft_error();
		ft_checks(pieces);
		tetri_list = ft_separate(pieces);
		free(pieces);
		if (!tetri_list)
			ft_error();
		ft_board(tetri_list);
	}
	else
		ft_usage();
	return (0);
}
