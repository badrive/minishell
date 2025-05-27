/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:51:32 by w                 #+#    #+#             */
/*   Updated: 2025/05/19 16:55:59 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool     is_ws(char c)
{
    return (ft_strchr("\t\n ", c));
}

int count_word(const char *s) 
{
    int i = 0;
    int count = 0;
    int in_word = 0;
    char quote = 0; // To track if we're inside quotes and which quote type
    
    if (!s)
        return (0);
        
    while (s[i]) {
        // Check for quotes
        if ((s[i] == '"' || s[i] == '\'') && !quote) {
            // Opening quote
            quote = s[i];
            if (!in_word) {
                in_word = 1;
                count++;
            }
        }
        else if (s[i] == quote) {
            // Closing quote
            quote = 0;
        }
        // Handle spaces only if not in quotes
        else if (is_ws(s[i]) && !quote) {
            in_word = 0;
        }
        // Found start of a new word outside quotes
        else if (!in_word) {
            in_word = 1;
            count++;
        }
        i++;
    }
    return (count);
}

int ft_len(const char *s) {
    int i = 0;
    char quote = 0; // To track quotes
    
    if (!s)
        return (0);
        
    while (s[i]) {
        // Check for quotes
        if ((s[i] == '"' || s[i] == '\'') && !quote) {
            quote = s[i]; // Start of quoted string
        }
        else if (s[i] == quote) {
            quote = 0; // End of quoted string
        }
        // Stop at delimiter only if not in quotes
        else if (is_ws(s[i]) && !quote) {
            break;
        }
        i++;
    }
    return (i);
}

void free_split(char **ptr, size_t index) {
    while (index > 0)
        free(ptr[--index]);
    free(ptr);
}

char **ft_callocc(char **ptr, const char *s) {
    size_t j = 0;
    size_t i = 0;
    size_t len_word;
    char quote = 0;
    
    while (s[i]) {
        // Skip delimiter if not in quotes
        if (is_ws(s[i]) && !quote) {
            i++;
            continue;
        }

        len_word = ft_len(&s[i]);
        ptr[j] = ft_substr(s, i, len_word);

        if (!ptr[j]) {
            free_split(ptr, j);
            return (NULL);
        }

        // Skip past this word
        i += len_word;
        j++;
    }
    ptr[j] = NULL;
    return (ptr);
}

char **ft_split_cmd(const char *s) 
{
    char **ptr;
    size_t count;

    if (!s)
        return (NULL);

    count = count_word(s);

    ptr = (char **)malloc(sizeof(char *) * (count + 1));
    if (!ptr)
        return (NULL);

    if (count == 0) {
        ptr[0] = NULL;
        return (ptr);
    }
    
    if (!ft_callocc(ptr, s)) {
        free(ptr);
        return (NULL);
    }
    
    return (ptr);
}
