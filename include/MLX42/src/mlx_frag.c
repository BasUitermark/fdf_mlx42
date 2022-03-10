/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lol.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: W2wizard <w2.wizzard@gmail.com>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 22:34:59 by W2wizard      #+#    #+#                 */
/*   Updated: 2022/02/17 22:34:59 by W2wizard      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// If you wish to modify this file edit the .vert or .frag file!

#include "MLX42/MLX42_Int.h"

const char* frag_shader = "#version 330 core\n"
	"in vec2 TexCoord;"
	"out vec4 FragColor;  "
	"uniform sampler2D OutTexture;"
	"void main()"
	"{"
	"	FragColor = texture(OutTexture, TexCoord);"
	"}";
