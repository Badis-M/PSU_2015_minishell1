/*
** minishel.c for minishel in /home/merakc_b/rendu/PSU/PSU_2015_minishell1
** 
** Made by Badis Merakchi
** Login   <merakc_b@epitech.net>
** 
** Started on  Fri Jan 22 21:19:16 2016 Badis Merakchi
** Last update Mon Jan 25 15:42:19 2016 Badis Merakchi
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "mysh.h"
#include "get_next_line.h"

char	**cpy_paths(char **env)
{
  int	i;

  i = 0;
  while (env[i] && (env[i][0] != 'P' || env[i][1] != 'A' || env[i][2] != 'T'
		    || env[i][3] != 'H'  || env[i][4] != '='))
    {
      i++;
    }
  if (env[i] && env[i][5])
    return (my_str_to_wordtab(env[i] + 5, ':'));
  return (NULL);
}

char	*create_path(char *path, char *cmd)
{
  char	*new_path;

  if ((new_path = malloc(my_strlen(path) + my_strlen(cmd) + 2)) == NULL)
    return (NULL);
  *new_path = 0;
  my_strcpy(new_path, path);
  my_strcat(new_path, "/");
  my_strcat(new_path, cmd);
  return (new_path);
}

char		*create_exec_path(char	**paths, char *cmd)
{
  struct stat	sb;
  char		*path;

  if (cmd && cmd[0] == 0)
    return (NULL);
  if (cmd && stat(cmd, &sb) == 0 && S_ISREG(sb.st_mode)
      && access(cmd, X_OK) != -1)
    return (cmd);
  while (paths && *paths && cmd)
    {
      path = create_path(*paths, cmd);
      if (stat(path, &sb) == 0 && S_ISREG(sb.st_mode)
	  && access(path, X_OK) != -1)
	return (path);
      free(path);
      paths++;
    }
  return (NULL);
}

int	my_sh(char **env, char **paths)
{
  char	*str;
  char	**exec;
  char	*exec_path;
  int	pid;
  int	stat;

  if ((str = get_next_line(0)) == NULL)
    return (1);
  exec = my_str_to_wordtab(str, ' ');
  exec_path = create_exec_path(paths, exec[0]);
  if (exec_path && (pid = fork()) == -1)
    return (1);
  else if (exec_path && pid == 0)
    {
      execve(exec_path, exec, env);
      free(exec_path);
      exit(0);
    }
  else if (exec_path && (pid = wait(&stat)) == -1)
    return (1);
  return (0);
}

int	main(int argc, char **argv, char **env)
{
  char	**paths;

  (void)argc;
  (void)argv;
  paths = cpy_paths(env);
  while (42)
    {
      my_putstr("$> ");
      if (my_sh(env, paths))
	break;
    }
  write(1, "exit\n", 5);
  return (0);
}
