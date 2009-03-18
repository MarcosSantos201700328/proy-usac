#include <qapplication.h>
#include "serialchat.h"
#include "mainform.h"

int main( int argc, char ** argv ) {
    QApplication a( argc, argv );
/*    serialchat * mw = new serialchat();
    mw->setCaption( "serialchat" );
    mw->show();
    a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );
*/
    MainForm * mw = new MainForm();
    mw->show();
    a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );
    return a.exec();
}

