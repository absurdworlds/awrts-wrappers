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
class Object;

//! A node in the scene graph
class Node {
public:
	//! Default constructor
	Node();
	
	//! Attach child to node
	virtual bool addChild(Node* child);
	
	//! Remove child from node
	virtual bool removeChild(Node* child);
	
	//! Attach node to parent
	virtual bool setParent(Node* parent);

	//! Detach node from parent
	virtual bool removeParent();

	//! Callback to be called on parent removal
	virtual void onParentRemove();

	//! Set node's position via vector
	virtual void setPosition(Vector3d<f32> pos);
	
	//! Set node's position via coordinates
	virtual void setPosition(f32 const X, f32 const Y, f32 const Z);

	//! Set node's orientation via euler angles
	virtual void setOrientation(Vector3d<f32> euler);
	
	//! Set node's orientation via quaternion
	virtual void setOrientation(Quaternion<f32> const& quat);

	//! Set node's relative scale
	virtual void setScale(Vector3d<f32> scale);
	
	//! Get node's position
	virtual Vector3d<f32> getPosition();

	//! Get node's orientation
	virtual Vector3d<f32> getRotation();

	//! Get pointer to hidden details.
	impl::Node* getDetails()
	{
		return details.get();
	}
protected:
	virtual void initDetails(impl::Node* newDetails)
	{
		details.reset(newDetails);
	}
private:
	std::unique_ptr<impl::Node> details;
};
} // namespace scene
} // namespace awrts
#endif //_awrts_SceneNode_
