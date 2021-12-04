//
// Created by nuclaer on 11/26/21.
//

#ifndef DEEPERDECAY_LEVEL_H
#define DEEPERDECAY_LEVEL_H


#include <vmmlib/vector.hpp>
#include <deeperdecay/rendering/Shader.h>
#include "GameObject.h"

#define LEVEL_WIDTH_METERS 1024
#define CHUNK_WIDTH_METERS 16
#define LEVEL_WIDTH_CHUNKS (LEVEL_WIDTH_METERS / CHUNK_WIDTH_METERS)
#define NUM_CHUNKS LEVEL_WIDTH_CHUNKS * LEVEL_WIDTH_CHUNKS

class ObjectIteratorByPosition {
public:
	ObjectIteratorByPosition(std::vector<GameObject*>& objects, vec2d p1, vec2d p2) : objects(objects), p1(p1), p2(p2) {
		length = objects.size();
		position = -1;
		last = nullptr;
	}

	GameObject* getNext();

private:
	std::vector<GameObject*>& objects;
	vec2d p1;
	vec2d p2;

	int length;
	int position;
	GameObject* last;
};


class Level {
public:

	void update(double dt);

	std::vector<GameObject*>* posToChunk(vec2d point);
	bool addGameObject(vec2d point, GameObject& gameObject);
	ObjectIteratorByPosition getObjectsIn(vec2d chunk_point, vec2d p1, vec2d p2);

	void render(ShaderProgram* shader);

private:
	std::vector<GameObject*> chunks[NUM_CHUNKS];

};


#endif //DEEPERDECAY_LEVEL_H
