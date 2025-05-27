/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:45:27 by w                 #+#    #+#             */
/*   Updated: 2025/05/19 17:10:35 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"

// WORD PIPE WORD --: WORD 
// ls -l -a -t > file >> fileappend <filein << limeter 
/*
arg[0] = ls
arg[1] = -l
arg[2] = -a
arg[3] = -t
arg[4] = >
arg[5] = file
arg[6] = >>
arg[7] = fileappend
arg[9] = <
arg[8] = filein
arg[10] = | --> next cmd
ls-> type = word, 
*/

//

int main (int ac, char **av)
{
    t_data *data;
    (void)ac;
    (void)av;

    int     i;
    // int     j = 0;
    data = malloc(sizeof(t_data));
	if (!data)
		return (1);

	char	*str = NULL;

    while (1)
    {
		i = 0;
        str = readline("minishell~$ ");
		if (!str)
			break;

			// data->cmds = ft_split_cmd(str, ' ');
		char **cmd = ft_split(str, '|');
		
		while(cmd[i])
		{
			data->cmds = ft_split_cmd(cmd[i]);
			//data->cmds[0] is builtin or not
			int j = 0;
			while(data->cmds[j])
			{

				printf("cmd[%d] > {%s}\n", j, data->cmds[j]);
				j++;
			}
			i++;
		}
		add_history(str);
    }
}
