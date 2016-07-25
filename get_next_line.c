/*
** get_next_line.c for get_next_line in /home/merakc_b/rendu/CPE/CPE_2015_getnextline
** 
** Made by badis merakchi
** Login   <merakc_b@epitech.net>
** 
** Started on  Tue Jan 12 13:20:11 2016 badis merakchi
** Last update Sun Jan 24 14:46:14 2016 Badis Merakchi
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[++i]);
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  if (n < i)
    dest[i] = '\0';
  return (dest);
}

char		*add_to_line(char *line, int use, char *buffer, int *start)
{
  char		*new_line;
  int		old_line;

  if (line != 0)
    old_line = my_strlen(line);
  else
    old_line = 0;
  new_line = malloc((old_line + use + 1) * sizeof(*new_line));
  if (line != 0)
    my_strncpy(new_line, line, old_line);
  else
    my_strncpy(new_line, "", old_line);
  new_line[old_line + use] = 0;
  my_strncpy(new_line + old_line, buffer + *start, use);
  if (line)
    free(line);
  *start = *start + (use + 1);
  return (new_line);
}

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE];
  static int	nb_in_buffer = 0;
  static int	start;
  int		use;
  char		*line;

  line = 0;
  use = 0;
  while (1)
    {
      if (nb_in_buffer <= start)
        {
          start = 0;
          if (!(nb_in_buffer = read(fd, buffer, READ_SIZE)))
            return (line);
          if (nb_in_buffer == -1)
            return (NULL);
          use = 0;
        }
      if (buffer[start + use] == '\n')
        return (line = add_to_line(line, use, buffer, &start));
      if (start + use == nb_in_buffer - 1)
         line = add_to_line(line, use + 1, buffer, &start);
      use = use + 1;
    }
}
