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

#ifndef  __PRNG_H_
#define  __PRNG_H_

#include "list.h"

#define TEMPER 0xAABBCCDD
#define MASK   0xFFFFFFFF
#define ROTL(x, y) ((x << y) & MASK) | (x >> (8 * sizeof(x) - y))
#define ROTR(x, y) (x >> y) | (x << (8 * sizeof(x) - y))

typedef struct _prng
{
    list_t *list;
    INT temper;
} prng_t;

prng_t *new_prng();

void init_prng(prng_t *prng);

void reset_prng(prng_t *prng);

void prng_seed(prng_t *prng, INT seed);

INT get_random(prng_t *prng);

#endif /*__PRNG_H_*/
