#!/bin/env python
""" Motor para desarrollo de Algoritmo Genetico
    Por Erik Giron 200313492"""

# todo: arreglar para que la suma de los hijos + los padres < a la generacion anterior
# hacer video
# algoritmo de seleccion 2
# algoritmo de cruze 2

import math
import random
import os

import biggles
import math, Numeric



"""Selecciones"""
"""SeleccionElitista"""
class seleccionElitista(object):
    def seleccion(self, valoresFitness, poblacion,  beneficios,  pesos, PESO_MOCHILA, RANGO_ACEPTACION):
        # valor por cada genoma en la poblacion, ordenado
        idxSeleccionPrimaria = []
        seleccionPrimaria = []
        ben = []
        seleccionFinal = []
        # filtramos por peso
        for j in xrange(len(valoresFitness)):
            peso, beneficio = valoresFitness[j]
            # si cumple con la condicion de ser menor que el peso maximo
            if (peso <= PESO_MOCHILA):
                #agregamos elemento en el indice i que cumpla con el peso          
                idxSeleccionPrimaria.append(j) 
                seleccionPrimaria.append(poblacion[j])
                ben.append(beneficio)
            
        #calculamos el porcentaje de aceptacion
        maximum = max(ben)
        minimum = min(ben)
        
        #seleccionamos los mejores
        for i in xrange(len(seleccionPrimaria)):            
            #SI SE ENCUENTRA EN EL RAGNO DE ACEPTACION
            
            if(ben[i] >= minimum + (RANGO_ACEPTACION*(maximum - minimum))):
                seleccionFinal.append(seleccionPrimaria[i])            
        if(len(seleccionFinal) <= len(seleccionPrimaria)):
            return seleccionFinal
        else:
            return seleccionFinal[0:len(seleccionPrimaria)]

"""Seleccion Por Ruleta"""
class seleccionRuletera(object):
    def seleccion(self, valoresFitness, poblacion,  beneficios,  pesos, PESO_MOCHILA, RANGO_ACEPTACION):
        # valor por cada genoma en la poblacion, ordenado
        if(sum(x for x, y in valoresFitness) == 0):
            return poblacion
            
        
        
        c = 1.0/sum(x for x, y in valoresFitness)
        fitnessNormalizado = [x*c for x, y in valoresFitness]
        poblacionNormal = {}
        #ordenamos
        kv =  map(None, fitnessNormalizado, poblacion)
        poblacionNormal = kv
        poblacionNormal.sort(reverse=True)

        i = 0
        fitnessAcumulado = []
        #calculamos fitness acumulado
        for k, v in poblacionNormal:
            if i == 0:
                fitnessAcumulado.append(k)
            else:
                fitnessAcumulado.append(k + fitnessAcumulado[i-1])
            i += 1
            
        #calculamos numero aleatorio
        r = random.random()
        # se obtiene resultado tal que el valor acumulado de los elementos a elegir sea < al fitness acumulado
        result = []
        i = 0        
        while (fitnessAcumulado[i] < r):
            t= poblacionNormal[i]
            result.append(t[1])
            i+=1
        if(len(result) > 0):
            return result
        else:
            return poblacion
        
       

    
"""Cruzamientos"""

""" Cruze entre dos genomas, devuelve hijo entre los dos genomas"""
class cruzamientoNormal(object):
    """Cruzamiento entre 2 individuos"""
    def sexo(self, padre,  madre):
        hijo = []
        for n in xrange(len(padre)):
            if n < len(padre)/2:
                hijo.append(padre[n])
            else:
                hijo.append(madre[n])
        return hijo    
        
    """rutina de reproduccion entre poblacion"""
    def reproducir(self,  poblacion, totalPoblacion):
        #seleccionamos conjunto de padres
        padres = poblacion[:len(poblacion)/2]
        madres = poblacion[len(poblacion)/2:]
        # si el numero de padres es mayor que el de madres insertamos un elemento aleatorio para ajustar
        if len(padres) < len(madres):
            padres.append(madres[random.randrange(0, len(madres))])
        if len(madres) < len(padres):
            madres.append(padres[random.randrange(0, len(padres))])
        #cruzamos cada padre y cada madre
        hijos = [ self.sexo(padres[i], madres[i]) for i in xrange(len(padres))]
        if totalPoblacion - len(poblacion) !=0:
            return hijos[:random.randrange(totalPoblacion - len(poblacion))]
        else:
            return []
            
            
""" Cruze entre dos genomas, devuelve hijo entre los dos genomas, acotado a 2/3"""
class cruzamientoAcotado(object):
    """Cruzamiento entre 2 individuos"""
    def sexo(self, padre,  madre):
        hijo = []
        for n in xrange(len(padre)):
            if n < len(padre)/2:
                hijo.append(padre[n])
            else:
                hijo.append(madre[n])
        return hijo    
        
    """rutina de reproduccion entre poblacion"""
    def reproducir(self,  poblacion, totalPoblacion):
        #seleccionamos conjunto de padres
        padres = poblacion[:len(poblacion)/3]
        madres = poblacion[len(poblacion)/3:2*len(poblacion)/3]
        # si el numero de padres es mayor que el de madres insertamos un elemento aleatorio para ajustar
        if len(padres) < len(madres):
            padres.append(madres[random.randrange(0, len(madres))])
        if len(madres) < len(padres):
            madres.append(padres[random.randrange(0, len(padres))])
        #cruzamos cada padre y cada madre
        hijos = [ self.sexo(padres[i], madres[i]) for i in xrange(len(padres))]
        if totalPoblacion - len(poblacion) !=0:
            return hijos[:random.randrange(totalPoblacion - len(poblacion))]
        else:
            return []
            

class mochilero(object):
    
    #parametros
    MAX_GENES = 10
    MIN_PESO = 10
    MAX_PESO = 100
    MAX_BENEFICIO = 20
    PESO_MOCHILA = 1000
    MAX_POBLACION = 50
    GENERACIONES = 100    
    MUT_RATIO = 0.5
    OUTPUT_PATH = "/home/kreig/output/"
    TIPO_SALIDA = "MOVIE"#"TEXT"
    #seleecciona el peorcentaje dado como mejores
    RANGO_ACEPTACION = 0.5    
    beneficios = []
    pesos = []
    def __init__(self,  selStrategy, crossStrategy):
        self.metodoSeleccion = selStrategy
        self.metodoCruzamiento = crossStrategy
        """Asignamos valores aleatorios de beneficios"""
        self.beneficios = [random.randrange(1, self.MAX_BENEFICIO) for i in range(self.MAX_GENES)]
        """ Asignamos valores aleatorios de pesos"""
        self.pesos = [random.randrange(1, self.MAX_PESO) for i in range(self.MAX_GENES)]

    
    """Crea poblacion inicial"""
    def crearPoblacionInicial(self):
        poblacionInicial = []
        genoma = []
        for i in xrange(self.MAX_POBLACION):
            genoma = [random.randrange(0, 2) for k in range(self.MAX_GENES)]
            poblacionInicial.append( genoma)
        #print poblacionInicial        
        return poblacionInicial
    
    """Mutacion"""
    def mutar(self, genoma):
        bitAcambiar = random.randrange(0, self.MAX_GENES)
        genomaNuevo = genoma
        if ( genoma[bitAcambiar] == 0):
            genomaNuevo[bitAcambiar] = 1
        else:
            genomaNuevo[bitAcambiar] = 0
        return genomaNuevo
        
        
    
    """ calcula el fitness, devuelve tupla con peso y beneficio"""
    def fitness(self, lgenoma, lbeneficios, lpesos):
        #Devuelve el valor total del genoma si el peso es menor al peso maximo 
        pesoTotal = 0
        beneficioTotal = 0
        
        for n in xrange(len(lgenoma)):
            pesoTotal += lgenoma[n] * lpesos[n]
            beneficioTotal += lgenoma[n] * lbeneficios[n]
        # si el peso no se sobrepasa se devuelve pareja con peso total y beneficio total
        return (pesoTotal,  beneficioTotal)
     #end fitness
     
    """ Cruze entre dos genomas, devuelve hijo entre los dos genomas"""
    def sexo(self, padre,  madre):
        return self.metodoCruzamiento.sexo(padre, madre)


    def seleccion(self, valoresFitness, poblacion,  beneficios,  pesos, pesoMayor, rango):
        return self.metodoSeleccion.seleccion(valoresFitness, poblacion, beneficios, pesos, pesoMayor, rango)
        
    # rutina de reproduccion entre poblacion
    def reproducir(self,  poblacion, totalPoblacion):
        return self.metodoCruzamiento.reproducir(poblacion, totalPoblacion)
        
    #rutina de mutacion
    def mutacion(self, poblacion, porcentaje):
        mutantes = []
        poblacionPivote = poblacion
        poblacionAMutar = []
        #tomamos porcentaje definido en MUT_RATIO de elementos de la poblacion pivote y lo metemos en poblacion a mutar
        while len(poblacionAMutar) < len(poblacion)*porcentaje:
            idx = random.randrange(0, len(poblacion))
            elemento = poblacionPivote[idx]
            del poblacionPivote[idx]
            poblacionAMutar.append(elemento)
        #mutamos la poblacion obtenida
        mutantes = [ self.mutar(poblacionAMutar[i]) for i in xrange(len(poblacionAMutar))]
        #insertamos poblacion no mutante con poblacion mutante
        mutantes.extend(poblacionPivote)
        return mutantes
                
        
    def evolucion(self):
        poblacion = self.crearPoblacionInicial()
        porcentajeMutacion = self.MUT_RATIO
        #fitness para la nueva generacion
        valoresFitness = [ self.fitness(poblacion[i], self.beneficios, self.pesos) for i in xrange(len(poblacion))]
        poblacionActual = poblacion
        for x in xrange(self.GENERACIONES):
            self.generarSalida(valoresFitness, x)
            #elegimos elementos a reproducir            
            seleccion = self.seleccion(valoresFitness, poblacionActual,  self.beneficios,  self.pesos, self.PESO_MOCHILA, self.RANGO_ACEPTACION)
            #si la seleccion actual es optima, terminamos la ejecucion             

                
            print "seleccion",  len(seleccion)
            #reproducimos los mejores elementos de la poblacion
            nuevaGeneracion = self.reproducir(seleccion, len(poblacionActual))
            if len(seleccion)  + len(nuevaGeneracion) > len(poblacionActual):
                break
            print "hijos",  len(nuevaGeneracion)
            #mutamos la nueva generacion
            nuevaGeneracion = self.mutacion(nuevaGeneracion, porcentajeMutacion)
            #insertamos los hijos mutantes en la poblacion actual
            seleccion.extend(nuevaGeneracion)
            #calculamos fitness para la nueva generacion
            valoresFitness = [ self.fitness(seleccion[i], self.beneficios, self.pesos) for i in xrange(len(seleccion))]
            #asignamos 
            poblacionActual = seleccion
            print "poblacionActual",  len(seleccion)
            
        #se usa mencoder para el video final
        if(self.TIPO_SALIDA == "MOVIE"):
            
            #convertimos imagenes png a jpg
            os.system("echo \"generando imagenes\"")
            os.system("mogrify -format jpg %s*.png" % self.OUTPUT_PATH)            
            #limpiamos
            os.system("rm %s*.png" % self.OUTPUT_PATH)
            #convertimos imagenes resultantes al video final
            os.system("mencoder mf://%s*.jpg -mf w=512:h=384:fps=5:type=jpg -ovc lavc -lavcopts vcodec=mpeg4:mbd=2:trell -oac copy -o %ssalida.avi" % (self.OUTPUT_PATH, self.OUTPUT_PATH))
            #limpiamos
            os.system("rm %s*.jpg" % self.OUTPUT_PATH)
            
    
    """genera salida de texto de las generaciones dadas"""
    def generarSalida(self, valoresFitness, numGeneracion):
        filename = "%stxtGraph_%s.txt" % (self.OUTPUT_PATH, str(numGeneracion))
        
            
        if(self.TIPO_SALIDA == "TEXT"):
            to_print = []
            to_print.append("#Generado por GenErik (c) 2008 Erik Giron")
            to_print.append("#Generacion %d\n" % numGeneracion)
            to_print.append("#Total Poblacion " + str(len(valoresFitness)) + "\n\n")        
            to_print.append("#Peso:\tBeneficio:\n")        
            for (x, y) in valoresFitness:
                to_print.append(" %f\t%f\n" % (x, y))        
            FILE = open(filename, "w")
            FILE.writelines(to_print)
            FILE.close()
        
        if(self.TIPO_SALIDA == "MOVIE"):
            x = [] #biggles.read_column ( 0, filename, float, '#' )
            y = []#biggles.read_column ( 1, filename, float, '#' ) 
            for i, j in valoresFitness:
                x.append(i)
                y.append(j)
                
            g = biggles.FramedPlot()
            g.xrange = (0, self.MAX_PESO*self.MAX_GENES)
            g.yrange = (0, self.MAX_BENEFICIO*self.MAX_GENES)
            pts =  biggles.Points( x, y)#biggles.Points( x, y)
            #line = biggles.Curve(x, y)
            g.add( pts)
            g.xlabel = "Peso total"
            g.ylabel = "Beneficio total"
            g.title = "Grafo para Generacion %d\n Por GenErik (c) 2008 Erik Giron" % numGeneracion
            g.write_img( 512, 384, "%sgenGraph%03d.png" % (self.OUTPUT_PATH, numGeneracion) )

def main():
    #elegimos metodo de seleccion
    #seleccion = seleccionElitista()
    seleccion = seleccionRuletera()
    #elegimos metood de cruze
    #cruzamiento = cruzamientoNormal()    
    cruzamiento = cruzamientoAcotado()    
    #instanciamos mochilero
    mochila = mochilero(seleccion, cruzamiento)
    #ejecutamos algoritmo    
    mochila.evolucion()
    
    
if __name__ == "__main__":
    main()

