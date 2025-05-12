/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: w <w@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:45:27 by w                 #+#    #+#             */
/*   Updated: 2025/05/12 15:48:12 by w                ###   ########.fr       */
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


// split 

int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '"' ||  s[i] == '\'')
			i++;
		if (s[i] != '"' ||  s[i] != '\'')
			i++;
		if (s[i] != '"' &&  s[i] != '\'')
			break;
		
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	ft_len(const char *s, char c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	free_split(char **ptr, size_t index)
{
	while (index > 0)
		free(ptr[--index]);
	free(ptr);
}

char	**ft_callocc(char **ptr, const char *s, char c)
{
	size_t	j;
	size_t	i;
	size_t	len_word;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		len_word = ft_len(&s[i], c);
		ptr[j] = ft_substr(s, i, len_word);
		if (!ptr[j])
		{
			free_split(ptr, j);
			return (NULL);
		}
		i += len_word;
		j++;
	}
	ptr[j] = NULL;
	return (ptr);
}

char	**ft_split_cmd(const char *s, char c)
{
	char	**ptr;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_word(s, c);
	printf("-> count :%ld\n", count);
	ptr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	if (count == 0)
	{
		ptr[0] = NULL;
		return (ptr);
	}
	if (!ft_callocc(ptr, s, c))
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

//
int main (int ac, char **av)
{
    t_data *data;
    (void)ac;
    (void)av;

    int     i;
    int     j = 0;
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

		data->cmds = ft_split_cmd(str, ' ');
        printf("command  : *%s* \n", str);
		while(data->cmds[i])
		{
			printf("[%d] -> '%s'\n", i, data->cmds[i]);
			
			i++;
		}
    }
}
