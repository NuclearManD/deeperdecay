//
// Created by nuclaer on 11/26/21.
//

#include "Level.h"

static inline int posToChunkIndex(vec2d point) {
	int x = floor(point[0]);
	int y = floor(point[1]);

	if (x < 0 || y < 0 || x >= LEVEL_WIDTH_METERS || y >= LEVEL_WIDTH_METERS)
		return -1;

	return (x / CHUNK_WIDTH_METERS) + (y / CHUNK_WIDTH_METERS) * LEVEL_WIDTH_CHUNKS;
}

GameObject* ObjectIteratorByPosition::getNext() {
	if (position >= length)
		return nullptr;
	if (length != objects.size())
		return nullptr;

	position++;
	while (position < length) {
		vec2d pos = objects[position]->position.xy;
		if (pos[0] >= p1[0] &&
			pos[1] >= p1[1] &&
			pos[0] <= p2[0] &&
			pos[1] <= p2[1])
			return (last = objects[position]);
	}
	return nullptr;
}

std::vector<GameObject*>* Level::posToChunk(vec2d point) {
	int index = posToChunkIndex(point);
	if (index == -1)
		return nullptr;
	return &chunks[index];
}

bool Level::addGameObject(vec2d point, GameObject &gameObject) {
	int index = posToChunkIndex(point);
	if (index == -1)
		return false;

	gameObject.position = Position(this, point);
	chunks[index].push_back(&gameObject);
	return true;
}

ObjectIteratorByPosition Level::getObjectsIn(vec2d chunk_point, vec2d p1, vec2d p2) {
	int index = posToChunkIndex(chunk_point);
	if (index == -1)
		return ObjectIteratorByPosition(chunks[3], vec2d(0, 0), vec2d(-1, -1));

	vec2d new_p1(fmin(p1[0], p2[0]), fmin(p1[1], p2[1]));
	vec2d new_p2(fmax(p1[0], p2[0]), fmax(p1[1], p2[1]));
	return ObjectIteratorByPosition(chunks[index], new_p1, new_p2);
}

void Level::update(double dt) {
	for (auto & chunk : chunks) {
		for (GameObject* object : chunk) {
			object->update(dt);
		}
	}
}

void Level::render(ShaderProgram *shader) {
	shader->setRenderOrigin(0, 0, 0);
	for (auto & chunk : chunks) {
		for (GameObject* object : chunk) {
			object->render(shader);
		}
	}
}

