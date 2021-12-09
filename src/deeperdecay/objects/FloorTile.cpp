//
// Created by nuclaer on 12/9/21.
//

#include "FloorTile.h"

#include "deeperdecay/rendering/primitives.h"


void FloorTile::render(ShaderProgram* shader) {
	shader->setMeshPosition(position.xy[0], position.xy[1], 0);
	shader->setMeshScale(1, 1, 1);
	shader->setTextureSelected(*texture);
	drawSquare();
}
