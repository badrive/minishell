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

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    
    char *str = NULL;
    t_data *data = NULL;

    while (1)
    {
        str = readline("minishell~$ ");
        if (!str)
            break;

        char **cmd = ft_split(str, '|');
        if (!cmd)
            continue;
		// full struct
        int i = 0;
		int j = 0;
        while (cmd[i])
        {
            char **args = ft_split_cmd(cmd[i]);
            if (args)
                ft_lstadd_back2(&data, new_node(args));  // ✅ Use dynamic node
            i++;
        }

        // ✅ Print full command list
        t_data *temp = data;
		int k = 0;
        while (temp)
        {
                printf("comand line number :[%d] \n", k);
			if(temp->cmds)
			{
			j = 0;
            while (temp->cmds[j])
            {
                printf("------arg[%d]: %s\n", j, temp->cmds[j]);
                j++;
            }
			}
            temp = temp->next;
			k++;
        }
		// free
		free_list(data);
		data = NULL;
        add_history(str);
        free(str);
    }
    return 0;
}
