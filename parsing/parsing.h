/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:29:34 by w                 #+#    #+#             */
/*   Updated: 2025/05/14 18:52:25 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "../libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

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
    NOTDEF
} t_type;

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

typedef struct s_data
{
    char    **cmds;//ls -la
    t_redir *redir;
    t_heredoc *herdoc;
    struct  s_data *cmd;
}   t_data;


char **ft_split_cmd(const char *s, char c);

#endif