
#include<bits/stdc++.h>
using namespace std;

int main() {
    int attempts = 7;      //số lượt đoán tối đa
    int answer = 42;       // số đúng
    int guess;             //số đoán

    cout << "Welcome to the game!" << endl;

    while (attempts > 0) {
        cout << "Enter your guess (1-100): ";
        cin >> guess;

        if (guess == answer) {
            cout << "Congratulations! You guessed it right." << endl;
            break;
        } else if (guess < answer) {
            cout << "Too low!" << endl;
        } else {
            cout << "Too high!" << endl;
        }

        attempts--;
    }

    if (attempts == 0) {
        cout << "Game over! The correct answer was: " << answer << endl;
    }

    return 0;
}

