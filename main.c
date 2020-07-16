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

#include <stdio.h>
#include "prng.h"

int
main(int argc, char *argv[])
{
    prng_t *prng = new_prng();
    init_prng(prng);
    prng_seed(prng, 616);
    int i;
    for (i = 0; i < 1000; i++)
    {
        int k = get_random(prng);
        printf("%02dth number: %u\n", i, k);
    }
    return 0;
}