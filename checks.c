/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:16:19 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/28 10:41:30 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_characters(char *pieces)
{
	size_t	index;
	size_t	tag;
	size_t	dot;
	size_t	new_lines;

	index = 0;
	dot = 0;
	tag = 0;
	new_lines = 0;
	while (pieces[index])
	{
		if (pieces[index] == '.')
			++dot;
		if (pieces[index] == '#')
			++tag;
		if (pieces[index] == '\n')
			++new_lines;
		++index;
	}
	if (new_lines == 0 || tag == 0 || dot == 0)
		ft_error();
	if ((new_lines + 1) % 5 != 0 || tag % 4 != 0 || dot % 12 != 0)
		ft_error();
	if (((new_lines + 1) / 5) > 26)
		ft_error();
}

static void	ft_check_line_len(char *pieces)
{
	size_t	len;
	size_t	line_count;
	size_t	index;

	len = 0;
	line_count = 0;
	index = 0;
	while (pieces[index])
	{
		len++;
		if (pieces[index] == '\n')
		{
			line_count++;
			if (line_count % 5 != 0)
				if (len != 5)
					ft_error();
			if (line_count % 5 == 0 && pieces[index] != '\n')
				if (len != 1)
					ft_error();
			len = 0;
		}
		index++;
	}
}

static size_t	ft_check_adjacent(char *pieces, size_t index, size_t adjacent,
size_t count)
{
	if (count > 0 && pieces[index] == '#' && pieces[index - 1] == '#')
		++adjacent;
	if (count < 20 && pieces[index] == '#' && pieces[index + 1] == '#')
		++adjacent;
	if (count > 4 && pieces[index] == '#' && pieces[index - 5] == '#')
		++adjacent;
	if (count < 16 && pieces[index] == '#' && pieces[index + 5] == '#')
		++adjacent;
	return (adjacent);
}

static void	ft_adjacent(char *pieces)
{
	size_t	index;
	size_t	adjacent;
	size_t	count;

	count = 0;
	index = 0;
	adjacent = 0;
	while (pieces[index])
	{
		adjacent = ft_check_adjacent(pieces, index, adjacent, count);
		++index;
		++count;
		if ((index + 1) % 21 == 0)
		{
			if (!(adjacent == 6 || adjacent == 8))
				ft_error();
			adjacent = 0;
			count = 0;
		}
	}
}

void	ft_checks(char *pieces)
{
	ft_characters(pieces);
	ft_check_line_len(pieces);
	ft_adjacent(pieces);
}
