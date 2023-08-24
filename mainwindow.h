#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPrinter>
#include <QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString currentFile;

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void save();
    void saveAs();

    void print();
    void printPreview(QPrinter *printer);
    void printPreviewDialog();
    void exportPdf();

    void undo();
    void redo();

    void cut();
    void copy();
    void paste();

    void fontBold();
    void fontItalic();
    void fontUnderLine();

    void right();
    void left();
    void center();
    void justify();

    changeFont();
    changeColor();
    about();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
