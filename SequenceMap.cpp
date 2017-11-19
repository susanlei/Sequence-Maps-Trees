#include "SequenceMap.h"

int main() {
	string recSequence = "SEQUENCE";
	string recSequence_ = "SEQUENCE_";
	string enzymeOne = "enzymeOne";
	string thingS = "THINGS";
	string enzymeThree = "enzymeThree";
	SequenceMap mySM(recSequence, enzymeOne);
	SequenceMap anotherSM(recSequence, enzymeThree);
	SequenceMap diffSM(thingS, thingS);
	if (mySM < diffSM) {
		cout << "it is true" << endl;
	}
	else {
		cout << "it is false" << endl;
	}
	//cout << mySM;
	mySM.Merge(diffSM);
	mySM.Merge(anotherSM);

	cout << "###############" << endl;
	cout << mySM;
	//*/
	return 0;
}