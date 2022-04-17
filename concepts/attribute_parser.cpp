#include<iostream>
#include<memory>
#include<list>
#include<vector>
#include<map>
#include<sstream>

#define MAX_LINE_LEN 200

/**
 * @brief Get the tag object
 * 
 * @param str 
 * @return std::string 
 */
std::string get_tag(std::string str)
{
    return nullptr;
}

/**
 * @brief Get the key object
 * 
 * @param str 
 * @return std::string 
 */
std::string get_key(std::string str)
{
    return nullptr;
}

int main()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<std::string> tags;
    std::vector<std::string> attr;
    std::vector<std::string> quer;

    for( int i = 0; i < n/2; i++)
    {
        std::string tag = "<tag";
        std::string id = std::strcat(tag, std::to_string(i));
        tags.push_back();
    }

    std::cin.ignore();
    for(int i = 0; i < n; i++)
    {
        char str[MAX_LINE_LEN];
        std::cin.getline(str, MAX_LINE_LEN);
        attr.push_back(std::string(str));
    }

    for(int i = 0; i < q; i++)
    {
        char str[MAX_LINE_LEN];
        std::cin.getline(str, MAX_LINE_LEN);
        quer.push_back(std::string(str));
    }

    return 0;
}

class Tag
{
public:
    int start;
    int end;
    std::string this_tag;
    Tag * nested;
    std::map<std::string, std::string> key_val;
};

void parse_hrml(std::string line)
{
    Tag begin;
    begin.start = 0;
    char delimiter = ' ';
    char key_delimiter = ' =';
    char line_delimiter = '>';
    char tag_begin = '<';
    char tag_end = '</';
    line.find(delimiter, -1);
    if(delimiter != -1)
    {
        begin.end = delimiter - 1;
        begin.this_tag = line.substr(begin.start, begin.end);
    }
}

void parse_query()
{
    
}