#ifndef SDLOPENGL_H__
#define SDL_OPENGL_H__

#include <SDL.h>
#include <string>

class SDLOpenGL
{
public:
    //The constructor of the class
    SDLOpenGL(const std::string &_name,
              int _x,
              int _y,
              int _width,
              int _height);

    void makeCurrent() const { SDL_GL_MakeCurrent(m_window,m_glContext); }
    void swapWindow() const { SDL_GL_SwapWindow(m_window); }


private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    std::string m_name;
    SDL_GLContext m_glContext;
    SDL_Window *m_window;

    //Create some methods
    void init();
    void createGLContext();

    //Adding const makes this a read only method
    void errorExit(const std::string &_msg) const;



};

#endif
