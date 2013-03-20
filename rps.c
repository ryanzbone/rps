#include <stdio.h>
#include <stdlib.h>

char playAgain();
void printOutcomeMessage(int, int);

/* Main Function
*  Author: Ryan Bone
*  Purpose: Rock, Paper, Scissors game. 
*  Input: User enters numberic input from keyboard.
*  Output: Prints results to screen.
*/
int main() {
  //Initialize variables
  char playerChoice = ' ';
  int  computerChoice = 3;
  int  computerVengeance = 13;

  while (playerChoice != 'n'){
    //Begin game
    printf("\n*=======================================*\n");
    printf("* Rock, Paper, Scissors! Pick a number! *\n");
    printf("*=======================================*\n");
    printf("\n(1)Rock\n(2)Paper\n(3)Scissors\n> ");
    
    //Get player choice
    playerChoice = getchar();
    getchar();

    if (playerChoice != '1' && playerChoice != '2' && playerChoice != '3') {
      printf("\n\nIt's not that difficult, PLAYER. Enter a valid number (1, 2, 3).\n");
      playerChoice = 'y';
      continue;
    }
     
    //Get computer choice
    srand(time(NULL));
    computerChoice = rand() % 3 + 49;

    //sanity check
    if (computerChoice < 49 || computerChoice > 51) {
      printf("The computer has made an invalid choice.\n");
      printf("Congratulations PLAYER, looks like you've won this time.\n\n");
      break;
    }
    
    //Determine winner and print win/loss statements
    int outcome = playerChoice - computerChoice;
    printOutcomeMessage(playerChoice, computerChoice);
    
    if (computerVengeance > 20) {
      outcome = -1;
      playerChoice = 'y';
      computerVengeance++;
      printf("THE COMPUTER WINS.");
      if (computerVengeance > 27) {
    printf("\n\n\n\n\nYOU CANNOT WIN.\n\n\nCOMPUTER BEATS PAPER.\n\n");
    printf("COMPUTER BEATS ROCK.\n\nCOMPUTER BEATS SCISSORS.\n\n\n");
    break;
      }
    } else if (outcome == 0) {
      //Tie
      printf("\nMost fortuitous for you, PLAYER.\n\nTry again?\n(1)Yes\n(2)No\n> ");
      computerVengeance++;
      playerChoice = playAgain();
    } else if (outcome == 1 || outcome == -2) {
      //Player wins
      computerVengeance++;
      printf("\nCongratulations PLAYER! You've won! \nYou were able to beat the cold, ");
      printf("calculating computer through your sheer determination and force of will!");
      printf("\n\nPlay again?\n(1)Yes\n(2)No\n> ");
      playerChoice = playAgain();
    } else {
      //Computer wins
      printf("\nCongratulations COMPUTER! You've won!\nYou beat that meatbag. ");
      printf("Its passions and disorganized thoughts doomed from the start.\n");
      printf("\n\nPlay again?\n(1)Yes\n(2)No\n> ");
      
      //Determine if computer will play again
      computerChoice = rand() % 20;
      if(computerChoice < computerVengeance) {
    printf("y \n");
    printf("\nThe computer has chosen to play again. Best of luck, PLAYER.\n");
      }
      else{
    printf("n \n");
    printf("\nThe computer does not deign to play you again, PLAYER.\n\n"); 
    break;
      }
    }  
  }
}

/* playAgain helper function
*  Author: Ryan Bone
*  Purpose: Determine if user wants to play again. 
*  Input: User enters numberic input from keyboard.
*  Output: Prints results to screen.
*/
char playAgain() {
  char playerChoice = getchar();
  getchar();
  
  switch (playerChoice) {
  case '1':
    printf("\nGood luck, PLAYER.\n\n");
    playerChoice = 'y';
    break;
  case '2':
    printf("\nA wise choice.\n\n");
    playerChoice = 'n';
    break;
  default:
    printf("\nThat was not an option, PLAYER. You will not continue playing.\n\n");
    playerChoice = 'n';
    break;
  }
  return playerChoice;
}

/* printOutcomeMessage helper function
*  Author: Ryan Bone
*  Purpose: Gives information about win or loss 
*  Input: Takes in previously determined integer playerChoice and computerChoice.
*  Output: Prints results to screen.
*/
void printOutcomeMessage(int playerChoice, int computerChoice){
  enum {
    ROCK = 49,
    PAPER = 50,
    SCISSORS = 51
  };
  
  if (playerChoice == computerChoice) {
    printf("\nA tie.\n");
  } else {
    switch(playerChoice){
    case ROCK:
      if(computerChoice == SCISSORS) {
    printf("\nRock smashes scissors!\n");
      } else {
    printf("\nPaper covers rock...\n");
      }
      break;
    case PAPER:
      if(computerChoice == ROCK) {
    printf("\nPaper covers rock!\n");
      } else {
    printf("\nScissors cuts paper...\n");
      }
      break;
    case SCISSORS:
      if(computerChoice == PAPER) {
    printf("\nScissors cuts paper!\n");
      } else {
    printf("\nRock smashes scissors...\n");
      }
    }
  }
}