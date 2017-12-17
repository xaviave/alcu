/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alum1.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 15:43:43 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 17:23:42 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _ALUM1_H
# define _ALUM1_H

# include "libft/libft.h"

# define UI_LINE "*************************************************************"

typedef struct		s_player
{
	char			*name;
	int				(*func)(int, int);
	char			*color;
}					t_player;

t_player			g_player_1;
t_player			g_player_2;

int					get_computer_input(int board_line, int nu_line);
int					get_computer_input2(int board_line, int nu_line);
int					get_player_input(int board_line, int nu_line);
int					is_valid_line(char *line);
int					parse_error(void);
void				print_board(int board[10000]);
void				put_blanks(int blanks);
void				sort_board(int board[10000]);
void				set_game_mode(int board[10000]);
int					suite_main(void);

#endif
