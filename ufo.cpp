#include <iostream>
#include <vector>
#include <string>
#include "ufo_function.h"

int main(){
	
	greet();

	std::string codeword = "charlie", answer = "_______"; 
	int misses = 0;
	std::vector<char> incorrect;
	bool guess = false;
	char letter;
	while(answer != codeword && misses < 7){
	
			display_misses(misses);
			display_status(incorrect, answer);
			std::cout<<"Please Enter your guess: ";
			std::cin>>letter;

			// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
			std::cout << "\x1B[2J\x1B[H";

			for(int i=0; i<codeword.length(); i++){
					if(letter==codeword[i]){
							answer[i]=letter;
							guess = true;
					}
			}
			if (guess == true){
					std::cout<<"Correct!\n";
			} else {
					std::cout<<"Incorrect! tractor bream pulls the person in furthur.\n";
					incorrect.push_back(letter);
					misses++;
			}
			guess = false;


	
	}
	
	end_game(answer, codeword);
	
}	
