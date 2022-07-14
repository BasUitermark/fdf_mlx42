/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 10:20:27 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/07 12:46:00 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include "../include/MLX42/include/MLX42/MLX42.h"
# include "../include/libft/include/libft.h"
# define WIDTH 1920
# define HEIGHT 1080

//== Structs ==//

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	int	*points;
	int	width;
	int	height;
}	t_map;

typedef struct s_grid
{
	int		size;
	int		x_offset;
	int		y_offset;
	int		z_offset;
	double	height_mod;
	double	x_rot;
	double	y_rot;
	double	z_rot;
}	t_grid;

typedef struct s_instance
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*str_img;
	t_grid		grid;
}	t_instance;

//== Functions ==//

/**
 * @brief Checks for a correct arg count and runs the initialization
 * function to setup the mlx instance.
 * If the initilialize function doesn't fail it will run the map parser,
 * initialize grid variables, setup an image, puts instructions on the image,
 * project the map on the image and put it on display,
 * checks for key inputs and loop the function.
 * If the initialize function fails, the program will exit.
 * 
 * @param argc Argument count.
 * @param argv Arguments.
 */
int		main(int argc, char const **argv);

/**
 * @brief Reads an ".fdf" file , through the passed argv argument,
 * stores the data in a string and converts it to an int array and 
 * stores this in a struct. It also counts the width and height of the map and
 * stores this in the same struct.
 * 
 * @param filepath The relative path to the mapfile.
 * @return t_map The t_map struct with: map.map_points, map.map_width,
 * map.map_height.
 */
t_map	parse_map(const char *filepath);

/**
 * @brief The error handling function.
 * If a system call returns an error it will display this error. 
 * Otherwise it will display a premade error message to
 * the standard error filedescriptor.
 * 
 * @param error_msg The message to be displayed 
 */
void	error(char *error_msg);

/**
 * @brief initializes the the grid parameters and sets up de z_offset
 * to make sure the height of the map doesn't go out of bounds.
 * 
 * 
 * @param fdf The struct where the grid struct is located.
 */
void	initialize_grid(t_instance *fdf);

/**
 * @brief This function will calculate a path of pixels to draw a line on.
 * It does this by calulating a boundary value that,
 * depending if it is above or below zero,
 * will switch the itteration between the x or y coordinate.
 * 
 * 
 * @param img The image to display the line on.
 * @param start The starting coordinate for the line.
 * @param end The ending coordinate for the line.
 */
void	draw_line(mlx_image_t *img, t_coord start, t_coord end);

/**
 * @brief Generates a starting point with a nested while loop and initiates
 * the grid drawing. Draw grid then draws a line to the right and down, and
 * calculates an offset through calc_coord.
 * 
 * get_height simply looks for the appropriate point in
 * map.points by the product y and map.width, which gives the row.
 * Adding x gives the appropriate column number in
 * the row. z_offset then normalizes the (height) map point to
 * be within the window size bounds.
 * 
 * @param fdf The instance where mlx and the image is located.
 */
void	project_map(t_instance fdf);

/**
 * @brief Puts the coordinates into a struct.
 * 
 * @param x X coordinate
 * @param y Y coordinate
 * @return t_coord The struct with the coordinates.
 */
t_coord	translate_coord(int x, int y);

/**
 * @brief Sets up the line length(grid size), recalculates the rotation
 * if necessary, the iso rotation (isometric view), the placement and
 * the processed coordinate.
 * 
 * Iso rotation: Clockwise rotation
 * @param fdf The instance where the grid struct is located.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @param z The z coordinate.
 * @return t_coord The processed coordinate.
 */
t_coord	calc_coord(t_instance fdf, int x, int y, int z);

/**
 * @brief Checks if the close hook has been used.
 * If it has been used it will close the windown,
 * terminate mlx instance and exit the program.
 * 
 * @param param The fdf instance.
 */
void	close_hook(void *param);

/**
 * @brief Checks if a motion hook has been used.
 * If one has been used it will check which one and
 * execute the appropiate function.
 * 
 * @param param The fdf instance.
 */
void	key_hooks(void *param);

/**
 * @brief Increases or decreases the x or y coordinate and
 * reloads the image with the recalculated coordinates.
 * 
 * @param fdf The fdf instance.
 */
void	location(t_instance *fdf);

/**
 * @brief Increases or decreases the gridsize and
 * reloads the image with the recalculated coordinates.
 * 
 * @param fdf The fdf instance.
 */
void	zoom(t_instance *fdf);

/**
 * @brief Increases or decreases the x, y or z rotation value,
 * which adjusts to where the coordinate will be located in 3D space,
 * and reloads the image with the recalculated coordinates.
 * @param fdf The fdf instance.
 */
void	rotation(t_instance *fdf);

#endif
