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

TEST_CASE("Test addFather") {
    T.addFather("Yosef", "Yaakov");
    CHECK((T.relation("Yaakov")).compare("father"));
	T.addFather("Yaakov", "Isaac");
    CHECK((T.relation("Isaac")).compare("grandfather"));
	T.addFather("Isaac", "Avraham");
    CHECK((T.relation("Avraham")).compare("great-grandfather"));
	T.addFather("Avraham", "Terah");
    CHECK((T.relation("Terah")).compare("great-great-grandfather"));
    T.addFather("Yosef", "David");
    CHECK_THROWS_AS(T.relation("David"), std::exception);
    CHECK_THROWS_AS(T.addFather("", "Yosef"), std::exception);
    CHECK_THROWS_AS(T.addFather("Terach", " "), std::exception);
    CHECK_THROWS_AS(T.addFather(" ",""), std::exception);
    CHECK_THROWS_AS(T.addFather("AAA","A"), std::exception);
    CHECK_THROWS_AS(T.addFather("terah", "Betuel"), std::exception);
}

TEST_CASE("Test addMother") {
    T.addMother("Yosef", "Rachel");
    CHECK((T.relation("Rachel")).compare("mother"));
    T.addMother("Yaakov", "Rivka");
    CHECK((T.relation("Rivka")).compare("grandmother"));
    T.addMother("Isaac", "Sara");
    CHECK((T.relation("Sara")).compare("great-grandmother"));
    T.addMother("Yaakov", "Lea");
    CHECK_THROWS_AS(T.relation("Lea"), std::exception);
    CHECK_THROWS_AS(T.addMother("", "Lea"), std::exception);
    CHECK_THROWS_AS(T.addMother("Sara", " "), std::exception);
    CHECK_THROWS_AS(T.addMother(" ",""), std::exception);
    CHECK_THROWS_AS(T.addMother("AAA",""), std::exception);
    CHECK_THROWS_AS(T.addMother("sara", "Milka"), std::exception);
    CHECK_THROWS_AS(T.addMother("Lea", "Milka"), std::exception);
}

TEST_CASE("Test relation") {
    CHECK((T.relation("Yaakov")).compare("father"));
    CHECK((T.relation("Rachel")).compare("mother"));
    CHECK((T.relation("Rivka")).compare("grandmother"));
    CHECK((T.relation("Avraham")).compare("great-grandfather"));
    CHECK((T.relation("Terah")).compare("great-great-grandfather"));
    CHECK((T.relation("Yosef")).compare("me"));
    CHECK((T.relation("Isaac")).compare("grandfather"));
    CHECK((T.relation("Sara")).compare("great-grandmother"));
    CHECK_THROWS_AS(T.relation("Milka"), std::exception);
    CHECK_THROWS_AS(T.relation(""), std::exception);
    CHECK_THROWS_AS(T.relation(" "), std::exception);
    CHECK_THROWS_AS(T.relation("David"), std::exception);
    CHECK_THROWS_AS(T.relation("yosef"), std::exception);
    CHECK_THROWS_AS(T.relation("Milka"), std::exception);
    CHECK_THROWS_AS(T.relation("mother"), std::exception);
    CHECK_THROWS_AS(T.relation("isaAc"), std::exception);
    T.addFather("Rivka", "Betuel");
    CHECK((T.relation("Rivka")).compare("great-grandfather"));
    CHECK_THROWS_AS(T.relation("Lavan"), std::exception);

}

TEST_CASE("Test find") {
    CHECK((T.find("father")).compare("Yaakov"));
    CHECK((T.find("mother")).compare("Rachel"));
    CHECK((T.find("grandmother")).compare("Rivka"));
    CHECK(((T.find("great-grandfather")).compare("Avraham") || (T.find("great-grandfather")).compare("Betuel")));
    CHECK((T.find("great-great-grandfather")).compare("Terah"));
    CHECK((T.find("me")).compare("Yosef"));
    CHECK((T.find("grandfather")).compare("Isaac"));
    CHECK((T.find("great-grandmother")).compare("Sara"));
    CHECK_THROWS_AS(T.find("Mother"), std::exception);
    CHECK_THROWS_AS(T.find(""), std::exception);
    CHECK_THROWS_AS(T.find(" "), std::exception);
    CHECK_THROWS_AS(T.find("greatgrandfather"), std::exception);
    CHECK_THROWS_AS(T.find("great grandfather"), std::exception);
    CHECK_THROWS_AS(T.find("great-njfg-grandfather"), std::exception);
    CHECK_THROWS_AS(T.find("great-great-father"), std::exception);
    CHECK_THROWS_AS(T.find("Yosef"), std::exception);
    CHECK_THROWS_AS(T.find("great-great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(T.find("uncle"), std::exception);
    CHECK_THROWS_AS(T.find("child"), std::exception);
    CHECK_THROWS_AS(T.find("motHer"), std::exception); 
}

TEST_CASE("Test remove") {
    T.remove("Terah");
    CHECK_THROWS_AS(T.relation("Terah"), std::exception);
    CHECK_THROWS_AS(T.find("great-great-grandfather"), std::exception);
    T.remove("Avraham");
    CHECK_THROWS_AS(T.relation("Avraham"), std::exception);
    T.remove("Sara");
    CHECK_THROWS_AS(T.relation("Sara"), std::exception);
    CHECK_THROWS_AS(T.find("great-grandmother"), std::exception);
    T.remove("Rivka");
    CHECK_THROWS_AS(T.relation("Rivka"), std::exception);
    CHECK_THROWS_AS(T.relation("Betuel"), std::exception);
    CHECK_THROWS_AS(T.find("grandmother"), std::exception);
    CHECK_THROWS_AS(T.find("great-grandfather"), std::exception);
    T.remove("Isaac");
    CHECK_THROWS_AS(T.relation("Isaac"), std::exception);
    CHECK_THROWS_AS(T.find("grandfather"), std::exception);
    T.remove("Yaakov");
    CHECK_THROWS_AS(T.relation("Yaakov"), std::exception);
    CHECK_THROWS_AS(T.find("father"), std::exception);
    T.remove("Rachel");
    CHECK_THROWS_AS(T.relation("Rachel"), std::exception);
    CHECK_THROWS_AS(T.find("mother"), std::exception);
    CHECK_THROWS_AS(T.remove("Rachel"), std::exception);
    CHECK_THROWS_AS(T.remove(""), std::exception);
    CHECK_THROWS_AS(T.remove(" "), std::exception);
    CHECK_THROWS_AS(T.remove("yosef"), std::exception);
    T.addFather("Yosef", "Yaakov");
    CHECK_THROWS_AS(T.remove("yaaKov"), std::exception);
    CHECK_THROWS_AS(T.remove("mother"), std::exception);
    T.remove("Yaakov");
    CHECK_THROWS_AS(T.relation("Yaakov"), std::exception);
    CHECK_THROWS_AS(T.find("father"), std::exception);
}

TEST_CASE("Test find") {
    CHECK((T.find("father")).compare("Yaakov"));
    CHECK((T.find("mother")).compare("Rachel"));
    CHECK((T.find("grandmother")).compare("Rivka"));
    CHECK(((T.find("great-grandfather")).compare("Avraham") || (T.find("great-grandfather")).compare("Betuel")));
    CHECK((T.find("great-great-grandfather")).compare("Terah"));
    CHECK((T.find("me")).compare("Yosef"));
    CHECK((T.find("grandfather")).compare("Isaac"));
    CHECK((T.find("great-grandmother")).compare("Sara"));
    CHECK_THROWS_AS(T.find("Mother"), std::exception);
    CHECK_THROWS_AS(T.find(""), std::exception);
    CHECK_THROWS_AS(T.find(" "), std::exception);
    CHECK_THROWS_AS(T.find("greatgrandfather"), std::exception);
    CHECK_THROWS_AS(T.find("great grandfather"), std::exception);
    CHECK_THROWS_AS(T.find("great-njfg-grandfather"), std::exception);
    CHECK_THROWS_AS(T.find("great-great-father"), std::exception);
    CHECK_THROWS_AS(T.find("Yosef"), std::exception);
    CHECK_THROWS_AS(T.find("great-great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(T.find("uncle"), std::exception);
    CHECK_THROWS_AS(T.find("child"), std::exception);
    CHECK_THROWS_AS(T.find("motHer"), std::exception); 
}