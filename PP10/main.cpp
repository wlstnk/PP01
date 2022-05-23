#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib,"OpenGL32")

#include "GameLoop.hpp"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    Engine::GameLoop gameLoop;
    gameLoop.Run();
}