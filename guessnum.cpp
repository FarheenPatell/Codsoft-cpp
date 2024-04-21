#include<iostream>
#include<ctime>
#include<cstdlib>

int main() {
    srand(time(0));
    int secretNumber= rand() % 100 +1;
    int userGuess;
    int attemps=0;
    std::cout<<"WELCOME TO THE GUESS THE NUMBER GAME!\n";
    std::cout<<"I have generated a random number between 1 and 100.\n";
    std::cout<<"Can you guess what it is?";

    do{
        std::cout<<"Enter your Guess";
        std::cin>>userGuess;
        attemps++;

        if (userGuess>secretNumber){
            std::cout<<"Too high! Try Again!";
        }
        else
        {
            std::cout<<"Too Low! Try Again!\n";

        }
    }
    while(userGuess!= secretNumber);
    
    std::cout<<"Congratulations! you found the number in"<<attemps<<" attemps.\n";
    return 0;

}