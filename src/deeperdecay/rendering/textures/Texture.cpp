//
// Created by nuclaer on 10/15/21.
//

#include <fcntl.h>
#include <unistd.h>

#include "Texture.h"
#include "deeperdecay/util/strutil.h"
#include "deeperdecay/util/logging.h"


class TextureBMP: public Texture {
public:
    TextureBMP(const char* path) {
        // Data read from the header of the BMP file
        unsigned char header[54]; // Each BMP file begins by a 54-bytes header
        unsigned int dataPos;     // Position in the file where the actual data begins
        unsigned int width, height;
        unsigned int imageSize;   // = width*height*3
        // Actual RGB data
        unsigned char * data;

        // Open the file.  The int 'fd' means 'file descriptor'.  It's just a file ID
        // that we can use with C functions to identify our file.
        int fd = open(path, O_RDONLY);
        if (fd < 0) {
            log_error("Image %s could not be opened\n", path);
            didLoad = false;
            return;
        }

        // Read the BMP file header.
        // If not 54 bytes read then some of the header is missing,
        // indicating an invalid file.
        if (read(fd, header, 54) != 54) {
            log_error("Image %s is not a valid BMP file (too short)\n", path);
            didLoad = false;
            close(fd);
            return;
        }

        // Check that the first two bytes match the expected values
        if (header[0]!='B' || header[1]!='M') {
            log_error("Image %s is not a valid BMP file (bad start bytes)\n", path);
            didLoad = false;
            close(fd);
            return;
        }

        // Read ints from the byte array (parses BMP header)
        // TODO: This does NOT check endianness and may not work properly on some CPU architectures!!1
        dataPos    = *(int*)&(header[0x0A]);
        imageSize  = *(int*)&(header[0x22]);
        width      = *(int*)&(header[0x12]);
        height     = *(int*)&(header[0x16]);

        // Some BMP files are misformatted, guess missing information
        if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
        if (dataPos==0)      dataPos=54; // The BMP header is done that way

        // Create a buffer
        data = new unsigned char [imageSize];

        // Read the actual data from the file into the buffer
        if (read(fd, data, imageSize) < imageSize) {
            log_error("Image %s is not a valid BMP file (EOF in color data)\n", path);
            didLoad = false;
            close(fd);
            return;
        }

        //Everything is in memory now, the file can be closed
        close(fd);

        // Create one OpenGL texture
        glGenTextures(1, &textureId);

        // "Bind" the newly created texture : all future texture functions will modify this texture
        glBindTexture(GL_TEXTURE_2D, textureId);

        // Give the image to OpenGL
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

        // When MAGnifying the image (no bigger mipmap available), use LINEAR filtering
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // When MINifying the image, use a LINEAR blend of two mipmaps, each filtered LINEARLY too
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        // Generate mipmaps, by the way.
        glGenerateMipmap(GL_TEXTURE_2D);

        didLoad = true;
    }

    operator bool () {
        return didLoad;
    }

private:
    bool didLoad;
};



static TextureInvalid invalid_texture{};

Texture* tex;

Texture& loadTexture(const char* path) {
    if (strendswith(path, ".bmp")) {
        tex = new TextureBMP(path);
        return *tex;
    } else {
        log_error("Unable to load %s: Unrecognized file extension", path);
        return invalid_texture;
    }
}
