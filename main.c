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


t_data *new_node()
{
	t_data *node;
	
	node = malloc(sizeof(t_data));
	if(!node)
		return NULL;
	node->cmds = NULL;
	node->cmd_lst = malloc(sizeof(t_cmd_lst));
	node->redir = NULL;
	node->herdoc = NULL;
	node->next = NULL;
	return node;
}
t_data	*ft_lstlast2(t_data *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back2(t_data **lst, t_data *new)
{
	if (!lst)
		return ;
	if(*lst)
	{
	while((*lst)->next)
	{
		(*lst) = (*lst)->next;
	}
	(*lst)->next = new;
	}
	else
		*lst = new;
	
}

// void	ft_pipe(char **arg)
// {
// 	t_data *temp = new_node();
// 	t_data *temp2 = temp;
// 	int		i;
// 	int j = 0;
// 	i = 0;
// 	while (arg[i])
// 	{
// 		if (ft_strncmp(arg[i],"|",1) == 0)
// 		{
// 			ft_lstadd_back2(&temp, new_node());
// 			while(temp2->next)
// 				temp2 = temp->next;
// 			if(temp2)
// 				temp->next = temp2; 
// 			// if(!temp)
// 			printf("exist\n");
// 			j = 0;
// 			// temp->cmds[j] = arg[i];
// 		}
// 			if(temp && arg[i])
// 			{
// 			temp->cmds[j] = arg[i];
// 			printf("temp ->cmd : {%s}\n",temp->cmds[i]);
// 			printf("ARG : {%s}\n",arg[i]);
// 			}
// 		i++;
// 		j++;
// 	}
	
// }
//addback(head,new_node())

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
		char **cmd = ft_split_cmd(str, '|');
		
		while(cmd[i])
		{
			data->cmds = ft_split_cmd(cmd[i], ' ');
			//data->cmds[0] is builtin or not
			int j = 0;
			while(data->cmds[j])
				printf("cmd-> {%s}\n",data->cmds[j++]);
			i++;
		}
		// ft_pipe(cmd);
		
			
			//hayedti white spaces
			//dir functions tatkhedem b strcmp
			/*
			if(strcmp(arg[i]),"|")
			 data->cmds[i] = cmd[i];
				new node l cmd jaya
			else if(strcmp(arg[i]),">>")
				hna 4adi t3amer linked list d redirection
			*/

        // printf("command  : *%s* \n", str);
		// while(cmd[i])
		// {
		// 	printf("[%d] -> '%s'\n", i, cmd[i]);
		// 	i++;
		// }
    }
}
