#include"TagDatabase.hpp"

int main()
{
    TagDatabase<std::string> db;
    db.add_item_with_tags("item1", "#new #item1");
    db.add_item_with_tags("item2", "#new #item2");
    db.get_item("new");
    db.get_item("item2");
    return 0;
}
