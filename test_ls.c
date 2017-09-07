/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangari <arangari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 08:53:01 by arangari          #+#    #+#             */
/*   Updated: 2017/09/07 11:20:21 by arangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int ac, char **av)
{
    struct dirent   **namelist;
    int             n;
    if (ac < 1)
    {
        exit (EXIT_FAILURE);
    }
    else if (ac ==1)
    {
        n = scandir(".", &namelist, NULL, alphasort);
    }
    else
    {
        n = scandir(av[1], &namelist, NULL, alphasort);
    }
    if (n < 0)
    {
        perror("scandir");
        exit(EXIT_FAILURE);
    }
    else
    {
        while (n--)
        {
            printf("%s    ", namelist[n]->d_name);
            free(namelist[n]);
        }
        free(namelist);
	}    
    exit(EXIT_SUCCESS);
}
