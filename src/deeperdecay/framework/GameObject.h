//
// Created by nuclaer on 10/30/21.
//

#ifndef DEEPERDECAY_GAMEOBJECT_H
#define DEEPERDECAY_GAMEOBJECT_H

#include "Position.h"
#include <deeperdecay/rendering/Shader.h>


class GameObject {
public:
	// Do nothing by default
	virtual void update(double dt) {}

	virtual void render(ShaderProgram *shader) {}

	Position position = Position(nullptr, 0, 0);
};


#endif //DEEPERDECAY_GAMEOBJECT_H
