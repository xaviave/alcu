/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 19:10:56 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 19:11:09 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbarnay <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 14:48:42 by gbarnay      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 17:22:39 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "alum1.h"

static int	set_players(int mode)
{
	g_player_1.name = "Player 1";
	g_player_1.func = &get_player_input;
	g_player_1.color = KRESET;
	if (mode == 1)
	{
		g_player_2.name = "Player 2";
		g_player_2.func = &get_player_input;
		g_player_1.color = KCYN;
	}
	else if (mode == 2)
	{
		g_player_2.name = "Computer";
		g_player_2.func = &get_computer_input;
		g_player_1.color = KORANGE;
	}
	else
		return (0);
	return (1);
}

static int	play_round(int board[10000], int i, int *p2_rem)
{
	print_board(board);
	ft_putstr(KRESET);
	board[i] -= g_player_1.func(board[i], i);
	if (!board[i])
		i--;
	print_board(board);
	ft_putstr(KRESET);
	if (!(*p2_rem = g_player_2.func(board[i], i)))
		return (-1);
	board[i] -= *p2_rem;
	if (g_player_2.func == &get_computer_input)
	{
		ft_putstr("<");
		ft_putstr(g_player_2.name);
		ft_putstr("> removed [");
		ft_putstr(ft_itoa(*p2_rem));
		ft_putstr("] matches.\n");
	}
	if (!board[i])
		i--;
	return (i);
}

static void	start_game(int board[10000])
{
	int i;
	int	p2_rem;

	ft_putstr(KYEL""UI_LINE"\n* Game started:\n"UI_LINE"\n");
	ft_putstr(KRESET);
	i = -1;
	while (board[++i])
		;
	i--;
	while (board[i])
	{
		i = play_round(board, i, &p2_rem);
		if (i < 0)
			break ;
	}
	ft_putstr(KYEL"\n"UI_LINE"\n* Game finished : ");
	if (!p2_rem)
		ft_putstr(g_player_2.name);
	else
		ft_putstr(g_player_1.name);
	ft_putstr(" won !!\n"UI_LINE"\n"KRESET);
}

void		set_game_mode(int board[10000])
{
	char	*line;
	int		mode;

	ft_putstr("What game mode do you want to play (1, 2 or 3) ?\n");
	ft_putstr("1. <Player> vs <Player>\n");
	ft_putstr("2. <Player> vs <Computer [Easy]>\n");
	get_next_line(0, &line);
	mode = ft_atoi(line);
	free(line);
	if (!set_players(mode))
		set_game_mode(board);
	start_game(board);
}

int			main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		board[10000];
	int		i;

	i = -1;
	fd = next_main();
	if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY)))
			return (parse_error());
	}
	else
		ft_putstr("Provide a number of matches to add (1 to 10000): ");
	while (get_next_line(fd, &line) && line[0])
	{
		if (!fd)
			ft_putstr("Provide a number of matches to add (1 to 10000): ");
		board[++i] = ft_atoi(line);
		if (board[i] < 1 || board[i] > 10000 || !is_valid_line(line))
			return (parse_error());
	}
	free(line);
	sort_board(board);
	return (0);
}
