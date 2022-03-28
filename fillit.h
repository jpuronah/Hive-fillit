/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:03:06 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/28 13:44:16 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

void	ft_error(void);
void	ft_checks(char *pieces);
void	ft_board(char **tetri_list);
char	*ft_solve(char *board, char **tetri_list, size_t size);
char	**ft_separate(char *pieces);
char	*ft_reader(char *argv);

#endif
