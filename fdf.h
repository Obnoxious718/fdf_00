/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:24:15 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/03 14:24:15 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** ------ LIBRARIES ------
*/
# include "ft_libgfx/minilibx_macos_sierra/mlx.h"
# include "libgfx.h"
# include <math.h>

/*
** ------ VARIABLES ------
*/
# define BUF_SIZE		777
# define WIN_WIDTH 		400//1080
# define WIN_HEIGHT 	400//720
# define WIN_SIZE 		500
# define IMG_SIZE 		477
# define OFF_X			0
# define OFF_Y			0
# define ROT_DEGREES	5
# define MV_PIXELS		5
# define RED			0xFF2222
# define GREEN			0x22FF22
# define BLUE			0x2222FF
# define PURPLE			0xFF22FF
# define WHITE			0xFFFFFF
# define GREY			0xAAAAAA
# define DGREY			0x444444
# define AMETHYST		0x6C2DC7
# define G_APPLE		0x4CC417
# define B_ORCHID		0x1F45FC

/*
** KEYS
*/

# define KEY_ESC 53

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_SCROLL_BUTTON 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define KEY_W	13
# define KEY_S	1
# define KEY_A	0
# define KEY_D	2

# define KEY_ONE	83
# define KEY_TWO	84
# define KEY_THREE	85
# define KEY_FOUR	86
# define KEY_FIVE	87
# define KEY_SIX	88
# define KEY_SEVEN	89
# define KEY_EIGHT	91
# define KEY_NINE	92

# define KEY_PLUS   69
# define KEY_MINUS  78

/*
** ------ STRUCTS ------
*/
typedef struct		s_line
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				err2;
}					t_line;

typedef struct		s_img
{
	int				bpp;
	int				color_val;
	int				endian;
	int				line_size;
	void			*img;
	int				*data;
	int				width;
	int				height;
}					t_img;

typedef struct		s_vector
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_vector;

typedef struct		s_file
{
	char			**split_y;
	char			**split_x;
	char			*spaces;
	char			*cont;
	char			*tmp;
	char			buf[BUF_SIZE + 1];
	int				fd;
	int				ret;
}					t_file;

typedef struct		s_iterator
{
	int				i;
	int				x;
	int				y;
	int				z;
}					t_iterator;

typedef struct		s_map
{
	t_vector		*vectors;
	t_vector		prev;
	int				rows;
	int				cols;
	int				spaces;
	int				scale;
	int				max_z;
	float			z_height;
	int				center_x;
	int				center_y;
	int				rot_x;
	int				rot_y;
	int				move_x;
	int				move_y;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	char			*file;
	t_img			img;
	t_map			map;
	int				shift;
	int				mode;
	int				color_on;
}					t_mlx;

/*
** ------ PUBLIC FUNCTIONS ------
*/
void			blg(int	x0, int y0, int x1, int y1, t_mlx *mlx);
void			vlg(int x, int y0, int y1, t_mlx *mlx);
void			hlg(int x0, int x1, int y, t_mlx *mlx);
void 			put_img_square(t_mlx *mlx);
void 			prep(t_mlx mlx, t_vector *vect);
void 			set_scale(t_mlx *mlx);
float			set_theta(int degrees);
void			set_color(t_vector *vect, t_map *map);
void 			map_set(t_mlx *mlx, t_file *file);
void 			set_vector(t_mlx *mlx, t_iterator *i, t_file *file);
void 			draw_line(t_mlx *mlx, t_vector start, t_vector end);
void 			set_up(t_mlx *mlx);
void 			check_err(int err, char *msg);
void 			img_clear(t_mlx *mlx);
void 			put_img_map(t_mlx *mlx);
void 			put_img_vector(t_mlx *mlx, t_vector vect);
void 			map_init(t_mlx *mlx);
void			read_file(t_mlx *mlx, t_file *file);
void			usage(void);
void			set_cord(t_mlx *mlx, t_file *file);
void 			draw(t_mlx *mlx);
void 			draw_c(t_mlx *mlx);
void 			connect_points(t_mlx *mlx);
void 			draw_s(t_mlx *mlx);
void 			draw_p(t_mlx *mlx);
void 			draw_plane(t_mlx *mlx);
void			draw_q(t_mlx *mlx);
// void			rot_z3d(double theta, t_mlx *mlx);
// void			rot_y3d(double theta, t_mlx *mlx);
// void			rot_x3d(double theta, t_mlx *mlx);
// int			b_line_gen(void *mlx_ptr, void *win_ptr, t_2d *cord, t_2d *points);
// int				b_line_gen(void *mlx_ptr, void *win_ptr, t_2d *end_points, t_2d *points);
// void			fdf(void *mlx_ptr, void *win_ptr);
// int 			key_event(int key, void *param);
// int 			mouse_event(int key, void *param);
// void			gfx_setup();

#endif
