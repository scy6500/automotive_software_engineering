#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateSecretNumber() {
    string secret = "";
    while (secret.length() < 4) {
        char digit = '0' + rand() % 10;
        if (secret.find(digit) == string::npos) {
            secret += digit;
        }
    }
    return secret;
}

pair<int, int> getBullsAndCows(const string& secret, const string& guess) {
    int bulls = 0, cows = 0;
    for (int i = 0; i < 4; ++i) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else if (secret.find(guess[i]) != string::npos) {
            cows++;
        }
    }
    return make_pair(bulls, cows);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    string secret = generateSecretNumber();
    string guess;
    int attempts = 0;

    cout << "Welcome to Bulls and Cows game!" << endl;
    cout << "I have generated a 4-digit secret number. Try to guess it!" << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess.length() != 4) {
            cout << "Please enter a 4-digit number." << endl;
            continue;
        }

        attempts++;
        pair<int, int> result = getBullsAndCows(secret, guess);

        if (result.first == 4) {
            cout << "Congratulations! You've guessed the secret number " << secret << " in " << attempts << " attempts." << endl;
            break;
        } else {
            cout << "Bulls: " << result.first << ", Cows: " << result.second << endl;
        }
    }

    return 0;
}
