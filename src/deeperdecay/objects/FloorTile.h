//
// Created by nuclaer on 12/9/21.
//

#ifndef DEEPERDECAY_FLOORTILE_H
#define DEEPERDECAY_FLOORTILE_H


#include <deeperdecay/framework/GameObject.h>

class FloorTile: public GameObject {
public:
	FloorTile() {
		texture = &loadTexture("res/floor_tile.bmp");
	}

	virtual void render(ShaderProgram *shader);

private:
	Texture* texture;
};


#endif //DEEPERDECAY_FLOORTILE_H
