/*
** utils.c for mysh in /home/merakc_b/rendu/PSU/PSU_2015_minishell1
** 
** Made by Badis Merakchi
** Login   <merakc_b@epitech.net>
** 
** Started on  Sun Jan 24 20:45:10 2016 Badis Merakchi
** Last update Sun Jan 24 21:26:12 2016 Badis Merakchi
*/

void	my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
}

void	my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i])
    {
      i++;
    }
  while (src[j])
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  dest[i] = 0;
}
