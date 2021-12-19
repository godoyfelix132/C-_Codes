#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QListWidget>
#include <QPushButton>
#include <QAbstractScrollArea>
#include <QVector>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QHBoxLayout *mainLayout;
    QVBoxLayout *dataLayout;
    QVBoxLayout *groupLayout;

    QLabel *hello;
    QLabel *hello2;

    QWidget *mainWidget;
    QWidget *dataWidget;

    QGroupBox *listGroupBox;
    QGroupBox *infoGroupBox;

    QListWidget *listListWidget;
    QLabel *ImgLabel;
    QPushButton *actionBtn;

    QVector<int> *listVector;


    QAbstractScrollArea *listScrollArea;

    void init_central_widget();

};
#endif // MAINWINDOW_H
