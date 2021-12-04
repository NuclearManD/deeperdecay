//
// Created by nuclaer on 12/4/21.
//

#ifndef DEEPERDECAY_BEAKER_H
#define DEEPERDECAY_BEAKER_H

#include <deeperdecay/framework/GameObject.h>
#include <deeperdecay/rendering/Shader.h>
#include <deeperdecay/rendering/primitives.h>


class Beaker: public GameObject {
public:
	Beaker() : texture(loadTexture("res/beaker_small.bmp")) {}

	virtual void render(ShaderProgram *shader);

private:
	Texture& texture;
};


#endif //DEEPERDECAY_BEAKER_H
