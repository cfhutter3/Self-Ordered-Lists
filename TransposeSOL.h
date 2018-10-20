#pragma once

#include "SelfOrderedListADT.h"
#include "llist.h"
#include <iomanip>

template <typename E>
class TransposeSOL : public SelfOrderedListADT<E> {
public:
	TransposeSOL() : SelfOrderedListADT<E>() {}

	~TransposeSOL() {}

	bool find(const E& it) override {
		linkedList->moveToStart();
		unsigned int whereami{ 0 };
		bool found{ false };
		for (int i{ 0 }; i < linkedList->length(); i++) {
			compareCount++;
			if (linkedList->getValue() == it) {
				found = true;
				linkedList->incrementFrequency();
				whereami = linkedList->currPos();
				break;
			}
			linkedList->next();
		}
		if (!found) {
			add(it);
			whereami = linkedList->length() - 1;
		}
		doHeuristic(whereami);
		linkedList->moveToStart();
		return found;
	}

	void add(const E& it) override {
		linkedList->append(it);
	}

	int getCompares() const override {
		return compareCount;
	}

	int size() const override {
		return linkedList->length();
	}

	void printlist() const override {
		unsigned int count{ 0 };
		linkedList->moveToStart();
		for (int i{ 0 }; i < linkedList->length(); i++) {
			if ((i + 1) % 10 == 0) {
				std::cout << '\n';
			}
			std::cout << setw(5) << linkedList->getValue() << '-' << linkedList->getFrequency();
			linkedList->next();
		}
		std::cout << '\n';
		linkedList->moveToStart();
	}

	void printlist(int n) const override {
		linkedList->moveToStart();
		for (int i{ 0 }; i < n; i++) {
			std::cout << setw(5) << linkedList->getFrequency() << '-' << linkedList->getValue() << '\n';
			linkedList->next();
		}
		std::cout << '\n';
		linkedList->moveToStart();
	}


private:
	LList<E>* linkedList = new LList<E>();
	unsigned int compareCount{ 0 };

	void doHeuristic(unsigned int whereami) {
		E temp;
		unsigned int freqTemp{ 0 };
		linkedList->moveToPos(whereami);
		freqTemp = linkedList->getFrequency();
		temp = linkedList->remove();
		linkedList->moveToPos((whereami == 0 ? whereami : whereami - 1));
		linkedList->insert(temp);
		linkedList->setFrequency(freqTemp);
		linkedList->moveToStart();
	}

};