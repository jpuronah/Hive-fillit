/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:18:05 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/23 16:10:52 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*Korjasin täält mallocin rivilt 57 about, double chekkaus por feivör

*/

static char	*ft_strsub_chr(char const *pieces, size_t start,
size_t len, ssize_t chr)
{
	char	*sub_string;
	size_t	i;

	if (!pieces)
		return (NULL);
	if (start >= ft_strlen(pieces))
		return (NULL);
	sub_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_string)
		ft_error();
	i = 0;
	while (i < len && pieces[start] != '\0')
	{
		if (pieces[start] == '#')
			sub_string[i] = (char)(chr + 65);
		else
			sub_string[i] = pieces[start];
		start++;
		i++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}

char	**ft_separate(char *pieces)
{
	char	**tetri_list;
	size_t	start;
	ssize_t	j;
	ssize_t	k;
	size_t	n_pieces;

	n_pieces = (ft_strlen(pieces) + 1) / 21;
	//printf("len: %zu\n", ft_strlen(pieces));
	//printf("pieces: %zu\n", n_pieces);
	//printf("%zu\n", (ft_strlen(pieces) + 1) / 21);
	tetri_list = (char **)malloc(sizeof(char) * (n_pieces * 21) + 1);
	if (!tetri_list)
		ft_error();
	j = 0;
	k = 0;
	start = 0;
	while (pieces[k] != '\0')
	{
		if (k++ % 20 == 0)
		{
			tetri_list[j] = ft_strsub_chr(pieces, start, 20, j);
			j++;
			start = start + 21;
		}
	}
	tetri_list[j] = NULL;
	free(pieces);
	return (tetri_list);
}
