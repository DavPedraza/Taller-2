#include <iostream>
#include <cassert>
#include <string>
#include <sstream>

#define ASSERT_WITH_MSG(cond, msg) do \
{ if (!(cond)) { std::ostringstream str; str << msg; std::cerr << str.str(); } \
 else { std::ostringstream str; str << "Test passed "; std::cout << str.str(); } \
} while(0)

#include "../libs/List.h"

using namespace std;

List<string> split(string line, char delimiter);
void testSplit();
int main() {

    testSplit();
    return 0;
}

List<string> split(string line, char delimiter) {
    List<string> tokens;
    for(int i = 0; i < line.size(); i++) {
        string token = "";
        while(i < line.size() && line[i] != delimiter) {
            token += line[i];
            i++;
        }
        tokens.add(token);
    }
    //TODO: Implement this function to split a string into a list of string tokens
    return tokens;
}

void testSplit() {

    cout << "===Checking first function: Split string into tokens===" << endl;

    cout << "---Case 1: splitting string with spaces" << endl;
    cout << "--Case 1.1: splitting letters of lowercase alphabet" << endl;

    string lineCase1Test1 = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
    List<string> expectedCase1Test1;
    expectedCase1Test1.add("a");
    expectedCase1Test1.add("b");
    expectedCase1Test1.add("c");
    expectedCase1Test1.add("d");
    expectedCase1Test1.add("e");
    expectedCase1Test1.add("f");
    expectedCase1Test1.add("g");
    expectedCase1Test1.add("h");
    expectedCase1Test1.add("i");
    expectedCase1Test1.add("j");
    expectedCase1Test1.add("k");
    expectedCase1Test1.add("l");
    expectedCase1Test1.add("m");
    expectedCase1Test1.add("n");
    expectedCase1Test1.add("o");
    expectedCase1Test1.add("p");
    expectedCase1Test1.add("q");
    expectedCase1Test1.add("r");
    expectedCase1Test1.add("s");
    expectedCase1Test1.add("t");
    expectedCase1Test1.add("u");
    expectedCase1Test1.add("v");
    expectedCase1Test1.add("w");
    expectedCase1Test1.add("x");
    expectedCase1Test1.add("y");
    expectedCase1Test1.add("z");

    List<string> resultCase1Test1 = split(lineCase1Test1, ' ');
    string errorMsgCase1Test1 = "Case 1 failed \n Expected: " + expectedCase1Test1.toString() + " but got: " + resultCase1Test1.toString() + "\n";

    ASSERT_WITH_MSG(resultCase1Test1 == expectedCase1Test1, errorMsgCase1Test1);
    cout << endl;
    cout << "--Case 1.2: splitting letters of csv file" << endl;

    string lineCase1Test2 = "1,2,3,4,5,6,7,8,9,0";

    List<string> expectedCase1Test2;
    expectedCase1Test2.add("1");
    expectedCase1Test2.add("2");
    expectedCase1Test2.add("3");
    expectedCase1Test2.add("4");
    expectedCase1Test2.add("5");
    expectedCase1Test2.add("6");
    expectedCase1Test2.add("7");
    expectedCase1Test2.add("8");
    expectedCase1Test2.add("9");
    expectedCase1Test2.add("0");

    List<string> resultCase1Test2 = split(lineCase1Test2, ',');
    string errorMsgCase1Test2 = "Case 1 failed \n Expected: " + expectedCase1Test2.toString() + " but got: " + resultCase1Test2.toString() + "\n";

    ASSERT_WITH_MSG(resultCase1Test2 == expectedCase1Test2, errorMsgCase1Test2);
    

}

