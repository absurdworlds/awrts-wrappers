/*
 * Copyright(C) 2014  absurdworlds
 * Copyright(C) 2015  hedede <haddayn@gmail.com>
 *
 * License LGPLv3-only:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#include <algorithm>

#include <awrts/scene/Node.h>

namespace OGRE {
class SceneNode;
}

namespace hrengin {
namespace scene {
class Node::Details {
public:
	OGRE::SceneNode* getOgreNode()
	{
		return ogreNode;
	}
private:
	OGRE::SceneNode* ogreNode;
}

namespace impl {
class Node : scene::Node {
public:
	//! Should be called only by scene::Manager
	Node(scene::Manager* mgr)
		: scene::Node(new scene::Node::Details)
	{
	}
	
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
private:
	Vector3d<f32> scale;
	Vector3d<f32> position;
	Quaternion<f32> orientation;

	OGRE::SceneNode* getOgreNode()
	{
		return getDetails()->getOgreNode();
	}
}
} // namespace impl
} // namespace scene
} // namespace awrts
