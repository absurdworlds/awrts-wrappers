/*
 * Copyright(C) 2015  hedede <haddayn@gmail.com>
 *
 * License LGPLv3-only:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef _awrts_scene_entity_
#define _awrts_scene_entity_

namespace awrts {
namespace scene {

//! Entity can be attached to a node in scene graph
class Entity {
/******************* Internal implementation details *******************/
public:
	class Details;

	Details* getDetails()
	{
		return details.get();
	}
protected:
	Entity(Details* details)
		: details(details)
	{
	}
private:
	std::unique_ptr<Details*> details;
};
} // namespace scene
} // namespace awrts
#endif //_awrts_scene_entity_
