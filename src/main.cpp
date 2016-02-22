#include <iostream>
#include "SDLOpenGL.h"
#include <ngl/NGLInit.h>

void initializeGL();
void renderGL();

int main(int argc, char* argv[])
{
    SDLOpenGL window("Test",0,0,1024,720);
    window.makeCurrent();

    initializeGL();

    bool _while=true;

    while(_while)
    {
        renderGL();
        window.swapWindow();
        SDL_Delay(10);
        if(SDL_QUIT==1)
        {
            _while=false;
        };

   }



}

void initializeGL()
{
    ngl::NGLInit::instance();
    glClearColor(0.8,0.8,0.8,1.0);

}

void renderGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
