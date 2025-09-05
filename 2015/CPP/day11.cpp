#include <iostream>
#include <string>

/* -- Lessons learnt --
 * Functions are good
 * No premature optimisations
 * Clear code is much nicer than fast code when developing, optimise later
 * i<=string.length() and not i>=string.length()
 * Do not develop everything at once develop in parts
 * Abstractions are good
 */

std::string& operator++(std::string& s)
{
    bool carry = true;
    for(std::string::reverse_iterator back = s.rbegin();
        carry && (back != s.rend()); back++) {
        if(*back == 'z') {
            *back = 'a';
        } else {
            ++(*back);
            carry = false;
        }
    }
    return s;
}

bool does_not_satisfies_conditions(const std::string& s)
{
    bool c1 = true, c2 = true, c3 = true, c4 = true;
    int  iol {0};
    char already_seen {};

    for(int i = 0; i <= s.length(); ++i) {
        if(s[i] == 'i' || s[i] == 'o' || s[i] == 'l') {
            ++iol;
        }
    }

    if(iol == 0) {
        c1 = false;
    }

    for(int i = 1; i <= s.length(); ++i) {
        if(!abs(s[i - 1] - s[i]) && already_seen != s[i - 1]) {
            if(!c2) {
                c3           = false;
                already_seen = s[i - 1];
            } else {
                c2           = false;
                already_seen = s[i - 1];
            }
        }
    }

    for(int i = 2; i <= s.length(); ++i) {
        int diff1 = s[i - 1] - s[i - 2], diff2 = s[i] - s[i - 1];

        if(diff1 == 1 && diff2 == 1) {
            c4 = false;
        }
    }

    return c1 | c2 | c3 | c4;
}

int main()
{
    std::string input_string("cqjxxyzz");
    bool        next_string {true};
    while(next_string) {
        ++input_string;
        next_string = does_not_satisfies_conditions(input_string);
    }
    std::cout << input_string << "\n";
}
