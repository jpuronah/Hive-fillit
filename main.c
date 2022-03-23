/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:10:11 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/23 12:36:30 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
= = = =  Lisätty ympäri ohjelmaa initializationeit, eli XXX = NULL; = = = =


NÄÄ KAKS!!!!!!
- halutaaks printtaa vaik esim ft_putendl_fd:llä mielummi toi error?
- ft_usagen fd, onks STDERR_FILENO oikee vai iha vaa ykköne (1)

Lisäks:
- Makefiles leaks taas et se pitää muistaa vaihtaa lopuks
- 
*/

void	ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

static void	ft_usage(void)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd("fillit", STDERR_FILENO);
	ft_putstr_fd(" input_file\n", STDERR_FILENO);
}
/*Mainissa noi ehdot: if(jotain paskaa), tarviiks olla?

*/
int	main(int argc, char **argv)
{
	char	*pieces;
	char	**tetri_list;

	pieces = NULL;			//Lisäsin kans nää
	tetri_list = NULL;		//Lisäsin kans nää
	if (argc == 2)
	{
		pieces = ft_reader(argv[1]);
		if (pieces)
			ft_checks(pieces);
		tetri_list = ft_separate(pieces);
		if (tetri_list)
			ft_board(tetri_list);
	}
	else
		ft_usage();
	return (0);
}
