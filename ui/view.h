//
// Copyright � 2014 - Alberto Alonso
// This work is free. You can redistribute it and/or modify it under the
// terms of the Do What The Fuck You Want To Public License, Version 2,
// as published by Sam Hocevar. See the COPYING file or http://www.wtfpl.net/ 
// for more details.
//
// FILE:        view.h
// PURPOUSE:    Base class for the UI views.
//

#pragma once

#include "math/vector.h"
#include "renderer/canvas.h"
#include <vector>

namespace ui {

class View {
public:
    typedef std::vector<View *> ViewVector;

public:
                            View                ();
                            View                (const Vector2i& position);
                            View                (int x, int y);
    virtual                 ~View               ();

    void                    addView             (View* view);
    virtual void            draw                (renderer::Canvas* canvas) {}
    virtual void            onLayout            (const Recti& rect) {}

    ViewVector&             getChildren         () { return mChildren; }
    const ViewVector&       getChildren         () const { return mChildren; }
    View*                   getParent           () const { return mParent; }

    void                    setPosition         (const Vector2i& position);
    const Vector2i&         getPosition         () const { return mPosition; }

private:
    View*           mParent;
    ViewVector      mChildren;
    Vector2i        mPosition;
};

}
