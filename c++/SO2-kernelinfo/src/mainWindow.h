/****************************************************************************
** Form interface generated from reading ui file 'mainWindow.ui'
**
** Created: Wed Mar 26 22:06:06 2008
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.7   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRM_MAIN_H
#define FRM_MAIN_H

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
class QTabWidget;
class QWidget;
class QTable;
class QPushButton;
class QGroupBox;
class QLabel;
class QLineEdit;
class QCheckBox;
class QTextBrowser;

class frm_main : public QMainWindow
{
    Q_OBJECT

public:
    frm_main( QWidget* parent = 0, const char* name = 0, WFlags fl = WType_TopLevel );
    ~frm_main();

    QTabWidget* tabs;
    QWidget* tab;
    QTable* tableProcess;
    QPushButton* pushButtonKill;
    QWidget* tab_2;
    QTable* tableModule;
    QPushButton* btn_descargar;
    QGroupBox* grp_moduleCharger;
    QLabel* textLabel1;
    QLineEdit* txt_nombremodulo;
    QCheckBox* chk_cargaralinicio;
    QPushButton* btn_cargar;
    QWidget* TabPage;
    QGroupBox* grp_dev;
    QTextBrowser* txtbox_dev;
    QPushButton* btn_exportdevices;
    QWidget* TabPage_2;
    QTextBrowser* txt_mem;
    QMenuBar *menubar;
    QPopupMenu *Archivo;
    QPopupMenu *Ayuda;
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
    QAction* Action;

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
    virtual void changeTab(QWidget * w);
    virtual void kill();
    virtual void cargarModulo();
    virtual void descargarModulo();
    virtual void exportdev();

protected:
    QVBoxLayout* frm_mainLayout;
    QVBoxLayout* tabLayout;
    QVBoxLayout* tabLayout_2;
    QVBoxLayout* grp_moduleChargerLayout;
    QHBoxLayout* layout1;
    QVBoxLayout* TabPageLayout;
    QVBoxLayout* grp_devLayout;
    QVBoxLayout* TabPageLayout_2;

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

#endif // FRM_MAIN_H
