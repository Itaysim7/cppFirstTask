/**
*AUTHORS: <Itay Simhayev 205666407>
 * Date: 2020-03
 */
#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "Xxx") == string("xxx"));
    CHECK(find(text, "YyY") == string("yyy"));
}

TEST_CASE("Test replacement of p and b") {
    string text = "xxx bobi is happy yyy ";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    CHECK(find(text, "bobi") == string("bobi"));
    CHECK(find(text, "popi") == string("bobi"));
    CHECK(find(text, "pobi") == string("bobi"));
    CHECK(find(text, "bopi") == string("bobi"));
}

TEST_CASE("Test replacement of v and w") {
    string text = "Vivian wants to say wow vhen gets vanilla ice cream";
    CHECK(find(text, "vanilla") == string("vanilla"));
    CHECK(find(text, "wanilla") == string("vanilla"));
    CHECK(find(text, "vow") == string("wow"));
    CHECK(find(text, "wov") == string("wow"));
    CHECK(find(text, "vov") == string("wow"));
    CHECK(find(text, "vants") == string("wants"));
    CHECK(find(text, "wivian") == string("Vivian"));
    CHECK(find(text, "Viwian") == string("Vivian"));
    CHECK(find(text, "when") == string("vhen"));
}

TEST_CASE("Test replacement of f and p") {
    string text = "pafi frefer to forget you porever";
    CHECK(find(text, "prefer") == string("frefer"));
    CHECK(find(text, "freper") == string("frefer"));
    CHECK(find(text, "preper") == string("frefer"));
    CHECK(find(text, "porget") == string("forget"));
    CHECK(find(text, "forever") == string("porever"));
    CHECK(find(text, "porever") == string("porever"));
    CHECK(find(text, "papi") == string("pafi"));
    CHECK(find(text, "fafi") == string("pafi"));
    CHECK(find(text, "fapi") == string("pafi"));
}

TEST_CASE("Test replacement of j and g") {
    string text = "Justin giger just jive me a jift";
    CHECK(find(text, "gustin") == string("Justin"));
    CHECK(find(text, "jijer") == string("giger"));
    CHECK(find(text, "jiger") == string("giger"));
    CHECK(find(text, "gijer") == string("giger"));
    CHECK(find(text, "gust") == string("just"));
    CHECK(find(text, "give") == string("jive"));
    CHECK(find(text, "gift") == string("jift"));
}

TEST_CASE("Test replacement of c and k and q") {
    string text = "Kobi kobica give the  queen a Square caqe  ";
    CHECK(find(text, "qace") == string("caqe"));
    CHECK(find(text, "qaqe") == string("caqe"));
    CHECK(find(text, "kake") == string("caqe"));
    CHECK(find(text, "cace") == string("caqe"));
    CHECK(find(text, "kobi") == string("Kobi"));
    CHECK(find(text, "Cobi") == string("Kobi"));
    CHECK(find(text, "cueen") == string("queen"));
    CHECK(find(text, "kueen") == string("queen"));
    CHECK(find(text, "Scuare") == string("Square"));
    CHECK(find(text, "Skuare") == string("Square"));
    CHECK(find(text, "kobika") == string("kobica"));
    CHECK(find(text, "cobika") == string("kobica"));
    CHECK(find(text, "qobiqa") == string("kobica"));
    CHECK(find(text, "cobiqa") == string("kobica"));
}

TEST_CASE("Test replacement of s and z") {
    string text = "Zoi went to the zoo and saw sebra znakes and chimpanzees  ";
    CHECK(find(text, "zoi") == string("Zoi"));
    CHECK(find(text, "soi") == string("Zoi"));
    CHECK(find(text, "soo") == string("zoo"));
    CHECK(find(text, "zaw") == string("saw"));
    CHECK(find(text, "zebra") == string("sebra"));
    CHECK(find(text, "snakes") == string("znakes"));
    CHECK(find(text, "znakez") == string("znakes"));
    CHECK(find(text, "snakez") == string("znakes"));
    CHECK(find(text, "chimpanZeeS") == string("chimpanzees"));
    CHECK(find(text, "chimpanseez") == string("chimpanzees"));
    CHECK(find(text, "chimpanzeez") == string("chimpanzees"));
    CHECK(find(text, "chimpansees") == string("chimpanzees"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "David took tali on a date";
    CHECK(find(text, "daviD") == string("David"));
    CHECK(find(text, "tavid") == string("David"));
    CHECK(find(text, "Davit") == string("David"));
    CHECK(find(text, "Tavit") == string("David"));
    CHECK(find(text, "dook") == string("took"));
    CHECK(find(text, "dali") == string("tali"));
    CHECK(find(text, "tate") == string("date"));
    CHECK(find(text, "dade") == string("date"));
    CHECK(find(text, "tade") == string("date"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "Oren upup know to use outlook properly";
    CHECK(find(text, "uren") == string("Oren"));
    CHECK(find(text, "opop") == string("upup"));
    CHECK(find(text, "upop") == string("upup"));
    CHECK(find(text, "opup") == string("upup"));
    CHECK(find(text, "knuw") == string("know"));
    CHECK(find(text, "ose") == string("use"));
    CHECK(find(text, "uutluuk") == string("outlook"));
    CHECK(find(text, "ootlook") == string("outlook"));
    CHECK(find(text, "uutlook") == string("outlook"));
    CHECK(find(text, "ootluuk") == string("outlook"));
    CHECK(find(text, "uutluok") == string("outlook"));
    CHECK(find(text, "pruperly") == string("properly"));
}
TEST_CASE("Test replacement of y and i") {
    string text = "Yoni said to yasmin I love you";
    CHECK(find(text, "yoni") == string("Yoni"));
    CHECK(find(text, "ioni") == string("Yoni"));
    CHECK(find(text, "Yony") == string("Yoni"));
    CHECK(find(text, "iony") == string("Yoni"));
    CHECK(find(text, "sayd") == string("said"));
    CHECK(find(text, "YasmIn") == string("yasmin"));
    CHECK(find(text, "iasmyn") == string("yasmin"));
    CHECK(find(text, "iasmin") == string("yasmin"));
    CHECK(find(text, "yasmyn") == string("yasmin"));
    CHECK(find(text, "y") == string("I"));
    CHECK(find(text, "i") == string("I"));
    CHECK(find(text, "iou") == string("you"));
}
TEST_CASE("combain") {
    string text = "lets test combain sentence with a lot of words and complicated words like encyclopedia illumination Anaphylaxis";
    CHECK(find(text, "dezd") == string("test"));
    CHECK(find(text, "kumpayn") == string("combain"));
    CHECK(find(text, "qumfayn") == string("combain"));
    CHECK(find(text, "zendenqe") == string("sentence"));
    CHECK(find(text, "zendenke") == string("sentence"));
    CHECK(find(text, "vurtz") == string("words"));
    CHECK(find(text, "kumplyqadet") == string("complicated"));
    CHECK(find(text, "qumplykadet") == string("complicated"));
    CHECK(find(text, "enqiklupetya") == string("encyclopedia"));
    CHECK(find(text, "enkiqlufetya") == string("encyclopedia"));
    CHECK(find(text, "yllomynadyun") == string("illumination"));
    CHECK(find(text, "Anaphilaxyz") == string("Anaphylaxis"));
}
TEST_CASE("execption") {
    string text = "lets test combain sentence with a lot of words and complicated words like encyclopedia illumination Anaphylaxis";
    CHECK_THROWS(find(text, "tesb"));
    CHECK_THROWS(find(text, "combaim"));
    CHECK_THROWS(find(text, "aombaim"));
    CHECK_THROWS(find(text, "tentence"));
    CHECK_THROWS(find(text, "sentencr"));
    CHECK_THROWS(find(text, "qords"));
    CHECK_THROWS(find(text, "compticated"));
    CHECK_THROWS(find(text, "comwlicated"));
    CHECK_THROWS(find(text, "encyclopebia"));
    CHECK_THROWS(find(text, "encyclnpedia"));
    CHECK_THROWS(find(text, "rllumination"));
    CHECK_THROWS(find(text, "Anaphylavis"));
    CHECK_THROWS(find(text, ""));

}