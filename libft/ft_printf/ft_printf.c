/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 11:54:50 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 14:57:47 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		main_buffer(char *format, va_list params, int *printed, int fd)
{
	int		i;
	t_buff	*p_buff;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!(p_buff = percent_buffer(format + i, params)))
				return ;
			write(fd, p_buff->buff, p_buff->buff_size);
			*printed += p_buff->buff_size;
			i += p_buff->arg_offset;
			free_buff(p_buff);
		}
		else
		{
			ft_putchar_fd(format[i], fd);
			*printed += 1;
		}
		i++;
	}
}

int				ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list		params;
	int			printed;
	char		*f;

	f = (char *)format;
	va_start(params, format);
	printed = 0;
	main_buffer(f, params, &printed, fd);
	va_end(params);
	return (printed);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		params;
	int			printed;
	char		*f;

	f = (char *)format;
	va_start(params, format);
	printed = 0;
	main_buffer(f, params, &printed, 1);
	va_end(params);
	return (printed);
}

int				ft_error(const char *restrict format, ...)
{
	va_list		params;
	int			printed;
	char		*f;

	f = (char *)format;
	va_start(params, format);
	printed = 0;
	main_buffer(f, params, &printed, 2);
	va_end(params);
	return (printed);
}
