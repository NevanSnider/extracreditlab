
#include <iostream>
#include <fstream>

using namespace std;

// Checks if a given string character is a digit
bool isADigit(char check){
    char nums[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 10; i++){
        if (check == nums[i]){
            return true;
        }
    }
    return false;
}


int main() {

// Initital declarations
string endLoop = "";
string finalString = "";
int frontStopPoint = 0;
int backStopPoint = 0;

while (endLoop != "END"){
    string userInput;
    cout << "Enter a string or type END to exit" << endl;
    cin >> userInput;

    // ends the program if the user ends it
    if (userInput == "END"){
        break;
    }

    //Checks all the characters in the string
    for (int i = 0; i < userInput.length(); i++){
        //Finds the decimal if there is one
        if (userInput[i] == '.'){
            if ((i == 0) ||  (i == userInput.length() - 1)){
                cout << "Not a valid input, there is no number one one or more sides of the decimal" << endl;
                break;
            }

            //If theres a decimal, it sets both end points of the string to the location of the decimal and then works its way out til finding non digits
            else {
                int backStopPoint = i;
                int frontStopPoint = i;

                while (backStopPoint > 0 && isADigit(userInput[backStopPoint-1])){
                    backStopPoint -= 1;
                }

                while (frontStopPoint < userInput.length() - 1 && isADigit(userInput[frontStopPoint+1])){
                    frontStopPoint += 1;
                }

                int rightSideLength = frontStopPoint - i;

                int finalStringLen = (frontStopPoint - backStopPoint) + 1;
                finalString = userInput.substr(backStopPoint, finalStringLen);

                while (rightSideLength < 4){
                    finalString = finalString + "0";
                    rightSideLength += 1;
                }

                cout << backStopPoint << " " << frontStopPoint << " " << finalStringLen << endl;
            }
        }
    }
    
    
    //checks for valid input
    if (finalString.length() == 1 || finalString.length() == 2){
        cout << "Not a valid input, there are no numbers on one or more sides of the decimal" << endl;
    }

    else if (finalString == ""){
        cout << "Not a valid input, there is no decimal in the string" << endl;
    }

    else{

        cout << "The input is: " << finalString << endl;
    }
}
}
