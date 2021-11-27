//
// Created by nuclaer on 11/27/21.
//

#include "TestObject.h"

void TestObject::render(ShaderProgram* shader) {
	shader->setMeshPosition(position.xy[0], position.xy[1], 0);
	shader->setMeshScale(1, 1, 1);
	shader->setTextureSelected(texture);
	drawSquare();
}