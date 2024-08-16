#include<bits/stdc++.h>
using namespace std;
int main() {
    const char* source_file_std = "C:\\Users\\Administrator\\Desktop\\ACM\\Compare\\std.cpp";
    const char* output_file_std = "C:\\Users\\Administrator\\Desktop\\ACM\\Compare\\std.exe";
    string compile_command_std = std::string("g++ ") + source_file_std + " -std=c++2a -o " + output_file_std;
    system(compile_command_std.c_str());

    const char* source_file_solve = "C:\\Users\\Administrator\\Desktop\\ACM\\Compare\\solve.cpp";
    const char* output_file_solve = "C:\\Users\\Administrator\\Desktop\\ACM\\Compare\\solve.exe";
    string compile_command_solve = std::string("g++ ") + source_file_solve + " -std=c++2a -o " + output_file_solve;
    system(compile_command_solve.c_str());

    int t = 0;
    while (true) {
        cout << "test: " << t++ << '\n';
        system("python C:\\Users\\Administrator\\Desktop\\ACM\\Compare\\data.py");
        system("C:\\Users\\Administrator\\Desktop\\ACM\\Compare\\std.exe < ..\\data.in > std.out");
        system("C:\\Users\\Administrator\\Desktop\\ACM\\Compare\\solve.exe < ..\\data.in > solve.out");
        if (system("fc std.out solve.out > C:\\Users\\Administrator\\Desktop\\ACM\\Compare\\diff.log")) {
            cout << "Wrong Answer\n";
            break;
        }
        cout << "Accepted\n";
    }
}