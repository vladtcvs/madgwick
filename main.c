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

#include <definitions.h>
#include <quaternion.h>

quaternion_t madgwick_iterate(quaternion_t pos,
			      real wx, real wy, real wz,
			      real ax, real ay, real az,
			      real mx, real my, real mz,
			      real dt)
{
	quaternion_t res;
	quaternion_t w, Sqw;
	w.w = 0;
	w.x = wx;
	w.y = wy;
	w.z = wz;
	Sqw = q_add(pos, q_scale(q_multiply(pos, w), 0.5*dt));

	return res;
}