/* This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc., 59
 * Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#pragma once

#include <definitions.h>

struct quaternion_s {
	real x, y, z, w;
};

typedef struct quaternion_s quaternion_t;

quaternion_t q_conjugate(quaternion_t q);

quaternion_t q_multiply(quaternion_t q1, quaternion_t q2);

quaternion_t q_add(quaternion_t q1, quaternion_t q2);

quaternion_t q_scale(quaternion_t q1, real n);

real q_length(quaternion_t q);

real q_length2(quaternion_t q);

quaternion_t q_invert(quaternion_t q);

quaternion_t q_rotation(real angle, real nx, real ny, real nz);
