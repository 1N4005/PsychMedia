#ifndef PSYCH_MEDIA_H
#define PSYCH_MEDIA_H

#include <iostream>

#include <SDL.h>

struct Color {
    int r;
    int g;
    int b;
    int a;

    Color(int r, int g, int b, int a);
};

class Window {
    public:
        bool fullscreen;

        int r;
        int b;
        int g;
        int a;

        Window(const char* title, Color color, int width, int height);
        void Rectangle(int start_x, int start_y, int end_x, int end_y, Color color);
        void Loop();
        bool GetRunning();
        void Stop();
        void Draw();
    private:
        void _draw_bg();
        void _input();
        void _update();

        const char* _title;

        int _width;
        int _height;

        bool _running;

        SDL_Renderer* _renderer;
        SDL_Window* _window;
};

#endif
