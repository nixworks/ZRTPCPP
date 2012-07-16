/*
  Copyright (C) 2006-2012 Werner Dittmann

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _ZRTPRANDOM_H_
#define _ZRTPRANDOM_H_

/**
 * @file ZrtpCommon.h
 * @brief ZRTP standalone random number generator
 * @defgroup GNU_ZRTP The GNU ZRTP C++ implementation
 * @{
 */

#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>

class ZrtpRandom {
public:
    /**
     * @brief This method adds entropy to the PRNG.
     *
     * An application may seed some entropy data to the PRNG. If the @c buffer is
     * @c NULL or the @c length is zero then the method adds at least some system
     * entropy.
     *
     * @param buffer some entropy data to add
     *
     * @param length length of entropy data in bytes
     *
     * @return number of entropy bytes added on success, -1 on failure. Number of
     *         bytes added bigger then @c length because of additional added system
     *         entropy.
     */
    static int addEntropy(const uint8_t *buffer, uint32_t length);

    /**
     * @brief Get some random data.
     *
     * @param buffer that will contain the random data
     *
     * @param length how many bytes of random data to generate
     *
     * @return the number of generated random data bytes
     */
    static int getRandomData(uint8_t *buffer, uint32_t length);

private:
    static void initialize();
    static ssize_t getSystemSeed(uint8_t *seed, ssize_t length);

};

#endif /* ZRTPRANDOM */