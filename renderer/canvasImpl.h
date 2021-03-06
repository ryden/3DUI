//
// Copyright � 2014 - Alberto Alonso
// This work is free. You can redistribute it and/or modify it under the
// terms of the Do What The Fuck You Want To Public License, Version 2,
// as published by Sam Hocevar. See the COPYING file or http://www.wtfpl.net/ 
// for more details.
//
// FILE:        canvasImpl.h
// PURPOUSE:    Bridge to the renderer-specific implementation of Canvas.
//

#pragma once

#include "math/rect.h"
#include "math/vector.h"
#include "model/material.h"
#include "renderer.h"
#include "shared/color.h"
#include <string>

namespace renderer {
    class CanvasImpl {
    public:
        virtual             ~CanvasImpl     () {}

        virtual void        fillRect        (Renderer* renderer, const model::ViewPort& viewPort, const Recti& rect, model::Material* material) = 0;
        virtual void        drawText        (Renderer* renderer, const model::ViewPort& viewPort, const Vector2i& position, const std::string& text, const Color& color) = 0;
        virtual void        drawTexture     (Renderer* renderer, const model::ViewPort& viewPort, const Recti& rect, Texture* texture, const Rectf& textureCoordinates) = 0;
    };
}