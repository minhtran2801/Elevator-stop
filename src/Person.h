/*
 * Person.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Minh Tran
 */

#ifndef PERSON_H_
#define PERSON_H_


class Person {
private:
	int weight;
	int targetFloor;
public:
	Person(int w, int floor) {
		weight = w;
		targetFloor = floor;
	}
	int getWeight() {return weight;};
	int getTargetFloor() {return targetFloor;};
};


#endif /* PERSON_H_ */
