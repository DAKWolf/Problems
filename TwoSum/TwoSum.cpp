/*
1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return[0, 1].
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

static const auto __________ = []()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    using SizeType = std::remove_reference_t<decltype(nums)>::size_type;
    using ValueToIndexMapType = std::unordered_map<int, SizeType>;
    ValueToIndexMapType hashmap;
    std::vector<int> indices(2);
    for (SizeType index = 0; index < nums.size(); ++index)
    {
      const auto foundIterator = hashmap.find(target - nums[index]);
      if (foundIterator != std::end(hashmap) && foundIterator->second != index)
        return std::vector<int>{ static_cast<int>(index), static_cast<int>(foundIterator->second) };
      else
        hashmap.emplace(nums[index], index);
    }
    throw std::runtime_error("Solution not found");
  }
  bool checkExample()
  {
    std::vector<int> nums = { 2, 7, 11, 15 };
    int target = { 9 };
    std::vector<int> check = { 0, 1 };

    Solution solution;
    std::vector<int> result = solution.twoSum(nums, target);

    std::sort(result.begin(), result.end());
    if (result.size() == check.size())
      if (result[0] == check[0] && result[1] == check[1])
        return true;

    return false;
  }
};


int main()
{
  Solution solution;
  solution.checkExample();

  return 0;
}
