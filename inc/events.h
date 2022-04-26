/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:01:44 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/07 21:10:00 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <raycaster.h>
# include <exit.h>

typedef struct s_state	t_state;
typedef struct s_vec2	t_vec2;

// Keycodes
# define W_KC 13
# define A_KC 0
# define S_KC 1
# define D_KC 2
# define F_KC 3

# define LEFT_KC 123
# define RIGHT_KC 124

# define ESC_KC 53

// Movement speed
# define ROTATION_SPEED 0.05
# define STEP_SIZE 0.1

// Events
# define KEY_DOWN 2
# define KEY_UP 3
# define MOUSE_DOWN 4
# define MOUSE_UP 5
# define MOUSE_MOVE 6
# define DESTROY 17

// key_hook.c
int		key_down(int kc, t_state *state);
int		key_up(int kc, t_state *state);
// int		exit_cub(t_state *state);

// loop_hook.c
int		loop_hook(t_state *state);

// mouse_hook.c
int		mouse_down(int button, int x, int y, t_state *state);
int		mouse_up(int button, int x, int y, t_state *state);
int		mouse_move(int x, int y, t_state *state);

// movement.c
void	go(t_state *state, t_vec2 dir);
void	rotate(t_state *state, int dir);
void	movement(t_state *state);

#endif
