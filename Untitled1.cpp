#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

const int MAX_X = 20;
const int MAX_Y = 20;
const int SNAKE_LENGTH = 5;

struct Snake {
    int x[100];
    int y[100];
    int length;
    int direction;
};

void initSnake(Snake &snake) {
    snake.length = SNAKE_LENGTH;
    snake.direction = 1; // start moving to the right
    for (int i = 0; i < snake.length; i++) {
        snake.x[i] = i + 10;
        snake.y[i] = 10;
    }
}

void moveSnake(Snake &snake) {
    for (int i = snake.length - 1; i > 0; i--) {
        snake.x[i] = snake.x[i - 1];
        snake.y[i] = snake.y[i - 1];
    }
    if (snake.direction == 1) {
        snake.x[0]++;
    } else if (snake.direction == 2) {
        snake.y[0]++;
    } else if (snake.direction == 3) {
        snake.x[0]--;
    } else {
        snake.y[0]--;
    }
}

int main() {
    initscr(); // initialize ncurses
    noecho(); // don't print user input
    curs_set(0); // don't display cursor
    srand(time(0)); // seed random number generator

    Snake snake;
    initSnake(snake);

    while (true) {
        clear(); // clear the screen

        for (int i = 0; i < snake.length; i++) {
            mvprintw(snake.y[i], snake.x[i], "o");
        }

        moveSnake(snake);
        refresh(); // refresh the screen
        usleep(100000); // wait for 0.1 seconds
    }

    endwin(); // end ncurses
    return 0;
}
