/*
 * Copyright(C) 2014  absurdworlds
 * Copyright(C) 2015  hedede <haddayn@gmail.com>
 *
 * License LGPLv3-only:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef _awrts_SceneNode_
#define _awrts_SceneNode_
#include <awrts/common/types.h>

#include <awrts/math/Vector3d.h>
#include <awrts/math/Matrix4.h>
#include <awrts/math/Quaternion.h>

namespace awrts {
namespace scene {
class Entity;

//! A node in the scene graph
class Node {
public:
	//! Attach child to node
	virtual bool addChild(Node* child);
	
	//! Remove child from node
	virtual bool removeChild(Node* child);

	//! Callback on parent removal
	virtual void onParentRemove();

	//! Set node's position via vector
	virtual void setPosition(Vector3d<f32> pos);
	
	//! Set node's position via coordinates
	virtual void setPosition(f32 const x, f32 const y, f32 const z);

	//! Set node's orientation via euler angles
	virtual void setOrientation(Vector3d<f32> euler);
	
	//! Set node's orientation via quaternion
	virtual void setOrientation(Quaternion<f32> const& orientation);

	//! Set node's relative scale
	virtual void setScale(Vector3d<f32> scale);
	
	//! Get node's position
	virtual Vector3d<f32> getPosition();

	//! Get node's orientation
	virtual Quaternion<f32> getOrientation();

	//! Get node's scale
	virtual Vector3d<f32> getScale();

	//! Attach an Entity
	virtual void attachEntity(Entity* entity);

	//! Remove an Entity
	virtual void detachEntity(Entity* entity);

/******************* Internal implementation details *******************/
public:
	class Details;

	Details* getDetails();

protected:
	Node(Details* details)
		: details(details)
	{
	}
private:
	std::unique_ptr<Details> details;
};
} // namespace scene
} // namespace awrts
#endif //_awrts_SceneNode_
