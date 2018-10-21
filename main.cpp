#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// Function prototypes
std::vector<int> Decomposition(int aPowers[], int num);

int main(){
  //declaration of num and initialization aPowers to the powers of 3
  int aPowers[5] = {1,3,9,27,81};
  char again = 'Y';

  while (again == 'Y'){
    int num  = -999;
    //while loop for boundary check (-121 <= num <= 121)
    while(num > 121 || num < -121){
      std::cout << "What number would you like to decompose by the powers of 3: ";
      std::cin >> num;
    }

    std::vector<int> vPowers = Decomposition(aPowers, num);

    //exits program if num could be decomposed by the powers of 3
    if (vPowers[0] == -999)
      continue;

    std::cout << num << " = " << vPowers[0];

    //for loop to loop to display vector of powers of 3 that successfully decomposed onto console
    //creates blank space between numbers as directed by Professor Ammari
    for(int i = 1; i <= vPowers.size()-1; i++){
      if (vPowers[i] > 0) std::cout << " + "; //+ operator if vPowers[i] is positive
      else if (vPowers[i] < 0) std::cout << " - "; //- operator if vPowers[i] is positive
      std::cout << abs(vPowers[i]); //takes the absolute value of vPowers[i];
    }

    std::cout << std::endl;
    std::cout << "Would you like to decompose another number? (Y/N): ";
    std::cin >> again;
    again = toupper(again);
  }

  std::cout << "Goodbye!" << std::endl;

  return 0;
}


//Function Definitions

/*
Returns vector of all the powers that was decomposed from desired number
@param aPowers: array of cubes
@param num: user inputted number to be decomposed by powers of 3;
*/
std::vector<int> Decomposition(int aPowers[], int num){
  //declaration of vPowers, which has no values, and initialization of sign to 1
  std::vector<int> vPowers;
  int sign = 1; //determines whether the value of aPowers will be positive or negative

  //for loop that pushes back the vaue of aPowers into vPowers based on the interval of num is in
  for(int i = 4; i >= 0; i--){
    //conditional to determine whether value pushed back into vPowers will be positive or negative
    if(num < 0)
      sign = -1;
    else
      sign = 1;

    //conditional to determine the value of aPowers based which interval num is in
    if ((num >= 14 && num <= 40) || (num <= -14 && num >= -40)) i = 3;
    else if ((num >= 5 && num <= 13) || (num <= -5 && num >= -13)) i = 2;
    else if ((num >= 2 && num <= 4) || (num <= -2 && num >= -4)) i = 1;
    else if (num == 1 || num == -1) i = 0;

    //pushes back value of aPOwers into vPowers, which will later be used to calculate the sum in main
    vPowers.push_back(sign*aPowers[i]);
    num -= sign*aPowers[i];

    //breaks the for loop if num = 0 meaning decomposition is complete
    if(num == 0)
      break;
  }

  //first index of vPowers = -999, which in main will cause the program to exit
  if (num != 0){
    std::cout << "Number cannot be decomposed according to the powers of 3" << std::endl;
    vPowers[0] = -999;
    return vPowers;
  }

  return vPowers;
}

// //conditional to determine the starting interval of aPowers
// if(num == 1 || num == -1){
//   //conditional to determine whether value pushed back into vPowers will be positive or negative
//   if(num < 0)
//     sign = -1;
//   else
//     sign = 1;
//   vPowers.push_back(sign*aPowers[0]); //aPowers[0] = 1
// }else if ((num >= 2 && num <= 4) || (num <= -2 && num >= -4)){
//   //for loop that iterates from the second index in the array and decrements; initial value of aPowers = 3
//   for(int i = 1; i >= 0; i--){
//     //conditional to determine whether value pushed back into vPowers will be positive or negative
//     if(num < 0)
//       sign = -1;
//     else
//       sign = 1;
//
//     vPowers.push_back(sign*aPowers[i]);
//     num -= sign*aPowers[i];
//
//     //breaks the for loop if num = 0 meaning decomposition is complete
//     if(num == 0)
//       break;
//   }
// }else if ((num >= 5 && num <= 13) || (num <= -5 && num >= -13)){
//   //for loop that iterates from the thid index in the array and decrements; initial value of aPowers = 9
//   for(int i = 2; i >= 0; i--){
//     //conditional to determine whether value pushed back into vPowers will be positive or negative
//     if(num < 0)
//       sign = -1;
//     else
//       sign = 1;
//
//     if (num == sign*aPowers[i-1]){
//       vPowers.push_back(sign*aPowers[i-1]);
//       break;
//     }
//
//     vPowers.push_back(sign*aPowers[i]);
//     num -= sign*aPowers[i];
//
//     if(num == 0)
//       break;
//   }
// }else if ((num >= 14 && num <= 40) || (num <= -14 && num >= -40)){
//   //for loop that iterates from the fourth index in the array and decrements; initial value of aPowers = 27
//   for(int i = 3; i >= 0; i--){
//     //conditional to determine whether value pushed back into vPowers will be positive or negative
//     if(num < 0)
//       sign = -1;
//     else
//       sign = 1;
//
//     if (num == sign*aPowers[i-1]){
//       vPowers.push_back(sign*aPowers[i-1]);
//       break;
//     } else if ( num == sign*aPowers[i-2]){
//       vPowers.push_back(sign*aPowers[i-2]);
//       break;
//     }
//
//     vPowers.push_back(sign*aPowers[i]);
//     num -= sign*aPowers[i];
//
//     if(num == 0)
//       break;
//   }
// }else if ((num >= 41 && num <= 121) || (num <= -41 && num >= -121)){
//   //for loop that iterates from the fifth index in the array and decrements; initial value of aPowers = 81
//   for(int i = 4; i >= 0; i--){
//     //conditional to determine whether value pushed back into vPowers will be positive or negative
//     if(num < 0)
//       sign = -1;
//     else
//       sign = 1;
//
//     if (num == sign*aPowers[i-1]){
//       vPowers.push_back(sign*aPowers[i-1]);
//       break;
//     } else if (num == sign*aPowers[i-2]){
//       vPowers.push_back(sign*aPowers[i-2]);
//       break;
//     } else if (num == sign*aPowers[i-3]){
//       vPowers.push_back(sign*aPowers[i-3]);
//       break;
//     }
//
//     vPowers.push_back(sign*aPowers[i]);
//     num -= sign*aPowers[i];
//
//     if(num == 0)
//       break;
//   }
// }
