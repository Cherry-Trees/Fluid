#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "functions.hpp"
#include "Cell.hpp"
#include <math.h>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(W, H), "Fluid");

    Cell** U = new Cell*[ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        U[i] = new Cell[COLS];
        for (int j = 0; j < COLS; j++)
        {
            U[i][j].sprite = RectangleShape({PIXEL_DELTA, PIXEL_DELTA});
            U[i][j].sprite.setPosition(Vector2f(j * PIXEL_DELTA, i * PIXEL_DELTA));
            U[i][j].q = 0;
            U[i][j].update(window);
        }
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                    for (int i=0; i<ROWS; i++) {delete[] U[i];}
                    delete[] U;
                    window.close();
            }

            if(Keyboard::isKeyPressed(Keyboard::R)) {
                for (int i=0; i<ROWS; i++) {
                    for (int j=0; j<COLS; j++) {U[i][j].q = 0;}
                }
            }

            if (event.type == Event::MouseMoved) {
                
                if (Mouse::isButtonPressed(Mouse::Left)) {

                    Vector2i cell_indices = Mouse::getPosition(window) / PIXEL_DELTA;
                    for (int i=cell_indices.y-2; i < cell_indices.y+2; i++)
                    {
                        for (int j=cell_indices.x-2; j < cell_indices.x+2; j++)
                        {
                            U[i][j].q += 200;
                        }
                    }
                }
                if (Mouse::isButtonPressed(Mouse::Right)) {

                    Vector2i cell_indices = Mouse::getPosition(window) / PIXEL_DELTA;
                    for (int i=cell_indices.y-2; i < cell_indices.y+2; i++)
                    {
                        for (int j=cell_indices.x-2; j < cell_indices.x+2; j++)
                        {
                            U[i][j].q -= 200;
                        }
                    }  
                }
            }
        }
        window.clear();


        for (int y = 1; y < ROWS-1; ++y)
        {
            for (int x = 1; x < COLS-1; ++x)
            {
                U[y][x].q += divergence(U, x, y);
                U[y][x].update(window);
            }
        }
        
        
        window.display();
    }

    return 0;
}


// TO RUN:

// g++ -I"C:\SFML-2.6.1\include" -c main.cpp -o main.o
// g++ main.o -o app.exe -L"C:\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -mwindows

// OR

// MinGW32-make compile
// MinGW32-make link

// OR

// MinGW32-make all
