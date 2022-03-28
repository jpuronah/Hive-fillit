/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:33:09 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/28 10:35:45 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* fd:tä ei tartteis välttämät viedä funktiost toisee ku se kuitenki rivil 25 
asetetaa uusiks, en tiiä onksil välii
*/

static char	*ft_read_to_fill(char *argv, char *pieces)
{
	int		fd;
	char	buf;
	size_t	index;
	ssize_t	n_bytes;

	buf = '\0';
	n_bytes = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error();
	n_bytes = read(fd, &buf, 1);
	index = 0;
	while (n_bytes == 1)
	{
		pieces[index++] = buf;
		n_bytes = read(fd, &buf, 1);
	}
	pieces[index] = '\0';
	close(fd);
	return (pieces);
}

char	*ft_reader(char *argv)
{
	int		fd;
	char	buf;
	char	*pieces;
	ssize_t	n_bytes;
	size_t	length;

	buf = '\0';
	pieces = NULL;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error();
	n_bytes = read(fd, &buf, 1);
	length = 0;
	while (n_bytes == 1)
	{
		n_bytes = read(fd, &buf, 1);
		++length;
	}
	pieces = ft_strnew(length);
	if (!pieces)
		ft_error();
	close(fd);
	return (ft_read_to_fill(argv, pieces));
}
