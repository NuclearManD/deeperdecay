//
// Created by nuclaer on 12/11/21.
//

#include <deeperdecay/objects/DynamicallyDefinedObject.h>
#include <deeperdecay/util/logging.h>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"
#include <cstdio>
#include <unordered_map>

using namespace rapidjson;


std::unordered_map<std::string, DynamicObjectDefinition*> dynamic_definitions;


static void loadObjectsError() {
	log_error("Failed to load object definitions, this will probably cause a lot of problems!");
}


void loadObjects() {
	static bool isAlreadyLoaded = false;

	if (isAlreadyLoaded) {
		log_warning("loadObjectDefinitions() was called more than once.  Not reloading.");
		return;
	}

	log_info("Loading object definitions");

	// Open and set up the object defintions file and the corresponding JSON Document
	FILE* fp = fopen("res/definitions/objects.json", "rb");
	if (fp == nullptr) {
		log_error("Could not open res/definitions/objects.json");
		return loadObjectsError();
	}
	char readBuffer[1024];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	Document document;
	document.ParseStream(is);

	// Parse the JSON data
	if (!document.IsArray()) {
		log_error("Objects definition file is not a list (as it should be).");
		fclose(fp);
		return loadObjectsError();
	}
	for (SizeType i = 0; i < document.Size(); i++) {
		if (document[i].IsObject()) {
			auto& definitionData = document[i];
			if (definitionData.HasMember("id") && definitionData.HasMember("name")) {
				Texture* texture = nullptr;
				if (definitionData.HasMember("texture")) {
					texture = &loadTexture(definitionData["texture"].GetString());
				}
				const char* name = definitionData["name"].GetString();
				const char* id = definitionData["id"].GetString();
				DynamicObjectDefinition* definition = new DynamicObjectDefinition(texture, name);
				dynamic_definitions[id] = definition;
			} else {
				log_error("Object definition #%u is incomplete, it will be skipped.  This may cause problems.", i);
			}
		} else {
			log_error("Object definition #%u is not an object, it will be skipped.  This may cause problems.", i);
		}
	}
	isAlreadyLoaded = true;
	log_info("Done loading object definitions");
}

DynamicObjectDefinition* getObjectDefinitionById(const char* id) {
	return dynamic_definitions[id];
}

GameObject* instantiateObjectById(const char* id) {
	return dynamic_definitions[id]->instantiate();
}

