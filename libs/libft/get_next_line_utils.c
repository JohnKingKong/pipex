/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:53:16 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/15 16:36:03 by jvigneau         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	the_one_that_reads(char **buffer, int fd)
{
	int		len_read;
	char	*new_buffer;

	while (!*buffer || !len_n_seek(*buffer, '\n'))
	{
		new_buffer = malloc(sizeof(char) * 1 + 1);
		if (!new_buffer)
			return (0);
		len_read = read(fd, new_buffer, 1);
		if (len_read <= 0)
		{
			free(new_buffer);
			return (0);
		}
		new_buffer[len_read] = '\0';
		*buffer = the_one_that_joins(*buffer, new_buffer);
		free(new_buffer);
	}
	return (len_n_seek(*buffer, '\n'));
}

int	len_n_seek(char *str, char to_search)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != to_search)
		len++;
	if (!to_search)
		return (len);
	if (str[len] != to_search)
		return (0);
	else
		return (len + 1);
}

char	*the_one_that_joins(char *buffer, char *line_read)
{
	char	*new_buffer;
	int		len_tot;
	int		cnt1_buffer;
	int		cnt2_line;

	cnt1_buffer = 0;
	cnt2_line = 0;
	len_tot = len_n_seek(buffer, 0) + len_n_seek(line_read, 0);
	new_buffer = malloc(sizeof(char) * len_tot + 1);
	if (!new_buffer)
		return (NULL);
	while (buffer && buffer[cnt1_buffer])
	{
		new_buffer[cnt1_buffer] = buffer[cnt1_buffer];
		cnt1_buffer++;
	}
	free(buffer);
	while (line_read && line_read[cnt2_line])
	{
		new_buffer[cnt1_buffer] = line_read[cnt2_line];
		cnt1_buffer++;
		cnt2_line++;
	}
	new_buffer[cnt1_buffer] = '\0';
	return (new_buffer);
}

void	the_one_that_copies(char **buffer, char **line, int len)
{
	int		cnt;
	char	*new_buffer;

	cnt = 0;
	while (cnt < len)
	{
		(*line)[cnt] = (*buffer)[cnt];
		cnt++;
	}
	(*line)[cnt] = '\0';
	if (!len_n_seek(*buffer, '\n'))
	{
		free(*buffer);
		*buffer = NULL;
	}
	else
	{
		new_buffer = the_one_that_doops(&(*buffer)[len]);
		free(*buffer);
		*buffer = new_buffer;
	}
}

char	*the_one_that_doops(char *buffer)
{
	int		cnt;
	int		len;
	char	*final_line;

	cnt = 0;
	len = len_n_seek(buffer, 0);
	final_line = malloc(sizeof(char) * len + 1);
	if (!final_line)
		return (NULL);
	while (buffer[cnt])
	{
		final_line[cnt] = buffer[cnt];
		cnt++;
	}
	final_line[cnt] = '\0';
	return (final_line);
}
