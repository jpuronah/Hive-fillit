/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:16:39 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/28 11:31:51 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* Added: sub_string = NULL line 27
	changed tetri_list malloc

	vielki outo: eka malloccaan koko piecesin verran tilaa, minkä jälkee
	jokaselle tetripiecelle vielä eriksee 21??!! en ymmärrä
	*/

static char	*ft_strsub_chr(char const *pieces, size_t start,
size_t len, ssize_t chr)
{
	char	*sub_string;
	size_t	index;

	if (!pieces)
		return (NULL);
	if (start >= ft_strlen(pieces))
		return (NULL);
	sub_string = NULL;
	sub_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_string)
		ft_error();
	index = 0;
	while (index < len && pieces[start] != '\0')
	{
		if (pieces[start] == '#')
			sub_string[index] = (char)(chr + 65);
		else
			sub_string[index] = pieces[start];
		start++;
		index++;
	}
	sub_string[index] = '\0';
	return (sub_string);
}

char	**ft_separate(char *pieces)
{
	char	**tetri_list;
	size_t	start;
	ssize_t	chr;
	ssize_t	index;

	tetri_list = NULL;
	tetri_list = (char **)malloc(sizeof(char) * ft_strlen(pieces) + 1);
	if (!tetri_list)
		ft_error();
	chr = 0;
	index = 0;
	start = 0;
	while (pieces[index] != '\0')
	{
		if (index++ % 20 == 0)
		{
			tetri_list[chr] = ft_strsub_chr(pieces, start, 20, chr);
			chr++;
			start = start + 21;
		}
	}
	tetri_list[chr] = NULL;
	free(pieces);
	return (tetri_list);
}

/*
char	**ft_separate(char *pieces)
{
	char	**tetri_list;
	size_t	start;
	ssize_t	chr;
	ssize_t	index;
	size_t	len_pieces;

	tetri_list = NULL;
	len_pieces = ft_strlen(pieces);
	tetri_list = (char **)malloc(sizeof(char) * len_pieces + 1);
	if (!tetri_list)
		ft_error();
	chr = 0;
	index = 0;
	start = 0;
	while (pieces[index] != '\0')
	{
		if (index++ % 20 == 0)
		{
			tetri_list[chr] = ft_strsub_chr(pieces, start, 20, chr);
			chr++;
			start = start + 21;
		}
	}
	tetri_list[chr] = NULL;
	free(pieces);
	return (tetri_list);
}*/
