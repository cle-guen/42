/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:23:43 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/06 15:19:09 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <locale.h>

# define BUFF_SIZE 4096

typedef enum		e_mod
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z
}					t_mod;

typedef struct		s_flags
{
	int				sharp;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				point;
	int				pre;
	int				width;
	int				star;
	t_mod			mod;
}					t_flags;

typedef struct		s_buff
{
	char			content[BUFF_SIZE];
	int				index;
	struct s_buff	*next;
}					t_buff;

typedef struct		s_pos
{
	t_buff			*first;
	t_buff			*buff;
	int				str_index;
	int				error;
	int				i_error;
}					t_pos;

int					ft_printf(const char *str, ...);
void				pf_putchar(char c);
char				*pf_itoa_base(t_flags *flags, uintmax_t n,\
					char *ba, int base);
int					pf_get_value(t_flags *flags, va_list al, t_pos *pos,\
					char *str);
int					pf_d(t_flags *flags, va_list al, t_pos *pos);
int					pf_gd(t_flags *flags, va_list al, t_pos *pos);
int					pf_u(t_flags *flags, va_list al, t_pos *pos);
int					pf_gu(t_flags *flags, va_list al, t_pos *pos);
int					pf_o(t_flags *flags, va_list al, t_pos *pos);
int					pf_go(t_flags *flags, va_list al, t_pos *pos);
int					pf_x(t_flags *flags, va_list al, t_pos *pos);
int					pf_gx(t_flags *flags, va_list al, t_pos *pos);
int					pf_p(t_flags *flags, va_list al, t_pos *pos);
int					pf_c(t_flags *flags, va_list al, t_pos *pos, char *str);
int					pf_gc(t_flags *flags, va_list al, t_pos *pos, char *str);
int					pf_s(t_flags *flags, va_list al, t_pos *pos, char *str);
int					pf_gs(t_flags *flags, va_list al, t_pos *pos);
void				pf_put_buff(t_pos *pos, char *str, int len);
void				pf_put_wbuff(t_pos *pos, wchar_t *str, int len);
t_buff				*pf_create_buffer(void);
int					pf_write_buff(t_pos *pos, int ret);
int					pf_len_wchar(wchar_t c);
int					pf_put_wchar(t_pos *pos, wchar_t c);
int					pf_len_wstring(wchar_t *str);
void				pf_w_width(t_flags *flags, t_pos *pos, wchar_t wc);
void				*pf_memcpy(void *dst, const void *src, size_t n);
void				pf_dead_space(t_pos *pos, t_flags *flags, int pre,\
					wchar_t *str);
int					pf_strlen(char *str);
int					pf_space(t_flags *flags);
int					pf_plus(t_flags *flags);
int					pf_l(t_flags *flags);
int					pf_h(t_flags *flags);
int					pf_j(t_flags *flags);
int					pf_z(t_flags *flags);
int					pf_point(t_flags *flags);
int					pf_minus(t_flags *flags);
int					pf_sharp(t_flags *flags);
int					pf_star(t_flags *flags, va_list al);
int					pf_zero(t_flags *flags);
void				pf_width(t_flags *flags, t_pos *pos, int bol);
void				pf_precision(t_flags *flags, t_pos *pos, int bol);

#endif
