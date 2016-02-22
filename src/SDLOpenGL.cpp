#include "SDLOpenGL.h"
#include<iostream>


SDLOpenGL::SDLOpenGL(const std::string &_name, int _x, int _y, int _width, int _height)
{
    //Set all of the class variables using the data passed into the constructor
    m_name = _name;
    m_x = _x;
    m_y = _y;
    m_width = _width;
    m_height = _height;
    init();
}

void SDLOpenGL::init()
{
    //If SDL init fails print error message
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        errorExit("Error calling SDL Init");
    }

    //Create a window and store in the correct variable
    m_window=SDL_CreateWindow(m_name.c_str(),
                              m_x,m_y,
                              m_width,m_height,
                              SDL_WINDOW_OPENGL);

    //If creating a window fails print error message
    if(!m_window)
    {
        errorExit("Could not open SDL Window");
    }

    //Call the create context function
    createGLContext();

}

void SDLOpenGL::createGLContext()
{
    //Set GL context
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,5);

    //Enable sampling
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,4);

    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

    //Create context
    m_glContext=SDL_GL_CreateContext(m_window);
}

void SDLOpenGL::errorExit(const std::string &_msg) const
{
    std::cerr<<_msg<<std::endl;
    std::cerr<<SDL_GetError()<<std::endl;
    SDL_Quit();
    exit(EXIT_FAILURE);
}
