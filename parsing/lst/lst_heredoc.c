/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: w <w@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:00:33 by w                 #+#    #+#             */
/*   Updated: 2025/06/04 12:00:47 by w                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_heredoc *new_node_heredoc(char *dlm)
{
    t_heredoc *node;
	
	node = malloc(sizeof(t_heredoc));
	if(!node)
		return NULL;
    node->delimeter = dlm;
	node->next = NULL;
	return node;
}



t_heredoc *ft_lstlast_heredoc(t_heredoc *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}





void ft_lstadd_back_heredoc(t_heredoc **lst, t_heredoc *new)
{
    if (!lst || !new)
        return ;
    
    if (*lst == NULL)
    {
        *lst = new;  // First node
    }
    else
    {
        t_heredoc *temp = *lst;  // ✅ Use temporary pointer
        while (temp->next)    // ✅ Traverse without modifying original
        {
            temp = temp->next;
        }
        temp->next = new;     // ✅ Add new node at the end
    }
}