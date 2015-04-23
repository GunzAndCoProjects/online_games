#ifndef FIELDINFO_H
#define	FIELDINFO_H


#include <vector>
#include <map>

typedef std::vector<std::vector<int> > field;
typedef std::map<int, char> mapping;

struct FieldInfo
{
    field Field;
    mapping TokenMapping;
};

#endif