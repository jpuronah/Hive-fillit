/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:29:51 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/28 13:52:27 by jpuronah         ###   ########.fr       */
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

static char	*ft_set_board(char *board, char **tetri_list, size_t size)
{
	char	*output;

	output = NULL;
	while (board && tetri_list && size) //onks tää parempi ehto ku while (1) ? ja onks tää normin mukaa ok?
	{
		board = ft_empty_board(board, size);
		output = ft_solve(board, tetri_list, size);
		if (!output)
		{
			size++;
			free(board);
			//board = ft_strnew(size * (size + 1) + 1);			näist toine
			board = (char *)malloc(sizeof(size * (size + 1) + 1));
		}
		else
			return (output); //Täs oli ennen board
	}
	return (NULL);
}

//Yks vaihtis ois myös initializaa boardi vast ft_set_boardis ja printtaa se sielt

void	ft_board(char **tetri_list)
{
	char	*board;
	size_t	size;
	size_t	n_pieces;

	size = 0;
	n_pieces = 0;
	board = NULL;
	while (tetri_list[n_pieces] != NULL)
		++n_pieces;
	while (size * size < n_pieces * 4)
		size++;
	//board = ft_strnew(size * (size + 1) + 1);			//näist pitäs valita
	board = (char *)malloc(sizeof(size * (size + 1) + 1));
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
