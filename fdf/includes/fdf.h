/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:24:34 by cle-guen          #+#    #+#             */
/*   Updated: 2018/02/13 16:22:00 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 2560
# define WIN_HEIGHT 1440
# define ESC 53
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ZOOM_IN 69
# define ZOOM_OUT 78
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define ROTATE_RIGHT 124
# define ROTATE_LEFT 123
# define RADIAN 0.0174533
# define RESET 82
# define ADD_LAYER 126
# define REMOVE_LAYER 125
# define INCREASE_ALT 47
# define DECREASE_ALT 43

# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				state[512];
	char			*buff;
	int				b_p_pix;
	int				size_line;
	int				oct_p_pix;
	void			*img_ptr;
	int				origin_x;
	int				origin_y;
	int				endian;
	int				zoom;
	float			angle;
	float			cos;
	float			sin;
	int				**c_x;
	int				**c_y;
	int				**map;
	int				width_map;
	int				height_map;
	int				int_min;
	int				int_max;
	int				color[2];
	int				palette[10];
	int				theme;
	int				scale;
	int				level;
}					t_env;

typedef struct		s_draw
{
	int				x;
	int				y;
	int				err;
	int				err2;
	int				color;
	int				i;
	int				max;
}					t_draw;

typedef struct		s_argb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_argb;

typedef union		u_col
{
	int				color;
	t_argb			argb;
}					t_col;

int					count(char *line);
int					get_model(t_env *env, char *file);
void				trace_fdf(t_env *env);
int					ft_color(float t, int col_a, int col_b);
void				draw_line(t_env *env, int x0, int y0, t_draw point);
void				palette(t_env *env);
int					key_funct(t_env *env);
int					close_program(t_env *env);
void				reset(t_env *env);
int					key_press(int keycode, t_env *env);
int					key_release(int keycode, t_env *env);
int					init_tabs(t_env *env);
void				help(char **tab);
int					check_digit(char *str);
void				not_valid(void);

#endif
