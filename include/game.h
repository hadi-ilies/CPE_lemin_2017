/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** game.h
*/

#ifndef GAME_H_
#define GAME_H_

#include <stdbool.h>
#include "room.h"

#define START "##start"
#define END "##end"
#define GAME_ERROR (game_t){.nb_ant = 0}
#define ROOM_EXIST_DOUBLE my_strcmp(link[0], link[1]) == 0 || \
		check_room_exist(game, link) == false

typedef struct {
	size_t nb_ant;
	room_t *start;
	room_t *end;
	size_t nb_room;
	room_t *room;
} game_t;

int count_adds(char **file, int j, game_t *game);
void display_error_more_start_end(char **file, int j);
void display_error_link(char **file, int j);
bool check_end(char **file);
bool check_start(char **file);
void display_file(char **file);
void free_file(char **file);
bool check_ants(char *nb_ants);
bool take_rooms(game_t *game, char **file, int i);
bool take_info(game_t *game, char **file);
int count_rooms(char **file);
char *supr_comment(char *str);
char **save_file(void);
bool count_bar(char *link);
bool parsing3(game_t *game, char **file);
bool parsing2(game_t *game, char **file);
bool parsing(char **file);
bool check_name_and_coord(game_t *game, size_t *j);
bool check_room_exist(game_t *game, char **link);
game_t game_create(void);
int find_room(game_t *game, char *room);
void linked_room(room_t *room1, room_t *room2);
void make_link(game_t *game, char **file);
bool parsing(char **file);
void game_destroy(game_t *game);
bool game_error(game_t *game);
bool game_set_var(game_t *game, char **file);

#endif
