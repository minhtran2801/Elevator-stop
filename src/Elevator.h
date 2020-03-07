/*
 * Elevator.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Minh Tran
 */

#ifndef ELEVATOR_H_
#define ELEVATOR_H_

#include"Person.h"
#include <iostream>
#include <queue>
#include <list>

using namespace std;

const int MAX_PEOPLE_AT_ONE_TIME = 2;
const int MAX_WEIGHT_CAPACITY = 200;
const int TOTAL_FLOOR = 5;

class Elevator {
private:
	int maxWeight;
	int currentWeight;
	int maxPeopleAtOneTime;

	queue<Person> personQueue;
	list<Person> passengerList;
public:
	Elevator() {
		maxWeight = MAX_WEIGHT_CAPACITY;
		currentWeight = 0;
		maxPeopleAtOneTime = MAX_PEOPLE_AT_ONE_TIME;
	}
	void setCurrentWeight(int i) {
		currentWeight += i;
	}

	void setmaxWeight(int i) {
		maxWeight = i;
	}
	void setMaxPeopleAtOneTime(int i) {
		maxPeopleAtOneTime = i;
	}

	int getmaxWeight() {return maxWeight;};
	int getMaxPeopleAtOneTime() {return maxPeopleAtOneTime;};
	int getCurrentWeight() {return currentWeight;};

	bool isValid(Person p) {
		return !personQueue.empty() && (currentWeight + p.getWeight() < maxWeight)
				&& (passengerList.size() < maxPeopleAtOneTime);
	}

	void addPeopleToQueue(Person p) {

			personQueue.push(p);

	}

	int calculateStops() {
		int stops = 0;
		while(!personQueue.empty()) {
			while (isValid(personQueue.front())) {
				passengerList.push_back(personQueue.front());
				personQueue.pop();
			}
			stops += passengerList.size();
			passengerList.clear();
			stops++;

		}
		return stops;
	}

	void run() {
		int people[] = {60,80,40,190};
		int floor[] = {2,3,5,1};
		for (int i = 0; i < 4; i++) {
			Person p(people[i], floor[i]);
			addPeopleToQueue(p);
		}

		cout << "Number of stops: " << calculateStops();
	}
};



#endif /* ELEVATOR_H_ */
