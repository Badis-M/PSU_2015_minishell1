/*
** get_nextline.c for get_next_line in /home/merakc_b/rendu/CPE/CPE_2015_getnextline
** 
** Made by badis merakchi
** Login   <merakc_b@epitech.net>
** 
** Started on  Mon Jan 11 16:55:17 2016 badis merakchi
** Last update Sun Jan 24 14:36:21 2016 Badis Merakchi
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

void		my_putstr(char *str);
char		*get_next_line(const int fd);
int		my_strlen(char *str);
char		*my_strncpy(char *dest, char *src, int n);
void		*my_malloc(unsigned int size);
char		*add_to_line(char *line, int treat, char *buff, int *start);

# ifndef READ_SIZE
#  define READ_SIZE 5000
# endif /* !READ_SIZE */

#endif /* !GET_NEXT_LINE_H_ */
