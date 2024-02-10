/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:03:20 by rchahban          #+#    #+#             */
/*   Updated: 2024/02/10 19:32:59 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define WIDTH 1900
#define HEIGHT 1200
#define BLOCK 32
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include "../MLX42/include/MLX42/MLX42.h"
#include "../src/utils/get_next_line/get_next_line.h"

// RAYCASTING

typedef struct s_mydda
{
  double xstart;
  double ystart;
  double endy;
  double endx;
  double ytext;
  double xtext;
} t_mydda;

typedef struct s_ThreeD
{
  double distance;
  double newDistance;
  double projectedWallHeight;
  int wallStripHeight;
  int walltoppixel;
  int wallbottompixel;
  int index;
} t_ThreeD;

typedef struct s_mymlx
{
  //   t_text *text;
  t_mydda mydda;
  t_ThreeD s_3d;
  int ceelingRed;
  int ceelingBlue;
  int ceelingGreen;
  int floorRed;
  int floorBlue;
  int floorGreen;
  int map_line_counter;
  void *mlx;
  void *img;
  void *img2;
  double x;
  double y;
  double dirX;
  double dirY;
  double XisAllowed;
  double YisAllowed;
  int reader;
  double width;
  double hight;
  char *map1;
  char **grid;
  double radius;
  int is_wall;
  int is_not_wall;
  double circleColor;
  int walkdirection;
  int turnDirection;
  double endX;
  double endY;
  char playertype;
  double tile_x;
  double tile_y;
  double rotation_angle;
  double rotation_speed;
  double movespeed;
  double move_step;
  char **maptester;
  char **splited;
  int num_rows;
  int num_col;
  double newplayer_x;
  double newplayer_y;
  int num_rays;
  double wallhit_x;
  double wallhit_y;
  double fov_angle;
  double ray_angle;
  int RayFaceDown;
  int RayFaceUp;
  int RayFaceRight;
  int RayFaceLeft;
  double nexthorztouchX;
  double nexthorztouchY;
  double nextVerttouchX;
  double nextVerttouchY;
  double Hxintercept;
  double Hyintercept;
  double Vxintercept;
  double Vyintercept;
  double xstep;
  double ystep;
  int foundVertWall;
  double VertwallhitX;
  double VertwallhitY;
  int Vertwallcontent;
  int foundHorizWall;
  int horiwallhitX;
  int horiwallhitY;
  int horzwallcontent;
  double horzHitDistance;
  double vertHitDistance;
  double wallHitX;
  double wallHitY;
  double xtocheck;
  double ytocheck;
  int wallHitContent;
  int wasHitVertical;
  double distance;
  double heightwall;
  int idx;
  float mypi;
  mlx_texture_t *ea;
  mlx_texture_t *so;
  mlx_texture_t *we;
  mlx_texture_t *no;
  int cred;
  int cgreen;
  int cblue;
  int fgreen;
  int fblue;
  int fred;
  int offset_x ;
} t_mymlx;

// RAYCASTING

typedef struct Node
{
  int x;
  int y;
  struct Node *next;
} t_Node;

typedef struct Stack
{
  t_Node *top;
} t_Stack;

typedef struct s_element
{
  char *id;
  int found_status;
  char *path;
  char **colors;
  struct s_element *next;
} t_element;

typedef struct scene
{
  t_mymlx *mymlx;
  char **scene_info;
  char **temp_map;
  int biggest_len;
  char **map;
  t_element *info_list;
  char player_type;
  int player_x;
  int player_y;
  int map_cols;
  int map_rows;
  double x;
  double y;
  t_Stack *s;
  t_Stack *visited;
  char *no_texture;
  char *so_texture;
  char *we_texture;
  char *ea_texture;
  char **ceiling_colors;
  char **floor_colors;
} t_scene;

int valid_extension(char *path);
char **read_scene(char *map_path);
int ft_2d_len(char **scene);
int ft_strcmp(char *s1, char *s2);
int ft_atoi(char *str);
int ft_isalnum(int c);
int ft_isdigit(int arg);
int ft_isprint(int c);
char *ft_itoa(int n);
char **ft_split(char const *s, char c);
char *ft_strdup(char *s1);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
char *ft_strtrim(char *s1, char *set);
char *ft_substr(char const *s, unsigned int start, size_t len);
char **custom_split(char *s);
char *join_2d_arr(char **arr);
int begins_with_wall(char *str);
int ends_with_wall(char *str);
char **strdup_2d_arr(char **ptr);
void free_2d_arr(char **ptr);
int are_walls(char *str);
void free_list(t_element *list);
char *ft_strtrim_end(char *s1, char *set);
void get_player_props(t_scene *scene);
void add_element(t_element **list, char *id, char *path, char **colors);
void edit_node(t_element **list, char *id, char *path, char **colors);
void init_elements(t_element **elements);
int ids_found(t_element *list);
int is_player(char c);
int is_map_start(char *str);
int fails_by_commas(char *str);
int are_numeric_values(char **colors);
int are_rgb_numbers(char **str);
int is_rgb_number(int nbr);
int is_already_found(t_element *list, char *i, char *str);
int map_contains_player(char **map);
char **custom_split2(char *s);
int is_valid_color_id(char **colors);
char **run_operations(char *str);
char **rebuild_map(char **map, int biggest_len);
char **get_scene_map(char **scene, int map_lines, int *map_start_pos);
int get_map_count(char **scene, int *map_start);
int in_visited(t_Stack *visited, int a, int b);
void push(t_Stack *stack, int x, int y);
t_Stack *create_stack(void);
t_Node *pop(t_Stack *stack);
int is_empty(t_Stack *stack);
void free_nodes(t_Node *head);
char **get_scene_info(char **scene, int *count);
int get_scene_info_count(char **scene, int *map_start_pos);
int path_is_valid(t_scene *scene);
void free_stack(t_Stack *stack);
void free_stacks(t_scene *scene, t_Node *popped);
void free_nodes(t_Node *head);
void create_stacks(t_scene *scene);
void print_2d_arr(char **colors);
int handle_path_ids(t_element *list, char *id, char **str);
int valid_scene_info(char **scene_info, t_element *list);
int handle_color_ids(char **str, char *id, t_element *list, char *line);
int handle_invalid_identifier(char *id, char **str);
void search_void(t_Node *popped, int *void_found, t_scene *scene);
void get_next_moves(t_Stack *s, int a, int b, t_scene *scene);
int extract_biggest_line_len(char **map);
int map_contains_correct_possible_chars(char **map);
int map_is_sorrounded_by_walls(char **map);
int valid_map(char **initial_map, t_scene *scene);
void print_map(char **map);
void display_list(t_element *head);
void ft_bzero(void *s, size_t n);
void *ft_memset(void *b, int c, size_t len);
void get_text(t_scene *scene);
void init_var(t_scene *scene);
void mlx_initiate(t_scene *scene);
void get_text(t_scene *scene);
void playertype(t_scene *scene);
void ft_hook(void *param);
void hook_awsd(t_scene *scene);
void checkdir(t_mymlx *mymlx, double rotation_angle);
int is_move_allowed(t_scene *scene);
void print_grid(t_scene *scene);
void cast_all_rays(t_scene *scene);
double normalize_angle(double angle);
int map_has_wall(t_scene *scene, double x, double y);
void calculate_distance(t_mymlx *mymlx);
void drawLine(t_mymlx *mymlx, int x1, int y1, int x2, int y2);
void cloear(mlx_image_t *img, t_mymlx *mymlx);
double get_short_distance(t_mymlx *mymlx);
void three_drendring(t_scene *scene, t_mymlx *mymlx, int i);
int get_rgba(int r, int g, int b, int a);
void ishorizontal(t_scene *scene);
void incr_hsteps(t_scene *scene);
void init_horizontal(t_scene *scene);
void init_direction(t_scene *scene);
void isvertical(t_scene *scene);
void init_vertical(t_scene *scene);
void find_intercept(t_scene *scene);
void incr_vsteps(t_scene *scene);
void vertical_functions(t_scene *scene);
double	rad(float degree);
double distance_between_points(double x1, double y1, double x2, double y2);
void three_drendring(t_scene *scene, t_mymlx *mymlx, int i);
void draw_player_view(t_mymlx *mymlx);
void cast_all_rays(t_scene *scene);
void drawline(t_mymlx *mymlx, int x1, int y1, int x2, int y2);
void	calcul_distance(t_scene *scene);
int	get_texture(t_mymlx *mymlx, mlx_texture_t *texture, int offset_x , int y);
void	getcolors(t_scene *scene);
void drawCircle(t_mymlx *mymlx);
#endif