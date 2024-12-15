#include <iostream>
#include <cmath>  
#include <conio.h> 
#include <windows.h> 


class Movement {
public:
    virtual void move(double& x, double& y, double amplitude, double frequency, double& t) = 0; 
};


class HorizontalMovement : public Movement {
public:
    void move(double& x, double& y, double amplitude, double frequency, double& t) override {
        x += 0.1; 
        y = amplitude * std::sin(frequency * t); 
        t += 0.1;
    }
};


class VerticalMovement : public Movement {
public:
    void move(double& x, double& y, double amplitude, double frequency, double& t) override {
        y += 0.1; 
        x = amplitude * std::sin(frequency * t); 
        t += 0.1;
    }
};


void clearScreen() {
    COORD cursorPosition;    
    cursorPosition.X = 0;    
    cursorPosition.Y = 0;    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

int main() {
    double x = 0, y = 0; 
    double amplitude = 5; 
    double frequency = 0.5; 
    double t = 0;         
    Movement* movement = new HorizontalMovement(); 

    while (true) {
        clearScreen();

 
        for (int i = 0; i < (int)y; ++i) std::cout << "\n"; 
        for (int i = 0; i < (int)x; ++i) std::cout << " ";  
        std::cout << "O\n";  

        if (_kbhit()) { 
            char ch = _getch();
            if (ch == 27) break;  
            else if (ch == 'h') { 
                delete movement;
                movement = new HorizontalMovement();
            }
            else if (ch == 'v') { 
                delete movement;
                movement = new VerticalMovement();
            }
        }

        movement->move(x, y, amplitude, frequency, t);  
        Sleep(50);  
    }

    delete movement;  
    return 0;
}