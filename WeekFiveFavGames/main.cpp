//Annastachia Brown Spring 2024
//Week Five Homework

#include <iostream>
using namespace std;
#include <string>
#include <vector>

int main() {
  cout<< "Howdy partner! We are going to make a list of your favorite games!\n";
 
  vector<string> favGame;        //creates the vector
  string gameInput = "";         // creates string for player input
  string input = "0";            // creates string for player option

  while (true) {
        cout << "\n";                 // a line to seperate the text block
        cout << "what would you like to do?\n";
        cout << "Press 1 to add to the list.\n";
        cout << "Press 2 to see the list.\n";
        cout << "Press 3 to quit.\n";

        getline(cin, input);         // gets imput from the player
        cout << "\n";                // a space to make the formating look better
      
        if (input == "1") {
            cout << "Let's add some games!";
            cout << "What game would you like to add?\n";
            getline(cin, input);        //getss input from player
            favGame.push_back(input);   // 
        } // end of if

        else if (input == "2") {
            cout << "Here is your list: \n";
            for (int i = 0; i < favGame.size(); i++) {
              cout << favGame[i] << "\n";
            } // end of for loop
        }   // end of else if

        else if (input == "3") {
            cout << "thanks for playing partner!\n";
            break;
        } // end of else if
        else {
            cout << "That was not an option. try again";
        }// end of else
    }   // end of while

} // end of int main