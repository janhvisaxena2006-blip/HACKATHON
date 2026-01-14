
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class GreenRewardsWallet {
private:
    int greenPoints;
    int actionsCompleted;
    string userName;

public:
    // Constructor
    GreenRewardsWallet() {
        greenPoints = 0;
        actionsCompleted = 0;
        userName = "";
    }

    void welcome() {
        cout << "WELCOME TO GREEN REWARDS WALLET \n\n";
        cout << "Every small action counts towards a greener future! Let's track your eco-friendly journey together.\n\n";
        cout << "What should we call you?\n ";
        getline(cin, userName);
        cout << "Hello " << userName << "Let's start making a difference😊\n";
    }

    void showMenu() {
        cout << "  What eco-friendly action did you take today?\n\n";
        cout << "  1. Paid bills digitally             (+10 points)\n";
        cout << "  2. Used public transport            (+20 points)\n";
        cout << "  3. Avoided single-use plastic       (+15 points)\n";
        cout << "  4. Used solar energy                (+30 points)\n";
        cout << "  5. Went carpooling                  (+25 points)\n";
        cout << "  6. Cycled or walked instead         (+20 points)\n";
        cout << "  7. Switched off unused appliances   (+10 points)\n";
        cout << "  8. Used energy-efficient devices    (+25 points)\n";
        cout << "  9. Planted a tree                   (+50 points)\n";
        cout << "  10. Chose paperless banking         (+15 points)\n\n";
        cout << "  11. Check my green impact\n";
        cout << "  0. Exit for now\n\n";
    }

    void addPoints(int points, string action) {
        greenPoints += points;
        actionsCompleted++;

        cout << "✨Amazing work " << userName << "!✨\n";
        cout << "Action: " << action << "\n";
        cout << "Points earned: +" << points << "\n";
        cout << "Total Green Points: " << greenPoints << "\n";

        // Motivational messages based on points
        if (greenPoints >= 200) {
            cout << "You're an eco-warrior! Keep it up!\n";
        } else if (greenPoints >= 100) {
            cout << "You're doing great! Mother Earth thanks you!\n";
        } else if (greenPoints >= 50) {
            cout << "Wonderful progress! Every action matters!\n";
        } else {
            cout << "Great start! Keep making green choices!\n";
        }
    }

    void displayBalance() {
        cout << "YOUR GREEN IMPACT SUMMARY-:\n";
        cout << "Name: " << userName << "\n";
        cout << "Total Green Points: " << greenPoints << "\n";
        cout << "Eco-Actions Completed: " << actionsCompleted << "\n\n";

        // Show impact level
        if (greenPoints == 0) {
           cout << "  Level:  Just Getting Started\n  Your journey begins now!\n";
        } else if (greenPoints < 50) {
            cout << "  Level:  Eco-Beginner\n You're on the right path!\n";
        } else if (greenPoints < 150) {
            cout << "  Level:  Green Enthusiast\n Your efforts are making a difference!\n";
        } else if (greenPoints < 300) {
            cout << "  Level:  Environmental Champion\n You're an inspiration to others!\n";
        } else {
            cout << "  Level:  Planet Protector\n You're truly changing the world!\n";
        }
    }

    void processChoice(int choice) {
        switch (choice) {
            case 1:
                addPoints(10, "Paid bills digitally ");
                break;
            case 2:
                addPoints(20, "Used public transport ");
                break;
            case 3:
                addPoints(15, "Avoided single-use plastic ");
                break;
            case 4:
                addPoints(30, "Used solar energy ");
                break;
            case 5:
                addPoints(25, "Went carpooling ");
                break;
            case 6:
                addPoints(20, "Cycled or walked ");
                break;
            case 7:
                addPoints(10, "Switched off unused appliances ");
                break;
            case 8:
                addPoints(25, "Used energy-efficient devices ");
                break;
            case 9:
                addPoints(50, "Planted a tree ");
                break;
            case 10:
                addPoints(15, "Chose paperless banking ");
                break;
            case 11:
                displayBalance();
                break;
            case 0:
                cout << "THANK YOU, " << userName << "!\n";
                cout << "  Your contribution: " << actionsCompleted << " eco-actions completed\n";
                cout << "  Final Green Points: " << greenPoints << " \n\n";
                cout << "  Remember: Every action, no matter how small, helps create a sustainable future. \n";
                cout << "  See you next time! Keep being amazing!\n\n";
                break;
            default:
                cout << "Oops! That's not a valid option.\n";
                cout << "Please choose a number between 0 and 11.\n";
        }
    }
};

int main() {
    GreenRewardsWallet user;
    int choice;

    user.welcome();

    do {
        user.showMenu();
        cout << "Your choice: ";
        cin >> choice;

        // Clear input buffer
        cin.ignore(1000, '\n');

        user.processChoice(choice);

        if (choice != 0) {
            cout << "Press Enter to continue";
            cin.get();
        }

    } while (choice != 0);

    return 0;
}
