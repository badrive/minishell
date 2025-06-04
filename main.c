/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: w <w@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:45:27 by w                 #+#    #+#             */
/*   Updated: 2025/06/04 19:16:52 by w                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    
    char *str = NULL;
    t_data *data = NULL;
    t_redir *redir = NULL;
    t_heredoc *heredoc = NULL;


    while (1)
    {
        str = readline("minishell~$ ");
        if (!str)
            break;

        char **cmd = ft_split(str, '|');
        if (!cmd)
            continue;
        parse_commands(str, &data, &redir, &heredoc);
		// // free
        // ✅ Print full command list
        // t_data *temp = data;
		// int k = 0;
        // t_heredoc *temp_her = heredoc;
        // while (temp)
        // {
        //         printf("comand line number :[%d] \n", k);
		// 	if(temp->cmds)
		// 	{
		// 	int j = 0;
        //     while (temp->cmds[j])
        //     {
        //         printf("------arg[%d]: %s\n", j, temp->cmds[j]);
        //         j++;
        //     }
        //     while(temp_her)
        //     {
        //         printf("delimter (%s)\n",temp_her->delimeter);
        //         temp_her = temp_her->next;
        //     }
		// 	}
        //     temp = temp->next;
		// 	k++;
        // }
    
		free_list(data);
		data = NULL;
        add_history(str);
        free(str);
    }
    return 0;
}
