#ifndef PAINTER_H
#define PAINTER_H

#include <QtGui>
#include <QMainWindow>
#include "drawwidget.h"

class QToolButton;
class QComboBox;
class QSpinBox;

class Painter : public QMainWindow
{
    Q_OBJECT
public:
    Painter(QWidget *parent=0);
    
    void createToolBar();
    
public slots:
    void slotColor();
    void slotStyle();
    
private: 
    DrawWidget *widget;
    QToolButton *colorBtn;
    QComboBox *styleComboBox;
    QSpinBox *widthSpinBox;
};

#endif
