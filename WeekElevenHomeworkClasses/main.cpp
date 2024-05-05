/*Annastachia Brown - coding one  week eleven homewor
HOMEWORK create BASIC adventure functionality using the enemy class for each encounter. 
each enemy must use a weapon. each enemy has health. 
player has option of using weapon or consumable 
at least one encounter, to the death. 
i am grading based on the enemy class, does it have the functionality that it needs to interact with the player */

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

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

enum itemType{
    // equal to 0,1,2
    weapon, tool, consumable
};

enum elementalType{
    basic = 0, fire = 1, ice = 2, candy = 3, slime = 4
};

class item{
public:
    itemType type = weapon;
    int damage = 10; 
    string name = "";
    elementalType element = basic;
    int remainingUses = 0;
    int healingAmount = 0;

    // //defualt constructor
    // item(){
    //     cout<< "creaating an item\n";
    // }

    item (string n = "stick", itemType t = weapon){
         name = n; // assign the name of the item to the given name
        type = t;

        if(type == weapon){
        //calculate damage and element
            damage = rand() % 5 + 3; 
            element = (elementalType)(rand() % 4);        //typecast  an int into an elementType
            remainingUses = 999;
            healingAmount = 0;
        }//end of if
        else if(type == tool){
            damage = 1;
            element = basic;
            remainingUses = rand() % 5+1;
            healingAmount = 0;

        }// end of else if
        else if(type == consumable) {
            healingAmount = rand() %5 + 1;
            damage = -healingAmount;
            element = basic;
            remainingUses = -1; 
        }//end of else if

    }//end of item constructor

void Inspect(){
    cout << name << " has damage of " << damage << " it's element is  " <<  ElementToString(element) << ".\n";
    cout << "it can be used " << remainingUses << " more times, heals for " << healingAmount << "\n";
    cout << "and is of the item type " << TypeToString(type) << ".\n\n";
}

string TypeToString(itemType type){
    //this is a switch statement. It is like an if staement
    //but it only has  to test once! all possible values are mapped
    switch(type){
        case weapon:
                 return "weapon"; 
                 break;
        case tool: 
                return "tool";
                 break;
        case consumable:
                return "consumable";
                break;
        default:
             return "unknown";
            break;
    } //end of switch statement
}// end of TypetoString 

string ElementToString(elementalType element){
        switch(element){
            case basic:
                return "basic";
                break;
            case fire:
                return "fire";
                break;
            case ice:
                return "ice";
                break;
            case candy: 
                    return "candy";
                    break;
            case slime:
                return "slime";
                break;
            default:
                return "unknown";
        }//end of switch
    }//end  of ElementToString

};//end of class item

class enemy{
public:
    int health = 10;
    item heldItem;

//enemy constructur
    enemy(){
        cout << "New enemy!\n";

    }

    int attack(){
        int damage = rand() % 5 +3;
        return damage;
    }
};


int main() {
    srand(time(0)); //seed the random numbers 
   string input = AskYN("Would you like to play a game?");
   
    do{
        // a vector of weapon names 
        vector<string> weaponNames = {"sword", "axe", "mace", "hammer", "spear", "battleaxe", "claymore", 
                                        "greatsword", "katana", "saber"};
        random_shuffle(weaponNames.begin(), weaponNames.end());

        item sting("sting", weapon);
        sting.Inspect();

        vector<item> weapons;

        enemy bob;
        // bob.heldItem = weapon[10];
        enemy player;
        player.heldItem = item("health potion", consumable);
        cout << "enemy attacks!\n";
        player.health -=bob.attack();
        cout << "your health is now " << player.health << ".\n";
        bob.health -= player.attack();
        cout << "you attack now!\n";
        cout << "the enemies health is now at " << bob.health << ".\n";
        input = AskYN("Would you like to continue?");
    }while(input == "y");
  
}