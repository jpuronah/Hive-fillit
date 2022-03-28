/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:29:51 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/28 17:35:55 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_empty_board(char *board, size_t size)
{
	size_t	index;

	index = 0;
	while (index < (size * (size + 1)))
	{
		board[index] = '.';
		if (index % (size + 1) == size)
			board[index] = '\n';
		++index;
	}
	board[index] = '\0';
	return (board);
}

static char	*ft_set_board(char *board, char **tetri_list, size_t size)
{
	char	*output;

	output = NULL;
	while (board && tetri_list)
	{
		board = ft_empty_board(board, size);
		output = ft_solve(board, tetri_list, size);
		if (!output)
		{
			++size;
			free(board);
			board = ft_strnew(size * (size + 1) + 1);
		}
		else
			return (output);
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
	board = NULL;
	while (tetri_list[n_pieces] != NULL)
		++n_pieces;
	while (size * size < n_pieces * 4)
		++size;
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
