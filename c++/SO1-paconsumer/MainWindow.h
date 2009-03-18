/****************************************************************************
** Form interface generated from reading ui file 'MainWindow.ui'
**
** Created: Fri Nov 9 22:07:42 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.7   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qmainwindow.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QAction;
class QActionGroup;
class QToolBar;
class QPopupMenu;
class QButtonGroup;
class QPushButton;
class QLabel;
class QSlider;
class QGroupBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( QWidget* parent = 0, const char* name = 0, WFlags fl = WType_TopLevel );
    ~MainWindow();

    QButtonGroup* BotonesLector;
    QPushButton* pushButton1;
    QPushButton* pushButton2;
    QLabel* txtSldrTitleTemp;
    QSlider* sldrTemp;
    QLabel* txtTemp;
    QGroupBox* Grupo1;
    QLabel* txtSldrTitleVelocidad;
    QSlider* sldrVelocidad;
    QLabel* txtVelocidad;
    QButtonGroup* BotonActivar;
    QPushButton* btnIniciar;
    QMenuBar *menubar;
    QPopupMenu *fileMenu;
    QPopupMenu *helpMenu;
    QAction* fileNewAction;
    QAction* fileOpenAction;
    QAction* fileSaveAction;
    QAction* fileSaveAsAction;
    QAction* filePrintAction;
    QAction* fileExitAction;
    QAction* editUndoAction;
    QAction* editRedoAction;
    QAction* editCutAction;
    QAction* editCopyAction;
    QAction* editPasteAction;
    QAction* editFindAction;
    QAction* helpContentsAction;
    QAction* helpIndexAction;
    QAction* helpAboutAction;

public slots:
    virtual void fileNew();
    virtual void fileOpen();
    virtual void fileSave();
    virtual void fileSaveAs();
    virtual void filePrint();
    virtual void fileExit();
    virtual void editUndo();
    virtual void editRedo();
    virtual void editCut();
    virtual void editCopy();
    virtual void editPaste();
    virtual void editFind();
    virtual void helpIndex();
    virtual void helpContents();
    virtual void helpAbout();
    virtual void Activar(bool pActivar);

protected:
    QVBoxLayout* layout8;
    QHBoxLayout* BotonesLectorLayout;
    QHBoxLayout* layout9;
    QHBoxLayout* layout6;
    QVBoxLayout* layout5;
    QVBoxLayout* layout4;
    QHBoxLayout* BotonActivarLayout;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;
    QPixmap image1;
    QPixmap image2;
    QPixmap image3;
    QPixmap image4;
    QPixmap image5;
    QPixmap image6;
    QPixmap image7;
    QPixmap image8;
    QPixmap image9;

};

#endif // MAINWINDOW_H
