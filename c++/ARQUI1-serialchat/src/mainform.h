
#ifndef MAINFORM_H
#define MAINFORM_H
/** - Create Setting Instance inside this class to manage the connection's settings
- connect the OK Message of opcionesform to Settings methods
- test the connections using a DB9 connector to Chucho's Machine
TODO Use some switch..case to configure the port options properly and reflects the changes at the time of send/receive data.
TODO Fix my pal's names and IDs
TODO Comment and use Doxygen to generate documentation
 */
#include "mainwindow.h"
#include <qtimer.h>
class MainForm: public Form1 {
Q_OBJECT
public:
    MainForm(QWidget *parent = 0, const char *name = 0);
    virtual void connectport();
    virtual void disconnectport();
public slots:
    virtual void lineEdit2_returnPressed();
public slots:
    virtual void pushButton1_released();
    virtual void retrieve();
    virtual void send();
public slots:
    virtual void EnviarMensaje();
    virtual void about();
    virtual void openOptionWindow();
private:
	QTimer* timer;/*
static char SERIAL_PORT_DEVICE[][4] = {
	"/dev/ttyS0";
	"/dev/ttyS1";
	"/dev/ttyS2";
	"/dev/ttyS3"  };
*/
};

#endif
