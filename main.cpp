#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map <char,string> encoder_array_one = {{'a',"<⬤>"},{'b',"<⬤⬤>"},{'c',"<▲>"},{'d',"<■>"},{'e',"<⬤■>"},{'f',"<▲▲>"},{'g',"<■▲>"},{'h',"<■■>"},
        {'i',"<⬤■■>"},{'j',"<■▲▲>"},{'k',"<■▲■>"},{'l',"<■■■>"},{'m',"<■▲▲▲>"},{'n',"<■▲■▲>"},{'o',"<■■▲■>"},{'p',"<■■■■>"},{'q',"<⬤■■▲■>"},
        {'r',"<⬤■■⬤■■>"},{'s',"<■▲■▲■⬤>"},{'t',"■⬤⬤■▲▲■"},{'u',"■■▲■■⬤⬤"},{'v',"■▲■■▲■"},{'w',"▲▲■▲▲■▲■"},{'x',"■■■■■■"},
        {'y',"<▲▲■▲▲■⬤■>"},{'z',"<⬤⬤▲▲■■⬤▲■>"},{' '," "},{'0',"⎔⬤▲■⎔"},{'1',"⎔⬤⎔"},{'2',"⎔⬤⬤⎔"},{'3',"⎔▲⎔"},{'4',"⎔■⎔"},
        {'5',"⎔⬤⬤▲⎔"},{'6',"⎔▲▲⎔"},{'7',"⎔▲■⎔"},{'8',"⎔■■⎔"},{'9',"⎔⬤■■⎔"}};

    map <string,string> encoder_array_two = {{"⬤","[]"},{"▲","/_\\"},{"■","|_|_"},{" ","<>"},{"⎔","|/\\|\\/"},{"<",":"},{">",";"}};

void encode(string file_output,string file_inout, map <char,string> array)
{
    string file_txt;
    
    ofstream convert(file_output);
    ifstream input_f(file_inout);

    while(getline(input_f,file_txt))
    {
        for(char count : file_txt)
        {
            count = tolower(count);
            convert << array[count];
        }
        convert << "\n";
    }
    input_f.close();
    convert.close();
}
void output(string file_output,string file_input,map<string, string> array)
{
    string file_txt;
    ofstream convert(file_output);
    ifstream input_f(file_input);

    while (getline(input_f, file_txt)) {
        for (const auto& pair : array) {
            size_t pos = 0;
            while ((pos = file_txt.find(pair.first, pos)) != string::npos) {
                file_txt.replace(pos, pair.first.length(), pair.second);
                pos += pair.second.length();
            }
        }
        convert << file_txt << "\n";
    }

    input_f.close();
    convert.close();
}



int main()
{
    encode("convert.txt","input.txt",encoder_array_one);
    output("output.txt","convert.txt",encoder_array_two);
    return 0;
}
