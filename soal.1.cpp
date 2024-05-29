#include <iostream>
    #include <vector>
    #include <string>
    using namespace std;

    void strToInfix(string input){
        vector<string> infix;
        string tmp;
        int len = input.length();

        for (int i = 0; i < len; i++){        
            if (isspace(input[i])) continue;

            else if (isdigit(input[i])) tmp += input[i];

            else {
                if (!tmp.empty()){
                    infix.push_back(tmp);
                    tmp = "";
                }
                if (input[i] == '-' && (i == 0 || !isdigit(input[i - 1]))) {
                    if(input[i - 1] != ')'){
                        if (i + 1 < len && input[i + 1] == '(' ){
                            infix.push_back("-1");
                            infix.push_back("*");
                        }
                        else if(i - 1 > 0 && input[i - 1] == '*' || input[i - 1] == '/' || input[i - 1] == '%' || input[i - 1] == '+'){
                            infix.push_back("-1");
                            infix.push_back("*");
                        }
                        else if(i - 1 > 0 && input[i - 1] == '-'){
                            infix.pop_back();
                            infix.push_back("+");
                        }
                        else if(i == 0) tmp += input[i];
                        else infix.push_back(string(1, input[i]));
                    }
                } 
                else{
                    infix.push_back(string(1, input[i]));
                }
            }
        }
        if (!tmp.empty()) {
            infix.push_back(tmp);
        }
        for(auto itr = infix.begin(); itr != infix.end(); itr++){
            cout << *itr << " ";
        }
    }

    int main() {
        string input;
        vector<string> infix;
        getline(cin, input);
        strToInfix(input);
        
        return 0;
    }