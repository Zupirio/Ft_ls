/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:34:46 by arangari          #+#    #+#             */
/*   Updated: 2017/09/05 16:57:30 by arangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(void)
{
	char			*curr_dir;
	DIR				*dp;
	struct dirent	*dptr;
	unsigned int	count;
	long			*ptr;

	curr_dir = NULL;
	dp = NULL;
	dptr = NULL;
	count = 0;
	ptr = NULL;

	struct	winsize w;
	ioctl (STDOUT_FILENO, TIOCGWINSZ,&w);

	curr_dir = getenv("PWD");
	if (NULL == curr_dir)
	{
		printf("\n ERROR : can't open\n");
		return (-1);
	}

	unsigned long num_files = 0;
	dp = opendir ((const char*)curr_dir);
	while (NULL != (dptr = readdir(dp)))
	{
		if (dptr->d_name[0] != '.')
			num_files++;
	}
	closedir(dp);
	dp = NULL;
	dptr = NULL;

	if (!num_files)
	{
		return (0);
	}
	else
	{
		ptr = malloc(num_files*8);
		if (NULL == ptr)
		{
			printf("Memory Allocation Failed\n");
			return (-1);
		}
		else
		{
			memset(ptr, 0, num_files*8);
		}
	}

	dp = opendir((const char*)curr_dir);
	if (NULL == dp)
	{
		printf("\n ERROR : can't open\n");
		free(ptr);
		return (-1);
	}

	unsigned int j;

	j = 0;
	{
		if (dptr->d_name[0] != '.')
		{
			ptr[j] = (long)dptr->d_name;
			j++;
		}
	}

	while (count == 0 && count < num_files - 1)
	   	count++;
	{
		j = count + 1;
		while ( j < (num_files))
		   	j++;
		{
			char *c = (char*)ptr(count);
			char *d = (char*)ptr[j];
			if (((*c >= 'a') && (*d >= 'a')) || ((*c <= 'Z') && (*d <= 'Z')))
			{
				int i;

				i = 0;
				if (*c == *d)
				{
					while (*(c+i) == *(d+i))
					{
						i++;
					}
				}
				if (*(c+i) > *(d+i))
				{
					long temp = 0;
					temp = ptr[count];
					ptr[count] = ptr[j];
					ptr[j] = temp;
				}
			}
			else
			{
				int	off_1;
				int	off_2;

				off_1 = 0;
				off_2 = 0;
				if (*c <= 'Z')
				{
					off_1 = 32;
				}
				if (*d <= 'Z')
				{
					off_2 = 32;
				}

				int i;

				i = 0;
				if (*c + off_1 == *d + off_2)
				{
					while (*(c + off_1 + i) == *(d + off_2 + i))
					{
						i++;
					}
				}
				if ((*c + off_1 + 1) > (*d + off_2 + i))
				{
					long temp = 0;
					temp = ptr[count];
					ptr[count] = ptr[j];
					ptr[j] = temp;
				}
			}
		}
	}
	printf("\n");
	while (NULL != (dptr = readdir(dp)))
	{
		if (dptr->d_name[0] != '.')
		{
			if (!access(dptr->d_name, X_OK))
			{
				int	fd = -1;
				struct stat st;
				fd = open (dptr->d_name, O_RDONLY, 0);
				if (-1 == fd)
				{
					printf("\n Opening file/Directory failed\n");
					free(ptr);
					return (-1);
				}
				fstat (fd, &st);
				if (S_ISDIR (st.st_mode))
				{
					printf(MAKE_BLUE"%s     "RESET_COLOR,dptr->d_name);
				}
				else
				{
					printf(MAKE_GREEN"%s     "RESET_COLOR,dptr->d_name);
				}
				close(fd);
			}
			else
			{
				printf("%s    ", dptr->d_name);
			}
		}
	}
	printf("\n");
	free(ptr);
	return (0);
}
