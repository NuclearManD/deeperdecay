//
// Created by nuclaer on 12/11/21.
//

#ifndef DEEPERDECAY_DYNAMICALLYDEFINEDOBJECT_H
#define DEEPERDECAY_DYNAMICALLYDEFINEDOBJECT_H

#include <deeperdecay/framework/GameObject.h>


class DynamicObjectDefinition;


class DynamicallyDefinedObject: public GameObject {
public:
	DynamicallyDefinedObject(DynamicObjectDefinition& definition) : definition(definition) {}

	void render(ShaderProgram *shader) override;

private:
	DynamicObjectDefinition& definition;
};


class DynamicObjectDefinition {
public:
	DynamicObjectDefinition(Texture* texture, const char* name) : texture(texture) {
		this->name = strdup(name);
	}

	~DynamicObjectDefinition() {
		delete name;
	}

	Texture* texture;
	const char *name;

	GameObject* instantiate() {
		return new DynamicallyDefinedObject(*this);
	}
};


#endif //DEEPERDECAY_DYNAMICALLYDEFINEDOBJECT_H
