#include <iostream>
using namespace std;

#include "../header/character.h"
#include "../header/skeleton.h"
#include "../header/thief.h"
#include "../header/goblin.h"
#include "../header/fight.h" // terrible for debugging purposes

// TODO: hard code damage? or randomize
/* 
    note: make sure to add new .cpp files to ~/src/CMakeLists.txt under add_library
    note: run tests with 
     cmake . && make && ./bin/runAllTests
    note: run build with 
     cmake . && make && ./bin/runBuild
    note: if want to see results but you're too lazy to write tests, use lazy main
     cmake . && make && ./bin/runLazyTests
    
*/


int main() {
    /*since the player can choose when to quit, will we implement some sort of loop?
    or will we implement some sorta function that we pass in the input in for every action */ 

    cout << endl << endl << "Welcome adventurer, to His majeasty's DragonSlayer's Quest" << endl;
    cout << "His majeasty's sacred treasure has been stolen by the mythical dragon king from the northern mountains" << endl;
    cout << "He beeseaches you to venture into his deen to kill the dragon king and reclaim his sacred treasure that has been lost" << endl;
    cout << "The King will reward you handsomely should you complete this quest!" << endl;
    cout << "Now adventurer, state your name and let your name be inscribbed to the records" << endl << endl;

    // Player's name input
    string playername, playerclass, userchoice;

    cout << "Enter your name: ";
    cin >> playername;
    if(playername == "q" || playername == "Q"){
        cout << "Farewell unknown Adventurer." << endl;
        return 0; // Exit the game
    }
    
    cout << endl << "Very well Adventurer " << playername << ", The guild under the king's authority has presented you with 3 classes" << endl;
    cout << "Please review each class and pick one of the 3 classes" << endl << endl;

    cout << "------------------------------------------" << endl;
    cout << "1.WARRIOR - High base HP" << endl << "Physical attack - sword swing" << endl << "Special attack - Flame Strike (fire elemental damage skill: does small damage per turn for x turns)" << endl;
    cout << "2.ARCHER - Normal base HP" << endl << "Physical attack - shoot arrow" << endl << "Special attack - Wind Arrow (wind elemental damage skill: damage multiplier towards base attack)" << endl;
    cout << "3.THIEF - Low base HP" << endl << "Physical attack - stab" << endl << "Special attack - Mirage Step (water elemental evasive skill: dodge skill for 1-2 turns)" << endl;
    cout << "------------------------------------------" << endl;
    cout << "What is your class?" << endl << "(Choose from Warrior, Archer, or Thief)" << endl << endl;

    cin >> playerclass;
    if (playerclass == "q" || playerclass == "Q") {//repeat this chunck for player's options
        cout << "Farewell Adventurer" << endl;
        return 0; // Exit the game 
    }
    bool failcheck = true;
    while(failcheck == true){
        if(playerclass == "Warrior" || playerclass == "warrior" || playerclass == "w" || playerclass == "W"){
            playerclass = "Warrior";
            Weapon playerweapon("Sword", 5, WARRIOR);
            Character player(playername, "Human", 200, playerweapon);
            cout << endl << endl;
            cout << "Welcome, " << player.get_race() << " " << playerclass << " " << player.get_name() << " your name has been recorded" << endl;
            cout << "As a " << playerclass << ", Your base HP is " << player.get_health() << endl;
            cout << "The king's guild then presents you a " << playerweapon.name << ", it has " << playerweapon.damage << " attack value." << endl << endl;
            failcheck = false;//not sure if i should use break instead
            //maybe replace playerclass with player.get_class_type() later?
        }
        else if(playerclass == "Archer" || playerclass == "archer" || playerclass == "a" || playerclass == "A"){
            playerclass = "Archer";
            Weapon playerweapon("Bow", 5, ARCHER);
            Character player(playername, "Human", 100, playerweapon);
            cout << endl << endl;
            cout << "Welcome, " << player.get_race() << " " << playerclass << " " << player.get_name() << " your name has been recorded" << endl;
            cout << "As a " << playerclass << ", Your base HP is " << player.get_health() << endl;
            cout << "The king's guild then presents you a " << playerweapon.name << ", it has " << playerweapon.damage << " attack value." << endl << endl;
            failcheck = false;

        }
        else if(playerclass == "Thief" || playerclass == "thief" || playerclass == "t" || playerclass == "T"){
            playerclass = "Thief";
            Weapon playerweapon("Dagger", 5, THIEF);
            Character player(playername, "Human", 75, playerweapon);
            cout << endl << endl;
            cout << "Welcome, " << player.get_race() << " " << playerclass << " " << player.get_name() << " your name has been recorded" << endl;
            cout << "As a " << playerclass << ", Your base HP is " << player.get_health() << endl;
            cout << "The king's guild then presents you a " << playerweapon.name << ", it has " << playerweapon.damage << " attack value." << endl << endl;
            failcheck = false;
        }
        else{
            cout << "Wrong class!"<< endl << "Choose your class" << endl;
            cin >> playerclass;
        }
    }
    cout << "You set off on your adventure..." << endl;
    cout << "You exit the castle walls and enter the plains, it is known that goblins and skeletons freqently roam this area" << endl;
    cout << "Press onwards or turn back now?" << endl << "> press anykey to press on" << endl << "> n/N or q/Q for retreat" << endl << endl;
    cin >> userchoice;
    if (userchoice == "n" || userchoice == "N" || userchoice == "q" || userchoice == "Q") {
        cout << "Farewell Adventurer." << endl;//placeholder for now
        return 0; // Exit the game
    }
    userchoice = "";//destructor for later push fowards or retreat
    cout << endl << "Knowing the dangers, you press on..." << endl;//placeholder
    cout << "Stepping into the field, you part the tall grass and plants to continue forth" << endl;
    cout << "You encounter a clearing where you encounter a goblin" << endl;
    /*
    first battle goes here
    */
    cout << "After a grueling battle, you emerge victorious" << endl;
    cout << "As you Catch your breath, you notice a fork in the road ahead..." << endl;
    cout << "Do you wish to continue through the fields or brave through the step cliffs towards the mountains?" << endl;
    cout << "> M for the mountain cliffs" << endl << "> F for fields" << endl << "> Q to retreat" << endl << endl;
    cin >> userchoice;
    if(userchoice == "f" || userchoice == "F"){
        userchoice == "";
        cout << endl << "You decide to further venture into the fields" << endl;
        cout << "As you walk along the beaten path, the fields turn into a dark forest" << endl;
        cout << "The Next thing you know, night has befallen on you and you are feeling tired" << endl;
        cout << "you decide on whether to make camp for the night or push on in the dark" << endl;
        cout << "> press any key except W or Q to make camp and rest the night" << endl;
        cout << "> press W to continue your journey at night" << endl;
        cout << "> press Q to quit" << endl << endl;
        cin >> userchoice;
        if(userchoice == "W" || userchoice == "w"){
            userchoice = "";
            cout << "You decide to trek on in the middle of the night..." << endl;
            cout << "As you do, the forest is pitch black and you are unable to see anyfurther than whats directly infront of you" << endl;
            cout << "Suddenly you get amushed by a skeleton from the back, and the next thing you know you are dead" << endl;
            cout << "GAME OVER" << endl;
            return 0;
        }
        else if(userchoice == "Q" || userchoice == "q"){
            userchoice = "";
            cout << "you have deserted the quest..." << endl << "A bounty has been place on your head!" << endl;
            return 0;
        }
        userchoice = "";
        cout << "You decide to rest the night..." << endl;
        cout << "You wake up the next morning feeling alert" << endl;
        cout << "feeling energetic you sense danger behind you as a skeleton approaches you from behind" << endl;
        cout << "> fight? (F)" << endl << "> flee(R)" << endl << endl;
        cin >> userchoice;
        if(userchoice == "F" || userchoice == "f"){
            userchoice = "";
            cout << " " << endl;//continue story
        }
        else if(userchoice == "R" || userchoice == "r"){
            cout << endl << "Sparked by your fears of skeletons, you decide to flee" << endl;
            cout << "As you run through the thick forest, you fall into a boobytrap laid out by the hunters of a different party and become unable to move" << endl;
            cout << "You turn around and you see that same skeleton that approached you earlier is not looming over you, sword in hand as it kills you off" << endl;
            cout << "due to some magic imbedded in the sword, you now become a undead, cursed to wander the lands..." << endl;
            cout << "GAME OVER" << endl;
            userchoice = "";
            return 0;//game over
        }
        else{
            userchoice = "";
            cout << "Wrong input!" << endl;
            cout << "you have hesitated and was stabbed to death by skeleton" << endl;
            cout << "due to some magic imbedded in the sword, you now become a undead, cursed to wander the lands..." << endl;
            cout << "GAME OVER" << endl;
            return 0;
        }
        /*
        skeleton fight goes here
        */
        cout << "Traveling further deeper into the dark forest, You are exhausted after that battle" << endl;
        cout << "You turn the corner around the path and you spot a cave" << endl;
        cout << "caves are nice places to rest but they can also be hosts to dangerous animals too" << endl;
        cout << "knowing this, you decide to go into the cave to rest anyways" << endl;
        cout << "the inside of the cave looks like someone or something has been there, and theres a chest at the back wall" << endl;
        cout << "thinking that the chest isnt going to run off anywhere, you decide to rest first before you open the chest" << endl;
        cout << "While resting, you encounter a pack of wolves on their return trip from their hunt, and they look angry that" << endl;
        cout << "You have decided to make their home a resting spot" << endl;
        cout << "With your back against the cave wall, You have no choice but to engage in a fight head on" << endl;
        /*
        wolf fight goes here
        */
        cout << "After a grueling battle, you emerge victorious as you finally get your rest" << endl;
        cout << "An hour later, you finally muster the strength to pull yourself together and decide on whether to open the chest or not" << endl;
        cout << "Open chest?" << endl << "> Yes (Y)" << endl << "> No (N)" << endl << endl;
        cin >> userchoice;
        if(userchoice == "Y" || userchoice == "y"){
            userchoice = "";
            cout << "You open the chest, and find a map inside." << endl;
            cout << "It leads to directions to the dragon's lair!" << endl;
            cout << "Proceed with the map's directions?" << endl;
            cout << "> Yes (Y)" << endl << "> No (N)" << endl << endl;
            cin >> userchoice;
            if(userchoice == "Y" || userchoice == "y"){
                userchoice ="";
                cout << "You continue down the cave's path, carefully following the directions." << endl;
                cout << "A strange smell permeates the area, so you rush ahead. Soon, you encounter a door. Open ?" << endl;
                cout << "> Yes (Y)" << endl << "> No (N)" << endl << endl;
                cin >> userchoice;
                if(userchoice == "n" || userchoice == "N"){
                    userchoice = "";
                    cout << "Leaving the door unopened, you succumb to the toxic fumes." << endl;
                    cout << "GAME OVER" << endl;
                    return 0;
                }
                else if(userchoice == "Y" || userchoice == "y"){
                    userchoice = "";
                    cout << "you barge through the door and you are face to face with more monsters" << endl;
                    cout << "No where to go, you are quickly forced into battle" << endl;
                    /*
                    fight goes here
                    */
                    cout << "Emerging victorious, a huge door now looms infront of you" << endl;
                    cout << "unsure whats behind the door, you take a peek through the tiny cracks in the door" << endl;
                    cout << "you quickly realize this door leads to the dragon king's deen as you spot the dragon king laying ontop of a mountian of gold." << endl;
                    cout << "Are you ready?" << endl;
                    cout << "> Yes(Y)" << endl << "> No(N)" << endl << endl;
                    cin >> userchoice;
                    if(userchoice == "N" || userchoice == "n"){
                        cout << "Faced with a almighty dragon, fear takes over you and you flee" << endl;
                        cout << "The dragon sensing that someone was at the door that wasnt his guards mocks you a you run away" << endl;
                        cout << "'HAHAHAHA COWARD!'" << endl;
                        cout << "GAME OVER" << endl;
                    }
                    else if(userchoice == "Y" || userchoice == "y"){
                        cout << "you open the door, and suddenly a loud voice booms the room..." << endl;
                        cout << "'WHO DARES WAKE ME FROM MY SLUMBER'" << endl;
                        /*
                        Dragon fight goes here
                        */
                        cout << "You have emerged victorious! With the defeat of the dragon king and the reclamation of His Majesty's sacred treasure from the depths of the northern mountains, the quest is fulfilled." << endl;
                        cout << "You return to the castle to a hero's welcome" << endl;
                        cout << "VICTORY" << endl;
                        return 0;
                    }
                    else{
                        cout << "Unsure what to do after seeing the dragon king, you dont flee nor fight" << endl;
                        cout << "However, with the dead dragon kings guard laying there, other guards have become alerted to your presense" << endl;
                        cout << "the next thing you know, you have become surrounded with both doors now locked" << endl;
                        cout << "you try your best to fight to stay alive, but their numbers are too much and you take a fatal blow" << endl;
                        cout << "Incapacitated, the dragon kings guards drag you to their king, and you become his lunch" << endl;
                        cout << "GAME OVER" << endl;
                        return 0;
                    }
                }
                else{
                    userchoice = "";
                    cout << "unsure what to do, you hesitate and succumb to the toxic fumes" << endl;
                    cout << "GAME OVER" << endl;
                    return 0;
                }
            }
            else{
            //if(userchoice == "n" || userchoice == "N"){
                userchoice = "";
                cout << "Dwelling too long on the contents of the map, you dont notice a dark shadowy figure sneaking up on you." << endl;
                cout << "the next thing you know, your on the floor bleeding out as you pass out" << endl;
                cout << "GAME OVER" << endl;
                return 0;
            }
        }
        else if(userchoice == "N" || userchoice == "n"){//chest prompt
            cout << "TODO" << endl;
            return 0;
        }
    }
    else if (userchoice == "M" || userchoice == "m"){//path prompt
        cout << "Mountain pass move" << endl;
        return 0;
    }   

    return 0;
}