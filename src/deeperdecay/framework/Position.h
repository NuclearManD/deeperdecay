//
// Created by nuclaer on 11/26/21.
//

#ifndef DEEPERDECAY_POSITION_H
#define DEEPERDECAY_POSITION_H

#include "vmmlib/vector.hpp"

using namespace vmml;

class Level;
class Position {
public:
	Position(Level* level, vec2d xy) : level(level), xy(xy) {}
	Position(Level* level, double x, double y) : level(level), xy(x, y) {}

	Level* level;
	vec2d xy;
};


#endif //DEEPERDECAY_POSITION_H
