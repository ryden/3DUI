//
// Copyright � 2014 - Alberto Alonso
// This work is free. You can redistribute it and/or modify it under the
// terms of the Do What The Fuck You Want To Public License, Version 2,
// as published by Sam Hocevar. See the COPYING file or http://www.wtfpl.net/ 
// for more details.
//
// FILE:        impl/opengl3/renderer.h
// PURPOUSE:    OpenGL3 renderer implementation.
//

#pragma once

#include "program.h"

namespace renderer {
namespace impl {

class OpenGL3Impl : public RendererImpl {
public:
                        OpenGL3Impl     ();
    virtual             ~OpenGL3Impl    ();

    //-------------------------------------------------
    // Methods inherited from RendererImpl
    void                clear           () override;
    void                renderMesh      ( model::Mesh* mesh, model::Material* material, const Transform& transform, RendererImplData* data ) override;
    RendererImplData*   createData      () const override;
    Program*            createProgram   () const override;
};

}
}