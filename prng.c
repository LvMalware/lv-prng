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
#include <stdio.h>
#include <math.h>
#include "prng.h"

const INT default_list[] = {0x12345678, 0x0ABCDEF0, 0x31415926, 0xC0DE0001};

prng_t *
new_prng()
{
    return (prng_t *) calloc(1, sizeof(prng_t));
}

void
init_prng(prng_t *prng)
{
    prng->list = new_list();
    prng->temper = TEMPER;
    int i;
    for (i = 0; i < sizeof(default_list) / sizeof(INT); i++)
    {
        insert_back(prng->list, default_list[i]);
    }
}

void
reset_prng(prng_t *prng)
{
    if (prng->list)
    {
        destroy_list(prng->list);
    }
    init_prng(prng);
}

void
prng_seed(prng_t *prng, INT seed)
{
    reset_prng(prng);
    insert_front(prng->list, seed);
}

void
temper_prng(prng_t *prng, INT num)
{
    item_t *item;
    for (item  = prng->list->begin; item != NULL; item = item->next)
    {
        item->value ^= prng->temper;
        item->value = (num % 2) ? ROTL(item->value, num) : ROTR(item->value, num);
        num = (num + item->value) % (8 * sizeof(INT));
    }
}

INT
get_random(prng_t *prng)
{
    INT k = get_front(prng->list);
    INT x = 0, i = 1;
    while (k)
    {
        int d = k % (INT) pow(10, i++);
        x += d * d;
        k /= 10;
    }
    prng->temper ^= ROTL(x, i);
    temper_prng(prng, i);
    insert_back(prng->list, x + i);
    return prng->temper;
}

