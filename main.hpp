/*
 * Copyright (c) 2015 Richard B Tilley <brad@w8rbt.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * main.hpp - List of virtual key-codes
 * http://msdn.microsoft.com/en-us/library/dd375731(VS.85).aspx
 *
 */


#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include <windows.h>


std::map<std::int16_t, std::vector<std::string> > vk()
{
        std::map<std::int16_t, std::vector<std::string> > k;

        std::vector<std::string> k1(2, " lmouse");
        std::vector<std::string> k2(2, " rmouse");
        std::vector<std::string> k4(2, " mmouse");
        std::vector<std::string> k8(2, " backspace");
        std::vector<std::string> k9(2, " tab");

        k[VK_LBUTTON] = k1; // 0x01
        k[VK_RBUTTON] = k2; // 0x02
        k[VK_MBUTTON] = k4; // 0x04
        k[VK_BACK]    = k8;// 0x08
        k[VK_TAB]     = k9;// 0x09

        std::vector<std::string> k12;
        k12.push_back(" clear");
        k12.push_back(" CLEAR");
        k[VK_CLEAR] = k12; // 0x0c

        std::vector<std::string> k13;
        k13.push_back(" enter");
        k13.push_back(" ENTER");
        k[VK_RETURN] = k13; // 0x0d

        std::vector<std::string> k16;
        k16.push_back(" shift");
        k16.push_back(" SHIFT");
        k[VK_SHIFT] = k16; // 0x10

        std::vector<std::string> k17;
        k17.push_back(" ctrl");
        k17.push_back(" CTRL");
        k[VK_CONTROL] = k17; // 0x11

        std::vector<std::string> k18;
        k18.push_back(" alt");
        k18.push_back(" ALT");
        k[VK_MENU] = k18; // 0x12

        std::vector<std::string> k19;
        k19.push_back(" pause");
        k19.push_back(" PAUSE");
        k[VK_PAUSE] = k19; // 0x13

        std::vector<std::string> k20;
        k20.push_back(" caps");
        k20.push_back(" CAPS");
        k[VK_CAPITAL] = k20; //0x14

        std::vector<std::string> k27;
        k27.push_back(" esc");
        k27.push_back(" ESC");
        k[VK_ESCAPE] = k27; // 0x1B

        std::vector<std::string> k32;
        k32.push_back(" space");
        k32.push_back(" SPACE");
        k[VK_SPACE] = k32; //0x20

        std::vector<std::string> k33;
        k33.push_back(" pageup");
        k33.push_back(" PAGEUP");
        k[VK_PRIOR] = k33; //0x21

        std::vector<std::string> k34;
        k34.push_back(" pagedown");
        k34.push_back(" PAGEDOWN");
        k[VK_NEXT] = k34; //0x22

        std::vector<std::string> k35;
        k35.push_back(" end");
        k35.push_back(" END");
        k[VK_END] = k35; //0x23

        std::vector<std::string> k36;
        k36.push_back(" home");
        k36.push_back(" HOME");
        k[VK_HOME] = k36; //0x24

        std::vector<std::string> k37;
        k37.push_back(" leftarrow");
        k37.push_back(" LEFTARROW");
        k[VK_LEFT] = k37; //0x25

        std::vector<std::string> k38;
        k38.push_back(" uparrow");
        k38.push_back(" UPARROW");
        k[VK_UP] = k38; //0x26

        std::vector<std::string> k39;
        k39.push_back(" rightarrow");
        k39.push_back(" RIGHTARROW");
        k[VK_RIGHT] = k39; //0x27

        std::vector<std::string> k40;
        k40.push_back(" downarrow");
        k40.push_back(" DOWNARROW");
        k[VK_DOWN] = k40; //0x28

        std::vector<std::string> k41;
        k41.push_back(" select");
        k41.push_back(" SELECT");
        k[VK_SELECT] = k41; //0x29

        std::vector<std::string> k42;
        k42.push_back(" print");
        k42.push_back(" PRINT");
        k[VK_PRINT] = k42; //0x2a

        std::vector<std::string> k43;
        k43.push_back(" execute");
        k43.push_back(" EXECUTE");
        k[VK_EXECUTE] = k43; //0x2b

        std::vector<std::string> k44;
        k44.push_back(" printscreen");
        k44.push_back(" PRINTSCREEN");
        k[VK_SNAPSHOT] = k44; //0x2c

        std::vector<std::string> k45;
        k45.push_back(" insert");
        k45.push_back(" INSERT");
        k[VK_INSERT] = k45; //0x2d

        std::vector<std::string> k46;
        k46.push_back(" del");
        k46.push_back(" DEL");
        k[VK_DELETE] = k46; //0x2e

        std::vector<std::string> k47;
        k47.push_back(" help");
        k47.push_back(" HELP");
        k[VK_HELP] = k47; //0x2f

        std::vector<std::string> k48;
        k48.push_back("0");
        k48.push_back(")");
        k[48] = k48; // 0x30

        std::vector<std::string> k49;
        k49.push_back("1");
        k49.push_back("!");
        k[49] = k49; // 0x31

        std::vector<std::string> k50;
        k50.push_back("2");
        k50.push_back("@");
        k[50] = k50; // 0x32

        std::vector<std::string> k51;
        k51.push_back("3");
        k51.push_back("#");
        k[51] = k51;

        std::vector<std::string> k52;
        k52.push_back("4");
        k52.push_back("$");
        k[52] = k52;

        std::vector<std::string> k53;
        k53.push_back("5");
        k53.push_back("%");
        k[53] = k53;

        std::vector<std::string> k54;
        k54.push_back("6");
        k54.push_back("^");
        k[54] = k54;

        std::vector<std::string> k55;
        k55.push_back("7");
        k55.push_back("&");
        k[55] = k55;

        std::vector<std::string> k56;
        k56.push_back("8");
        k56.push_back("*");
        k[56] = k56;

        std::vector<std::string> k57;
        k57.push_back("9");
        k57.push_back("(");
        k[57] = k57; //0x39

        std::vector<std::string> k65;
        k65.push_back("a");
        k65.push_back("A");
        k[65] = k65; //0x41

        std::vector<std::string> k66;
        k66.push_back("b");
        k66.push_back("B");
        k[66] = k66;

        std::vector<std::string> k67;
        k67.push_back("c");
        k67.push_back("C");
        k[67] = k67;

        std::vector<std::string> k68;
        k68.push_back("d");
        k68.push_back("D");
        k[68] = k68;

        std::vector<std::string> k69;
        k69.push_back("e");
        k69.push_back("E");
        k[69] = k69;

        std::vector<std::string> k70;
        k70.push_back("f");
        k70.push_back("F");
        k[70] = k70;

        std::vector<std::string> k71;
        k71.push_back("g");
        k71.push_back("G");
        k[71] = k71; //0x47

        std::vector<std::string> k72;
        k72.push_back("h");
        k72.push_back("H");
        k[72] = k72;

        std::vector<std::string> k73;
        k73.push_back("i");
        k73.push_back("I");
        k[73] = k73;

        std::vector<std::string> k74;
        k74.push_back("j");
        k74.push_back("J");
        k[74] = k74;

        std::vector<std::string> k75;
        k75.push_back("k");
        k75.push_back("K");
        k[75] = k75;

        std::vector<std::string> k76;
        k76.push_back("l");
        k76.push_back("L");
        k[76] = k76;

        std::vector<std::string> k77;
        k77.push_back("m");
        k77.push_back("M");
        k[77] = k77;

        std::vector<std::string> k78;
        k78.push_back("n");
        k78.push_back("N");
        k[78] = k78;

        std::vector<std::string> k79;
        k79.push_back("o");
        k79.push_back("O");
        k[79] = k79;

        std::vector<std::string> k80;
        k80.push_back("p");
        k80.push_back("P");
        k[80] = k80;

        std::vector<std::string> k81;
        k81.push_back("q");
        k81.push_back("Q");
        k[81] = k81;

        std::vector<std::string> k82;
        k82.push_back("r");
        k82.push_back("R");
        k[82] = k82;

        std::vector<std::string> k83;
        k83.push_back("s");
        k83.push_back("S");
        k[83] = k83;

        std::vector<std::string> k84;
        k84.push_back("t");
        k84.push_back("T");
        k[84] = k84;

        std::vector<std::string> k85;
        k85.push_back("u");
        k85.push_back("U");
        k[85] = k85;

        std::vector<std::string> k86;
        k86.push_back("v");
        k86.push_back("V");
        k[86] = k86;

        std::vector<std::string> k87;
        k87.push_back("w");
        k87.push_back("W");
        k[87] = k87;

        std::vector<std::string> k88;
        k88.push_back("x");
        k88.push_back("X");
        k[88] = k88;

        std::vector<std::string> k89;
        k89.push_back("y");
        k89.push_back("Y");
        k[89] = k89;

        std::vector<std::string> k90;
        k90.push_back("z");
        k90.push_back("Z");
        k[0x5A] = k90; //0x5A

        std::vector<std::string> k91;
        k91.push_back(" lwin");
        k91.push_back(" LWIN");
        k[0x5b] = k91; //0x5b

        std::vector<std::string> k92;
        k92.push_back(" rwin");
        k92.push_back(" RWIN");
        k[0x5c] = k92; //0x5c

        // The numeric key pad
        std::vector<std::string> k96(2, "0");
        std::vector<std::string> k97(2, "1");
        std::vector<std::string> k98(2, "2");
        std::vector<std::string> k99(2, "3");
        std::vector<std::string> k100(2, "4");
        std::vector<std::string> k101(2, "5");
        std::vector<std::string> k102(2, "6");
        std::vector<std::string> k103(2, "7");
        std::vector<std::string> k104(2, "8");
        std::vector<std::string> k105(2, "9");
        std::vector<std::string> k106(2, "*");
        std::vector<std::string> k107(2, "+");
        std::vector<std::string> k108(2, " separator_key");
        std::vector<std::string> k109(2, "-");
        std::vector<std::string> k110(2, ".");
        std::vector<std::string> k111(2, "/");

        k[VK_NUMPAD0] = k96;
        k[VK_NUMPAD1] = k97;
        k[VK_NUMPAD2] = k98;
        k[VK_NUMPAD3] = k99;
        k[VK_NUMPAD4] = k100;
        k[VK_NUMPAD5] = k101;
        k[VK_NUMPAD6] = k102;
        k[VK_NUMPAD7] = k103;
        k[VK_NUMPAD8] = k104;
        k[VK_NUMPAD9] = k105;
        k[VK_MULTIPLY] = k106;
        k[VK_ADD]      = k107;
        k[VK_SEPARATOR] = k108;
        k[VK_SUBTRACT]  = k109;
        k[VK_DECIMAL]   = k110;
        k[VK_DIVIDE]    = k111;

        std::vector<std::string> k112;
        k112.push_back(" f1");
        k112.push_back(" F1");
        k[VK_F1] = k112; // 0x70

        std::vector<std::string> k113;
        k113.push_back(" f2");
        k113.push_back(" F2");
        k[VK_F2] = k113; // 0x71

        std::vector<std::string> k114;
        k114.push_back(" f3");
        k114.push_back(" F3");
        k[VK_F3] = k114; // 0x72

        std::vector<std::string> k115;
        k115.push_back(" f4");
        k115.push_back(" F4");
        k[VK_F4] = k115; // 0x73

        std::vector<std::string> k116;
        k116.push_back(" f5");
        k116.push_back(" F5");
        k[VK_F5] = k116; // 0x74

        std::vector<std::string> k117;
        k117.push_back(" f6");
        k117.push_back(" F6");
        k[VK_F6] = k117; // 0x75

        std::vector<std::string> k118;
        k118.push_back(" f7");
        k118.push_back(" F7");
        k[VK_F7] = k118; // 0x76

        std::vector<std::string> k119;
        k119.push_back(" f8");
        k119.push_back(" F8");
        k[VK_F8] = k119; // 0x77

        std::vector<std::string> k144;
        k144.push_back(" numlock");
        k144.push_back(" NUMLOCK");
        k[VK_NUMLOCK] = k144; // 0x90

        std::vector<std::string> k186;
        k186.push_back(";");
        k186.push_back(":");
        k[VK_OEM_1] = k186;

        std::vector<std::string> k187;
        k187.push_back("=");
        k187.push_back("+");
        k[187] = k187;

        std::vector<std::string> k188;
        k188.push_back(",");
        k188.push_back("<");
        k[188] = k188;

        std::vector<std::string> k189;
        k189.push_back("-");
        k189.push_back("_");
        k[189] = k189;

        std::vector<std::string> k190;
        k190.push_back(".");
        k190.push_back(">");
        k[190] = k190;

        std::vector<std::string> k191;
        k191.push_back("/");
        k191.push_back("?");
        k[VK_OEM_2] = k191; //0xBF

        std::vector<std::string> k192;
        k192.push_back("`");
        k192.push_back("~");
        k[VK_OEM_3] = k192;

        std::vector<std::string> k219;
        k219.push_back("[");
        k219.push_back("{");
        k[VK_OEM_4] = k219;

        std::vector<std::string> k220;
        k220.push_back("\\");
        k220.push_back("pipe");
        k[VK_OEM_5] = k220;

        std::vector<std::string> k221;
        k221.push_back("]");
        k221.push_back("}");
        k[VK_OEM_6] = k221;

        std::vector<std::string> k222;
        k222.push_back("'");
        k222.push_back("\"");
        k[VK_OEM_7] = k222; //0xDE

        return k;
}
