#pragma once

#include "IRenderer3D.h"

namespace Moge
{
    class OpenGLRenderer final:
        public IRenderer3D
    {
    public:
        OpenGLRenderer();
        ~OpenGLRenderer();

        void forceDestroy() override;
        void updateScreen() override;
        void clear() override;

    protected:
    private:
    };
}