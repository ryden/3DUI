//
// Copyright � 2014 - Alberto Alonso
// This work is free. You can redistribute it and/or modify it under the
// terms of the Do What The Fuck You Want To Public License, Version 2,
// as published by Sam Hocevar. See the COPYING file or http://www.wtfpl.net/ 
// for more details.
//
// FILE:        renderer.h
// PURPOUSE:    Renderer interface
//

#pragma once

#include "constants.h"
#include "math/transform.h"
#include "model/mesh.h"
#include "model/scene.h"
#include "model/viewPort.h"

#include "rendererImpl.h"

namespace renderer {

class Renderer {
public:
                Renderer        ();
                ~Renderer       ();

    void        renderScene     (const model::ViewPort& viewPort, model::Scene* scene);
    void        renderMesh      (const model::ViewPort& viewPort, model::Entity* camera, model::Mesh* mesh, model::Material* material, const Transform& transform);
    void        clear           ();

    void        setEnabled      (Constant state, bool enabled);

    //------------------------------------------------
    // Private utility functions
private:
    bool        init            ();

private:
    RendererImpl*   mImpl;
};

}

