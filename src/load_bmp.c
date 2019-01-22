/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:26:31 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/22 22:34:47 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "rt.h"

static void	convert_sdl_clr_to_color_mask(t_color_mask *dest,
		void const *src, size_t const max)
{
	unsigned int	*pxl;
	size_t			i;

	i = 0;
	pxl = (unsigned int *)src;
	while (i < max)
	{
		dest[i].r = (double)((pxl[i] >> 16) & 0xff);
		dest[i].g = (double)((pxl[i] >> 8) & 0xff);
		dest[i].b = (double)((pxl[i]) & 0xff);
		++i;
	}
}

t_texu		*load_bmp(char const *file)
{
	SDL_Surface		*surface;
	t_texu			*texu;

	if (file == NULL || (surface = SDL_LoadBMP(file)) == NULL)
		return (NULL);
	if ((texu = (t_texu *)malloc(sizeof(*texu))) != NULL)
	{
		if ((texu->buf = (t_color_mask *)malloc(sizeof(t_color_mask)
						* surface->w * surface->h)) == NULL)
		{
			free(texu);
			SDL_FreeSurface(surface);
			return (NULL);
		}
		convert_sdl_clr_to_color_mask(texu->buf, surface->pixels,
				(size_t)(surface->w * surface->h));
		texu->size_x = surface->w;
		texu->size_y = surface->h;
	}
	SDL_FreeSurface(surface);
	return (texu);
}
