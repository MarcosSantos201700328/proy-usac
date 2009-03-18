/****************************************************************************
** Form interface generated from reading ui file 'TestWindow.ui'
**
** Created: Fri Nov 16 22:20:42 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.7   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qmainwindow.h>
#include "pacmanthread.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QAction;
class QActionGroup;
class QToolBar;
class QPopupMenu;
class QGroupBox;
class QPushButton;

class TestWindow : public QMainWindow
{
    Q_OBJECT

public:
    TestWindow( QWidget* parent = 0, const char* name = 0, WFlags fl = WType_TopLevel );
    ~TestWindow();

    QGroupBox* mainPanel;
    QGroupBox* grpbuffer;
    QPushButton* btnStart;
    QPushButton* btnStop;
    QMenuBar *menubar;
    QPopupMenu *fileMenu;
    QPopupMenu *editMenu;
    QPopupMenu *Help;
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
    virtual void add();
    virtual void editPaste();
    virtual void editFind();
    virtual void helpIndex();
    virtual void helpContents();
    virtual void helpAbout();
    virtual pacmanThread* remove();
    virtual void begin();
    virtual void end();

protected:
    QVBoxLayout* TestWindowLayout;
    QHBoxLayout* layout1;

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

#endif // TESTWINDOW_H
