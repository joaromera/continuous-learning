

// ---------- SEQUENCE CONTAINERS ----------

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <ctime>
#include <deque>
#include <list>
#include<forward_list>

bool isEven(const int& val){
    return (val % 2) == 0;
}

int main()
{

    // Contains data stored in order

    // ---------- DEQUES ----------

    // A deque (Deck) is a dynamic array like vectors
    // except it also allows for insertion or deletion
    // from the front
    deque<int> deq1;

    // Add to the end and front
    deq1.push_back(5);
    deq1.push_front(1);

    // Add values with assign
    deq1.assign({11,12});

    // Get the size
    cout << "Size : " << deq1.size()
            << endl;

    // Access by index
    cout << deq1[0] << endl;
    cout << deq1.at(1) << endl;

    // Add at an index using an iterator
    deque<int>::iterator it = deq1.begin() + 1;
    deq1.insert(it, 3);

    // Add multiple values
    int tempArr[5] = {6,7,8,9,10};
    deq1.insert(deq1.end(), tempArr, tempArr+5);

    // Erase at an index
    deq1.erase(deq1.end());

    // Erase 1st 2 elements
    deq1.erase(deq1.begin(), deq1.begin()+2);

    // Pop first value
    deq1.pop_front();

    // Pop last
    deq1.pop_back();

    // Create a deque with 2 50s
    deque<int> deq2(2,50);

    // Swap values in deques
    deq1.swap(deq2);

    // Delete all values
    deq1.clear();

    // Cycle through the deque
    for(int i : deq1)
        cout << i << endl;

    // ---------- END DEQUES ----------

    // ---------- LIST ----------
    // Lists are the most efficient at inserting,
    // moving and extracting elements, but lack
    // direct access to elements

    // Add values
    int arr[5] = {1,2,3,4,5};
    list<int> list1;
    list1.insert(list1.begin(), arr, arr+5);

    // Adding values with assign
    list1.assign({10,20,30});

    // Add to end and front
    list1.push_back(5);
    list1.push_front(1);

    // Get the size
    cout << "Size : " << list1.size()
            << endl;

    // Can't access index
    // cout << list1[0] << endl;

    // You can access the index with an iterator
    list<int>::iterator it2 = list1.begin();
    advance(it2, 1);
    cout << "2nd Index : " <<
            *it2 << endl;

    // Insert at an index
    it2 = list1.begin();
    list1.insert(it2, 8);

    // Erase at an index
    list1.erase(list1.begin());

    // Erase 1st 2 elements
    it2 = list1.begin();
    list<int>::iterator it3 = list1.begin();
    advance(it3, 2);
    list1.erase(it2, it3);

    // Pop first value
    list1.pop_front();

    // Pop last
    list1.pop_back();

    // Create another list
    int arr2[6] = {10,9,8,7,6,6};
    list<int> list2;
    list2.insert(list2.begin(), arr2, arr2+5);

    // Sort the list
    list2.sort();

    // Reverse the list
    list2.reverse();

    // Remove duplicates
    list2.unique();

    // Remove a value
    list2.remove(6);

    // Remove if a condition is true
    list2.remove_if (isEven);

    // Merge lists
    list1.merge(list2);

    for(int i : list2)
        cout << i << endl;

    cout << endl;

    // Cycle through the list
    for(int i : list1)
        cout << i << endl;

    cout << endl;

    // ---------- END LIST ----------

    // ---------- FORWARD_LIST ----------
    // A forward list is like a list, but each list
    // item only has a link to the next item in the
    // list and not to the item that proceeds it.

    // This make them the quickest of the sequence
    // containers

    forward_list<int> fl1;

    // Assign values
    fl1.assign({1,2,3,4});

    // Push and pop front
    fl1.push_front(0);
    fl1.pop_front();

    // Get 1st
    cout << "Front : " << fl1.front();

    // Get iterator for 1st element
    forward_list<int>::iterator it4 = fl1.begin();

    // Insert after 1st element
    it4 = fl1.insert_after(it4, 5);

    // Delete just entered 5
    it4 = fl1.erase_after(fl1.begin());

    // Place in 1st position
    fl1.emplace_front(6);

    // Remove a value
    fl1.remove(6);

    // Remove if a condition is true
    fl1.remove_if (isEven);

    forward_list<int> fl2;
    fl2.assign({9,8,7,6,6});

    // Remove duplicates
    fl2.unique();

    // Sort
    fl2.sort();

    // Reverse
    fl2.reverse();

    // Merge lists
    fl1.merge(fl2);

    // Clear
    fl1.clear();

    for(int i : fl1)
        cout << i << endl;

    cout << endl;

    for(int i : fl2)
        cout << i << endl;

    // ---------- END FORWARD_LIST ----------

    return 0;
}

