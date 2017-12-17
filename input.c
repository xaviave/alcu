/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 14:47:31 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 19:11:33 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "alum1.h"

int		get_computer_input(int board_line, int line_nb)
{
	ft_putstr(g_player_2.color);
	if (board_line > 3)
		return (3);
	else if (board_line > 0)
	{
		if (!line_nb)
			return (board_line > 2 ? 2 : 1);
		else
			return (1);
	}
	return (0);
}

int		get_player_input(int board_line, int line_nb)
{
	char	*line;
	int		nb_matches;
	char	*tmp;

	nb_matches = line_nb;
	ft_putstr("How many matches do you want to remove (");
	if (board_line > 1)
		ft_putstr("1 to ");
	tmp = ft_itoa(board_line);
	if (board_line < 4)
		ft_putstr(tmp);
	else
		ft_putstr("3");
	free(tmp);
	ft_putstr(") ? ");
	ft_putstr(g_player_1.color);
	get_next_line(0, &line);
	nb_matches = ft_atoi(line);
	if (nb_matches < 1 || nb_matches > 3 || nb_matches > board_line)
		return (get_player_input(board_line, line_nb));
	return (nb_matches);
}

int		next_main(void)
{
	ft_putstr(KYEL""UI_LINE"\n*                           ALCU");
	ft_putstr("                            *\n"UI_LINE"\n"KRESET);
	return (0);
}
