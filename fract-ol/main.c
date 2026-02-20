/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 08:34:48 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/19 08:41:59 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int main(void)
{
    void	*mlx;
    void	*win;
    
    // Step 1: Initialize connection to X server
    mlx = mlx_init();
    
    // Step 2: Create a window
    win = mlx_new_window(mlx, 640, 480, "My Window");
    
    // Step 3: Draw something
    mlx_pixel_put(mlx, win, 320, 240, 0x00FF0000);
    
    // Step 4: Register event handlers
    mlx_key_hook(win, handle_key, NULL);
    
    // Step 5: Start event loop (blocks forever)
    mlx_loop(mlx);
    
    return (0);
	}
}
