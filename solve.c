/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:09:20 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/28 14:06:11 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static ssize_t	ft_placement_check(char *board, char c, size_t size)
{
	size_t	i;
	size_t	side_count;

	i = 0;
	side_count = 0;
	while (board[i] != '\0')
	{
		if (board[i] == c)
		{
			if (i > 0 && board[i - 1] == c)
				++side_count;
			if (i < size * (size + 1) - 1 && board[i + 1] == c)
				++side_count;
			if (i > (size - 1) && board[i - size - 1] == c)
				++side_count;
			if (i < (size * (size + 1) - size)
				&& board[i + size + 1] == c)
				++side_count;
		}
		++i;
	}
	if (side_count == 6 || side_count == 8)
		return (1);
	else
		return (0);
}

static void	ft_clear_previous(char *board, ssize_t chr)
{
	ssize_t	index;

	index = 0;
	while (board[index] != '\0')
	{
		if (board[index] == chr)
			board[index] = '.';
		++index;
	}
}

static size_t	ft_adjust_index(char *piece, size_t index, size_t j,
size_t size)
{
	if (piece[j] == '\n' && size == 3)
		index--;
	if (piece[j] == '\n' && size != 3 && size != 4)
		index += (size - 4);
	return (index);
}

static size_t	ft_place(char *board, char *tetri, size_t index, size_t size)
{
	size_t		j;
	char		letter;
	size_t		count;

	j = 0;
	count = 0;
	letter = tetri[j];
	while (tetri[j])
	{
		index = ft_adjust_index(tetri, index, j, size);
		if (index > (size * (size + 1)) || board[index] == '\0')
			break ;
		if (board[index] == '.' && tetri[j] >= 'A')
		{
			board[index] = tetri[j];
			++count;
		}
		index++;
		j++;
		if (count == 4)
			break ;
	}
	if (ft_placement_check(board, letter, size))
		return (1);
	return (0);
}

char	*ft_solve(char *board, char **tetri_list, size_t size)
{
	size_t	index;

	index = 0;
	if (!tetri_list[0])
		return (board);
	while (tetri_list[0] && tetri_list[0][0] < 'A')
		tetri_list[0]++;
	while (board[index])
	{
		if (ft_place(board, *tetri_list, index, size) != 1)
			ft_clear_previous(&board[index], *tetri_list[0]);
		else if (!ft_solve(board, &tetri_list[1], size))
			ft_clear_previous(&board[index], *tetri_list[0]);
		else
			return (board);
		++index;
	}
	return (NULL);
}
