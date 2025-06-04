/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: w <w@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:45:27 by w                 #+#    #+#             */
/*   Updated: 2025/06/04 12:24:20 by w                ###   ########.fr       */
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
		free_list(data);
		data = NULL;
        add_history(str);
        free(str);
    }
    return 0;
}
