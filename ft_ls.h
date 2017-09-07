/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:25:33 by arangari          #+#    #+#             */
/*   Updated: 2017/09/04 10:11:58 by arangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_LS_H
#define  FT_LS_H

#define	RESET_COLOR "\e[m"
#define	MAKE_GREEN	"\e[32m"
#define	MAKE_BLUE	"\e[36"

#include <stdlib.h>
#include <dirent.h>
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

void	ft_putchar(char c);
void	ft_putstr(char const *s);

#endif
