/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:51:53 by abelahce          #+#    #+#             */
/*   Updated: 2023/04/19 10:05:32 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WWITH 1024.0
# define HHEITH 800
# define TILE 524
# define ROSE 0xFF00FF
# define YOLLOW 0xFFFF00
# define PURPLE 0x8000FF
# define SKY 0x00FFFF
# define MVSPEED 80
# define TUSPEED 0.0923598775597
# define TUSPEED1 0.0523598775597
# define FOV 1.0471975512
# define ADJ 0.0001
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "../libft/libft.h"

typedef struct s_draw
{
	int	x;
	int	y;
	int	i;
	int	projection_distance;
	int	*rgb1;
	int	*rgb2;
}	t_draw;

typedef struct s_ply_info
{
	double	x;
	double	y;
	double	angle;
	int		walk;
	int		offset;
	int		rotate;
}	t_ply_info;

typedef struct s_ray
{
	double	distance;
	double	ray_angle;
	double	x;
	double	y;
	int		touch;
	int		sight;
}			t_ray;
typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				height;
	int				width;
	unsigned int	*text_int;
}				t_data;

typedef struct s_minilibx
{
	void	*mlx;
	void	*win;
	t_data	*img;
}	t_minilibx;

typedef struct s_info
{
	char	*so;
	char	*no;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		flag_so;
	int		flag_no;
	int		flag_we;
	int		flag_ea;
	int		flag_f;
	int		flag_c;
	int		*floor_color;
	int		*sky_color;
}	t_info;

typedef struct s_textures
{
	t_data	noptr;
	t_data	weptr;
	t_data	eaptr;
	t_data	soptr;
}	t_textures;

typedef struct s_cub
{
	char		*map_name;
	char		*map;
	char		**map_final;
	int			map_lines;
	int			map_collumn;
	double		angl_btw;
	double		project;
	t_ray		*ray;
	t_info		*info;
	t_ply_info	*ply;
	t_minilibx	*mlx;
	t_textures	*txt;
}	t_cub;

//  paring

void	init_data(t_cub *data);
void	free_table(char **tab);
void	fill_map(t_cub *data);
void	fill_map(t_cub *data);
void	re_allocate_map(t_cub *data);
void	get_ply_info(t_cub *data);
void	store_player_info(t_cub *data, int i, int j);
void	parse_info(t_cub *data);
void	check_map(t_cub *data);
void	mutate_map(t_cub *data);
void	parse_map(t_cub *data);
void	read_map(t_cub *data);
void	parse(t_cub *data);
void	free_table(char **tab);
void	ft_free(char *str);
void	free_data(t_cub *data);
void	ft_error(char *str, t_cub *data);
void	check_leaks(void);
void	init_my_data(t_cub *data);
char	*r_map(char	*str);
int		str_search(char *str, int n);
void	get_map_info(t_cub *data);
void	store_colors(int	*flor, char *str);
int		store_info3(char *check, t_cub *data);
int		store_info2(char *check, t_cub *data);
int		store_info(char *check, t_cub *data);
void	parse_each_textures(char *str);
void	parse_each_color(char *str);
int		ft_tablen(char **str);

// graphic 

void	graphic(t_cub *data);
double	angale_range(double angle);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int r, int g, int b);
void	sky_floor(t_cub *data);
int		my_mlx_pixel_get(t_data *data, int x, int y);
void	casting(t_cub *data, double ray_angl, t_ray *ray_info);
double	normalize(double ply_angle, double ray_angle, double distance);
void	cats_rays(t_cub *data);
void	get_y_ray(t_cub *data, double ray_angle, t_ray *ray_info);
void	get_x_ray(t_cub *data, double ray_angle, t_ray *ray_info);
void	moveply(t_cub *data);
void	try_offset_ply(t_cub *data, double x, double y);
int		moves_up(int keycode, t_cub *data);
int		moves(int keycode, t_cub *data);
int		destruction(t_cub *data);
void	get_textures(t_cub *data);
t_data	*get_tex(t_cub *data, int i, double *n, double *y);
void	scale_var(int *m, double *y, double *n, double projection_distance);
int		on_mousemove(int x, int y, t_cub *data);

#endif