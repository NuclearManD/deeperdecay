//
// Created by nuclaer on 10/30/21.
//

#ifndef DEEPERDECAY_GAMEOBJECT_H
#define DEEPERDECAY_GAMEOBJECT_H

#include "ObjectPart.h"
#include "vmmlib/vector.hpp"

using namespace vmml;


class GameObject {
public:
	void update(double dt);

	ObjectPart* part;
private:
	vec3d position;

};


#endif //DEEPERDECAY_GAMEOBJECT_H
