/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:34:43 by kradoste          #+#    #+#             */
/*   Updated: 2018/04/21 23:29:16 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	char_changer(char *s)
{
	*s = 'x';
}
char	char_change(char s)
{
	s = 'x';
	return (s);
}
void	char_changer2(unsigned int n, char *s)
{
	if (n == 4)
		*s = 'a';
}
char	char_change2(unsigned int n, char s)
{
	if (n == 1)
		s = 'a';
	return (s);
}

int	main()
{
	//print functions
	ft_putstr("---------------- PRINT STUFF --------------- \n");
	ft_putstr("putchar: ");
	ft_putchar('a');
	ft_putchar('\n');
	ft_putstr("putstr: ");
	ft_putstr("Hello");
	ft_putchar('\n');
	ft_putstr("putendl: ");
	ft_putendl("Hello");
	ft_putstr("putnbr: ");
	ft_putnbr(-2147483648);
	ft_putchar(' ');
	ft_putnbr(-3149);
    ft_putstr("\n\n");

	//memory with string and pointers
	ft_putstr("---------------- MALLOC STUFF --------------- \n");
    char *mal_set;
    ft_putstr("memalloc (abc) = ");
    mal_set = ft_memalloc(10);
    mal_set[0] = 'a';
    mal_set[1] = 'b';
    mal_set[2] = 'c';
    mal_set[4] = 'e';
    ft_putstr(mal_set);
    ft_putstr("\nmemdel () =\n");
    ft_memdel((void **)&mal_set);
    ft_putstr(mal_set);
	char *mal_set2;
    ft_putstr("strnew (abc) = ");
    mal_set2 = ft_strnew(10);
    mal_set2[0] = 'a';
    mal_set2[1] = 'b';
    mal_set2[2] = 'c';
    mal_set2[4] = 'e';
    ft_putstr(mal_set2);
    ft_putstr("\nstrdel () =\n");
    ft_strdel((char **)&mal_set2);
    ft_putstr(mal_set2);	

	//string with malloc
    ft_putstr("\n---------------- STRING M. --------------- \n");
	char str_test[15] = "Hello Man";
	ft_putstr("strclr: ");
	ft_putstr(str_test);
	ft_strclr(str_test);
	ft_putstr(str_test);
	char str_test1[100] = "Hello Man";
	ft_putstr("\nstriter: Hello Man -> ");
	ft_striter(str_test1, char_changer);
	ft_putstr(str_test1);
	ft_putstr("\nstriteri: xxxxxxxxx -> ");
	ft_striteri(str_test1, char_changer2);
	ft_putstr(str_test1);
	ft_putstr("\nstrmap: xxxaxxxxx -> ");
	ft_strcpy(str_test1, ft_strmap(str_test1, char_change));
	ft_putstr(str_test1);
	ft_putstr("\nstrmapi: xxxxxxxxx -> ");
	ft_strcpy(str_test1, ft_strmapi(str_test1, char_change2));
	ft_putstr(str_test1);
	ft_putstr("\nstrequ: abc abc -> ");
	ft_putnbr(ft_strequ("abc", "abc"));
	ft_putstr("\nstrnequ: abc abc 2 -> ");
	ft_putnbr(ft_strnequ("abc", "abc", 2));
	ft_putstr("\nstrsub: abcde -> ");
	ft_putstr(ft_strsub("abcde", 3, 2));
	ft_putstr("\nstrjoin: abc def -> ");
	ft_putstr(ft_strjoin("abc", "def"));
	ft_putstr("\nstrtrim: |  \t \t \n   \n\n\n\t| -> ");
	ft_putstr(ft_strtrim("  \t \t \n   \n\n\n\t"));
	char	**str_test2;
	ft_putstr("\nstrsplit:      split       this for   me  !        -> ");
	str_test2 = ft_strsplit("      split       this for   me  !       ", ' ');
	int i = 0;
	while (str_test2[i])
		ft_putstr(str_test2[i++]);
	ft_putstr(str_test2[i]);
	ft_putstr("\nitoa: -2147483648 -> ");
	ft_putstr(ft_itoa(-2147483648));
	ft_putstr("\n\n");

	//memsesh
	ft_putstr("---------------- MEM SESH --------------- \n");
	ft_putstr("memset: cccxxxxxx = ");
	char mem_str[100] = "xxxxxxxxx\0";
	ft_putstr(ft_memset(mem_str, '\200', 3));
	ft_putchar('\n');
	ft_putstr("bzero: cccxx = ");
	ft_bzero(&(mem_str[5]), 3);
	ft_putstr(mem_str);
	ft_putchar('\n');
	ft_putstr("memcpy: abcdefg = ");
	char mem_str1[100] = "xxxxefg";
	ft_putstr(ft_memcpy(mem_str1, "abcd", 4));
	ft_putchar('\n');
	ft_putstr("memccpy: xxefg = ");
	char mem_str2[100] = "xxxxefg";
	ft_putstr(ft_memccpy(mem_str2, "abcd", 98, 4));
	ft_putchar('\n');
	ft_putstr("memmove big test with memcpy:\n");
 	char mem_str3[100] = "xxABCD";
	ft_putstr(ft_memmove(&(mem_str3[2]), (&(mem_str3[0])) , 4));
	ft_putchar(' ');
	ft_putstr(ft_memcpy(&(mem_str3[2]), (&(mem_str3[0])) , 4));
	ft_putchar('\n');
	ft_putstr("actual mem stuff:\n");
 	char mem_str4[100] = "xxABCD";
	ft_putstr(memmove(&(mem_str4[2]), (&(mem_str4[0])) , 4));
	ft_putchar(' ');
	ft_putstr(memcpy(&(mem_str4[2]), (&(mem_str4[0])) , 4));
	ft_putchar('\n');
	ft_putstr("memchr: acbcd = ");
	char mem_str5[100] = "acbcd";
	ft_putstr(ft_memchr(mem_str5, 99, 4));
    ft_putchar('\n');
	ft_putstr("memcmp: ");
    ft_putstr("abcd ");
    ft_putstr("abc ");
    ft_putnbr(ft_memcmp(".........", ".........", 2));
    ft_putstr("\n\n");

	//string manipulations
	ft_putstr("---------------- STRING STUFF --------------- \n");
    char *ptr;
    ft_putstr("memalloc (abc) = ");
    ptr = ft_memalloc(10);
    ptr[0] = 'a';
    ptr[1] = 'b';
    ptr[2] = 'c';
    ptr[4] = 'e';
    ft_putstr(ptr);
    ft_putstr("\nmemdel () =\n");
    ft_memdel((void **)&ptr);
    ft_putstr(ptr);
	ft_putstr("strlen: ");
	ft_putstr("Hello Man = ");
	ft_putnbr(ft_strlen("Hello Man"));
	ft_putchar('\n');
	ft_putstr("strcpy: ");
	char str1[100] = "Hello Man";
	ft_putstr(ft_strcpy(str1, "Hello"));
	ft_putchar('\n');
	char str2[100] = "Hello Man asdfasdf";
	size_t len = 9;
	ft_putstr("strncpy: ");
	ft_putstr(ft_strncpy(str2, "Hello Man", len));
	ft_putchar('\n');
	ft_putstr("strstr: ");
	ft_putstr(ft_strstr("Heabcllo", "x"));
	ft_putchar('\n');
	ft_putstr("strnstr: ");
	ft_putstr(ft_strnstr("Heabcllo", "abcl", 12));
	ft_putchar('\n');
	ft_putstr("strcmp: ");
	ft_putstr("abcd ");
	ft_putstr("abc ");
	ft_putnbr(ft_strcmp("abcd", "abc"));
	ft_putchar('\n');
	ft_putstr("strncmp: ");
	ft_putstr("abcd ");
	ft_putstr("abc ");
	ft_putnbr(ft_strncmp("abcd", "abc", 4));
	ft_putchar('\n');
	ft_putstr("strcat: ");
	ft_putstr("Hello ");
	ft_putstr("Man, ");
	char str3[100] = "Hello ";
	ft_putstr(ft_strcat(str3, "Man"));
	ft_putchar('\n');
	ft_putstr("strncat: ");
	ft_putstr("Hello ");
	ft_putstr("Man, ");
	char str4[100] = "Hello ";
	ft_putstr(ft_strncat(str4, "Man", 100));
	ft_putchar('\n');	
	ft_putstr("strlcat: ");
	ft_putstr("Hello ");
	ft_putstr("Man, ");
	char str5[20] = "hello";
	ft_putnbr(strlcat(str5, "man", 6));
	char str6[20] = "hello";
	ft_putnbr(ft_strlcat(str6, "man", 6));
	ft_putchar('\n');
	ft_putstr("strchr: ");
    ft_putstr("acbcd ");
	ft_putstr(ft_strchr("the cake is a lie !\0I'm hidden lol\r\n", 'x'));
	ft_putstr(strchr("the cake is a lie !\0I'm hidden lol\r\n", 'x'));
    ft_putchar('\n');
	ft_putstr("strrchr: ");
    ft_putstr("acbcd ");
    ft_putstr(ft_strrchr("acbcd", 99));
    ft_putstr("\n\n");

	//numbers and strings
    ft_putstr("---------------- NUM STR --------------- \n");
	ft_putstr("ascii: ");
	ft_putstr("-2147483648 ");
	ft_putnbr(ft_atoi("-2147483648"));
	ft_putchar('\n');
	ft_putstr("isalpha: ");
	ft_putstr("a ");
	ft_putnbr(ft_isalpha(97));
	ft_putchar('\n');
	ft_putstr("isdigit: ");
	ft_putstr("1 ");
	ft_putnbr(ft_isdigit(49));
	ft_putchar('\n');
	ft_putstr("isalnum: ");
	ft_putstr("a ");
	ft_putstr("5 ");
	ft_putnbr(ft_isalnum(97));
	ft_putnbr(ft_isalnum(53));
	ft_putchar('\n');
	ft_putstr("isascii: ");
	ft_putstr("~ ");
	ft_putnbr(ft_isascii(126));
	ft_putchar('\n');
	ft_putstr("isprint: ");
	ft_putstr("+ ");
	ft_putnbr(ft_isprint(43));
	ft_putchar('\n');
	ft_putstr("toupper: ");
	ft_putstr("x ");
	ft_putnbr(ft_toupper(120));
	ft_putchar('\n');
	ft_putstr("tolower: ");
	ft_putstr("D ");
	ft_putnbr(ft_tolower(68));
	ft_putchar('\n');
	ft_putstr("strdup: ");
	ft_putstr(ft_strdup("Hello man\n"));

	printf("%d\n", atoi(ft_itoa(-2147483647 -1)));
	printf("%d\n", atoi(ft_itoa(-2147483647)));
	return (0);
}
