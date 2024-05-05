/*
Annastachia Brown's coding Homework
Spring 2024 
what I plan on doing WOW!! pseudoCode
A do while loop 
damage taken from an orc
dice roll
blocking to decide damage
(adding this for fun) dice roll for an attack against orc
if block is successful find random amount of gold 1-10
if block is unsuccessful find no gold
if orcHealth reaches zero the game is over because the orc is dead L
gives 20 gold
a doctor that costs three coins 
player needs <=5 health && >=3 coins 
*/

#include <cstdlib> // for rand
#include <ctime>   // for rand
#include <iostream>
#include <string> //for string use
#include <vector> //For vector use
using namespace std;

//The functions

string AskYN(string question){            // gets a yes or no returns their answer 
    do{
        cout << question << " (y/n)\n";
        char input;
        cin >> input;

        if (input == 'y'){
            return "y";
        }       
        if (input == 'n'){
            return "n";
        }else 

        cout << "You need to tyoe a lowercase 'y' or 'n'\n";
    }while(true);    //end of do while
}//End of AskYN



void BigGap(){        //For the formatings just a new line
    cout << "\n";
}//end of BigGap

string Comparison(int orcRoll, int playerRoll){
    if (orcRoll >= playerRoll){
        return "Your block was unsuccessful!!!";
    }else
        return "Your block was successful!! you only lost one HP";
}//end of Comparison

int DiceRoll(int sides = 6) {

    //called clamping - setting it at a min and a max can not get out 
    if(sides < 1 ){
        sides = 2;
    }
    if (sides > 100 ){
        sides = 100;
    }
    return rand() % sides +1;
}//end of DiceRoll

int GoldRandNum(int goldAmount){
    goldAmount = rand() % 10 + 1;
    goldAmount += 1;
    return goldAmount;
}//end of GoldRandNum

//The main code
int main() {
    srand(time(0));
    cout << "Howdy partner! let's play a game!\n";
   
    //initiaizing
    int playerHealth = 20;  //for the player health      
    int orcHealth = 20;    //for the orc health
    int goldAmount = 0;    //for collected the gold
    int playerRoll = 0;    //the number that the player will roll
    int orcRoll = 0;    //the number that the orc will roll  
    int counter = 0;    //counting the amount of loops 
    string input = "y";
    
    
    do {
        counter += 1; //adds one to the counter 
        
        cout << "You have " << playerHealth << " HP left\n";    //lets player know health
        cout << "you encounter an orc who looks like he is about to attack! Get ready to BLOCK!\n";
       
        BigGap();//formating
        
       //roll the dice to compare 
        playerRoll = DiceRoll();
        orcRoll = DiceRoll();
        
        //let player know the rolls 
        cout << "You rolled a " << playerRoll << "!\n";
        cout << "the orc rolled a " << orcRoll << "!\n";
        
        string successRate = Comparison(orcRoll, playerRoll); //sees if it was successful
        if (successRate == "Your block was successful!! you only lost one HP"){
            playerHealth -= 1;        // minus one from total health
            cout << successRate << "\n";
            goldAmount += GoldRandNum(goldAmount);
            cout << "you found " << goldAmount << "coins! Good job\n";
        }//end of if
        else if(successRate == "Your block was unsuccessful!!!"){
            playerHealth -= orcRoll;        // minus the number the orc rolled from total health
            cout << successRate;
           
        }//end of else if
        
        if ( playerHealth <= 0){        //ends the game if health is at 0
            cout << "Your health has reached 0 :( Thanks for Playing!";
            break;//end of if
        }
            
        cout << "you now have " << playerHealth << " HP!\n";  //lets player know their health level

        BigGap();

        if(playerHealth <=5 && goldAmount >=3){ // going to the doctor
            cout << "your health is getting low. Lets step to the doctor\n";
            playerHealth +=5;//adds health
            goldAmount -= 3;//takes gold away
            
            cout << "You now have " << playerHealth << " HP and " << goldAmount << "coins left\n";
        }//end of if
        else if (playerHealth <= 5){//cannot go pay for doctor but health is low
            cout << "your health is low but you can not pay for health care\n";
        }

        cout << "It is your turn to attack! lets roll to see if your successful\n"; //player can retaliate
        playerRoll = DiceRoll();
        orcRoll = DiceRoll();

        //lets player know what was rolled
        cout << "You rolled a " << playerRoll << "!\n";
        cout << "the orc rolled a " << orcRoll << "!\n";

        successRate = Comparison(orcRoll, playerRoll); //sees if it was successful (will be backwards)
        if (successRate == "Your block was successful!! you only lost one HP"){    //orc block fail
            cout << "the orc failed to block they loose" << playerRoll << " hp\n";
            orcHealth -= playerRoll;
            cout << "the orc has " << orcHealth << " hp left\n"; 
        }//end of if
            
        else if(successRate == "Your block was unsuccessful!!!"){     //orc block success

               cout << "the orcs block was successful and they lose one HP\n";
                orcHealth -= 1;
                cout << "the orc has " << orcHealth << " hp left\n";     
        }//end of else if

        if(orcHealth <= 0){ //orc died and game is over player gets a reward
            cout << "you have won the orc is gone! you gain 20 coins\n";
            goldAmount += 20;
            break;
        }

        BigGap();//formating 
        
        input = AskYN("Would you like to play a game\n");        // to continue or not
    }while(input == "y");//end of do while 

    BigGap();//formating 
    
    cout << "You played for " << counter << " rounds! and ended with " << goldAmount << " coins! Lets play again someday okay?";//lets the player know their end statistics 
}//end of int main



