/*
 * Copyright (C) 2020 Lucas V. Araujo <lucas.vieira.ar@disroot.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef  __LIST_H_
#define  __LIST_H_

#include <stdint.h>

#define INT uint32_t

typedef struct _item
{
    INT value;
    struct _item *next;
}	item_t;

typedef struct _list
{
    item_t *begin;
    item_t *end;
} list_t;

list_t *new_list();
item_t *new_item(INT value);
void insert_front(list_t *list, INT value);
void insert_back(list_t *list, INT value);
INT get_front(list_t *list);
INT get_back(list_t *list);
void destroy_list(list_t *list);

#endif /*__LIST_H_*/
