#include<bits/stdc++.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
using namespace std;

int main() {


    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)" ");
    
    // Necessary initializations of variables
    int snakeX[200], snakeY[200]; // snake coordinates{body}
    int key_dir; // direction of the snake's movement
    int foodX, foodY; // food coordinates
    int obstacleX, obstacleY; // obstacle coordinates
    int delayTime = 150; // delay time for the game loop
    int score = 0; // player's score
    int p_dir = 1; // previous direction(1: right, 2: left, 3: up, 4: down)
    int length = 10; // initial length of the snake
    bool game = true; // game state (true: running, false: over)

    // Initialize snake's initial position
    snakeX[0] = 320;
    snakeY[0] = 240;
    key_dir = (rand() % 4) + 1; // random initial direction (1-4)
    foodX = rand() % 640;
    foodY = rand() % 480;

    // main game loop
    while (game)
    {
        
        //Background or Board
        setfillstyle(SOLID_FILL, BLACK);// Set the fill style to solid black
        bar(0, 0, 640, 480); // Draw the background

        // Borders
        setfillstyle(SOLID_FILL, RED); //Set the border color to blue
        bar(0, 0, 640, 10); // Top border
        bar(0, 470, 640, 480); // Bottom border
        bar(0, 0, 10, 480); // Left border
        bar(630, 0, 640, 480); // Right border

        // Snake Drawing
        for(int i = 0; i < length; i++)
        {
            if(i == 0){
                setcolor(YELLOW);
                setfillstyle(SOLID_FILL, YELLOW); // Set the head color to yellow
                bar(snakeX[i], snakeY[i], snakeX[i] + 10, snakeY[i] + 10); // Draw the head
            }else{
                //Body
                setcolor(WHITE);
                setfillstyle(SOLID_FILL, WHITE); // Set the body color to white
                bar(snakeX[i], snakeY[i], snakeX[i] + 10, snakeY[i] + 10); // Draw the body

                // Add small body style
                setfillstyle(SOLID_FILL, WHITE);
                bar(snakeX[i]+3, snakeY[i]+3, snakeX[i] + 7, snakeY[i] + 7);
            }
        }



        // Movement input
        // Read keys. 
        // Note: We use 'p_dir' (previous direction) to prevent 180-degree turns.
        // You cannot go Left (2) if currently going Right (1), etc.

        if((GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) && p_dir != 2) 
            key_dir = 1;
        else if((GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) && p_dir != 1) 
            key_dir = 2;
        else if((GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) && p_dir != 4) 
            key_dir = 3;
        else if((GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) && p_dir != 3) 
            key_dir = 4;



            // Update Body Movement according to the direction
            {
                for(int i = length - 1; i > 0; i--)
                {
                    snakeX[i] = snakeX[i - 1];
                    snakeY[i] = snakeY[i - 1];
                }

                // move head
                switch(key_dir)
                {
                    case 1: snakeX[0] += 10; break; // right
                    case 2: snakeX[0] -= 10; break; // left
                    case 3: snakeY[0] -= 10; break; // up
                    case 4: snakeY[0] += 10; break; // down
                }

                
            }



    }
    






    
    getch();
    closegraph();


    return 0;
}