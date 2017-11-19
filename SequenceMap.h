#ifndef SEQUENCEMAP_H
#define SEQUENCEMAP_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SequenceMap {
public:
	// Zero-parameter constructor.
    SequenceMap() = default;
    // Copy-constructor.
    SequenceMap(const SequenceMap &rhs) = default;
    // Copy-assignment.
    SequenceMap& operator=(const SequenceMap &rhs) = default;
    // Move-constructor. 
  	SequenceMap(SequenceMap &&rhs) = default;
  	// Move-assignment.
  	SequenceMap& operator=(SequenceMap &&rhs) = default;
  	// Destructor.
  	~SequenceMap() = default;

  	// Start of Part 1 

  	// Constructor for recognition sequence and enzyme acronym
	SequenceMap(const string &a_rec_seq, const string &an_enz_acro) {
		recognition_sequence_ = a_rec_seq;
		enzyme_acronyms_.push_back(an_enz_acro);
	}

	// Constructor for recognition sequence only
	SequenceMap(const string &a_rec_seq) {
		recognition_sequence_ = a_rec_seq;
		enzyme_acronyms_.push_back("");
	}

	// Overload the < operator
	bool operator<(const SequenceMap &rhs) const {
		return (recognition_sequence_ < rhs.recognition_sequence_);
	}

	// Overload the << operator to print the recognition sequence with enzyme acronyms
	friend std::ostream &operator<<(std::ostream &out, const SequenceMap &a_SequenceMap) {
		out << a_SequenceMap.recognition_sequence_ << "   ";
		for (int i = 0; i < a_SequenceMap.enzyme_acronyms_.size(); ++i) {
			out << a_SequenceMap.enzyme_acronyms_[i] << " ";
		}
		return out;
	}

	// Merge two SequenceMap objects 
	void Merge(const SequenceMap &other_sequence) {
		for (int i = 0; i < other_sequence.enzyme_acronyms_.size(); ++i) {
			enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[i]);	
		}
	}

	// Print the recognition sequence
	string getRecognitionSequence() const {
		return recognition_sequence_;
	}

	// Print enzyme acronym
	void printAllEnzAcroOfRecSeq() const {
		for (int i = 0; i < enzyme_acronyms_.size() ; ++i) {
			cout << enzyme_acronyms_[i] << "   ";	
		}
		cout << endl;
	}


private:
	string recognition_sequence_ ; 
	vector<string> enzyme_acronyms_;
};

#endif