/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Shahar Engel 318511375
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;

family::Tree T ("Yosef");

// TEST_CASE("Test addFather") {
//     CHECK((T.addFather("Yosef", "Yaakov")).compare("Happi"));
// }

// TEST_CASE("Test addMother") {
//     CHECK((T.addMother("Yosef", "Yaakov")).compare("Happi"));
// }

TEST_CASE("Test relation") {
    CHECK((T.relation("Yaakov")).compare("father"));
    CHECK((T.relation("Rachel")).compare("mother"));
    CHECK((T.relation("Rivka")).compare("grandmother"));
    CHECK((T.relation("Avraham")).compare("great-grandfather"));
    CHECK((T.relation("Terah")).compare("great-great-grandfather"));
    CHECK((T.relation("Yosef")).compare("me"));
    CHECK((T.relation("Isaac")).compare("grandfather"));
    CHECK((T.relation("Sara")).compare("great-grandmother"));
}

TEST_CASE("Test find") {
    CHECK((T.find("father")).compare("Yaakov"));
    CHECK((T.find("mother")).compare("Rachel"));
    CHECK((T.find("grandmother")).compare("Rivka"));
    CHECK((T.find("great-grandfather")).compare("Avraham"));
    CHECK((T.find("great-great-grandfather")).compare("Terah"));
    CHECK((T.find("me")).compare("Yosef"));
    CHECK((T.find("grandfather")).compare("Isaac"));
    CHECK((T.find("great-grandmother")).compare("Sara"));
}

// TEST_CASE("Test display") {
//     CHECK((T.addFather("Yosef", "Yaakov")).compare("Happi"));
// }

// TEST_CASE("Test remove") {
//     CHECK((T.addFather("Yosef", "Yaakov")).compare("Happi"));
// }