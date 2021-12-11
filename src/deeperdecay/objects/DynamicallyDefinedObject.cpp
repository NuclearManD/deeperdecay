//
// Created by nuclaer on 12/11/21.
//

#include "DynamicallyDefinedObject.h"

#include "deeperdecay/rendering/primitives.h"


void DynamicallyDefinedObject::render(ShaderProgram* shader) {
	if (definition.texture != nullptr) {
		shader->setMeshPosition(position.xy[0], position.xy[1], 0);
		shader->setMeshScale(1, 1, 1);
		shader->setTextureSelected(*(definition.texture));
		drawSquare();
	}
}