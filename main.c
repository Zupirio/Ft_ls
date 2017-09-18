/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangari <arangari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:12:15 by arangari          #+#    #+#             */
/*   Updated: 2017/09/18 18:03:39 by arangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			add_args(t_env *e, char *arg)
{
	int		x;

	x = 1;
	while (arg[x] != '\0')
	{
		if (arg[x] == 'l')
			e->l = 1;
		if (arg[x] == 'a')
			e->a = 1;
		if (arg[x] == 'r')
			e->r = 1;
		if (arg[x] == 't')
			e->t = 1;
		if (arg[x] == 'R')
			e->rr = 1;
		else
		{
			ft_putstr(arg);
			ft_putendl(": Invalid argument");
			return (0);
		}
		x++;
	}
	return (1);
}

int			compare_strings(t_dir d1, t_dir d2)
{
	return (ft_strcmp(d1.dir, d2.dir));
}

int		compare_time(t_dir d1, t_dir d2)
{
	if (d1.time < d2.time)
		return (1);
	else
		return (0);
}

void		sort_list(t_dir **head, int (*cmp)(t_dir, t_dir), int done)
{
	t_dir	**src;
	t_dir	*temp;
	t_dir	*next;

	while (!done && *head != NULL && (*head)->next != NULL)
	{
		src = head;
		temp = *head;
		next = (*head)->next;
		done = 1;
		while (next)
		{
			if (cmp(*temp, *next) > 0)
			{
				temp->next = next->next;
				next->next = temp;
				*src = next;
				done = 0;
			}
			src = &temp->next;
			temp = next;
			next = next->next;
		}
	}
}

int			main(int ac, char **av)
{
	int		i;
	t_env	e;
	t_dir	*temp;

	i = 1;
	e.list = NULL;
	while (i < ac)
	{
		if (av[i][0] != '-' && (temp = (t_dir *)malloc(sizeof(t_dir))))
		{
			temp->dir = av[i];
			temp->next = e.list;
			e.list = temp;
		}
		else if (add_args(&e, av[i]) == 0)
			return (0);
		i++;
	}
	if (e.list == NULL)
		do_list(&e);
	ft_ls(&e);
}
