﻿<div align="center"> 
    <h1> Game </h1>
    <img alt=License src="https://img.shields.io/badge/license-MIT-blue"></img>
</div>
🎮 Game Project made in C++ 💻

### How to run
- In the command prompt or the terminal, run ```git clone https://github.com/PlayerGameProject/Game.git --recursive```.
- Run the ```Build-Windows.bat``` or ```Build-Unix.sh``` file depends on your operating system.
- Open the project folder in the IDE of your choice and run the project or create a new basic main ```Game.cpp``` file and run:
```c++
#include "App.h"

int main()
{
    App Game(640, 480, "Game", nullptr, true);
    Game.Run();
    
    return EXIT_SUCCESS;
}
```

### License
This project is under the MIT license.
For more information, please read the ```License.txt``` file.
