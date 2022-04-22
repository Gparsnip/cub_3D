
#ifndef CUB3D_H
# define CUB3D_H

# include "mlx_mac/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define CLOSE 17
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define SHIFT 56
# define SIZE_CHUNK 4096
# define STEP 1000
# define FOV 60
# define TURN_LEFT 123
# define TURN_RIGHT 124
# define FOV2 30
# define PI 3.14
# define SIZE_PLAYER 1

typedef struct s_vars
{
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_key
{
	int			keycode;
	int			run;
}				t_key;

typedef struct s_reycast
{
	int			width;
	double		dist_screen;
	double		ugl;
	int			step;
	double		hypotenuse;
	double		dist;
	double		dist_x;
	double		dist_y;
	double		l;
	double		*rey_len;
	int			check_sprite;
	int			count_sprite;
}				t_reycast;

typedef struct s_sprite
{
	double			x;
	double			y;
	double			dist;
	int				size;
	int				start;
	int				y_start;
	struct s_sprite	*next;
}					t_sprite;

typedef struct s_maping_texture
{
	int				x_mass;
	int				y_mass;
	int				y_tmp;
	double			x;
	double			y;
}					t_maping_texture;

typedef struct s_position
{
	double		x;
	double		y;
}				t_position;

typedef struct s_length
{
	int			x;
	int			y;
	int			max_x;
	int			max_y;
}				t_length;

typedef struct s_turn
{
	double		alpha;
}				t_turn;

typedef struct s_file
{
	int			R_x;
	int			R_y;
	char		*NO_texture;
	char		*SO_texture;
	char		*WE_texture;
	char		*EA_texture;
	char		*S_texture;
	int			F[3];
	int			C[3];
	char		**map;
	int			max_str;
	int			check_save_image;
	int			check_last_str;
	int			err_ceil;
	int			err_res;
	int			err_flo;
}				t_file;

typedef struct s_texture
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	double			color_x;
	double			color_y;
}					t_texture;

typedef struct s_all
{
	t_file				file;
	t_vars				vars;
	t_data				data;
	t_key				key;
	t_position			player;
	t_length			map_length;
	t_length			pix_for_map;
	t_turn				turn;
	t_reycast			visual;
	t_texture			NO_texture;
	t_texture			SO_texture;
	t_texture			WE_texture;
	t_texture			EA_texture;
	t_texture			S_texture;
	t_sprite			*sprite;
}						t_all;

void			free_sprite(t_all *all);
void			all_image(t_all *all);
int				all_window(t_all *all);
int				ft_close_exit(t_all *all);
void			print_error(t_all *all);
void			all_addr(t_all *all);
int				all_null(t_all *all);
void			check_resolution(t_file *file);
void			save_sprite_list(t_all *all);
int				check_step_right(t_all	*all);
int				check_step_left(t_all *all);
void			move_utils(t_all *all, int i);
void			consist_map(t_all *all, char **map);
void			ft_ordinate(t_all *all, t_reycast *ordinate, double cos_a);
void			ft_abscissa(t_all *all, t_reycast *abscissa, double sin_a);
void			reycast_utils(t_all *all,
					t_reycast *abscissa, t_reycast *ordinate);
void			pull_texture_utils(t_all *all, t_maping_texture *texture);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);
void			draw_flag(t_all *all);
unsigned int	get_color_image(t_texture *texture, int x, int y);
void			wall_for_screen(t_all *all, t_maping_texture *texture);
void			pull_texture(t_all *all,
					t_maping_texture *texture, int h, int h_real);
void			draw(t_all *all, double x, double y, double l);
void			check_sprite_utils(t_all *all, double step);
int				check(double n1, double n2);
void			sort_help(t_sprite **pr,
					t_sprite **q, t_sprite **p, t_sprite **out);
t_sprite		*sort_list(t_sprite *head);
void			print_texture_sprite(t_all *all);
void			draw_sprite(t_all *all);
void			check_sprite(t_all *all, double step);
void			ft_reycast(t_all *all);
int				check_step_back(t_all *all);
int				check_step_fwd(t_all *all);
void			move(t_all *all);
void			print_byts_offset(int value, int fd);
void			print_byts(unsigned char byts, int count, int fd);
void			create_bmp_help(t_all *all, int fd, int size_file);
unsigned int	get_color(t_data *data, int x, int y);
void			create_bmp(t_all *all);
int				render_next_frame(t_all *all);
int				ft_key_hook(int keycode, t_all *all);
int				ft_key_stop(int keycode, t_all *all);
int				ft_window(t_file file);
int				ft_check_wall(char **map, int i, int j);
int				ft_check_map(char **map);
int				ft_check_save_file(t_file *file);
void			ft_save_map(char *line, t_file *file, char **map_line);
void			ft_save_file_char(char *line, t_file *file, char **map_line);
int				ft_save_file_int(char *line, int *i, t_file *file);
int				ft_check_double(char *line, t_file *file);
int				ft_file_save(char *line, t_file *file, char **map_line);
void			ft_file_null(t_file *file);
int				ft_pars(int fd, t_file *file);
int				ft_check_save(t_file *file, char **argv);
int				ft_check_argv_help(int argc, char **argv, t_file *file);
int				ft_check_argv(int argc, char **argv, t_file *file);
int				main(int argc, char **argv);
void			check_resolution_error(char *line);
void			check_ceiling_floor(char *line);
int				check_edje(char **map, int i, int j);
int				check_space(char **map, int i, int j);

#endif
