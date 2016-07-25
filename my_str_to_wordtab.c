/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/merakc_b/rendu/PSU/PSU_2015_minishell1
** 
** Made by Badis Merakchi
** Login   <merakc_b@epitech.net>
** 
** Started on  Sun Jan 24 20:09:30 2016 Badis Merakchi
** Last update Sun Jan 24 22:37:17 2016 Badis Merakchi
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

char	*my_strndup(char *str, int n)
{
  char	*new_str;
  int	i;

  i = 0;
  new_str = malloc(my_strlen(str) + 1);
  while (str[i] && i < n)
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = 0;
  return (new_str);
}

char	**wordtab(char	**tab, char *str, char c, int nb)
{
  int	i;
  int	j;
  int	boolean;

  i = 0;
  j = 0;
  boolean = 1;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && str[i] != c)
	{
	  i++;
	  j++;
	  boolean = 0;
	}
      if (!boolean)
	{
	  tab[nb] = my_strndup(str + i - j, j);
	  nb++;
	  j = 0;
	}
      while (str[i] == c && str[i] && i++);
    }
  tab[nb] = NULL;
  return (tab);
}

char	**my_str_to_wordtab(char *str, char c)
{
  int	i;
  int	boolean;
  int	nb;
  char	**tab;

  i = 0;
  boolean = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] != c && boolean == 0)
	{
	  nb++;
	  boolean = 1;
	}
      else if (str[i] == c)
	boolean = 0;
      i++;
    }
  tab = malloc(sizeof(char *) * (nb + 1));
  if (tab == NULL)
    return (NULL);
  tab = wordtab(tab, str, c, 0);
  return (tab);
}
