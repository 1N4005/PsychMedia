#include "PsychMedia.h"

int main() {
    Color c(0, 255, 0, 255);
    Color c2(0, 0, 255, 255);
    Window myWindow("name", c, 1280, 720);
    while (myWindow.GetRunning()) {
        myWindow.Loop();
        myWindow.Rectangle(100, 100, 200, 200, c2);
        myWindow.Draw();
    }
    myWindow.Stop();
}
