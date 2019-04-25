#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QResizeEvent>

#include <../headers/id_map.h>
#include <deque>
#include <vector>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
    void initializMyLabel(IDMap *a);
    std::vector <int> getplan();
    void setOriginPixmap();
    bool hasOriginPixmap();
protected:
    void mousePressEvent(QMouseEvent *ev);
    void resizeEvent(QResizeEvent *ev);
signals:

public slots:
    origin_action_triggered();
    destination_action_triggered();
    transfer_action_triggered();
private:
    int mouse_x;
    int mouse_y;

    QMenu *rightbutton_menu;
    QLabel *mark_origin;
    int where_mark_origin;
    QLabel *mark_destination;
    int where_mark_destination;
    QLabel *mark_transfer[31];
    bool has_mark_transfer[31];

    int current_set_city;
    std::deque <int> transfer_city;

    int city_pos[31][2];      //在图片大小为900x650情况下
    int col_map[7];
    int row_map[5];

    IDMap *idmap;

    void initialize_citymap_pos();
    bool in_city_range(int i);
    int judge_mouse_pos();

    QPixmap origin_pixmap;
};

#endif // MYLABEL_H
