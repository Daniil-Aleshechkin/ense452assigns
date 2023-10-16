/**
   Project: Implementation of a Queue in C++.
   Programmer: Karim Naqvi
   Course: enel452
   Description: test code
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "queue.h"

/**
   Compare the given queue to the given array of data elements.  Return
   true if they are all equal.
 */
bool testQueueEquality( Queue & q, std::vector<Data> const & array)
{
    if (q.size() != array.size())
	return false;

    for (unsigned i = 0; i < q.size(); ++i)
    {
        Data d(0,0);
	q.remove(&d);
	if ( !d.equals(array[i]) )
	    return false;
	q.insert(d);
    }
    return true;
}

/**
   Assert that the queue correctly inserts an element in the middle of the queue
 */
bool testQueueInsertMid() {

    Queue q;
    q.insert(Data(1,2));
    q.insert(Data(3,4));
    q.insert(Data(5,6));
    q.insert(Data(-4,-5), 2);

    std::vector<Data> expectedResult;
    expectedResult.push_back(Data(1,2));
    expectedResult.push_back(Data(3,4));
    expectedResult.push_back(Data(-4,-5));
    expectedResult.push_back(Data(5,6));

    return testQueueEquality(q, expectedResult);
}


/**
   Asserts the queue inserts an element at the head
 */
bool testQueueInsertHead() {

    Queue q;
    q.insert(Data(1,2));
    q.insert(Data(3,4));
    q.insert(Data(5,6));
    q.insert(Data(0,1), 0);

    std::vector<Data> expectedResult;
    expectedResult.push_back(Data(0,1));
    expectedResult.push_back(Data(1,2));
    expectedResult.push_back(Data(3,4));
    expectedResult.push_back(Data(5,6));

    return testQueueEquality(q, expectedResult);
}

/**
   Asserts the queue inserts an element at the second position
 */
bool testQueueInsertSecond() {

    Queue q;
    q.insert(Data(1,2));
    q.insert(Data(3,4));
    q.insert(Data(5,6));
    q.insert(Data(0,2), 1);

    std::vector<Data> expectedResult;
    expectedResult.push_back(Data(1,2));
    expectedResult.push_back(Data(0,2));
    expectedResult.push_back(Data(3,4));
    expectedResult.push_back(Data(5,6));
    
    return testQueueEquality(q, expectedResult);

}

/**
   Asserts the queue inserts an element at the tail
 */
bool testQueueInsertTail() {

    Queue q;
    q.insert(Data(1,2));
    q.insert(Data(3,4));
    q.insert(Data(5,6));
    q.insert(Data(0,3), 3);

    std::vector<Data> expectedResult;
    expectedResult.push_back(Data(1,2));
    expectedResult.push_back(Data(3,4));
    expectedResult.push_back(Data(5,6));
    expectedResult.push_back(Data(0,3));
    
    return testQueueEquality(q, expectedResult);

}

/**
   Asserts the queue fails when you attempt to insert outside the range
 */
bool testQueueFailOutOfRange() {
    return true;
}

int main()
{
    using namespace std;

    cout << "Testing queue.\n";
    Queue q1;

    q1.insert(Data(1,1));
    q1.insert(Data(3,3));
    q1.insert(Data(5,5));

    q1.print();

    vector<Data> dataVec;
    dataVec.push_back(Data(1,1));
    dataVec.push_back(Data(3,3));
    dataVec.push_back(Data(5,5));

    assert(testQueueEquality(q1, dataVec));

    Data d44(4, 4);
    bool found = q1.search(d44);
    assert(found == false);


    q1.insert(d44);  // now is (1,1),(3,3),(5,5),(4,4)
    found = q1.search(d44);
    assert(found == true);

    // now queue is(1,1),(3,3),(5,5),(4,4) and 
    // dataVec has (1,1),(3,3),(5,5).  Not equal
    assert(testQueueEquality(q1, dataVec) == false);

    Data temp;
    q1.remove(&temp);  // now q1 is (3,3),(5,5),(4,4)

    Data temp2(1,1);
    assert(temp.equals(temp2));  // (1,1) == (1,1)

    Data temp3(6,6);
    found = q1.search(temp3);
    assert(found == false);

    assert(testQueueInsertHead());
    assert(testQueueInsertSecond());
    assert(testQueueInsertMid());
    assert(testQueueInsertTail());

}
