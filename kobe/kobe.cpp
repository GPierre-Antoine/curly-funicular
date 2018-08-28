#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <random>
#include <exception>

using namespace std;

vector<string> arguments;
int success_rate;
size_t attempt_count_per_session;
size_t session_count = 100000;

size_t success_count=0;

string usage(){
    return "./a.out success_rate attempt_count_per_session [ session_count = 100000  ]";
}

bool makeAttempt(){
    return ((rand()+1)%100) < success_rate;
}

bool runSession(){
    for (size_t i=0;i<attempt_count_per_session;++i)
        if (makeAttempt())
            return true;
    return false;
}

void assignValues(int argc, char ** argv){
    arguments = vector<string>(argv+1,argv+argc);
    if (arguments.size()<2){
        throw std::invalid_argument(usage());
    }

    srand(time(nullptr));
    success_rate = stoi(arguments[0]);
    attempt_count_per_session = stoi(arguments[1]);
    
    if (arguments.size()==3){
        session_count = stoi(arguments[2]);
    }
}

void startTrials(){
    for (size_t i = 0; i< session_count; ++i){
        if (runSession()){
            success_count+=1;
        }
    }
}

void displayResults(){
    cout << "After " << session_count << " there has been " << success_count << " successes. Which means a rate of " << float(success_count)/session_count << "%" << endl;
}

int main(int argc, char** argv){
    try{
    assignValues(argc, argv);
    startTrials();
    displayResults();
    } catch(std::exception & e){
        std::cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
