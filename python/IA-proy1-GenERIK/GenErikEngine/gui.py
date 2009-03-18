#!/usr/local/bin/python     
"""Interfaz Grafica de la aplicacion
    Por Erik Giron 200313492"""
import os
from Tkinter import *      
from moch import *

class Application(Frame):  

    def __init__(self, master=None):
        Frame.__init__(self, master)   
        self.grid()                    
        self.createWidgets()
        
    def generar(self):
        #elegimos metodo de seleccion
        if('1' in self.selSeleccion.curselection()):
            seleccion = seleccionRuletera()
        else:
            seleccion = seleccionElitista()
            
        
        #elegimos metood de cruze
        if('1' in self.selCrossover.curselection()):            
            cruzamiento = cruzamientoAcotado()            
        else:
            cruzamiento = cruzamientoNormal()    
        #instanciamos mochilero
        mochila = mochilero(seleccion, cruzamiento)
        mochila.MUT_RATIO = (self.sldMutacion.get() )/100.0
        mochila.PESO_MOCHILA = self.sldCapacidad.get()
        mochila.MAX_POBLACION = self.sldnumElem.get()
        mochila.GENERACIONES = self.sldNumGeneraciones.get()
        print self.selOutput.curselection()
        if('1' in self.selOutput.curselection()):
            mochila.TIPO_SALIDA = "MOVIE"
        else:
            mochila.TIPO_SALIDA = "TEXT"
        
        mochila.OUTPUT_PATH = "%s%s" % (self.txtPath.get("0.0", END).strip("\t\n "), self.separator)

        #ejecutamos algoritmo    
        try:
            self.lblStatus.text = "Evolucionando, para mayor informacion ver consola"
            mochila.evolucion()
            self.lblStatus.text = "Evolucion terminada"
        except:
            self.lblStatus.text = "Error ",  sys.exc_info()[0]

    def createWidgets(self):
        #tipos de cruze        
        self.label1 = Label(self, text="Tipo de cruzamiento:")
        self.label1.grid(row=0, column=0)
        self.yScroll  =  Scrollbar ( self, orient=VERTICAL )
        self.yScroll.grid ( row=0, column=2, sticky=N+S )
        self.selCrossover = Listbox(self, width=30, height=1, yscrollcommand=self.yScroll.set)
        self.selCrossover.insert(0, "Cruce Normal", "Cruce Acotado")
        self.selCrossover.select_set(0)        
        self.selCrossover.grid( row=0, column=1)
        self.yScroll["command"]  =  self.selCrossover.yview

        #tipos de seleccion  
        self.label2 = Label(self, text="Tipo de seleccion:")
        self.label2.grid(row=1, column=0)      
        self.yScroll2  =  Scrollbar ( self, orient=VERTICAL )
        self.yScroll2.grid ( row=1, column=2, sticky=N+S )
        self.selSeleccion = Listbox(self, width=30, height=1, yscrollcommand=self.yScroll2.set)
        self.selSeleccion.insert(0, "Seleccion Elitista", "Seleccion Por Ruleta")        
        self.selSeleccion.select_set(0)
        self.selSeleccion.grid( row=1,  column=1)
        self.yScroll2["command"]  =  self.selSeleccion.yview

        #porcentaje de mutacion
        self.sldMutacion = Scale(self, from_=1.0, to=100.0, label="Porcentaje de Mutacion", 
                                 orient=HORIZONTAL, length=200,  resolution=1, variable=DoubleVar())
        self.sldMutacion.grid(row=2,  column=0, columnspan=2)
        self.sldMutacion.set(50.0)

        #Capacidad de la mochila
        self.sldCapacidad = Scale(self, from_=1000, to=10000, label="Peso max. de la mochila", 
                                 orient=HORIZONTAL, length=200,  resolution=1, variable=IntVar())
        self.sldCapacidad.grid(row=3,  column=0, columnspan=2)
        self.sldCapacidad.set(2000)
        
       #Numero de poblacion
        self.sldnumElem = Scale(self, from_=25, to=200, label="Poblacion Inicial", 
                                 orient=HORIZONTAL, length=200,  resolution=1, variable=IntVar())
        self.sldnumElem.grid(row=4,  column=0, columnspan=2)
        self.sldnumElem.set(50)

      #Maximo de Generaciones
        self.sldNumGeneraciones = Scale(self, from_=5, to=500, label="Maximo numero de Generaciones", 
                                 orient=HORIZONTAL, length=200,  resolution=1, variable=IntVar())
        self.sldNumGeneraciones.grid(row=5,  column=0, columnspan=2)
        self.sldNumGeneraciones.set(100)

      #Tipo de salida
        self.label3 = Label(self, text="Tipo de Salida:")
        self.label3.grid(row=6, column=0)      
        self.yScroll3  =  Scrollbar ( self, orient=VERTICAL )
        self.yScroll3.grid ( row=6, column=2, sticky=N+S )
        self.selOutput = Listbox(self, width=30, height=1, yscrollcommand=self.yScroll3.set)
        self.selOutput.insert(0, "Texto", "Video")        
        self.selOutput.select_set(0)
        self.selOutput.grid( row=6,  column=1)
        self.yScroll3["command"]  =  self.selOutput.yview
        

        #path de salida
        try:
            from win32com.shell import shellcon, shell
            self.separator="\\"
            homedir = shell.SHGetFolderPath(0, shellcon.CSIDL_APPDATA, 0, 0)
        except ImportError: # quick semi-nasty fallback for non-windows/win32com case
            self.separator="/"
            homedir = os.path.expanduser("~")            
        self.label4 = Label(self, text="Ruta de salida:")
        self.label4.grid(row=7, column=0)      
        self.txtPath = Text(self, height=1, width=32, )
        self.txtPath.insert("0.0", homedir)
        self.txtPath.grid( row=7,  column=1, columnspan=2)
        
        #boton generar
        self.generateButton = Button ( self, text="Generar",
            command=self.generar )        
        self.generateButton .grid(row=8, column=1)      

        #boton salir
        self.quitButton = Button ( self, text="Salir",
            command=self.quit )        
        self.quitButton.grid(row=8, column=0)               
    
        self.label5 = Label(self, text="Estado:")
        self.label5.grid(row=9, column=0)      
        self.lblStatus = Label(self, text="Listo")
        self.lblStatus.grid(row=9, column=1, columnspan=2)      

app = Application()                    
app.master.title("GenErik > proyecto de IA, (c) 2008, Erik Giron (200313492)") 
app.mainloop()                 
