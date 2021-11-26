//
// Created by nuclaer on 11/26/21.
//

#ifndef DEEPERDECAY_POSITION_H
#define DEEPERDECAY_POSITION_H

#include "vmmlib/vector.hpp"
#include "Level.h"

using namespace vmml;


class Position {
public:
	Level& level;
	vec2d xy;
};


#endif //DEEPERDECAY_POSITION_H
