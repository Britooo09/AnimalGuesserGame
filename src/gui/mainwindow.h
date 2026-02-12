#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>

#include <QMainWindow>
#include <QElapsedTimer>
#include <QTime>
#include "node.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum Pages {
        MAIN_MENU = 0,
        QUESTIONS = 1,
        ANSWER = 2,
        HOW_TO_PLAY = 3,
        LEARN = 4,
        RESULTS = 5,
        TRY_AGAIN = 6
    };

private slots:
    void clean_and_close();

    void on_btnExit_clicked();

    void on_btnStart_clicked();

    void on_btnHowto_clicked();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_btnYes_clicked();

    void on_btnNo_clicked();

    void on_btnProbYes_clicked();

    void on_btnProbNo_clicked();

    void on_btnRight_clicked();

    void on_btnWrong_clicked();

    void on_actionNewGame_triggered();

    void on_btnDontPlayAgain_clicked();

    void on_btnPlayAgain_clicked();

    void on_btnBack_clicked();

private:
    Ui::MainWindow *ui;

    QElapsedTimer timer;

    void refreshCounter();

    void startGame();

    void showQuestion(Node* ptrNode);

    void processButton();

    void guiHandleAnimalNode(Node* ptrNode);

    void resultHandle();
};
#endif // MAINWINDOW_H
