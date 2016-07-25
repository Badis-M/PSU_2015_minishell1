/*
** mysh.h for mysh in /home/merakc_b/rendu/PSU/PSU_2015_minishell1
** 
** Made by Badis Merakchi
** Login   <merakc_b@epitech.net>
** 
** Started on  Sun Jan 24 21:41:20 2016 Badis Merakchi
** Last update Sun Jan 24 23:18:15 2016 Badis Merakchi
*/

#ifndef MYSH_H_
# define MYSH_H_

char    **my_str_to_wordtab(char *str, char c);
char    *my_strndup(char *str, int n);
int     my_strlen(char  *str);
void    my_strcpy(char *dest, char *src);
void    my_strcat(char *dest, char *src);
void	my_exit(char **wordtab);

#endif /* !MYSH_H_ */
