/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 15:52:59 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 17:24:31 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "alum1.h"

void		sort_board(int board[10000])
{
	int		i;
	int		j;
	int		tmp;

	i = -1	;
	while (board[++i])
	{
		j = -1;
		while (board[++j])
		{
			if (i != j && board[i] > board[j])
			{
				tmp = board[i];
				board[i] = board[j];
				board[j] = tmp;
			}
		}
	}
	set_game_mode(board);
}

int			is_valid_line(char *line)
{
	while (*line)
		if (*line != '\n' && !ft_isdigit(*line++))
			return (0);
	return (1);
}

int			parse_error(void)
{
	ft_putstr("ERROR\n");
	return (0);
}

void		put_blanks(int blanks)
{
	while (blanks--)
		ft_putstr(" ");
}

void		print_board(int board[10000])
{
	int		i;
	int		tmp;
	int		blanks;

	blanks = 0	;
	i = -1;
	while (board[++i])
	{
		if (blanks || (i > 0 && (board[i - 1] - board[i]) > 0))
		{
			blanks += (board[i - 1] - board[i]) / 2;
			if (!blanks)
				blanks++;
			put_blanks(blanks);
		}
		tmp = board[i];
		while (tmp--)
			ft_putchar('|');
		ft_putchar('\n');
	}
	ft_putstr(KRESET);
}
