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

//! An entity can be attached to a node in scene graph
class Entity {
public:
	//! Default constructor
	Entity();

	//! Get pointer to hidden details.
	impl::Entity* getDetails()
	{
		return details.get();
	}
protected:
	virtual void initDetails(std::unique_ptr<impl::Entity> newDetails)
	{
		details = newDetails;
	}
private:
	std::unique_ptr<impl::Entity> details;
};
} // namespace scene
} // namespace awrts
#endif //_awrts_scene_entity_
