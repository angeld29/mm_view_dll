/*

Copyright (C) 2010 Angel (angel.d.death@gmail.com)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the included (GNU.txt) GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifndef aeGeometry
#define aeGeometry
#include <inttypes.h>
namespace angel{
#pragma pack(push,1)
       	struct mm_int_vec3_s
       	{
       		int x,y,z;
			inline friend std::ostream& operator <<
				( std::ostream& o, const mm_int_vec3_s& v )
			{
				o << "v3i(" << v.x << ", " << v.y << ", " << v.z << ")" ;
				return o;
			}
       	};
       	struct mm_int_bbox_s
       	{
       		mm_int_vec3_s min,max;
			inline friend std::ostream& operator <<
				( std::ostream& o, const mm_int_bbox_s& v )
			{
				o << "min:" << v.min << " max:"<<v.max ;
				return o;
			}

       	};
       	struct mm_int_plane_s
       	{
       		mm_int_vec3_s normal;
       		int dist;
			inline friend std::ostream& operator <<
				( std::ostream& o, const mm_int_plane_s& v )
			{
				o << "n:" << v.normal<< " d:"<<v.dist;
				return o;
			}
       	};
       	struct mm_short_vec3_s
       	{
       		int16_t x,y,z;
			inline friend std::ostream& operator <<
				( std::ostream& o, const mm_short_vec3_s& v )
			{
				o << "v3s(" << v.x << ", " << v.y << ", " << v.z << ")" ;
				return o;
			}
       	};
       	struct mm_short_bbox_s
       	{
			int16_t minx,maxx;
			int16_t miny,maxy;
			int16_t minz,maxz;
			inline friend std::ostream& operator <<
				( std::ostream& o, const mm_short_bbox_s& v )
			{
				o << "min(" << v.minx << ", " << v.miny << ", " << v.minz << ")" ;
				o << " max(" << v.maxx << ", " << v.maxy << ", " << v.maxz << ")" ;
				return o;
			}
       	};
       	struct mm_float_vec3_s
       	{
       		float x,y,z;
			inline friend std::ostream& operator <<
				( std::ostream& o, const mm_float_vec3_s& v )
			{
				o << "v3f(" << v.x << ", " << v.y << ", " << v.z << ")";
				return o;
			}
       	};
       	struct mm_float_plane_s
       	{
			mm_float_vec3_s normal;
       		float dist;
			/* Function for writing to a stream.*/
			inline friend std::ostream& operator <<
				( std::ostream& o, const mm_float_plane_s& v )
			{
				o << "n:" << v.normal  << " d:" << v.dist;
				return o;
			}
       	};

#pragma pack(pop)
	struct vec3_t
	{
	public:
		vec3_t(){}
		vec3_t( const float* xyz):x(xyz[0]),y(xyz[1]),z(xyz[2]){}
		vec3_t( const vec3_t& v):x(v.x),y(v.y),z(v.z){}
		vec3_t( float x, float y, float z):x(x),y(y),z(z){}
		vec3_t( float x, float y ):x(x),y(y),z(1.0){}
		~vec3_t(){}

		bool operator==(const vec3_t & u) const
		{
			return (u.x == x && u.y == y && u.z == z) ? true : false;
		}
		bool operator!=( const vec3_t& rhs ) const
		{
			return !(*this == rhs );
		}
		vec3_t & operator*=( float lambda )
		{
			x*= lambda;
			y*= lambda;
			z*= lambda;
			return *this;
		}

		vec3_t operator - () const
		{
			return vec3_t(-x, -y, -z);
		}
		vec3_t & operator-=(const vec3_t & u)
		{
			x-= u.x;
			y-= u.y;
			z-= u.z;
			return *this;
		}
		vec3_t & operator+=(const vec3_t & u)
		{
			x+= u.x;
			y+= u.y;
			z+= u.z;
			return *this;
		}
		float vlen() const
		{
			return sqrt(x*x + y*y + z*z);
		}
		float normalize()
		{
			float	length, ilength;

			length = vlen();

			if (length)
			{
				ilength = 1/length;
				x *= ilength;
				y *= ilength;
				z *= ilength;
			}
			return length;
		}

		float& operator[](int i)
		{
			return vec_array[i];
		}

		const float operator[](int i) const
		{
			return vec_array[i];
		}
		union {
			struct {
				float x,y,z;        // standard names for components
			};
			struct {
				float s,t,r;        // standard names for components
			};
			float vec_array[3];     // array access
		};
	};
	struct  plane_t
	{
		vec3_t	normal;
		float dist;
	};

	struct bbox_t
	{

		vec3_t mins,maxs;
	};

        
}
#endif
