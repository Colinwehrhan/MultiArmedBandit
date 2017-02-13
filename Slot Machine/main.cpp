//
//  main.cpp
//  Slot Machine
//
//  Created by Colin Wehrhan on 2/11/17.
//  Copyright © 2017 Colin Wehrhan. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <ostream>
#include <random>
#include <fstream>

using namespace std;

// function prototypes


// make a class of the of slot machine arms

class Arm {
public:
    
    // intilize the arms
    
    int counter;
    double mu;
    double sigma;
    double mullerResult;
    
    // generate arm function
    void makeArm();
    
    // print the arm
    void printArm();
    
};

// slot machince prototype
    // takes in a integer for # of arms and return/pass inteteger for reward
double slotMachine( int numArms);

// get a standard deviation of entered number
    // mu is the number mean
    // sigma is the standard deviation
double generateGaussianNoise(double mu, double sigma);


// initialize variables

double boxResult;
int numArms;
double muHard;
double sigmaHard;
int humanCheck;

// create an instance of an arm

Arm armInstance;

// vector of the arms, prechosen
vector<Arm> unfilteredArms;

// main program

int main(int argc, const char * argv[]) {
    
    
    // ask for number of arms
    cout << " How many arms you got there partner?" << endl;
    cout << "Enter number of arms: ";
    cin >> numArms ;
    

    
    // do for a number of arms
    for( int i; i < numArms; i++)
    {
            // make an arm
            armInstance.makeArm();
        
            // push arm class into vector
        
            unfilteredArms.push_back(armInstance);
    }
    
    
    // check if class vector is populating
    cout << unfilteredArms.size() << " size of vector" << endl;
    
    for( int i; i < numArms; i++)
    {
        cout << "Sigma: " << unfilteredArms[i].sigma << "Mu: " << unfilteredArms[i].mu << "Result: " <<  unfilteredArms[i].mullerResult << endl;
       
        
    }
    
    
    // ask if human or robot playing
    cout << "Is a human playing? (enter 0 for human, enter 1 for robot ): " ;
    cin >> humanCheck;
    

        // if human pull arm manually
    
            // as for arm to pull
    
            // actuate MAB
    
            // push winner to new array
    
            // apphend to human file
    
    
        // if robot
    
            // run action value learner
    
            // actuate MAB
    
            // push winner to new array
    
            // print to robot file
    
    
    
    
    muHard = 20;
    
    sigmaHard = .8;
    // test box muller for returning value

    boxResult = generateGaussianNoise(muHard, sigmaHard);
    
    cout << boxResult << endl;
    
    // Kill function
    return 0;
}






// supplemental functions

void Arm::makeArm()
{
    
    // generate a mu
    mu =20;
    
    // generate a sigma
    sigma = .2;
    
    if (counter > 1)
    {
        // generate a mu
        mu =10;
        
        // generate a sigma
        sigma = .2;
    }
    
    
    mullerResult = generateGaussianNoise(mu, sigma);
    counter++;
    
}



void Arm::printArm()
{
    // print the line
    cout << mu << sigma << " devaition " << mullerResult << endl;
    
}

double MAB(int numArms)
{
    //
    
    

    
    double reward;

    return reward;
}




double generateGaussianNoise(double mu, double sigma)
{
    srand(time(NULL));
    const double epsilon = std::numeric_limits<double>::min();
    const double two_pi = 2.0*3.14159265358979323846;
    
    static double z0, z1;
    static bool generate;
    generate = !generate;
    
    if (!generate)
        return z1 * sigma + mu;
    
    double u1, u2;
    do
    {
        u1 = rand() * (1.0 / RAND_MAX);
        u2 = rand() * (1.0 / RAND_MAX);
    }
    while ( u1 <= epsilon );
    
    z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
    z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
    return z0 * sigma + mu;
}

