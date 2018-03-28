/*
3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

static const auto ______ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int lengthOfLongestSubstring(string s)
  {
    int flags[256];
    for (int i = 0; i < 256; i++)
      flags[i] = -1;

    int longest = 0;
    int i = 0;
    int collision = -1;
    while (s[i] != 0)
    {
      if (flags[s[i]] != -1)
        collision = (collision > flags[s[i]] ? collision : flags[s[i]]);
      flags[s[i]] = i;
      longest = (i - collision > longest ? i - collision : longest);
      i++;
    }

    return longest;
  }
  /*int lengthOfLongestSubstring(string s) {
    if (s.size() < 2)
      return static_cast<int>(s.size());

    int first_index(0), last_index(0), max_length(1);
    map<char, int> letters;
    int counter(0);
    while (counter < s.size())
    {
      last_index = counter;

      if (letters.find(s[counter]) != letters.end() && letters[s[counter]] >= 0)
      {
        while (first_index < (letters[s[counter]] + 1))
        {
          letters[s[first_index]] = -1;
          first_index++;
        }

        while (s[first_index] == s[counter])
          first_index++;
        if (first_index > counter)
        {
          first_index--;
          counter = first_index;
        }
      }
      else
      {
        const auto length = last_index - first_index + 1;
        if (max_length < length)
          max_length = length;
      }

      letters[s[counter]] = counter;

      counter++;
    }

    const auto length = last_index - first_index;
    if (max_length < length)
      max_length = length;

    return max_length;
  }*/
  bool checkExample()
  {
    using VSType = vector<string>;
    using VIType = vector<int>;
    VSType vstr = { "jxdlnaaij", "tmmzuxt", "abcabcbb" , "bbbbb" , "pwwkew", "abc" };

    VIType result;
    for (const auto& it_vstr : vstr)
      result.push_back(lengthOfLongestSubstring(it_vstr));

    VSType check = { "jxdlna", "mzuxt", "abc" , "b" , "wke", "abc" };
    bool is_ok(true);
    for (VSType::size_type i = 0; i < check.size(); ++i)
      is_ok &= result[i] == check[i].size();

    return is_ok;
  }
};


int main()
{
  Solution solution;
  solution.checkExample();

  return 0;
}
