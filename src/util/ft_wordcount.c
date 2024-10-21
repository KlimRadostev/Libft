/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:07:22 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 21:31:58 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functionality.h"

int ft_wordcount(const char *str)
{
    int word_count = 0; // Word count
    int index = 0; // Index
    bool in_word = false; // Flag to track if we're inside a word

    while (str[index] != '\0')
    {
        if ((FT_ISSPACE(str[index]) == false) && (in_word == false))
        {
            // We're at the start of a new word
            word_count++;
            in_word = true; // Mark that we're inside a word
        }
        else if ((FT_ISSPACE(str[index]) == true) && (in_word == true))
        {
            // We've encountered whitespace, marking the end of a word
            in_word = false; // Reset the in_word flag
        }
        index++;
    }
    return word_count;
}
