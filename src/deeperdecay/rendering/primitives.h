//
// Created by nuclaer on 10/20/21.
//

#ifndef DEEPERDECAY_PRIMITIVES_H
#define DEEPERDECAY_PRIMITIVES_H

// I almost made this a whole directory.  We may split it that way in the future.
// But I don't think so.

// We assume, for all of these, that you have already selected your texture/color,
// along with any other special OpenGL options, shader config, etc
// All units are -1..1, with -1 being on the left/bottom and 1 at the top/right
void drawRectangle(float x1, float y1, float x2, float y2, float z);

#endif //DEEPERDECAY_PRIMITIVES_H
