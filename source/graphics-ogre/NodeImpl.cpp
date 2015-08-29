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
void Node::addChild(Node* child)
{
	OGRE::SceneNode* childOgreNode = child->getDetails()->getOgreNode();
	OGRE::SceneNode* ogreNode = getOgreNode();
	ogreNode->addChild(childOgreNode);
}

void Node::removeChild(Node* child)
{
	OGRE::SceneNode* childOgreNode = child->getDetails()->getOgreNode();
	OGRE::SceneNode* ogreNode = getOgreNode();
	ogreNode->removeChild(childOgreNode);
	// TODO:
	// child->onParentRemove();
}

//! Callback to be called on parent removal
void Node::onParentRemove()
{
}

void Node::setPosition(Vector3d<f32> newPosition)
{
	position = newPosition;
	getOgreNode()->setPosition(toOgre(newPosition));
}

//! Set node's position via coordinates
void Node::setPosition(f32 const x, f32 const y, f32 const z)
{
	position = Vector3d<f32>(x, y, z);
	getOgreNode()->setPosition(x, y, z);
}

void Node::setScale(Vector3d<f32> newScale)
{
	scale = newScale;
	getOgreNode()->setScale(toOgre(newScale));
}

void Node::setOrientation(Quaternion<f32> const& quat)
{
	orientation = quat;
	getOgreNode->setOrientation(toOgre(quat));
}

Vector3d<f32> Node::getScale()
{
	return scale;
}

Vector3d<f32> Node::getPosition()
{
	return position;
}

Quaternion<f32> Node::getOrientation()
{
	return rotation;
}
} // namespace impl
} // namespace scene
} // namespace awrts
