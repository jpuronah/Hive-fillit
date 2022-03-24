/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:29:51 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/23 12:35:41 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
Kaikki turha täält pois, eli ne jos h ==1 tai h == 4 lähti fittuu
	-> on hidas mut ehk menee läpi

	HUOM!
	-	ft_set_boardissa oli hämärää paskaa, jota muutin

	Yks kyssäri kans mietityttäny, et onks noi ft_strnew mallocit fine, mut kyl 
	varmaa?
*/

static char	*ft_empty_board(char *board, size_t size)
{
	size_t	i;

	i = 0;
	while (i < (size * (size + 1)))
	{
		board[i] = '.';
		if (i % (size + 1) == size)
			board[i] = '\n';
		i++;
	}
	board[i] = '\0';
	return (board);
}

/* ft_set_board:
Koitin malloccaa outputtia, asettaa board = output yms,
ja kaikki johti memory leakkeihi. Tää nykyne ei vuoda kummalkaa testil 
(testfile, 2 palaa)*/

static char	*ft_set_board(char *board, char **tetri_list, size_t size)
{
	char	*output;

	output = NULL;
	while (1)
	{
		board = ft_empty_board(board, size);	//Täs oli ennen pelkästää function call (ei board = ft....)
		//output = ft_strnew(size * (size + 1) + 1);
		output = ft_solve(board, tetri_list, size);
		/*board = output;
		free(output);*/
		//printf("output1:\n%s\n", output);
		if (!output)
		{
			size++;
			free(board);
			board = ft_strnew(size * (size + 1) + 1);
		}
		else
		{
			//printf("output2:\n%s\n", output);
			return (output);	//Täs oli ennen board
		}
	}
	return (NULL);
}

void	ft_board(char **tetri_list)
{
	char	*board;
	size_t	size;
	size_t	n_pieces;

	size = 0;
	n_pieces = 0;
	board = NULL;	//Lisäsin tän
	while (tetri_list[n_pieces] != NULL)
		++n_pieces;
	while (size * size < n_pieces * 4)
		size++;
	board = ft_strnew(size * (size + 1) + 1);
	if (!tetri_list || !board)
		ft_error();
	board = ft_set_board(board, tetri_list, size);
	if (board)
	{
		ft_putstr(board);
		free(board);
		exit(EXIT_SUCCESS);
	}
	else
		ft_error();
}
