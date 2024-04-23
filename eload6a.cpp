#include <iostream>
#include <chrono>
#include <thread>
#include <random>

using namespace std;

int WINDOW_HEIGHT;
int WINDOW_WIDTH;
int ballPosX;
int ballPosY;
int ballSpeedX;
int ballSpeedY;

void clearScreen() {
    cout << "\033[?25l";
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void drawBall(int x, int y) {
    clearScreen();
    for (int i = 0; i < WINDOW_HEIGHT; ++i) {
        for (int j = 0; j < WINDOW_WIDTH; ++j) {
            if (i == 0 || i == WINDOW_HEIGHT - 1) {
                cout << "-";
            } else if (j == 0 || j == WINDOW_WIDTH - 1) {
                cout << "|";
            } else if (i == y && j == x) {
                cout << "o";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    cout << "Adja meg a sebesseget: ";
    cin >> ballSpeedX;
    cout << "Adja meg a magassagot: ";
    cin >> WINDOW_HEIGHT;
    cout << "Adja meg a szelesseget: ";
    cin >> WINDOW_WIDTH;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> disX(1, WINDOW_WIDTH - 2);
    uniform_int_distribution<int> disY(1, WINDOW_HEIGHT - 2);

    ballPosX = disX(gen);
    ballPosY = disY(gen);
    ballSpeedY = ballSpeedX;

    while (true) {
        ballPosX += ballSpeedX;
        ballPosY += ballSpeedY;

        if (ballPosX <= 1 || ballPosX >= WINDOW_WIDTH - 2) {
            ballSpeedX = -ballSpeedX;
        }
        if (ballPosY <= 1 || ballPosY >= WINDOW_HEIGHT - 2) {
            ballSpeedY = -ballSpeedY;
        }

        drawBall(ballPosX, ballPosY);
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}
