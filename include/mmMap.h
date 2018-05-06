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
#ifndef _ae_mmMap
#define _ae_mmMap
#include <vector>
#include <string>
#include <inttypes.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <learnopengl/camera.h>
#include "lodfile.h"
#include "aeGeometry.h"

namespace angel{
	class mmMap{
    protected:
        int version;
		std::string mapname;
        pLodData loddata;
	public:
		mmMap( pLodData _loddata, const std::string name ):
         mapname(name), loddata(_loddata)
        {
        }
		~mmMap(){};
		virtual void Draw(glm::mat4 projection, glm::mat4 view, Camera camera)=0;
		int MapVersion() { return version;}  
		virtual void TogglePortals()=0;
		virtual void ToggleEnts()=0;
		const std::string& MapName(){ return mapname;}
		virtual void Select()=0;
	};
}
#endif //_ae_mmMap
