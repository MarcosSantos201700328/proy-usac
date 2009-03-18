/*
 * WaitQueue.java
 *
 * Creada el August 17, 2007, 6:21 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package pcb;

/**
 * Cola de procesos en espera
 *
 * @author Erik Giron (200313492)
 *
 */
public class WaitQueue extends AbstractQueue {
    
    
    /** Crea una nueva instancia de WaitQueue */
    public WaitQueue() {
    }
    /**Agrega un proceso a cola de espera*/
    public /*synchronized*/ void Push(Pcb p) {
  /*      if(this.procesos.size() <= 15){
            this.procesos.addLast(p);
      }*/
        if(this.procesos.size() <= 15){
            this.procesos.addLast(p);
            //labels[actual].setText(p.getId() + " " + p.getName() + " " + p.getQuantum());
            //actual ++;
            labels[procesos.size()-1].setText(p.getId() + " " + p.getName() + " " + p.getQuantum());
        }
    }
    /**Elimina un proceso de cola de espera*/
    public/* synchronized */Pcb Pop() {
/*        if(!procesos.isEmpty()){   
            try{
                Thread.currentThread().wait((int)(procesos.getFirst().getProceso().getQuantum()) * 1000);
            }
            catch(InterruptedException e){                
            }
            finally{
                Process head = this.procesos.getFirst();
                procesos.removeFirst();
                return head;
            }
           
        } */
        if(!procesos.isEmpty()){   
            //Process head = this.procesos.getFirst();
            Pcb head = this.procesos.getFirst();
            procesos.removeFirst();
            for (int i = 0; i < procesos.size(); i++)                
                labels[i].setText(labels[i + 1].getText());                            
            labels[ procesos.size()].setText("");
            return head;
        }
        return null;
    }
    
    /**Rota la cola*/
    public synchronized void rotate(){        
        Pcb temp;
        String tmpstr;
        if(!procesos.isEmpty()){
            try{
                Thread.currentThread().sleep((int)(procesos.getFirst().getQuantum()) * 1000);
            }
            catch(InterruptedException e){                
            }
            finally{
                temp = procesos.getFirst();                    
                procesos.removeFirst();
                procesos.addLast(temp);
                for (int i = 0; i < 15 && i < procesos.size(); i++){
                    if(i == procesos.size() - 1)
                        labels[i].setText(procesos.get(0).getId() + " " + procesos.get(0).getName() + " " + procesos.get(0).getQuantum());
                    else
                        labels[i].setText(procesos.get(i + 1).getId() + " " + procesos.get( i + 1).getName() + " " + procesos.get(i + 1).getQuantum());
                }
                changed = true;
                
            }
        }       
    }
    
}
