#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

// Car class
// to store the car position and speed in a pair manner
// inside car object
class Car{
    public:
        int position;
        int speed;

    Car(int position,int speed){
        this->position = position;
        this->speed = speed;
    }
};

// custom comparator for sorting the car with respect to it's position
bool myComp(Car&a,Car&b){
    return a.position<b.position;
}

int calculateNumberOfFleets(vector<int> & position, vector<int>& speed, int target){

    int n = position.size();
    vector<Car> cars;  // vector of Car type

    // looping over positio
    for(int i=0;i<n;i++){
        Car car(position[i],speed[i]);
        cars.push_back(car);
    }

    // sorting the cars based on position
    sort(cars.begin(),cars.end(),myComp);

    // calculating time for each car to reach the target
    // using the formula
    // time = target - distance / speed 
    // time is being calculated in such a way that there are no other cars
    // and we just calulating the time of every individual car that it will take to reach to the target
    vector<float> timeForEachCarToReachTarget;
    for(auto car:cars){
        float time = ((target-car.position) /(float)car.speed);
        timeForEachCarToReachTarget.push_back(time);
    }

    for(auto bb:timeForEachCarToReachTarget){
        cout<<bb<<" ";
    }
    cout<<endl<<endl;


    stack<float> st;

    for(int i=0;i<timeForEachCarToReachTarget.size();i++){

        float currentCarTime = (float)timeForEachCarToReachTarget[i];

        // if the stack is empty then push the current car time
        if(st.empty()) st.push(currentCarTime);
        
        // if the currentCar is taking more or equal time than the car behind it
        // then not matter how faster are the cars behind it, as it will form a fleet and the speed of that fleet 
        // will be the speed of currentCar i.e the slower one
        else if(currentCarTime >= st.top()){

            // popping every single car that is slower or equal in the time of the current car
            // as eventually they will form the fleet with current car, and with currentCar time and speed the fleet will go on
            while(!st.empty() && currentCarTime>=st.top()) st.pop();
            // after popping
            // pushing the currentCarTime
            st.push(currentCarTime);
        }

        // if the currentCarTime takes less time than the car behind it
        // then the previous car will not be able to from the fleet with currentCar
        // so pushing the currentCar time
        else if(currentCarTime < st.top()){
            st.push(currentCarTime);
        }

    }

    // the algo is designed in such a way that
    // st.size() will be answer
    // i.e st.size() === numberOfFleets that will reach the target destination
    return st.size();
    

}

int main(){

    vector<int> position = {6,8};
    vector<int> speed  = {3,2};
    int target = 10;

    cout<<calculateNumberOfFleets(position,speed,target);
    
    return 0;
}