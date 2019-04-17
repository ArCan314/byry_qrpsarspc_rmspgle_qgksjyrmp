#include "src/id_map.h"
#include "src/city_graph.h"
#include "src/io.h"
#include "src/log.h"
#include "src/path.h"
#include "src/save_at_exit.h"
#include "src/simulation.h"
#include "src/time_format.h"
#include "src/traveller.h"
#include "src/user_type.h"

#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_released();

private:
    Ui::Widget *ui;
    Traveller traveller;
    CityGraph citygraph;
    IDMap idmap;
    Path path;
    std::vector<City_id> plan;
    Strategy strategy;
    Time limit_time;
    Time init_time;
};

#endif // WIDGET_H
