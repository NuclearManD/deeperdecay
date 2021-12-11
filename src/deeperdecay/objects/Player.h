//
// Created by nuclaer on 12/9/21.
//

#ifndef DEEPERDECAY_PLAYER_H
#define DEEPERDECAY_PLAYER_H

#include <deeperdecay/framework/GameObject.h>
#include <deeperdecay/rendering/Window.h>


class Player: public GameObject {
public:
	explicit Player(Window& window) : window(window) {

		texture = &loadTexture("res/textures/player.bmp");
	}

	void render(ShaderProgram *shader) override;

	void update(double dt) override;

	void renderWorld(ShaderProgram *shader);

private:
	Window& window;
	Texture* texture;
};


#endif //DEEPERDECAY_PLAYER_H
