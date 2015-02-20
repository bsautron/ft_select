/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 05:34:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/20 04:54:26 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

char	**ar;

int		main(int argc, char **argv)
{
	char			*res;
	t_win			win;
	char			buf[3];

	ar = argv;
	if (argc > 1)
	{
		ft_tcg(0);
		ft_make_instruction("cl", NULL);
		ft_refresh();
		res = tgetstr("cm", NULL);
		tputs(tgoto(res, 0, 0), 1, ft_outc);
		while (1)
		{
			signal(SIGWINCH, ft_signal_handler);
			signal(SIGTSTP, ft_signal_handler);
			signal(SIGCONT, ft_signal_handler);
			read(0, buf, 3);
			if (buf[0] == '\033')
			{
				if (buf[2] == 'A')
					res = tgetstr("up", NULL);
				if (buf[2] == 'B')
					res = tgetstr("do", NULL);
				if (buf[2] == 'D')
					res = tgetstr("le", NULL);
				if (buf[2] == 'C')
					res = tgetstr("nd", NULL);
				tputs(res, 0, ft_outc);
			}
		}
	}
	ft_tcg(1);
	return (0);
}
