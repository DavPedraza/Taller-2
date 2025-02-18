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

string encryptOrDecrypt(string line);
void testEncryptOrDecrypt();
void decryptEntireMessage();
int main() {

    testEncryptOrDecrypt();
    decryptEntireMessage();
    return 0;
}

string encryptOrDecrypt(string line) {
    string encrypted = ""; 
    for (int i = 0; i < line.length(); i++) {
        char c = line[i];
        if (c >= 'a' && c <= 'z') {  
            encrypted += 'z' - (c - 'a');
        } 
        else if (c >= 'A' && c <= 'Z') {  
            encrypted += 'Z' - (c - 'A');
        } 
        else {  
            encrypted += c;
        }
    }
    return encrypted;
}
void testEncryptOrDecrypt() {

    cout << "===Checking first function: Encrypt or decrypt string===" << endl;

    cout << "-Case 1: encrypting string with spaces" << endl;
    cout << "--Case 1.1: encrypting letters of lowercase alphabet" << endl;

    string lineCase1Test1 = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
    string expectedCase1Test1 = "z y x w v u t s r q p o n m l k j i h g f e d c b a";
    string resultCase1Test1 = encryptOrDecrypt(lineCase1Test1);
    string errorMsgCase1Test1 = "Case 1 failed \n Expected: " + expectedCase1Test1 + " but got: " + resultCase1Test1 + "\n";

    bool lineWasNotModified = lineCase1Test1 == "a b c d e f g h i j k l m n o p q r s t u v w x y z";
    bool resultIsCorrect = resultCase1Test1 == expectedCase1Test1;

    ASSERT_WITH_MSG(lineWasNotModified, "The original line was modified\n");
    ASSERT_WITH_MSG(resultIsCorrect, errorMsgCase1Test1);

    cout << "--Case 1.2: encrypting letters of uppercase alphabet" << endl;

    string lineCase1Test2 = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    string expectedCase1Test2 = "Z Y X W V U T S R Q P O N M L K J I H G F E D C B A";
    string resultCase1Test2 = encryptOrDecrypt(lineCase1Test2);
    string errorMsgCase1Test2 = "Case 1 failed \n Expected: " + expectedCase1Test2 + " but got: " + resultCase1Test2 + "\n";

    bool lineWasNotModifiedCase1Test2 = lineCase1Test2 == "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";

    ASSERT_WITH_MSG(lineWasNotModifiedCase1Test2, "The original line was modified\n");
    ASSERT_WITH_MSG(resultCase1Test2 == expectedCase1Test2, errorMsgCase1Test2);

    cout << endl<<endl;
    cout << "-Case 2: encrypting string with numbers" << endl;

    string lineCase2Test1 = "1 2 3 4 5 6 7 8 9 0";
    string expectedCase2Test1 = "1 2 3 4 5 6 7 8 9 0";
    string resultCase2Test1 = encryptOrDecrypt(lineCase2Test1);
    string errorMsgCase2Test1 = "Case 2 failed \n Expected: " + expectedCase2Test1 + " but got: " + resultCase2Test1 + "\n";

    ASSERT_WITH_MSG(resultCase2Test1 == expectedCase2Test1, errorMsgCase2Test1);

    cout << endl<<endl;
}

void decryptEntireMessage() {
    cout << "===Last check: Decrypt entire message===" << endl;
    cout << "If your code is correct, you should see a message in spanish" << endl;

    List<string> lines;

    lines.add("Ol kvli jfv kfvwvh szxvi vh xvmgizigv vm oz mvtzgrerwzw.");
    lines.add("Ml gv hzoeziá wv oz kirhróm jfv vh oz nfvigv, wvo wloli wv ozh vmuvinvwzwvh, wv oz xifvowzw wvo grvnkl, wvo uiíl xzkzizaóm wv oz mzgfizovaz sfnzmz l wv oz kéiwrwz wv glwl ol jfv fmz eva gferhgv, jfvirwl.");
    lines.add("Sztzh ol jfv sztzh, ¡ml gv xvmgivh vm vhl!");
    lines.add("Xzhr hrvnkiv, vo kilyovnz ml vh jfv olh kilyovnzh z olh jfv mlh vmuivmgznlh ml gvmtzm hlofxróm");
    lines.add("Vo kilyovnz vh jfv gvmvnlh gzmgl nrvwl z uzoozi jfv mlh mvtznlh z evi mfvhgilh kilyovnzh wvhwv lgiz kvihkvxgrez.");
    lines.add("B vmglmxvh szxvnlh ol nrhnl fmz b lgiz, b lgiz eva.");
    lines.add("B xozil vhgá jfv, kli vhl, vmxlmgiznlh vo uzool jfv vhgáyznlh yfhxzmwl.");
    lines.add("Gf erwz hrvnkiv hviá fmz ofxsz b hrvnkiv gvmwiáh kilyovnzh.");
    lines.add("Kvil slb, szh gvmrwl oz lkligfmrwzw wv evi ozh xlhzh wv fm nlwl wrhgrmgl.");
    lines.add("Rmxofhl hr vhl hrtmrurxz vmuivmgzigv z lyhgáxfolh jfv zo kirmxrkrl kzivxízm rnklhryovh; kvmhzhgv wvhwv lgiz kvihkvxgrez b olh hfkvizhgv.");
    lines.add("Klijfv erhgv ozh xlhzh wvhwv fm ámtfol wruvivmgv, ozh vmgvmwrhgv kli ol jfv ivzonvmgv vizm.");
    lines.add("Klijfv hvtfrhgv nlerémwlgv szxrz zwvozmgv, hrm rnkligzi xfámgl gv zovqzizh wvo xznrml jfv hv gv liwvmó hvtfri l xfám rnkiverhryov hv eloerviz...");
    lines.add("Vmxlmgizhgv gf xznrml.");

    for (int i = 0; i < lines.size; i++) {
        string line = lines.get(i);
        string decryptedLine = encryptOrDecrypt(line);
        cout << decryptedLine << endl;
    }
    
}