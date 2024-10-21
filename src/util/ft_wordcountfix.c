/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcountfix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:58:29 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 21:32:10 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functionality.h"

int	ft_wordcountfix(const char *str, char c)
{
    int word_count = 0; // Word count
    int index = 0; // Index
    bool in_word = false; // Flag to track if we're inside a word

    while (str[index] != '\0')
    {
        if ((str[index] != c) && (in_word == false))
        {
            // We're at the start of a new word
            word_count++;
            in_word = true; // Mark that we're inside a word
        }
        else if ((str[index] == c) && (in_word == true))
        {
            // We've encountered c, marking the end of a word
            in_word = false; // Reset the in_word flag
        }
        index++;
    }
    return word_count;
}