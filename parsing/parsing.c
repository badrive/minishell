/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: w <w@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:04:35 by w                 #+#    #+#             */
/*   Updated: 2025/06/04 12:25:07 by w                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void parse_commands(char *str, t_data **data, t_redir **redir, t_heredoc **heredoc)
{
	t_lexer *lex = NULL;
    char **cmd = ft_split(str, '|');
    if (!cmd)
        return;
    
    int i = 0;
    while (cmd[i])
    {
        char **args = ft_split_cmd(cmd[i]);
        if (args)
        {
            lex = ft_cmp(args);
            t_lexer *temp_lex = lex;
            int size_lex = count_lex(lex, WORD);
            char **cmd_lex = malloc(sizeof(char *) * (size_lex + 1));
            int a = 0;
            
            while (temp_lex)
            {
                if (temp_lex->type == WORD && a < size_lex)
                    cmd_lex[a++] = temp_lex->value;
                else if ((temp_lex->type == REDIRE_IN || temp_lex->type == REDIRE_OUT || temp_lex->type == REDIR_APPEND))
                    ft_lstadd_back_redir(redir, new_node_redir(temp_lex->next->value, temp_lex->type));
                else if (temp_lex->type == HEREDOC)
                    ft_lstadd_back_heredoc(heredoc, new_node_heredoc(temp_lex->next->value));
                temp_lex = temp_lex->next;
            }
            
            cmd_lex[a] = NULL;
            if (cmd_lex)
                ft_lstadd_back2(data, new_node(cmd_lex));
        }
        i++;
    }
}

void free_list(t_data *begin)
{
	t_data *tmp = begin;
	while(tmp)
	{
		if(tmp->cmds)
		{
			int i = 0;
			while(tmp->cmds[i])
			{
				free(tmp->cmds[i]);
				i++;
			}
		}
		tmp = tmp->next;
	}
}
