//
// Created by nuclaer on 10/30/21.
//

#ifndef DEEPERDECAY_FIELDPOINT_H
#define DEEPERDECAY_FIELDPOINT_H

#include "vmmlib/vector.hpp"
using namespace vmml;


class FieldPoint {
public:
	vec3f direction;
	float strength;

	float scalar;
	vec3f vector;
};


#endif //DEEPERDECAY_FIELDPOINT_H
