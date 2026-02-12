#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include "answerHandler.h"
#include "gameLogic.h"
#include "globals.h"
#include "node.h"
#include "programLogic.h"

GameLogic game;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    refreshCounter();
    ui->stackedWidget->setCurrentIndex(MAIN_MENU);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clean_and_close() {
    cleanMemory(game.getRoot());
    close();
}

void MainWindow::refreshCounter() {
    int amount = countAnimals(game.getRoot());
    ui->txtAnimalCount->setText(QString("Animals currently in the database: %1").arg(amount));
}

void MainWindow::startGame() {
    QUESTION_COUNTER = 0;
    game.setCurrentNode(game.getRoot());
    showQuestion(game.getCurrentNode());
    timer.start();
    ui->stackedWidget->setCurrentIndex(QUESTIONS);
}

void MainWindow::showQuestion(Node* ptrNode) {
    if (!ptrNode) return;
    QUESTION_COUNTER += 1;
    QString nodeText = QString::fromStdString(ptrNode->text);

    if (!game.getCurrentNode()->isQuestion) {
        ui->txtAnswer->setText(nodeText);
        ui->stackedWidget->setCurrentIndex(ANSWER);
    } else {
        ui->txtQuestion->setText(nodeText);
    }
}

void MainWindow::processButton() {
    Node* nextNode = answerHandler.processAnswer(game.getCurrentNode(), RESPONSE);
    game.setCurrentNode(nextNode);
    if (game.getCurrentNode()) {
        showQuestion(game.getCurrentNode());
    }
    else {
        // If no next node, try alternative path
        Node* alternativeNode = answerHandler.popProbablyNode();
        game.setCurrentNode(alternativeNode);
        if (game.getCurrentNode()) showQuestion(alternativeNode);
    }
}

void MainWindow::on_btnExit_clicked()
{
    clean_and_close();
}

void MainWindow::on_btnStart_clicked()
{
    startGame();
}

void MainWindow::on_btnHowto_clicked()
{
    ui->stackedWidget->setCurrentIndex(HOW_TO_PLAY);
}

void MainWindow::on_actionExit_triggered()
{
    clean_and_close();
}

void MainWindow::on_actionAbout_triggered()
{
    QString content;
    content = "<h2>Animal Guesser v1.0</h2>"
                "<p>An artificial intelligence game based on binary trees</p>"
                "<p><b>Team members:</b></p>"
                "<ul>"
                "<li>Barrios, Bismark; CI: 31.087.158</li>"
                "<li>Brito, José; CI: 30.515.175</li>"
                "<li>Cedeño, Geomar; CI: 30.834.323</li>"
                "<li>Guzmán, Gabriela; CI: 30.905.655</li>"
                "<li>Ramírez, Leonardo; CI: 31.483.681</li>"
                "</ul>"
                "<p>Project developed for the Data Structures course, 2026</p>";

    QMessageBox::about(this, "About", content);
}

void MainWindow::on_btnYes_clicked() {
    if (!game.getCurrentNode()) return;
    RESPONSE = "yes";
    processButton();
}

void MainWindow::on_btnNo_clicked() {
    if (!game.getCurrentNode()) return;
    RESPONSE = "no";
    processButton();
}

void MainWindow::on_btnProbYes_clicked() {
    if (!game.getCurrentNode()) return;
    RESPONSE = "probably yes";
    processButton();
}

void MainWindow::on_btnProbNo_clicked() {
    if (!game.getCurrentNode()) return;
    RESPONSE = "probably no";
    processButton();
}

void MainWindow::on_btnRight_clicked()
{
    ui->txtAmountofQuestions->setText(QString("Amount of questions: %1").arg(QUESTION_COUNTER));

    qint64 ms = timer.elapsed();
    QTime visualTime(0, 0);
    visualTime = visualTime.addMSecs(ms);
    QString timeText = visualTime.toString("mm:ss");
    ui->txtTimePlaying->setText("Time playing: " + timeText);

    ui->stackedWidget->setCurrentIndex(RESULTS);
}

void MainWindow::on_btnWrong_clicked()
{
    Node* alternativePath = answerHandler.popProbablyNode();
    game.setCurrentNode(alternativePath);

    if (game.getCurrentNode()) {
        ui->stackedWidget->setCurrentIndex(QUESTIONS);
        showQuestion(game.getCurrentNode());
    }
    else {
        clean_and_close();
    }
}

void MainWindow::on_actionNewGame_triggered()
{
    startGame();
}


void MainWindow::on_btnDontPlayAgain_clicked()
{
    clean_and_close();
}


void MainWindow::on_btnPlayAgain_clicked()
{
    startGame();
}


void MainWindow::on_btnBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(MAIN_MENU);
}

