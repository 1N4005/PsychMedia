#include "PsychMedia.h"

Color::Color(int _r, int _g, int _b, int _a) {
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

Window::Window(const char* title, Color color, int width, int height) {
    r = color.r;
    g = color.g;
    b = color.b;
    a = color.a;

    fullscreen = false;

    _width = width;
    _height = height;
    _title = title;
    _running = true;
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Failed at SDL_Init()" << std::endl;
    }

    if(SDL_CreateWindowAndRenderer(_width, _height, 0, &_window, &_renderer)) {
        std::cout << "Failed at SDL_CreateWindowAndRenderer" << std::endl;
    }

    SDL_SetWindowTitle(_window, title);
    SDL_ShowCursor(1);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
}

void Window::Loop() {
    _update();
    _input();
    _draw_bg();
}

bool Window::GetRunning() {
    return _running;
}

void Window::Stop() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Window::_update() {
    if(fullscreen) {
        SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    } else {
        SDL_SetWindowFullscreen(_window, 0);
    }
}

void Window::_input() {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) {
            _running = false;
        }
    }
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if(keystates[SDL_SCANCODE_ESCAPE]) {
        _running = false;
    }
    if(keystates[SDL_SCANCODE_F]) {
        fullscreen = !fullscreen;
    }
}

void Window::_draw_bg() {
    SDL_SetRenderDrawColor(_renderer, r, g, b, a);
    SDL_Rect rect;
    rect.x = rect.y = 0;
    rect.w = _width;
    rect.h = _height;
    SDL_RenderFillRect(_renderer, &rect);
}

void Window::Draw() {
    SDL_RenderPresent(_renderer);
}

void Window::Rectangle(int start_x, int start_y, int end_x, int end_y, Color color) {
    SDL_Rect rect;
    rect.x = start_x;
    rect.y = start_y;
    rect.w = end_x - start_x;
    rect.h = end_y - start_y;
    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(_renderer, &rect);
}
