//
// Created by nuclaer on 12/4/21.
//

#include "Beaker.h"


void Beaker::render(ShaderProgram* shader) {
	shader->setMeshPosition(position.xy[0], position.xy[1], 0);
	shader->setMeshScale(1, 1, 1);
	shader->setTextureSelected(texture);
	drawSquare();
}