#include "Polycode.h"
#include "PolycodeView.h"
#include "HelloPolycodeApp.h"
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[]) {
    srand(time(0));
    PolycodeView *view = new PolycodeView("Hello Polycode!");
    HelloPolycodeApp *app = new HelloPolycodeApp(view);
    while(app->Update()) {}
    return 0;
}
