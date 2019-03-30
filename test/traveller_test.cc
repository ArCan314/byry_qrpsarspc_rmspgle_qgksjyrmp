#ifndef TEST_TRAVELLER_SAVE
#define TEST_TRAVELLER_SAVE

#include <vector>
#include <iostream>
#include <string>

#include "../src/path.h"
#include "../src/io.h"
#include "../src/traveller.h"

int main()
{
    CityGraph graph;
    IDMap idmap;
    std::string buf;
    std::cin >> buf;
    Traveller t(buf);
    std::vector<int> plan;
    plan.push_back(29);
    plan.push_back(27);
    plan.push_back(16);
    Time now(1, 7);
    Time limit(1, 24);
    Path path = t.GetPath(graph, plan, LIMIT_TIME, now, limit);
    /*path.Show();
    if (PathConfirm(path, now))
    {
        t.set_path(path);
    }*/
    t.set_path(path);
    t.ShowState(graph,idmap,now);
    if (t.SaveData())
        std::cout << "success!" << std::endl;
    else
        std::cout << "干!" << std::endl;

    /*Traveller t("test2");
    std::vector<int> plan;
    plan.push_back(30);
    plan.push_back(18);
    plan.push_back(14);
    Time ti;
    Path a = t.GetPath(graph, plan, LEAST_TIME, ti);
    t.set_path(a);
    t.ShowPath();
    if (t.SaveData())
        std::cout << "success!" << std::endl;
    else
        std::cout << "干!" << std::endl;*/

    /*Traveller t("test");
    if(t.LoadData(1,graph))
    {
        std::cout<<"success!"<<std::endl;
        t.ShowPath();
    }
    else std::cout<<"干!"<<std::endl;*/
    return 0;
}
#endif // TEST_TRAVELLER_SAVE