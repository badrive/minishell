/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: w <w@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:29:34 by w                 #+#    #+#             */
/*   Updated: 2025/06/04 19:14:04 by w                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "../libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include <stdlib.h>

// Forward declarations
typedef struct s_lexer t_lexer;
typedef struct s_redirections t_redir;
typedef struct s_heredoc t_heredoc;

typedef enum s_type
{
    WORD,
    PIPE,
    REDIRE_IN,
    REDIRE_OUT,
    REDIR_APPEND,
    HEREDOC,
    FILEE,
    DELIMITER,
    NOTDEF
} t_type;
// echo bhdbf jdfbjdf $home jchdc
//i  = 10  i + 1 11 home 14 getenv(home) /home/user 4adi tremplaci pos 10 tal 14 b 
// echo bhdbf jdfbjdf /home/user jchdc
typedef struct s_lexer
{
    t_type type;
    char *value;
    t_lexer *next;    
}   t_lexer;
//t_lexer *head, head->type = REDIRE_IN;
typedef struct s_redirections
{
    char *filename;//smiya dyal file
    t_type type;//REIR IN OUT APPEND type dyal token li l9itit
    t_redir *next;//next file ila kan
}   t_redir;

typedef struct s_heredoc
{
    char *delimeter;
    t_heredoc *next;
} t_heredoc;

// typedef struct s_cmd
// {
//     char *value;
//     struct s_cmd *next;
// }   t_cmd_lst;

typedef struct s_data
{
    char    **cmds;//ls, -la, zft ,|, wc ,-l,NULL
    // t_cmd_lst *cmd_lst;
    t_redir *redir;
    t_heredoc *herdoc;
    struct  s_data *next;//create new node
}   t_data;


char **ft_split_cmd(const char *s);
t_data *new_node(char **args);
void ft_lstadd_back2(t_data **lst, t_data *new);
void free_list(t_data *begin);

t_redir *new_node_redir(char *file,t_type type);
t_redir	*ft_lstlast_redir(t_redir *lst);
void ft_lstadd_back_redir(t_redir **lst, t_redir *new);

t_lexer *ft_cmp(char **av);
int count_lex(t_lexer *lex, t_type type);
t_lexer *new_node_lexer(char *args,t_type type);
t_lexer	*ft_lstlast_lexer(t_lexer *lst);
void ft_lstadd_back_lexer(t_lexer **lst, t_lexer *new);

t_heredoc *new_node_heredoc(char *dlm);
t_heredoc *ft_lstlast_heredoc(t_heredoc *lst);
void ft_lstadd_back_heredoc(t_heredoc **lst, t_heredoc *new);



void parse_commands(char *str, t_data **data, t_redir **redir, t_heredoc **heredoc);



#endif
 