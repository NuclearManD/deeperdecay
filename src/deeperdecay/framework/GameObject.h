//
// Created by nuclaer on 10/30/21.
//

#ifndef DEEPERDECAY_GAMEOBJECT_H
#define DEEPERDECAY_GAMEOBJECT_H

#include "Position.h"


class GameObject {
public:
	// Do nothing by default
	void update(double dt) {}

	Position position;
};


#endif //DEEPERDECAY_GAMEOBJECT_H
