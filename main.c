/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 18:04:01 by sle-guil          #+#    #+#             */
/*   Updated: 2015/06/11 19:22:59 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfts.h"

#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void    ft_istest(void)
{
        int		i;
        int		win = 0;

        printf("	Testing ft_is<stuff>...\n");
		printf("Test is about comparing each function to the real one\n");
        for (i = -128; i <= 127; i++)
        {
                printf("\033[1;31m");
                if (isalpha(i) != ft_isalpha(i) && (win |= 1))
                        printf("%c ft_isalpha->%d isalpha->%d\n", i, ft_isalpha(i), isalpha(i));
                else if (isalnum(i) != ft_isalnum(i) && (win |= 2))
                        printf("%c ft_isalnum->%d isalnum->%d\n", i, ft_isalnum(i), isalnum(i));
                else if (isdigit(i) != ft_isdigit(i) && (win |= 4))
                        printf("%c ft_isdigit->%d isdigit->%d\n", i, ft_isdigit(i), isdigit(i));
                else if (isascii(i) != ft_isascii(i) && (win |= 8))
                        printf("%c ft_isascii->%d isascii->%d\n", i, ft_isascii(i), isascii(i));
                else if (isprint(i) != ft_isprint(i) && (win |= 16))
                        printf("%c ft_isprint->%d isprint->%d\n", i, ft_isprint(i), isprint(i));
                else if (isspace(i) != ft_isspace(i) && (win |= 32))
                        printf("%d ft_isspace->%d isspace->%d\n", i, ft_isspace(i), isspace(i));
        }
        if (win == 0)
                printf("\033[1;32mft_is ALL OK\n");
        if (win & 1)
                printf("\033[1;31mft_isalpha->KO");
        if (win & 2)
                printf("\033[1;31mft_isalpha->KO");
        if (win & 4)
                printf("\033[1;31mft_isalpha->KO");
        if (win & 8)
                printf("\033[1;31mft_isalpha->KO");
        if (win & 16)
                printf("\033[1;31mft_isalpha->KO");
        if (win & 32)
                printf("\033[1;31mft_isspace->KO");
        printf("\033[0m---------------------------\n\n");
}

void	ft_bzero_test()
{
	int		i;
	int		win = 0;
	char	test[] = "12345";
	char	test6[] = "Saucisson\0fort";

    printf("	testing ft_bzero\n");
	printf("Test is about simply using the function on allocated aera and checking the area afteryard\n");
    ft_bzero(test, 5);
    ft_bzero(test, 6);
    ft_bzero(test6, 15);
    for (i = 0; i < 6; i++)
    {
    	if (test[i] && (win = 1))
        	printf("\033[1;31merror %c pour %d\033[0m\n", test[i], i);
    }
    for (i = 0; i < 15; i++)
    {
    	if (test6[i] && (win = 2))
        	printf("\033[1;31merror %c pour %d\033[0m\n", test6[i], i);
    }
    if (win == 0)
    	printf("\033[1;32mft_bzero OK\n");
    if (win & 1)
		printf("\033[1;31mtest ONE KO\n");
    if (win & 2)
		printf("\033[1;31mtest TWO KO\n");
    printf("\033[0m---------------------------\n\n");
}

void    ft_memset_test()
{
	int     i;
    int     win = 0;
    char	test1[] = "12345";
    char	test2[] = "hello, my name is bon Jan !";

    printf("	testing ft_memset\n");
	printf("Test is just about setting an available aera. any try to an unknow aera result un SF.\n");
    ft_memset(test1, 's', 5);
    ft_memset(test2, 'b', 26);
	//ft_memset(NULL, 'S', 666);	// This test have to SF
    for (i = 0; i < 5; i++)
    {
    	if (test1[i] != 's' && (win = 1))
        	printf("\033[1;31merror %c pour %d\033[0m\n", test1[i], i);
    }
    for (i = 0; i < 26; i++)
    {
    	if (test2[i] != 'b' && (win = 2))
        	printf("\033[1;31merror %c pour %d\033[0m\n", test2[i], i);
	}
    if (win == 0)
    	printf("\033[1;32mft_memset OK\n");
    if (win & 1)
    	printf("\033[1;31mtest ONE KO\n");
    if (win & 2)
        printf("\033[1;31mtest TWO KO\n");
    printf("\033[0m---------------------------\n");
}

void    ft_memset_cpy()
{
	int		win = 0;
    char    test[] = "qwerr";
    char    test2[] = "12345";
    char    test6[] = "je SUI une pouleOK ASM PoWa";
    char    test7[] = "abcdefghijklmnopqrstuvwxyz ";
    char    test3[] = "asdfghjhkj";
    char    test4[] = "abcdefghijklmnopqrstuvwxyz ";
    char    test8[] = "abcdefghijklmnopqrstuvwxyz ";
    char    test9[] = "asdfghjhkj";

    printf("	Testing ft_memcpy\n");
	printf("This test copy several chuck of data into different place with both ft_memcpy and memcpy to compare the result\n");
    ft_memcpy(test, test2, 5);
    ft_memcpy(test6, test7, 27);
    ft_memcpy(test3, test4, 10);
    ft_memcpy(test8, test9, 26);
	//ft_memory(NULL, test2, 5);	// this have to SF
	//ft_memory(test1, NULL, 5);	// this could SF, or be useless anyway
    if (strcmp(test, test2) && (win |= 1))
    	printf("\033[1;31merror %s pour %s\033[0m\n", test2, test);
    if (strcmp(test6, test7) && (win |= 2))
        printf("\033[1;31merror %s pour %s\033[0m\n", test7, test6);
    if (strcmp(test3, "abcdefghij") && (win |= 4))
        printf("\033[1;31merror %s pour %s\033[0m\n", test3, test4);
    if (strcmp(test8, test9) && (win |= 8))
        printf("\033[1;31merror %s pour %s\033[0m\n", test8, test9);

    if (win == 0)
        printf("\033[1;32mft_memcpy OK\n");
    if (win & 1)
        printf("\033[1;31mtest ONE KO\n");
    if (win & 2)
        printf("\033[1;31mtest TWO KO\n");
    if (win & 4)
        printf("\033[1;31mtest THREE KO\n");
    if (win & 8)
    	printf("\033[1;31mtest FOUR KO\n");
    printf("\033[0m---------------------------\n");
}

void    ft_str_cpy(void)
{
	int		win = 0;
    char    *test = strdup("werr");
    char    *test2 = strdup("12345");
    char    *test6 = strdup("je SUI une pouleOK ASM PoWa");
    char    *test7 = strdup("abcdefghijklmnopqrstuvwxyz ");
    char    *test3 = strdup("qasdfghjhkj");
    char    *test4 = strdup("abcdefghijklmnopqrstuvwxyz ");
    char    *test8 = strdup("abcdefghijklmnopqrstuvwxyz ");
    char    *test9 = strdup("asdfghjhkj");

    printf("	<Bonus round> testing ft_strcpy\n");
	printf("This test creat some string, concaten them and compare with the real strcpy\n");
    ft_strcpy(test, test2);
    ft_strcpy(test6, test7);
    //ft_strcpy(test3, test4);      This test have to segfault since it copy into a location that's too small
    ft_strcpy(test8, test9);
    if (strcmp(test, test2) && (win |= 1))
        printf("\033[1;31merror %s pour %s\033[0m\n", test2, test);
    if (strcmp(test6, test7) && (win |= 2))
        printf("\033[1;31merror %s pour %s\033[0m\n", test7, test6);
    if (strcmp(test8, test9) && (win |= 8))
        printf("\033[1;31merror %s pour %s\033[0m\n", test8, test9);

    if (win == 0)
		printf("\033[1;32mft_strcpy OK\n");
    if (win & 1)
        printf("\033[1;31mtest ONE KO\n");
    if (win & 2)
        printf("\033[1;31mtest TWO KO\n");
    if (win & 4)
        printf("\033[1;31mtest THREE KO\n");
    if (win & 8)
    	printf("\033[1;31mtest FOUR KO\n");
    printf("\033[0m---------------------------\n");
}

void    ft_strcat_test()
{
	char    *test2 = strdup("54321");
    char    *test3 = strdup("qwertyyui54321\0");
    char    *test4 = strdup("qwertyyui54321");
    char    *test5 = strdup("plmokijn54321\0");
    char	*test6 = strdup("plmokijn54321\0");
    int		win = 0;

    test2[5] = '\0';
    test3[5] = '\0';
    test4[5] = '\0';
    test5[5] = '\0';
    test6[5] = '\0';

    printf("	testing ft_strcat\n");
	printf("This test creat some string, concaten them and compare with the real strcat\n");
    ft_strcat(test3, test2);
    strcat(test4, test2);
    ft_strcat(test5, test2);
    strcat(test6, test2);
	//ft_strcat(NULL, test2);	// this have to SF in my implementation
    if (strcmp(test3, test4) && (win |= 1))
        printf("\033[1;31mt1 error %s pour %s\033[0m\n", test3, test4);
    if (strcmp(test5, test6) && (win |= 2))
        printf("\033[1;31mt2 error %s pour %s\033[0m\n", test5, test6);
    if (win == 0)
        printf("\033[1;32mft_strcat OK\n");
    if (win & 1)
        printf("\033[1;31m test ONE KO\n");
    if (win & 2)
        printf("\033[1;31m test TWO KO\n");
    printf("\033[0m---------------------------\n");
}

void    ft_to_()
{
	char    test5[] = "je SUI une pouleOK ASM PoWa";
    char    test6[] = "je SUI une pouleOK ASM PoWa";
    int     i;

    for (i = 0; test5[i]; i++)
    {
    	test5[i] = ft_tolower(test5[i]);
        test6[i] = ft_toupper(test6[i]);
    }
    printf("	testing toupper and tolower\n");
	printf("This test apply the two function on string, and make strcmp with hard coded string\n");
    if (strcmp(test5, "je sui une pouleok asm powa"))
        printf("\033[1;31mt1 error tolower %s\033[0m\n", test5);
    else
        printf("\033[1;32mft_tolower OK\n");
    if (strcmp(test6, "JE SUI UNE POULEOK ASM POWA"))
    	printf("\033[1;31mt1 error toupper %s\033[0m\n", test6);
    else
        printf("\033[1;32mft_ft_toupper OK\n");
    printf("\033[0m---------------------------\n");
}

void    ft_strlen_test()
{
	int		i;

    printf("	testing ft_strlen\n");
	printf("this test compare the result of strlen and ft_strlen on hard coded string\n");
    if ((i = ft_strlen("lolntr")) != strlen("lolntr"))
        printf("\033[1;31merror for "" ->[%d]\033[0m ", i);
    else
        printf("\033[1;32mgood\033[0m ");
    if ((i = ft_strlen("qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq")) != strlen("qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"))
        printf("\033[1;31merror for "" ->[%d]\033[0m ", i);
    else
    	printf("\033[1;32mgood\033[0m ");
    if ((i = ft_strlen("")) != strlen(""))
        printf("\033[1;31merror for "" ->[%d]\033[0m\n", i);
    else
        printf("\033[1;32mgood\033[0m\n");

}

void    ft_puts_test()
{
	int     i;
    char    buff[1025];
    char    fd[1024];
    int     file;

	printf("	testing ft_puts");
	printf("This test print string with puts and ft_puts, then display result. You have to put an eye on result !\nNote that ft_puts rely on ft_strlen to work");
    i = ft_puts("%$1231526377()*^(^%&$");
    printf("->ret = %d\n", i);
    i = puts("%$1231526377()*^(^%&$");
    printf("->ret = %d\n", i);
    i = ft_puts("ASPDJAS{FHASIUFHASIUFHASUPDHAPIUSDBHAF-018534698173058");
    printf("->ret = %d\n", i);
    i = puts("ASPDJAS{FHASIUFHASIUFHASUPDHAPIUSDBHAF-018534698173058");
    printf("->ret = %d\n", i);
    i = puts("1");
    printf("->ret = %d\n", i);
    i = ft_puts("1");
    printf("->ret = %d\n", i);
    i = puts("");
    printf("->ret = %d\n", i);
    i = ft_puts("");
    printf("->ret = %d\n", i);
    i = puts(NULL);
    printf("->ret = %d\n", i);
    i = ft_puts(NULL);
    printf("->ret = %d\n", i);

    printf("	<Bonus Round> ft_putstr\n");
    i = ft_putstr("$1231526377()*^(^&$");
    printf("\n");
    i = printf("$1231526377()*^(^&$");
    printf("\n");
    i = ft_putstr("ASPDJAS{FHASIUFHASIUFHASUPDHAPIUSDBHAF-018534698173058");
    printf("\n");
    i = printf("ASPDJAS{FHASIUFHASIUFHASUPDHAPIUSDBHAF-018534698173058");
    printf("\n");
    i = ft_putstr("1");
    printf("\n");
    i = printf("1");
    printf("\n");
    i = ft_putstr("");
    printf("\n");
    i = printf("");
    printf("\n");

    printf("<Bonus round> test de ft_putstr_fd : printing some victory in a file\n");
    file = open("fd_test", O_WRONLY | O_CREAT);
    ft_putstr_fd("SUCCESS\n", file);
    close(file);
    if (ft_putstr_fd("FAILURE\n", file) >= 0)
   		printf("putstr_fd failed miserably\n");
}

void    ft_cat_test()
{
	char    buff[1024 + 1];
    int             i;
    int             fd;

    printf("	testing ft_cat\n");
    printf("tapez 0 pour test l'entrer standard ou un fichier et exit pour arreter le test\n");
    if ((i = read(0, buff, 1024)))
    {
    	buff[i - 1] = '\0';
        if (!strcmp(buff, "0"))
        	ft_cat(0);
        else if (!strcmp(buff, "exit"))
        	;
        else
        {
        	fd = open(buff, O_RDONLY);
            printf("%d\n", fd);
            ft_cat(fd);
        }
    }
}

#include <stdlib.h>
void    ft_strdup_test()
{
	char    *s1;//[] = "lollol";
    char    *s2;

    s1 = malloc(sizeof(char) * 5);
    strcpy(s1, "lolo");
    s2 = ft_strdup(s1);
    printf("	Testing ft_strdup\n");
	printf("This test dup some string, then try to free it and finaly compare address\n");
    if (strcmp(s2, s1))
        printf("\033[1;31merror\033[0m\n");
    else
        printf("\033[1;32mgood\033[0m\n");
    if (strcmp(ft_strdup("aaaaa"), "aaaaa"))
        printf("\033[1;31merror\033[0m\n");
    else
        printf("\033[1;32mgood\033[0m\n");
    free(s2);
    if (s1 == s2)
    	printf("\033[1;31merror : s1 == s2\033[0m\n");
}

void	ft_strcmp_test()
{
	int		win = 0;

	printf("	<Bonus round> testing ft_strcmp\n");
	printf("this test compare the result of strcmp and ft_strcmp on hard coded string\n");
	if (strcmp("Hello", "Hello") != ft_strcmp("Hello", "Hello") && win++)
		printf("\033[1;31m test ONE KO\n");
	if (strcmp("hello", "Hello") == ft_strcmp("hello", "Hello") && win++)
		printf("\033[1;31m test TWO KO\n");
	if (strcmp("Hello\200", "Hello1") <= ft_strcmp("Hello\200", "Hello1") && win++)
		printf("\033[1;31m test THREE KO\n");
	if (!win)
		printf("ft_strcmp OK\n");
    printf("\033[0m---------------------------\n");
}

int             main(void)
{
	ft_istest();
    ft_bzero_test();
    ft_memset_test();
    ft_memset_cpy();
    ft_str_cpy();
    ft_strcat_test();
    ft_to_();
    ft_puts_test();
    ft_strlen_test();
    ft_cat_test();
    ft_strdup_test();
	ft_strcmp_test();
    return (0);
}
