//
// Created by nuclaer on 11/27/21.
//

#ifndef DEEPERDECAY_TESTOBJECT_H
#define DEEPERDECAY_TESTOBJECT_H

#include <deeperdecay/framework/GameObject.h>
#include <deeperdecay/rendering/Shader.h>
#include <deeperdecay/rendering/primitives.h>

class TestObject: public GameObject {
public:
	TestObject() : texture(loadTexture("atom2.bmp")) {}

	virtual void render(ShaderProgram *shader);

private:
	Texture& texture;
};


#endif //DEEPERDECAY_TESTOBJECT_H
