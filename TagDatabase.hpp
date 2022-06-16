#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>
#include <map>

template<typename T>
class TagDatabase
{
public:
    void add_item_with_tags(T item, std::string_view const tags)
    {
        for(auto&& tag : parse_tags(tags))
        {
            map.insert(std::make_pair(tag, item));
        }
    }

    void get_item(std::string_view tag)
    {
        auto range = map.equal_range(tag);
        for(auto i = range.first; i != range.second; ++i)
        {
            std::cout << "value for " << i->first << " is " << i->second << std::endl;
        }
    }

private:
    std::vector<std::string_view> parse_tags(std::string_view const tags)
    { 
        std::vector<std::string_view> parsed_tags;
        int32_t start = 0;
        while(tags.find("#", start) != std::string_view::npos)
        {
            start = tags.find('#', start);
            start++;
            int32_t end = tags.find(' ', start);
            parsed_tags.push_back(tags.substr(start, end-1));
        }
        return parsed_tags; // TODO check if it has been applied RVO
    }

    std::multimap<std::string_view, T> map;
};

