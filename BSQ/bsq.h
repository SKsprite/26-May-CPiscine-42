/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:30:55 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/16 04:15:14 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define BUFF_SIZE 524288

# define ERR_MALLOC 476
# define ERR_MAP_INFO 417
# define ERR_INV_NUM 230
# define ERR_MAP_CHAR 119
# define ERR_MAP_COL 112

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_checks
{
	char	emp;
	char	obs;
	char	sqa;
	int		rows;
	int		cols;
	int		err;
	int		max;
	int		**map;
	char	buf[BUFF_SIZE];
	int		buf_pos;
	int		buf_len;
}	t_checks;

typedef int	t_bool;

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putendl(char *str);
void		ft_putnbr(int num);
void		init_dict(t_checks *dict);
void		print_map(t_checks dict);
void		normalize_map(t_checks dict);
int			**free_map(int **map);
void		solve(t_checks dict);
char		*str_join(char *str1, char c);
char		*f_realloc(char *ptr, int size);
void		arrcpy(char *dest, char *src);
int			f_atoi(char *str);
int			length(char *str);
int			valid_chars(t_checks *dict);
int			parse_num(char *num, t_checks *dict);
int			**biggest_sq(int **map, int size_row, int size_col, int *max);
void		process_row(int **map, int i, int *dims, int *max);
char		buf_read_char(int fd, t_checks *dict);
void		shift_chars(char c, t_checks *dict);
char		*read_header_line(int fd, t_checks *dict);
char		*read_line_valid(int fd, t_checks *dict);
void		parse_header(int fd, t_checks *dict);
void		fill_from_str(char *num, int *row, t_checks dict);
int			alloc_row_block(t_checks *dict);
int			fill_first_row(int fd, t_checks *dict);
int			read_row_direct(int fd, t_checks *dict, int idx);
int			fill_map(int fd, t_checks *dict);
t_checks	read_from_stdin(t_checks *dict);
t_checks	*fill_dict(int fd, t_checks *dict);
t_checks	get_checks_con(char *filename, t_checks *dict);
t_bool		line_not_end(char c);
t_bool		isnum(char *str);

#endif
