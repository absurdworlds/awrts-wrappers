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

namespace hrengin {
namespace scene {
namespace impl {
class Node {
public:
	virtual void addChild(Node* child)
	{
		OGRE::SceneNode* node = child->getDetails()->getOgreNode();
		ogreNode->addChild(node);
	}

	//! Remove child from node
	virtual void removeChild(Node* child)
	{
		OGRE::SceneNode* node = child->getDetails()->getOgreNode();
		ogreNode->removeChild(node);
		// TODO:
		// child->onParentRemove();
	}

	virtual void setPosition(Vector3d<f32> newPosition)
	{
		position = newPosition;
		ogreNode->setPosition(toOgre(newPosition));
	}

	virtual void setScale(Vector3d<f32> newScale)
	{
		scale = newScale;
		ogreNode->setScale(toOgre(newScale));
	}

	virtual void setOrientation(Quaternion<f32> const& quat)
	{
		orientation = quat;
		ogreNode->setOrientation(toOgre(quat));
	}

	virtual Vector3d<f32> getScale()
	{
		return scale;
	}

	virtual Vector3d<f32> getPosition()
	{
		return position;
	}

	virtual Quaternion<f32> getOrientation()
	{
		return rotation;
	}

	virtual OGRE::SceneNode* getOgreNode()
	{
		return ogreNode;
	}
private:
	OGRE::SceneNode* ogreNode;
	Vector3d<f32> scale;
	Vector3d<f32> position;
	Quaternion<f32> orientation;
}
}

//! Default constructor
Node::Node()
{
	std::unique_ptr details(new impl::Node());
	initDetails(std::move(details));
}

//! Attach child to node
virtual void addChild(Node* child)
{
	details->addChild(child);
}

//! Remove child from node
virtual void removeChild(Node* child)
{
	details->removeChild(child);
}

//! Callback to be called on parent removal
virtual void onParentRemove()
{
}

//! Set node's position via vector
virtual void setPosition(Vector3d<f32> pos)
{
	details->setPosition(pos);
}

//! Set node's position via coordinates
virtual void setPosition(f32 const x, f32 const y, f32 const z)
{
	details->setPosition(x, y, z);
}

//! Set node's orientation via euler angles
virtual void setRotation(Vector3d<f32> euler)
{
	details->setOrientation(euler);
}

//! Set node's orientation via quaternion
virtual void setOrientation(Quaternion<f32> const& quat)
{
	details->setOrientation(quat);
}

//! Set node's relative scale
virtual void setScale(Vector3d<f32> scale)
{
	details->setScale(scale);
}

//! Get node's scale
virtual Vector3d<f32> getScale()
{
	return getDetails()->getScale();
}

//! Get node's position
virtual Vector3d<f32> getPosition()
{
	return details->getPosition();
}

//! Get node's orientation
virtual Quaternion<f32> getOrientation()
{
	return details->getOrientation();
}

} // namespace scene
} // namespace awrts
