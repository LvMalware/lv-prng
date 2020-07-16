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

#include <stdlib.h>
#include "list.h"

list_t *
new_list()
{
    return (list_t *) calloc(1, sizeof(list_t));
}

item_t *
new_item(INT value)
{
    item_t *item = (item_t *) calloc(1, sizeof(item_t));
    item->value = value;
    return item;
}

void
insert_front(list_t *list, INT value)
{
    item_t *item = new_item(value);
    item->next = list->begin;
    list->begin = item;
}

void
insert_back(list_t *list, INT value)
{
    item_t *item = new_item(value);
    if (list->end)
    {
        list->end->next = item;
    }
    else
    {
        list->begin = item;
    }
    list->end = item;
}

INT
get_front(list_t *list)
{
    item_t *item = list->begin;
    list->begin = item->next;
    INT value = item->value;
    free(item);
    return value;
}

INT
get_back(list_t *list)
{
    item_t *item = list->end;
    list->end = item->next; //NULL
    INT value = item->value;
    free(item);
    return value;
}

void
destroy_list(list_t *list)
{
    item_t *item = list->begin;
    while (item)
    {
        item_t *next = item->next;
        free(item);
        item = next;
    }
    free(list);
}
