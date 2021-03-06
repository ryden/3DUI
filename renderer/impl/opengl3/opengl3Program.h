//
// Copyright � 2014 - Alberto Alonso
// This work is free. You can redistribute it and/or modify it under the
// terms of the Do What The Fuck You Want To Public License, Version 2,
// as published by Sam Hocevar. See the COPYING file or http://www.wtfpl.net/ 
// for more details.
//
// FILE:        impl/opengl3/program.h
// PURPOUSE:    Graphics rendering proram for OpenGL3
//

#pragma once

#include "../../program.h"
#include <functional>
#include <vector>

namespace renderer { namespace impl {

class OpenGL3_Program : public Program {
    typedef std::vector<std::function<void()>> CommandVector;

public:
                OpenGL3_Program     ();
    virtual     ~OpenGL3_Program    ();

private:
    bool        init                ();


    //--------------------------------------
    // Methods inherited from Program
protected:
    bool        loadVertex          (const char* source) override;
    bool        loadFragment        (const char* source) override;
    bool        link                () override;
    bool        bind                () override;
    bool        unbind              () override;

    bool        setVertexAttrib     (const std::string& name, VertexAttrib* attrib) override;

    bool        setUniform          (const std::string& name, bool value) override;
    bool        setUniform          (const std::string& name, float value) override;
    bool        setUniform          (const std::string& name, int value) override;
    bool        setUniform          (const std::string& name, const Vector2& vec) override;
    bool        setUniform          (const std::string& name, const Vector3& vec) override;
    bool        setUniform          (const std::string& name, const Vector4& vec) override;
    bool        setUniform          (const std::string& name, const Matrix& mat) override;
    bool        setUniform          (const std::string& name, const Matrix* mat, unsigned int count) override;
    bool        setUniform          (const std::string& name, const Color& col, bool includeAlpha) override;
    bool        setUniform          (const std::string& name, float* values, unsigned int count) override;

private:
    bool        execute             (const std::function<void()>&& bindFn);
    bool        execute             (const std::function<void()>&& bindFn, const std::function<void()>&& unbindFn);

private:
    void*   mHandle;
    bool    mInitialized;
    bool    mLinked;
    bool    mBound;

    CommandVector   mBindCommands;
    CommandVector   mUnbindCommands;
};

} }
