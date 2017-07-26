#include "painter.h"
#include <QToolButton>
#include <QComboBox>
#include <QSpinBox>
#include <QToolBar>
#include <QLabel>
#include <QColorDialog>

Painter::Painter(QWidget *parent)
	: QMainWindow(parent)
{
    QFont font("ZYSong18030",12);
    setFont(font);
    
    setWindowTitle(tr("Simple Painter"));    
   
    widget = new DrawWidget;
    setCentralWidget(widget);
    
    createToolBar();

    setMinimumSize(600,400);
    
    slotStyle();
    widget->setWidth(widthSpinBox->value());
    widget->setColor(Qt::black); 
}

void Painter::createToolBar()
{
    QToolBar *toolBar = addToolBar("Tool");
    QLabel *label1 = new QLabel(tr("style:"));
    styleComboBox = new QComboBox;
    styleComboBox->addItem("SolidLine", (int) Qt::SolidLine);
    styleComboBox->addItem("DashLine", (int) Qt::DashLine);
    styleComboBox->addItem("DotLine", (int) Qt::DotLine);
    styleComboBox->addItem("DashDotLine", (int) Qt::DashDotLine);
    styleComboBox->addItem("DashDotDotLine", (int) Qt::DashDotDotLine);
    toolBar->addWidget(label1);
    toolBar->addWidget(styleComboBox);
    toolBar->addSeparator();
    connect(styleComboBox,SIGNAL(activated(int)),this,SLOT(slotStyle()));
        
    QLabel *label2 = new QLabel(tr("width:"));
    widthSpinBox = new QSpinBox;
    widthSpinBox->setRange(0,10);
    toolBar->addWidget(label2);    
    toolBar->addWidget(widthSpinBox);
    toolBar->addSeparator();
    connect(widthSpinBox,SIGNAL(valueChanged(int)),widget,SLOT(setWidth(int)));
    
    colorBtn = new QToolButton;
    QPixmap pixmap(20,20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    toolBar->addWidget(colorBtn);
    toolBar->addSeparator();
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(slotColor()));
    
    QToolButton *clearBtn = new QToolButton;
    clearBtn->setText(tr("Clear"));
    toolBar->addWidget(clearBtn);
    connect(clearBtn,SIGNAL(clicked()),widget,SLOT(clear()));
}

void Painter::slotStyle()
{
    widget->setStyle(styleComboBox->itemData(
    		styleComboBox->currentIndex(),Qt::UserRole).toInt());
}

void Painter::slotColor()
{
    QColor color = QColorDialog::getColor(Qt::black,this);
    if (color.isValid())
    {
        widget->setColor(color);
        QPixmap p(20,20);
        p.fill(color);
        colorBtn->setIcon(QIcon(p));
    }
}

