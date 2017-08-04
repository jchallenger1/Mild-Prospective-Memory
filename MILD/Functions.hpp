#include <unordered_map>
#include <string>
#include <memory>
#include "entryitem.hpp"
class EntryItem;
using MapType = std::unordered_map<std::string, std::unique_ptr<EntryItem>>; //string representing the text in the entryitem.