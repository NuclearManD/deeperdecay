//
// Created by nuclaer on 12/9/21.
//

#include "Player.h"
#include <GLFW/glfw3.h>

#include "deeperdecay/rendering/primitives.h"
#include "deeperdecay/framework/Level.h"


#define SPEED 5


void Player::render(ShaderProgram* shader) {
	shader->setMeshPosition(position.xy[0], position.xy[1], 0);
	shader->setMeshScale(1, 1, 1);
	shader->setTextureSelected(*texture);
	drawSquare();
}

void Player::update(double dt) {
	// Move forward
	if (window.getKey(GLFW_KEY_UP) == GLFW_PRESS){
		position.xy[1] += dt * SPEED;
	}
	// Move backward
	if (window.getKey( GLFW_KEY_DOWN ) == GLFW_PRESS){
		position.xy[1] -= dt * SPEED;
	}
	// Strafe right
	if (window.getKey( GLFW_KEY_RIGHT ) == GLFW_PRESS){
		position.xy[0] += dt * SPEED;
	}
	// Strafe left
	if (window.getKey( GLFW_KEY_LEFT ) == GLFW_PRESS){
		position.xy[0] -= dt * SPEED;
	}
}

void Player::renderWorld(ShaderProgram *shader) {
	shader->setRenderOrigin(position.xy[0], position.xy[1]);
	position.level->render(shader);
}
