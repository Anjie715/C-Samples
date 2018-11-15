1. Execute SuperSnake.exe can directly open the game.
2. Find the include directory in your computer.Please create a new file named GLUT in the include directory.Put glut.h into that file.
3. Find the library directory in your computer.Put glut32.lib into that file.
4. Open the SuperSnake.sln.
5. Right click the project's name and open the properties.
6. Edit the include and library path to the directory where you store the glut.h and glut32.lib.
7. Add glut32.lib into additional dependency.
8. Build the project.