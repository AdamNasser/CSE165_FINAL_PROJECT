#include "App.h"

int main(int argc, char** argv) {
    //1000,500
    GlutApp* app = new App(argc, argv, 1000, 500, "Running Cat");
    app->run();
}
