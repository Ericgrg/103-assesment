/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
//void Create() {
   // std::ofstream myfile;
   // myfile.open("text.txt");
  //  myfile << "Writing to file \n";
  //  myfile.close();
//}
void Create() {
    std::fstream fileOut;

    fileOut.open("grades.csv", std::ios::out | std::ios::app);
    if (!fileOut) {

    }

    std::cout << " enter the details of 5 students: " << " roll(int),name(string), , math(int) ,phys(int), chem(int), bio(int)";

    int i, rollNum, phys, chem, math, bio;
    std::string name;


    for (i = 0; i < 5; i++) {
        std::cout << "please enter the details of students " << i + 1 << "\n\n";
        std::cin >> rollNum
            >> name
            >> math
            >> phys
            >> chem
            >> bio;

        fileOut << rollNum << ","\
            << name << ","
            << math << ","
            << phys << ","
            << chem << ","
            << bio << ","
            << rollNum << ","
            << "\n";

    }
}

void Read() {
    //creting our variable for reading
    std::fstream fileIn;

    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;

    int rowNum;
    // assigning the file to read and flag to fileIn
    fileIn.open("grades.csv", std::ios::in);

    //determine if a file is open
    if (fileIn.is_open()) {
        //while there is content to copy from fileIn to line, loop
        while (std::getline(fileIn, line)) {
            row.clear();  //deleting the current content from string

            std::stringstream str(line); //convers file data to string format

            //while content in str, copy to word and stop at each comma
            while (getline(str, word, ','))
                row.push_back(word);  //appending the content of var word into row

            content.push_back(row); //appending the row content into content var(variable).

        }
    }
    else {
        std::cout << " no file   found\n";
    }

    std::cout << " please input the roster number for the student you wish to view";
    std::cin >> rowNum;
    for (int i = 0; i < content.size() + 1; i++) {
        std::cout << content[rowNum - 1][i];
    }
    std::cout << "\n\n";
    return;

}

int main()
{
    int input;
    std::cout << " please select your operation:\n.\tCreate/write\n 2.\tRead";
    std::cin >> input;

    switch (input) {
    case 1:
        Create();
        break;

    case 2:
        Read();
        break;
    }

}*/


#include <iostream>

#include<ctime>
#include <string>


using namespace std;

const int MAX_TRIES = 3;
int letterFill(char, string, string&);



//we can make this program better by adding a hint for each word that is given. Plus, lets  change it to something people from NOrth america are more familiar with. 
int main()
{

    //HANDLE  hConsole;

    //hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

   // SetConsoleTextAttribute(hConsole, 40);
    string name;
    string yes_or_no;
    char letter;
    int num_of_wrong_guesses = 0;
    string hint;

    string word;
    string words[] =
    {
      "y",
      "o",
      "o",
      "b",
      "e",
      "e",
      
    };

    //choose and copy a word from array of words randomly
    srand(time(NULL));
    int n = rand() % 6; //range from to 0 and 10. so it will basically choose randomly any of these words. 
    word = words[n]; // word is equal to one of the country names in the array.


    switch (n) // a switch statement that will execute based on which word is chosen.  Range is from zero to 10. 
    {
    case 0: //if Mexico is chosen as the word to guess. Then give the player this hint. 
        hint = "Hint: Guess the missing letter in _oobee:";
        break;

    case 1: //if  France  is chosen as the word to guess. Then give the player this hint. 
        hint = "Hint : Guess the missing letter in y_obee : ";
        break;

    case 2: //if  Italy  is chosen as the word to guess. Then give the player this hint. 
        hint = "Hint: Guess the missing letter in yo_bee:";
        break;

    case 3: //if  South Africa  is chosen as the word to guess. Then give the player this hint. 
        hint = "Hint: Guess the missing letter in yoo_ee:";
        break;


    case 4: //if  Japan  is chosen as the word to guess. Then give the player this hint. 
        hint = "Hint: Guess the missing letter in yoob_e:";
        break;


    case 5: //if  Australia  is chosen as the word to guess. Then give the player this hint. 
        hint = "Hint: Guess the missing letter in yoobe_:";
        break;
    }


    // Initialize the secret word with the * character.
    string unknown(word.length(), ('_')); //takes each letter of the word and displays it with -. 

    // welcome the user
    cout << "\n\nWelcome to the guessing game...Guess a country Name"; //starts a new line and prints the quoted text. 
    cout << "\n\nEach letter is represented by a star."; //starts a new line and prints the quoted text. 
    cout << "\n\nYou have to type only one letter in one try";  //starts a new line and prints the quoted text. 
    cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";  //Starts a new line. prints the quoted text and max number of tries. 
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; //starts a new line and prints the quoted text. 

    // Loop until the guesses are used up
    while (num_of_wrong_guesses < MAX_TRIES)
    {
        cout << endl << hint << endl;
        cout << "\n\n" << unknown;         //new line  and the displays the word in a hidden way. 
        cout << "\n\nGuess a letter: ";    //prints the quoted text with a new line. 
        cin >> letter;                      //user enters the guessed letter.

        // Fill secret word with letter if the guess is correct,
        // otherwise increment the number of wrong guesses.
        if (letterFill(letter, word, unknown) == 0)  //returns the letter the user entered.  the current word selected and how much of the word the user has guessed. 
        {
            cout << endl << "\n\Whoops! That letter isn't in there!" << endl;
           

            //prints the quoted text and ends line.
            num_of_wrong_guesses++; //increase the number of guesses by one. 
        }
        else
        {
            cout << " hangman" << endl;
            cout << "                         " << endl;
            cout << "_________________        " << endl;
            cout << "|        )               " << endl;
            cout << "|        |               " << endl;
            cout << "|        o               " << endl;
            cout << "|        |               " << endl;
            cout << "|     /  |  \\           " << endl;
            cout << "|    /   |   \\          " << endl;
            cout << "|       /  \\            " << endl;
            cout << "|      /    \\           " << endl;
            cout << "|                        " << endl;
            cout << "|__________________      " << endl;

            cout << endl << "\n\You found a letter! Isn't that exciting!" << endl; // print the text and ends the line. 
        }
        // Tell user how many guesses has left.
        cout << "\n\You have " << MAX_TRIES - num_of_wrong_guesses; //prints the number of guesses left. This is done by subtracting the number of guesses from the number of max tries. 
        cout << " guesses left." << endl; //Prints the quoted text. 
        // Check if user guessed the word.
        if (word == unknown)
        {
            cout << word << endl; //prints the word selected for the user to guess. 
            cout << "\n\Yeah! You got it!" << endl;
            
                cout << "Closing program" << endl;
                return 0; //returns 0 to close the program.

            
            break;
        }
    }
    if (num_of_wrong_guesses == MAX_TRIES) //to execute when the number of wrong guesses equals the number of max tries. 
    {
        cout << "\n\Sorry, your guess is wrong" << endl;
        cout << " hangman" << endl;
        cout << "                         " << endl;
        cout << "_________________        " << endl;
        cout << "|        )               " << endl;
        cout << "|        |               " << endl;
        cout << "|        o               " << endl;
        cout << "|        |               " << endl;
        cout << "|    \\  |  /          " << endl;
        cout << "|     \\ | /            " << endl;
        cout << "|       /  \\            " << endl;
        cout << "|      /    \\           " << endl;
        cout << "|                        " << endl;
        cout << "|__________________      " << endl;

        
    }
    return 0; //ensures the program exits better. 
    //cin.ignore(); not needed. Causes issues with exiting. 
    //cin.get();  not needed. Causes issues with exiting. 

}

/* Take a one character guess and the secret word, and fill in the
 unfinished guess word. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill(char guess, string secretword, string& guessword)
{
    int i;
    int matches = 0;
    int len = secretword.length();
    for (i = 0; i < len; i++)
    {
        // Did we already match this letter in a previous guess?
        if (guess == guessword[i])
            return 0;
        // Is the guess in the secret word?
        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}