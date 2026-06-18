/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:01:15 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:01:20 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define DEFAULT_DICT  "numbers.dict"
# define DICT_INIT_CAP 16
# define NUM_BUF_SIZE  128

typedef struct s_entry
{
	char	*key;
	char	*value;
	int		is_scale;
	int		zeros;
}	t_entry;

typedef struct s_dict
{
	t_entry	*entries;
	int		count;
	int		capacity;
}	t_dict;

int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin3(char *s1, char *s2, char *s3);
void	ft_putendl(char *s);
int		ft_isdigit(char c);
int		is_valid_number(char *s);
int		is_scale_key(char *key, int *zeros);
int		str_cmp_num(char *a, char *b);
int		count_trailing_zeros(char *s);
void	str_divide(char *n, int z, char *out);
void	str_remainder(char *n, int z, char *out);
void	str_subtract(char *n, char *sub, char *out);
t_dict	*dict_new(void);
int		dict_grow(t_dict *dict);
void	dict_free(t_dict *dict);
char	*trim(char *s);
int		parse_line(char *line, t_dict *dict);
int		parse_content(char *content, t_dict *dict);
t_dict	*load_dict(char *path);
void	dict_sort(t_dict *dict);
char	*find_value(char *key, t_dict *dict);
char	*get_separator(char *key, char *rem);
int		has_scale_key_leq(char *n, t_dict *dict);
int		is_additive_skip(t_entry *e, char *n);
char	*step_exact_quotient(char *n, t_dict *dict);
char	*step_scale_split(char *n, t_dict *dict);
char	*step_additive(char *n, t_dict *dict);
char	*convert_rec(char *n, t_dict *dict);
char	*convert_number(char *n, t_dict *dict);
void	read_stdin_loop(t_dict *dict);

#endif
