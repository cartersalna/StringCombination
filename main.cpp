#include <iostream>
#include <string>
#include <vector>


//created a separate function for when testing overlaps with greater sizes
int OverlapNumberWhenSizeIsThreeOrMore(std::string s1, std::string s2) { 
    if ((s1.at(s1.size() - 1) == s2.at(0)) && (s1.at(s1.size() - 2) != s2.at(1))) {
        return 1;
    }
    else if (s1.substr(s1.size() - 2, 2) == s2.substr(0, 2)) {
       return 2;
    }
    else if (s1.substr(s1.size() - 3, 4) == s2.substr(0, 3)) {
        return 3;
    }
    else if(s1.size() == 3 || s2.size() == 3) {
        return 0;
    }
    else if(s1.substr(s1.size() - 4, 5) == s2.substr(0, 4)) {
        return 4;
    }
    else if (s1.size() == 4 || s2.size() == 4){
        return 0;
    }
    else if(s1.substr(s1.size() - 5, 5) == s2.substr(0, 5)) {
        return 5;
    }
    else if(s1.at(s1.size() - 1) == s2.at(0)) {
        return 1;
    }
    else {
        return 0;
    }
}
//basic function to return the number of overlapping characters between two words
int NumberOfCharactersOverlap(std::string const &s1, std::string const &s2) 
{
    int temp = 0;
    //if everything is the same, just return the string
    if (s1 == s2) {
        temp = s1.size();
        return temp;
    }
    //if both have zero size for whatever reason, return 0
    if (s1.size() == 0 || s2.size() == 0) {
        return 0;
    }
    //testing specifically when size 1 to avoid out of range errors
    else if (s1.size() == 1 || s2.size() == 1) {
        if (s1.at(s1.size() - 1) == s2.at(0)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (s1.size() == 2 || s2.size() == 2) { //if size is 2
        if (s1.substr(s1.size() - 2, 2) == s2.substr(0, 2)) {
            return 2;
        }
        else if(s1.at(s1.size() - 1) == s2.at(0)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        temp = OverlapNumberWhenSizeIsThreeOrMore(s1, s2); //call sister function to help out
        return temp;
    } 
}
//function to combine words
std::string CombineWords(std::string string1, std::string string2, int number) {   
    if (string1 == string2) { //if the strings are identical, just return one of them
        return string1; 
    }
    string1.replace(string1.size() - number, number, ""); //replace the end of the first string with nothing
    std::string sum_s = "";
    sum_s = string1 + string2; // add the full second to the edited first one 
    return sum_s;
}
//function that calculates the amount of words in a sentence
int NumberOfWords(std::string sentence) {
    int size = sentence.size();
    int num_of_spaces = 0;
    int count = 0;
    while (size != count) {
        if (sentence.at(count) == ' ') {
            num_of_spaces = num_of_spaces + 1;
        }
        count = count + 1;
    }
    return (num_of_spaces + 1); // if the number of spaces is always one less than the number of words

}
std::string TurnSentenceIntoWord(std::string str, int wordPlace) {
    int size = str.size(); //get size of string
    int count = 0;
    int space_location = 0; //initalize last space to first char
    int num_of_spaces = 0; //count spaces starting from 0
    std::string temp_s = "";
    while (1) {
        if (count == size - 1) { //to prevent outside of range error
            break;
        }
        if(str.at(count) == ' ')  { //scans the string for spaces
            temp_s = str.substr(space_location, count - space_location);
            num_of_spaces = num_of_spaces + 1;
            space_location = count; 
            if (num_of_spaces == wordPlace) { 
                //if the num of spaces matches the word place, i have the word
                return temp_s;
            }
            else if(num_of_spaces + 1 == NumberOfWords(str) && wordPlace == NumberOfWords(str)) {
                temp_s = str.substr(space_location, size - space_location);
                return temp_s;
            }
        }
        count = count + 1;
    }
    return temp_s;
}
std::string RemoveSpaces(std::string &word) { //Removes any excess spaces in words
    if (word.find(' ') != std::string::npos){ //if a space is there, if is activated
            int temp_l = word.find(" ");
            word.replace(temp_l, 1, "");
            return word;      
    }
    else {  
        return word;
    }
}
int main() {
    while(1) {
        if (std::cin.fail()) { //no input = break
            break;
        }
        std::string s = "";
        std::string s_sum = "";
        std::string combo = "";
        getline(std::cin, s);
        if (s.find(".") != std::string::npos) { //small code created to get rid of extra space after the period
            int location = s.find(".");
            s.replace(location + 1, 1, "");
        }
        std::vector <std::string> v; //created a vector to store all the words
        int vc = 1;
        int vsize = NumberOfWords(s);
        if (vsize == 1) {
            s_sum = s_sum + s + " ";
        }
        else {
            while(1) { //add the words to the vector
                if (vc == vsize + 1) {
                    break;
                }
                std::string wordsample = TurnSentenceIntoWord(s, vc);
                v.push_back(RemoveSpaces(wordsample));
                vc = vc + 1;
            }
            int j = v.size(); // getting the size of the vector as a signed int
            for(int i = 0; i < j; i++) { //for loop to loop thru the vector
                std::string first = v.at(i);
                first = RemoveSpaces(first);
                if (NumberOfCharactersOverlap(combo, first) > 0) {
                    combo = CombineWords(combo, first, NumberOfCharactersOverlap(combo, first)); 
                    combo = RemoveSpaces(combo); //keep the combination to compare it to the next word
                }
                else {
                    if (combo == "") {
                        s_sum = s_sum + combo;
                    }
                    else {
                        s_sum = s_sum + combo + " "; //if the number of characters overlap is 0, add the combo word
                    }
                    combo = first;
                }
                if (i == j - 1) { //used to break the loop
                    s_sum = s_sum + combo + " "; 
                }
            }
        }
        std::cout << s_sum << std::endl;
    }
}
