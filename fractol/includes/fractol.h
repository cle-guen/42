/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:04:37 by cle-guen          #+#    #+#             */
/*   Updated: 2018/04/16 18:44:23 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define USAGE "usage: ./fractol "
# define ARG "mandelbrot || julia || burningship || tricorn || eye || celtic\n"
# define MANDELBROT 0
# define JULIA 1
# define BURNINGSHIP 2
# define TRICORN 3
# define EYE 4
# define CELTIC 5
# define WIN_W 800
# define WIN_W_M WIN_W + 250
# define WIN_H 800
# define ESC 53
# define BUT1_KEY 1
# define BUT2_KEY 2
# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define ITER_MORE 24
# define ITER_LESS 27
# define RESET 51
# define PAUSE 49
# define H_KEY 4
# define THREAD 8
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define COLOR_NEXT 47
# define COLOR_PREV 43
# define WHITE 0x00FFFFFF

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include <pthread.h>
# include <math.h>

typedef struct		s_env
{
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	double			stepx;
	double			stepy;
	double			c_r;
	double			c_i;
	int				tab_c[4];
	int				state[512];
	int				mouse[10];
	int				theme;
	int				b_p_pix;
	int				size_line;
	int				endian;
	int				oct_p_pix;
	int				type;
	int				iter;
	int				mouse_x;
	int				mouse_y;
	int				zoom;
	char			*tab[10];
	char			*t_bis[18];
	char			*t_ter[6];
	char			*data;
	char			*str_fract;
	void			*mlx;
	void			*win;
	void			*img_ptr;
}					t_env;

typedef struct		s_calcul
{
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
	double			tmpx;
	double			tmpy;
	int				i;
	int				x;
	int				y;
	int				stop;
	int				tmp_pixels[2];
}					t_calcul;

typedef struct		s_pointer
{
	t_env			*e_th;
	int				thread;
}					t_pointer;

int					input_funct(t_env *e);
int					key_press(int keycode, t_env *e);
int					key_release(int keycode, t_env *e);
int					mouse_press(int button, int x, int y, t_env *e);
int					mouse_release(int button, int x, int y, t_env *e);
int					close_program(t_env *e);
int					window(t_env *e);
int					ft_hook(t_env *e);
int					mouse_funct(t_env *env);
int					parse(t_env *e, char *str);
int					mouse_move(int x, int y, t_env *e);
int					multi_thread(t_env *e);
void				set_man_eye_cel(t_env *e);
void				set_julia(t_env *e);
void				set_burningship(t_env *e);
void				set_tricorn(t_env *e);
void				init_img(t_env *e);
void				ft_put_pixels(t_env *e, int x, int y, int color);
void				calc_fract(t_env *e, int thread, double xt_min);
void				help(t_env *e);
void				zoom_in(t_env *e);
void				zoom_out(t_env *e);
void				tab_color(t_env *e);
void				info(t_env *e);
void				usage(void);

#endif
