#include "mainform.h"
#include <qtextedit.h>
#include <qlineedit.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qaction.h>
MainForm::MainForm(QWidget *parent, const char *name)
    :Form1(parent, name)
{
	ofrm = NULL;
	/**este timer lee el puerto mientras no se hace nada*/
	timer = new QTimer( this );
	/**Conectamos evento timeout del timer con el slot retrieve
	para que podamos escuchar el puerto mientras la aplicacion esta idle*/
	connect( timer, SIGNAL(timeout()), SLOT(retrieve()) );
	//timer->start( 0, FALSE );
}

void MainForm::connectport()
{
	int numpuerto;
/**Obtiene configuracion del form de configuracion*/
	if (ofrm != NULL){
		st = ofrm->getSettings();
	}
	numpuerto = st.getPuerto() - 1;

	/**Abrimos puerto*/
	char strPuerto[] = "/dev/ttySX";
	strPuerto[9] = (char)numpuerto + '0' ; //sustituimos numero de puerto
	//QString strPuerto = tr("/dev/ttyS") + tr(numpuerto);
	
	/**abrimos puerto si no se ha abierto previamente*/

	if(! serial_port.IsOpen() )
		serial_port.Open(strPuerto,std::ios::in|std::ios::out) ;
	
	if ( ! serial_port.good() ) 
	{
		QMessageBox::warning(this,tr("Aviso"), tr("Error: No se puede abrir puerto serial No " ) + tr(strPuerto)  + tr("\nVerifique si tiene los permisoss necesarios para leer/escribir en el puerto"), QMessageBox::Ok, QMessageBox::NoButton);
	
	}
	/**Asignamos velocidad*/
	//serial_port.SetBaudRate((SerialStreamBuf::BaudRateEnum)st.getVelocidad()  ) ;
	serial_port.SetBaudRate( SerialStreamBuf::BAUD_9600 ) ;
	if ( ! serial_port.good() ) 
	{
		QMessageBox::warning(this,tr("Aviso"), tr("Error: Imposible establecer la velocidad a " + st.getVelocidad()), QMessageBox::Ok, QMessageBox::NoButton);	
	}
	//
    // Asigna el numero de bits de dato
	//
	serial_port.SetCharSize( SerialStreamBuf::CHAR_SIZE_8 ) ;
	if ( ! serial_port.good() ) 
	{
		QMessageBox::warning(this,tr("Aviso"), tr("Error: No se pudo establecer el tamano de caracter " + SerialStreamBuf::CHAR_SIZE_8), QMessageBox::Ok, QMessageBox::NoButton);	

	}
	//
    // Activa o desactiva paridad.
	//
	//serial_port.SetParity((SerialStreamBuf::ParityEnum) st.getParidad() ) ;
	serial_port.SetParity( SerialStreamBuf::PARITY_NONE ) ;
	if ( ! serial_port.good() ) 
	{
		QMessageBox::warning(this,tr("Aviso"), tr("Error: No se pudo establecer la paridad a " + st.getParidad()), QMessageBox::Ok, QMessageBox::NoButton);	

	}
	//
    // Set the number of stop bits.
	//
	serial_port.SetNumOfStopBits( 1 ) ;
	if ( ! serial_port.good() ) 
	{
		QMessageBox::warning(this,tr("Aviso"), tr("Error: No se pudo establecer el numero bits de stop a 1"), QMessageBox::Ok, QMessageBox::NoButton);	
	}
	//
    // Turn on hardware flow control.
	//
	//serial_port.SetFlowControl( SerialStreamBuf::FLOW_CONTROL_NONE ) ;
	serial_port.SetFlowControl( SerialStreamBuf::FLOW_CONTROL_NONE ) ;
	if ( ! serial_port.good() ) 
	{
		QMessageBox::warning(this,tr("Aviso"), tr("Error: Imposible establecer el flujo de control por hardware"), QMessageBox::Ok, QMessageBox::NoButton);	
	}	
	
	
	/**Activamos y desactivamos controles si todo salio bien*/
	if ( serial_port.good() ) {
		sendButton->setEnabled(true);
		sendTxtBox->setEnabled(true);
//		retrieveButton->setEnabled(true);
		retrieveTxtBox->setEnabled(true);
		opcionesEstablecer_parametros_del_PuertoAction->setEnabled(false);
		archivoConexionConectarAction->setEnabled(false);
		archivoConexionDesconectarAction->setEnabled(true);
		//iniciamos el Timer
		timer->start( 0, FALSE );
	}
	
}
/**Se desconecta del puerto y cancela el evento de escucha desde el puerto.
Tambien desactiva los controles*/
void MainForm::disconnectport()
{
	/**Paramos el timer*/
	timer->stop();
	/**Cerramos Puerto*/
	serial_port.Close() ;
	/**Activamos y desactivamos controles*/
	sendButton->setEnabled(false);
	sendTxtBox->setEnabled(false);
//	retrieveButton->setEnabled(false);
	retrieveTxtBox->setEnabled(false);
	opcionesEstablecer_parametros_del_PuertoAction->setEnabled(true);
	archivoConexionConectarAction->setEnabled(true);
	archivoConexionDesconectarAction->setEnabled(false);
	
}
/**"puente" para envio de mensaje desde el boton*/
void MainForm::EnviarMensaje()
{
	this->send();
}
void MainForm::pushButton1_released()
{
}

void MainForm::lineEdit2_returnPressed()
{
}


/**Escucha el puerto y si recibe mensaje lo escribe en pantalla*/
void MainForm::retrieve()
{
	char tmp = 0;	
	if(serial_port.good()){ //si funciona la conexion...
		if( serial_port.rdbuf()->in_avail() > 0  )  // y si se recibio algun dato
		{
			/*char next_byte;
			serial_port.get(next_byte); //obtenemos un byte del buffer
			tmp = next_byte;
			retrieveTxtBox->append(tr( &tmp ));//actualizamos textbox
			*/
			char next_byte;
			serial_port.get(next_byte); //obtenemos un byte del buffer
			tmp = next_byte;
			if((tmp >= 'A' && tmp <= 'Z' ) || (tmp >='a' && tmp <='z'))
				retrieveTxtBox->append(tr( &tmp ));//actualizamos textbox
			/*std::cerr << std::hex << (int)next_byte << " ";*/
		} 

		
	}
}


void MainForm::send()
{
		
	const char* msg = (sendTxtBox->text()).ascii();
	
/*	while(msg) 
	{
		char next_byte ;
		//input_file.read( &next_byte, 1 ) ;
		//serial_port.write((char*)*msg, 1 ) ;
		serial_port.write(msg, 1 ) ;
		msg++;
}*/
	/** envia mensaje al puerto*/
	if(serial_port.good()){
		serial_port << msg;
	}
	
	retrieveTxtBox->append(tr("<Yo>: " + sendTxtBox->text()));
	sendTxtBox->setText(tr(""));
}
/**Muestra ventana de About*/
void MainForm::about()
{
	ab = new AboutWindow();
	ab->show();
}
/**Muestra ventana de opciones*/
void MainForm::openOptionWindow()
{
	ofrm = new OpcionesForm();
	ofrm->show();
	
}







