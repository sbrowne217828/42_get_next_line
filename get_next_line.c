/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labrown <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:28:42 by labrown           #+#    #+#             */
/*   Updated: 2017/12/18 18:56:30 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*multi_fd_store(int fd, t_list **start)
{
	t_list	*store;

	store = *start;
	while (store)
	{
		if (fd == (int)store->content_size)
			return (store);
		store = store->next;
	}
	store = ft_lstnew("\0", 1);
	store->content_size = fd;
	ft_lstadd(start, store);
	return (store);
}

char			*no_leak_strnjoin(char *s, char *s2, int n)
{
	char	*r;

	r = s;
	s = ft_strnjoin(s, s2, n);
	free(r);
	return (s);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fds;
	t_list			*start;
	char			*tmp;
	char			*no_leaks;
	int				b;

	tmp = NULL;
	if (!line || fd < 0 || BUFF_SIZE > INT_MAX / 2 || (read(fd, tmp, 0) < 0))
		return (-1);
	start = fds;
	fds = multi_fd_store(fd, &start);
	tmp = ft_strnew(BUFF_SIZE);
	while ((!ft_strchr(fds->content, '\n')) && (b = read(fd, tmp, BUFF_SIZE)))
		fds->content = no_leak_strnjoin((fds->content), tmp, b);
	b = 0;
	while (((char *)fds->content)[b] && ((char *)fds->content)[b] != '\n')
		++b;
	*line = ft_strndup(fds->content, b);
	(((char *)fds->content)[b] == '\n') ? ++b : 0;
	no_leaks = fds->content;
	fds->content = ft_strdup(fds->content + b);
	free(no_leaks);
	free(tmp);
	fds = start;
	return (b ? 1 : 0);
}
