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

#include <quaternion.h>
#include <math.h>

quaternion_t
q_conjugate(quaternion_t q)
{
	quaternion_t r;
	r.w = q.w;
	r.x = -q.x;
	r.y = -q.y;
	r.z = -q.z;
	return r;
}

quaternion_t
q_scale(quaternion_t q, real n)
{
	quaternion_t r;
	r.w = q.w * n;
	r.x = q.x * n;
	r.y = q.y * n;
	r.z = q.z * n;
	return r;
}

quaternion_t
q_add(quaternion_t q1, quaternion_t q2)
{
	quaternion_t r;
	r.w = q1.w + q2.w;
	r.x = q1.x + q2.x;
	r.y = q1.y + q2.y;
	r.z = q1.z + q2.z;
	return r;
}

quaternion_t
q_multiply(quaternion_t q1, quaternion_t q2)
{
	quaternion_t r;
	r.w = q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z;
	r.x = q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y;
	r.y = q1.w*q2.y + q1.y*q2.w + q1.z*q2.x - q1.x*q2.z;
	r.z = q1.w*q2.z + q1.z*q2.w + q1.x*q2.y - q1.y*q2.x;
	return r;
}

real
q_length(quaternion_t q)
{
	return sqrt(q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z);
}

real
q_length2(quaternion_t q)
{
	return q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z;
}

quaternion_t
q_invert(quaternion_t q)
{
	real l2;

	l2 = q_length2(q);
	if (l2 < eps) {
		/* do something */
	}
	return q_scale(q_conjugate(q), 1/l2);
}

quaternion_t
q_rotation(real angle, real nx, real ny, real nz)
{
	quaternion_t r;
	real len2 = nx*nx + ny*ny + nz*nz, len;
	real cosa, sina;

	if (len2 < eps) {
		/* do something */
	}
	len = sqrt(len2);
	nx /= len;
	ny /= len;
	nz /= len;
	cosa = cos(angle/2);
	sina = sin(angle/2);
	r.w = cosa;
	r.x = sina * nx;
	r.y = sina * ny;
	r.z = sina * nz;
	return r;
}
