#include <vector>
#include <string>
 #include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    std::vector<std::string> numberNames = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
        "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        return convertToWords(num).substr(1);
    }

private:
    string convertToWords(int num) {
        if (num >= 1000000000) {
            return convertToWords(num / 1000000000) + " Billion" + convertToWords(num % 1000000000);
        }
        else if (num >= 1000000) {
            return convertToWords(num / 1000000) + " Million" + convertToWords(num % 1000000);
        }
        else if (num >= 1000) {
            return convertToWords(num / 1000) + " Thousand" + convertToWords(num % 1000);
        }
        else if (num >= 100) {
            return convertToWords(num / 100) + " Hundred" + convertToWords(num % 100);
        }
        else if (num >= 20) {
            int d=num%10;
            int n=num-d;

            return " " + numberNames[n / 10 + 18] + (d > 0 ? " " + numberNames[d] : "");
        }
        else if(num>0) {
            return " " + numberNames[num];
        }
        else{
            return "";
        }
    }
};