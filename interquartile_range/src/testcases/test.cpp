// matthew shen and esha patel are prog partners!
#include "../src/interquartile_range.h"
#include <vector>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
	To check output (At the interquartile_range directory):
		g++ -std=c++14 -Werror -Wuninitialized -o test test-unit/test.cpp && ./test
*/

void TestInterQuartile(std::vector<int>& v, double expected) {
    Node* head = nullptr;
    for (int i: v)
        head = insertEnd(head, i);

    REQUIRE(interQuartile(head) == expected);

    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("User InterQuartile 1", "Minimum Size") {
	std::vector<int> v;
    v = {0, 1, 2, 3};
	TestInterQuartile(v, 2.00);
}

TEST_CASE("User InterQuartile 2", "Incrementing Size") {
	std::vector<int> v;
    v = {0, 1, 2, 3};

    v.push_back(4);
    TestInterQuartile(v, 3.00);
    v.push_back(5);
    TestInterQuartile(v, 3.00);
    v.push_back(6);
    TestInterQuartile(v, 4.00);
    v.push_back(7);
    TestInterQuartile(v, 4.00);
    v.push_back(8);
    TestInterQuartile(v, 5.00);
    v.push_back(9);
    TestInterQuartile(v, 5.00);
    v.push_back(10);
    TestInterQuartile(v, 6.00);
    v.push_back(11);
    TestInterQuartile(v, 6.00);
    v.push_back(12);
    TestInterQuartile(v, 7.00);
    v.push_back(13);
    TestInterQuartile(v, 7.00);
}

TEST_CASE("Same-Value Nodes", "[IQR]") {
    Node* head = new Node();
    head->value = 7;
    
    for (int i = 0; i < 7; ++i) {
        head = insertEnd(head, 7);
    }

    float result = interQuartile(head);

    REQUIRE(result == 0.00);

    while (head != nullptr) {
        Node* traverser = head;
        head = head->next;
        delete traverser;
    }
}

TEST_CASE("Odd Number", "[IQR]")
{
    Node* head = new Node();
    head->value = 0;
    
    for (int i = 1; i < 6; i++)
    {
        head = insertEnd(head, i);
    }

    float result = interQuartile(head);
    
    REQUIRE(result == 3.00);

    while (head != nullptr)
    {
        Node* traverser = head;
        head = head->next;
        delete traverser;
    }
}


TEST_CASE("Even Number", "[IQR]")
{
    Node* head = new Node();
    head->value = 0;

    for (int i = 10; i < 20; i++)
    {
        head = insertEnd(head, i);
    }

    float result = interQuartile(head);

    REQUIRE(result == 6.00);

    while (head != nullptr)
    {
        Node* traverser = head;
        head = head->next;
        delete traverser;
    }
}


TEST_CASE("Positive and Negative", "[IQR]")
{
    Node* head = new Node();
    head->value = -3;

    for (int i = 0; i < 5; i++)
    {
        insertEnd(head, i);
    }    

    float result = interQuartile(head);

    REQUIRE(result == 3.00);

    while(head != nullptr)
    {
        Node* traverser = head;
        head = head->next;
        delete traverser;
    }

}


// the syntax for defining a test is below. It is important for the name to be unique, 
// but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.

	// each section runs the setup code independently to ensure that they don't affect each other


// you must write 5 unique, meaningful tests for credit on the testing portion of this quiz!

// the provided tests from edugator are below. Note that you must determine the correct output for the [output_hidden] tests yourself

TEST_CASE("Function: IQR 1", "[given]") {
	std::vector<int> v = {2, 4, 4, 5, 6, 7, 8};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 3.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 2", "[given]") {
	std::vector<int> v = {1, 2, 3, 4};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 2.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}



TEST_CASE("Function: IQR 1", "[given]") {
	std::vector<int> v = {2, 4, 4, 5, 6, 7, 8};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 3.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 2", "[given]") {
	std::vector<int> v = {1, 2, 3, 4};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 2.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 3", "[output_hidden]") {
	std::vector<int> v = {1, 8, 15, 43, 82, 101, 110, 2456, 55345, 137556};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 2441.0);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 4", "[output_hidden]") {
	std::vector<int> v = {2, 4, 4, 5, 6, 7, 8, 9, 10};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 4.5);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 5", "[output_hidden]") {
	std::vector<int> v = {1, 8, 15, 43, 82, 101, 110, 2456, 55345, 137556, 137576};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 55330.0);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
