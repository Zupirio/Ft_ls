/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangari <arangari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 09:17:31 by arangari          #+#    #+#             */
/*   Updated: 2017/09/12 15:59:08 by arangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef    FT_LS_H
#define     FT_LS_H

#include <dirent.h>
#include "libft/libft.h"
#include <sys/stat.h>
#include <sys/types.h>
# include <sys/dir.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>

typedef struct  s_dir
{
    char            *dir;
    time_t          time;
    int             is_dir;
    struct s_dir    *next;
}                   t_dir

typedef struct     s_env
{
    int				l;
    int				a;
    int				r;
    int				t;
    int				rr;
    char			*path;
    DIR				*dirp;
	struct dirent	*dp;
	struct stat		sb;
	t_dir			*list;
}					t_env;

void			ft_ls(t_env *e);
void			do_ls(char *dir t_env *e)
int				compare_time(t_dir d1, t_dir d2);
int				compare_strings(t_dir s1, t_dir d2);
void			sort_list(t_dir **head, int (*cmp)(t_dir, t_dir), int done);
void			do_list(t_env *e);
void			print_l(t_dir *list);
void			ft_print_ls(t_dir *list, t_env *e, char *path);
int				ft_file_check(t_env *e);

#endif