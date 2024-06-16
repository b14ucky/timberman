#include "App.h"
#include<ctime>

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    App app;
    app.run();
    return 0;
}