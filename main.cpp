#include "App.h"
#include<ctime>

int main()
{
    srand(time(NULL));
    App app;
    app.run();
    return 0;
}