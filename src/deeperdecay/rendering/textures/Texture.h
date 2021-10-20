//
// Created by nuclaer on 10/15/21.
//

#ifndef DEEPERDECAY_TEXTURE_H
#define DEEPERDECAY_TEXTURE_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <stdbool.h>

class Texture {
public:

    // Validity check
    virtual operator bool() = 0;

    GLuint getTextureId() const { return textureId; }

protected:
    GLuint textureId;
};


// This class just allows us to return a valid texture reference
// and signify an invalid texture
class TextureInvalid: public Texture {
public:
    operator bool () { return false; }
};


Texture& loadTexture(const char* path);


#endif //DEEPERDECAY_TEXTURE_H
